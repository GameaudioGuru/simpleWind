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

#ifndef _HV_SIMPLEWIND_WWISE_PLUGIN_ENGINE_PARAMS_H_
#define _HV_SIMPLEWIND_WWISE_PLUGIN_ENGINE_PARAMS_H_

#include <AK/SoundEngine/Common/IAkPlugin.h>
#include <AK/Tools/Common/AkAssert.h>

/** Generated RTPC IDs */

// Input Parameters
static const AkPluginParamID HV_SIMPLEWIND_PARAM_IN_Q_ID = 0;
static const AkPluginParamID HV_SIMPLEWIND_PARAM_IN_CENTERFREQUENCY_01_ID = 1;

/** Parameters structure for this effect. */
struct Hv_simpleWind_RTPCParams {
  /** Generated Heavy Parameters */
  AkReal32 fHVParam_Q;
  AkReal32 fHVParam_centerFrequency_01;
};

/**
 * class Hv_simpleWind_EngineParams
 * Implementation of Heavy Wwise plugin shared parameters.
 */
class Hv_simpleWind_EngineParams : public AK::IAkPluginParam {
 public:
  /** Allow effect to call accessor functions for retrieving parameter values. */
  friend class Hv_simpleWind_WwisePluginEngine;

  /** Default Constructor. */
  Hv_simpleWind_EngineParams();

  /** Destructor. */
  virtual ~Hv_simpleWind_EngineParams();

  /** Copy constructor. */
  Hv_simpleWind_EngineParams(const Hv_simpleWind_EngineParams &in_rCopy);

  /** Create duplicate. */
  virtual IAkPluginParam *Clone(AK::IAkPluginMemAlloc *in_pAllocator);

  /** Parameters node initialization. */
  virtual AKRESULT Init(AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock,
      AkUInt32 in_uBlockSize);

  /** Terminate. */
  virtual AKRESULT Term(AK::IAkPluginMemAlloc *in_pAllocator);

  /** Set all parameters at once. */
  virtual AKRESULT SetParamsBlock(const void * in_pParamsBlock,
      AkUInt32 in_uBlockSize);

  /** Update one parameter. */
  virtual AKRESULT SetParam(AkPluginParamID in_ParamID, const void *in_pValue,
      AkUInt32 in_uParamSize);

private:
  /** Hide assignment operator. */
  Hv_simpleWind_EngineParams &operator=(const Hv_simpleWind_EngineParams &in_rCopy) = default;

  /** RTPC'd Heavy Parameter Getter Methods */
  AkReal32 GetParam_Q();
  AkReal32 GetParam_centerFrequency_01();

  /** RTPC Parameter structure. */
  Hv_simpleWind_RTPCParams m_Params;
};

/** Getter methods for generated Heavy parameters */
inline AkReal32 Hv_simpleWind_EngineParams::GetParam_Q() {
  AkReal32 fParam_Q = m_Params.fHVParam_Q;
  AKASSERT(fParam_Q >= 0.1 && fParam_Q <= 2.0);
  return fParam_Q;
}

inline AkReal32 Hv_simpleWind_EngineParams::GetParam_centerFrequency_01() {
  AkReal32 fParam_centerFrequency_01 = m_Params.fHVParam_centerFrequency_01;
  AKASSERT(fParam_centerFrequency_01 >= 20.0 && fParam_centerFrequency_01 <= 20000.0);
  return fParam_centerFrequency_01;
}


#endif // _HV_SIMPLEWIND_WWISE_PLUGIN_ENGINE_PARAMS_H_
