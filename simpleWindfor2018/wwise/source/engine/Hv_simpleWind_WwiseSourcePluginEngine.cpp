/**
 * Copyright (c) 2018 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Hv_simpleWind_WwiseSourcePluginEngine.h"
#include "Hv_simpleWind_WwisePluginIDs.h"
#include "Heavy_simpleWind.hpp"
#include <AK/AkWwiseSDKVersion.h>
#include <AK/Tools/Common/AkAssert.h>
#include <AK/Tools/Common/AkFNVHash.h>

typedef struct WavHeader {
  uint32_t ChunkID; // 0
  uint32_t ChunkSize; // 4
  uint32_t Format; // 8
  uint32_t Subchunk1ID; // 12
  uint32_t Subchunk1Size; // 16
  uint16_t AudioFormat; // 20
  uint16_t NumChannels; // 22
  uint32_t SampleRate; // 24
  uint32_t ByteRate; // 28
  uint16_t BlockAlign; // 32
  uint16_t BitsPerSample; // 34
  uint32_t Subchunk2ID; // 36
  uint32_t Subchunk2Size; // 40
  uint32_t Subchunk2Data; // 44
  uint32_t Subchunk3ID; // 48
  uint32_t Subchunk3Size; // 52
  // data -> 56
} WavHeader;


AK::IAkPlugin* CreateHv_simpleWind_WwisePluginEngine(AK::IAkPluginMemAlloc *in_pAllocator) {
  return AK_PLUGIN_NEW( in_pAllocator, Hv_simpleWind_WwisePluginEngine() );
}

/** Plugin mechanism. Parameters node creation function to be registered to the FX manager. */
AK::IAkPluginParam *CreateHv_simpleWind_WwisePluginEngineParams(AK::IAkPluginMemAlloc *in_pAllocator) {
  return AK_PLUGIN_NEW(in_pAllocator, Hv_simpleWind_EngineParams());
}


static void OnHeavyPrint(HeavyContextInterface *context, const char *printName, const char *str,
    const HvMessage *msg) {
  Hv_simpleWind_WwisePluginEngine *engine = reinterpret_cast<Hv_simpleWind_WwisePluginEngine *>(context->getUserData());
  if (engine != nullptr) {
    engine->PostDebugMessage(str);
  }
}

/** Static initializer object to register automatically the plugin into the sound engine */
AK::PluginRegistration Hv_simpleWind_WwiseSourcePluginRegistration(
  AkPluginTypeSource,
  HV_COMPANY_ID, HV_SIMPLEWIND_PLUGIN_ID,
  CreateHv_simpleWind_WwisePluginEngine,
  CreateHv_simpleWind_WwisePluginEngineParams);

Hv_simpleWind_WwisePluginEngine::Hv_simpleWind_WwisePluginEngine() {
  /** Initialize members. */
  m_pPluginContext = NULL;
  m_pEngineParams = NULL;
  m_pHeavyContext = NULL;
  m_uSampleRate = 0;
  m_fPrevParam_Q = 1.2f;
  m_fPrevParam_centerFrequency_01 = 130.0f;
}

Hv_simpleWind_WwisePluginEngine::~Hv_simpleWind_WwisePluginEngine() {

}

AKRESULT Hv_simpleWind_WwisePluginEngine::Init(AK::IAkPluginMemAlloc *in_pAllocator,
    AK::IAkSourcePluginContext *in_pPluginContext, AK::IAkPluginParam *in_pParams,
    AkAudioFormat &io_rFormat) {

  m_pPluginContext = in_pPluginContext;

  AKASSERT(in_pParams != NULL);

  // Initialise Heavy context
  m_uSampleRate = io_rFormat.uSampleRate;
  m_pHeavyContext = new Heavy_simpleWind((double) m_uSampleRate, 10, 2, 2);
  m_pHeavyContext->setUserData(this);
  
#ifndef AK_OPTIMIZED
  m_pHeavyContext->setPrintHook(&OnHeavyPrint);
#endif
  
  // Notify pipeline of chosen output format change.
  AkChannelMask channelMask = (hv_getNumOutputChannels(m_pHeavyContext) > 1)
      ? AK_SPEAKER_SETUP_2_0 : AK_SPEAKER_SETUP_MONO;
  io_rFormat.channelConfig.SetStandard(channelMask);
  
  // Initialise Parameters
  m_pEngineParams = reinterpret_cast<Hv_simpleWind_EngineParams *>(in_pParams);
  hv_sendFloatToReceiver(m_pHeavyContext, Heavy_simpleWind::Parameter::In::Q, m_pEngineParams->GetParam_Q());
  hv_sendFloatToReceiver(m_pHeavyContext, Heavy_simpleWind::Parameter::In::CENTERFREQUENCY_01, m_pEngineParams->GetParam_centerFrequency_01());
  
  AK_PERF_RECORDING_RESET();

  return AK_Success;
}

AKRESULT Hv_simpleWind_WwisePluginEngine::Term(AK::IAkPluginMemAlloc *in_pAllocator) {
  delete m_pHeavyContext;
  AK_PLUGIN_DELETE(in_pAllocator, this);
  return AK_Success;
}

AKRESULT Hv_simpleWind_WwisePluginEngine::GetPluginInfo(AkPluginInfo & out_rPluginInfo) {
  out_rPluginInfo.eType = AkPluginTypeSource;
  out_rPluginInfo.bIsInPlace = true;
  out_rPluginInfo.uBuildVersion = AK_WWISESDK_VERSION_COMBINED;
  return AK_Success;
}

void Hv_simpleWind_WwisePluginEngine::Execute(AkAudioBuffer *io_pBufferOut) {
  AK_PERF_RECORDING_START( "Hv_simpleWind_WwisePluginEngine", 25, 30);

  // Retrieve RTPC values and send in as a message to context
  AkReal32 param_Q = m_pEngineParams->GetParam_Q();
  if (param_Q != m_fPrevParam_Q) {
    hv_sendFloatToReceiver(m_pHeavyContext, Heavy_simpleWind::Parameter::In::Q, param_Q);
    m_fPrevParam_Q = param_Q;
  }
  AkReal32 param_centerFrequency_01 = m_pEngineParams->GetParam_centerFrequency_01();
  if (param_centerFrequency_01 != m_fPrevParam_centerFrequency_01) {
    hv_sendFloatToReceiver(m_pHeavyContext, Heavy_simpleWind::Parameter::In::CENTERFREQUENCY_01, param_centerFrequency_01);
    m_fPrevParam_centerFrequency_01 = param_centerFrequency_01;
  }

  

  // Calculate num frames to process and retrieve buffer
  AkUInt16 numFramesToProcess = io_pBufferOut->MaxFrames();
  float *buffer = (float *) io_pBufferOut->GetChannel(0);
  
  m_pHeavyContext->processInline(nullptr, buffer, numFramesToProcess);
  
  io_pBufferOut->uValidFrames = numFramesToProcess;
  io_pBufferOut->eState = AK_DataReady;

  AK_PERF_RECORDING_STOP("Hv_simpleWind_WwisePluginEngine", 25, 30);
}

AkReal32 Hv_simpleWind_WwisePluginEngine::GetDuration() const {
  return 0.0f; // Infinite duration.
}

AkReal32 Hv_simpleWind_WwisePluginEngine::GetEnvelope() const {
  return 1.0f; // Normalized envelope.
}

AKRESULT Hv_simpleWind_WwisePluginEngine::StopLooping() {
  return AK_Success;
}

void Hv_simpleWind_WwisePluginEngine::PostDebugMessage(const char *message) {
  m_pPluginContext->PostMonitorMessage(message, AK::Monitor::ErrorLevel::ErrorLevel_Message);
}

void Hv_simpleWind_WwisePluginEngine::LoadPluginMediaToHeavyTable(unsigned int mediaIndex,
    unsigned int tableHash, unsigned int tableSizeReceiverHash) {
  AkUInt8 *pPluginData = NULL;
  AkUInt32 uPluginDataSize;
  m_pPluginContext->GetPluginMedia(mediaIndex, pPluginData, uPluginDataSize); // retrieve stored plugin data

  if (pPluginData != NULL) {
    // determine wav header format
    WavHeader h;
    hv_memcpy(&h, pPluginData, sizeof(WavHeader));
    uint32_t offsetBytes = 0;
    const uint32_t dataID = 0x61746164; // 'data'
    const uint32_t factID = 0x74636166; // 'fact'
    if (h.Subchunk2ID == dataID) {
      offsetBytes = 44;
    }
    else if (h.Subchunk2ID == factID && h.Subchunk3ID == dataID) {
      offsetBytes = 56;
    }

    uint32_t newSizeBytes = uPluginDataSize - offsetBytes;
    if (offsetBytes > 0 && newSizeBytes > 0) {
      // adjust table size
      const uint32_t numSamples = newSizeBytes * 8 / h.BitsPerSample;
      m_pHeavyContext->setLengthForTable(tableHash, numSamples);

      float *buffer = m_pHeavyContext->getBufferForTable(tableHash);
      if (buffer != NULL && newSizeBytes > 0) {
        // copy contents and notify respective receiver
        hv_memcpy(buffer, (float *) (pPluginData + offsetBytes), newSizeBytes);
        m_pHeavyContext->sendFloatToReceiver(tableSizeReceiverHash, (float) numSamples);
      }
    }
  }
}

void Hv_simpleWind_WwisePluginEngine::SetOutRTPC(const char *rtpcName,
    unsigned int nameLength, float value) {
  AK::FNVHash32 hashFunc;
  // Set the RTPC value for the plugin's associated gameobject.
  // Note(joe): if the plugin is on a bus the gameobject will be null and thus
  // set the global RTPC.
  m_pPluginContext->GlobalContext()->SetRTPCValue(
      hashFunc.Compute((unsigned char *) rtpcName, nameLength*sizeof(char)),
      value,
      m_pPluginContext->GetVoiceInfo()->GetGameObjectID(),
      0,
      AkCurveInterpolation_Linear,
      true); // disable interpolation, let the plugin handle it internally
}
