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

#include "Heavy_simpleWind.hpp"

#define Context(_c) reinterpret_cast<Heavy_simpleWind *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_simpleWind_new(double sampleRate) {
    return new Heavy_simpleWind(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_simpleWind_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_simpleWind(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_simpleWind::Heavy_simpleWind(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_vf1pzYkf, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_SNl7n2og, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_jI3nRZ3I, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_sXHFfO3Q, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_hcyasJ9m, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_tar7c5jV, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sVari_init(&sVari_aut8Yt4Y, 0, 0, false);
  numBytes += cSlice_init(&cSlice_Np2A0Hma, 1, 1);
  numBytes += cRandom_init(&cRandom_1oarSilj, 2050873210);
  numBytes += cRandom_init(&cRandom_hDGCqg3z, 1364900309);
  numBytes += cSlice_init(&cSlice_X3fUcOw4, 1, 1);
  numBytes += sVari_init(&sVari_VtfBrZPE, 0, 0, false);
  numBytes += sVari_init(&sVari_awkwSxvB, 0, 0, false);
  numBytes += cRandom_init(&cRandom_dHjPAE2h, -683602384);
  numBytes += cSlice_init(&cSlice_khAFsJvr, 1, 1);
  numBytes += cBinop_init(&cBinop_duj9Vzsa, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_sV29vKkJ, 22050.0f);
  numBytes += cVar_init_f(&cVar_PZqNkw5L, 1.0f);
  numBytes += cBinop_init(&cBinop_XID8sJpX, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_GHgiPdmQ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_xawwm4se, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_5sgegJNE, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5sUnBs4A, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_RKuXHjLd, 0.0f);
  numBytes += cVar_init_f(&cVar_PN6P17Jp, 1.0f);
  numBytes += cBinop_init(&cBinop_MId9blJb, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MAzG1OpX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HyJtdoqi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_cX4wdgmP, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Jj3x8zHW, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_XE6cLVzR, 22050.0f);
  numBytes += cBinop_init(&cBinop_zxhx5cMP, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KIu4tBtN, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_9UaI8X94, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wFc3LBVU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0EtPiUGl, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_PFjA3kUE, 22050.0f);
  numBytes += cBinop_init(&cBinop_SRj0oqC4, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_04GU2JcG, 1.0f);
  numBytes += cBinop_init(&cBinop_N5Z37uK9, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_08BLB4hJ, 0.0f);
  numBytes += cVar_init_f(&cVar_dUlpqATO, 0.0f);
  numBytes += cVar_init_f(&cVar_scDLNTaT, 0.0f);
  numBytes += cBinop_init(&cBinop_O8Q7Bf9l, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_C4FFxZsY, 22050.0f);
  numBytes += cBinop_init(&cBinop_GRJAoClQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nuBBhYSo, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_OJQCiJ3A, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_9Nry2y47, 1.0f);
  numBytes += cBinop_init(&cBinop_kp7dpvIA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VYxQxxPq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_MnJFiYAX, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_WM44L5Vk, 1.0f);
  numBytes += cBinop_init(&cBinop_PvRE7osX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YiPqNUkR, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_hwQ22vSq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YV4hIEni, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_NHJrrzJX, 22050.0f);
  numBytes += cBinop_init(&cBinop_fZ6n5LMH, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_hsqUZSED, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XOa8f9q1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zyOD6MwC, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_rGxV73Sc, 1.0f);
  numBytes += cBinop_init(&cBinop_EISSvgxs, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_HSDZgDOH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BKBusjyv, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XmHhEsRF, 22050.0f);
  numBytes += cVar_init_f(&cVar_GUjC9kah, 0.0f);
  numBytes += cVar_init_f(&cVar_AHIbzr54, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_simpleWind::~Heavy_simpleWind() {
  // nothing to free
}

HvTable *Heavy_simpleWind::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_simpleWind::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xF3BA5CD4: { // Q
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2EnZ9wzD_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mrqNjPCT_sendMessage);
      break;
    }
    case 0x539436C5: { // centerFrequency_01
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UUyirtEs_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_simpleWind::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Q";
        info->hash = 0xF3BA5CD4;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.1f;
        info->maxVal = 2.0f;
        info->defaultVal = 1.2f;
        break;
      }
      case 1: {
        info->name = "centerFrequency_01";
        info->hash = 0x539436C5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 20.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 130.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_simpleWind::cUnop_64WB82kK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_34zJbigM_sendMessage(_c, 0, m);
}

void Heavy_simpleWind::cSlice_Np2A0Hma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1oarSilj, 1, m, &cRandom_1oarSilj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simpleWind::cBinop_MLl5jsqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_64WB82kK_sendMessage);
}

void Heavy_simpleWind::cSwitchcase_MKJjn0Sx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Np2A0Hma, 0, m, &cSlice_Np2A0Hma_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1oarSilj, 0, m, &cRandom_1oarSilj_sendMessage);
      break;
    }
  }
}

void Heavy_simpleWind::cRandom_1oarSilj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_MLl5jsqt_sendMessage);
}

void Heavy_simpleWind::cMsg_34zJbigM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_aut8Yt4Y, m);
}

void Heavy_simpleWind::cUnop_bnsRVnsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rM26PKT8_sendMessage(_c, 0, m);
}

void Heavy_simpleWind::cSwitchcase_16KBbHuy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_X3fUcOw4, 0, m, &cSlice_X3fUcOw4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hDGCqg3z, 0, m, &cRandom_hDGCqg3z_sendMessage);
      break;
    }
  }
}

void Heavy_simpleWind::cRandom_hDGCqg3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_BX2BM73a_sendMessage);
}

void Heavy_simpleWind::cBinop_BX2BM73a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_bnsRVnsp_sendMessage);
}

void Heavy_simpleWind::cSlice_X3fUcOw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hDGCqg3z, 1, m, &cRandom_hDGCqg3z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simpleWind::cMsg_rM26PKT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_VtfBrZPE, m);
}

void Heavy_simpleWind::cBinop_TyPLDmk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zj7mX5Zl_sendMessage);
}

void Heavy_simpleWind::cSwitchcase_ym65bbOa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_khAFsJvr, 0, m, &cSlice_khAFsJvr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dHjPAE2h, 0, m, &cRandom_dHjPAE2h_sendMessage);
      break;
    }
  }
}

void Heavy_simpleWind::cRandom_dHjPAE2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_TyPLDmk3_sendMessage);
}

void Heavy_simpleWind::cSlice_khAFsJvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dHjPAE2h, 1, m, &cRandom_dHjPAE2h_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simpleWind::cUnop_zj7mX5Zl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uKqsmIC7_sendMessage(_c, 0, m);
}

void Heavy_simpleWind::cMsg_uKqsmIC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_awkwSxvB, m);
}

void Heavy_simpleWind::cReceive_mrqNjPCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ym65bbOa_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_16KBbHuy_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_MKJjn0Sx_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_9Nry2y47, 0, m, &cVar_9Nry2y47_sendMessage);
  cMsg_wuJ2UxHJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_C4FFxZsY, 0, m, &cVar_C4FFxZsY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_04GU2JcG, 0, m, &cVar_04GU2JcG_sendMessage);
  cMsg_USsAkyex_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PFjA3kUE, 0, m, &cVar_PFjA3kUE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rGxV73Sc, 0, m, &cVar_rGxV73Sc_sendMessage);
  cMsg_36iLMAXw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XmHhEsRF, 0, m, &cVar_XmHhEsRF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WM44L5Vk, 0, m, &cVar_WM44L5Vk_sendMessage);
  cMsg_qsp8fJ3r_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NHJrrzJX, 0, m, &cVar_NHJrrzJX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PZqNkw5L, 0, m, &cVar_PZqNkw5L_sendMessage);
  cMsg_iwdWSRnX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sV29vKkJ, 0, m, &cVar_sV29vKkJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PN6P17Jp, 0, m, &cVar_PN6P17Jp_sendMessage);
  cMsg_7H4n2H8V_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XE6cLVzR, 0, m, &cVar_XE6cLVzR_sendMessage);
}

void Heavy_simpleWind::cMsg_iwdWSRnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ltK4iqoa_sendMessage);
}

void Heavy_simpleWind::cSystem_ltK4iqoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XID8sJpX, HV_BINOP_DIVIDE, 1, m, &cBinop_XID8sJpX_sendMessage);
}

void Heavy_simpleWind::cBinop_duj9Vzsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bKtq7nSs_sendMessage);
}

void Heavy_simpleWind::cVar_sV29vKkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_8veCtKn3_sendMessage);
}

void Heavy_simpleWind::cBinop_YgJ9XK9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sXHFfO3Q, 5, m);
}

void Heavy_simpleWind::cBinop_B8xxMvcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YgJ9XK9f_sendMessage);
}

void Heavy_simpleWind::cVar_PZqNkw5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_SunTPbc3_sendMessage);
}

void Heavy_simpleWind::cBinop_aqPsZuvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_GWKn0ZtA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_duj9Vzsa, HV_BINOP_MULTIPLY, 0, m, &cBinop_duj9Vzsa_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5sgegJNE, HV_BINOP_MULTIPLY, 0, m, &cBinop_5sgegJNE_sendMessage);
}

void Heavy_simpleWind::cBinop_XID8sJpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5sgegJNE, HV_BINOP_MULTIPLY, 1, m, &cBinop_5sgegJNE_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_oGrt12K5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xawwm4se, HV_BINOP_DIVIDE, 0, m, &cBinop_xawwm4se_sendMessage);
}

void Heavy_simpleWind::cBinop_8veCtKn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XID8sJpX, HV_BINOP_DIVIDE, 0, m, &cBinop_XID8sJpX_sendMessage);
}

void Heavy_simpleWind::cBinop_GHgiPdmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5sUnBs4A, HV_BINOP_MULTIPLY, 1, m, &cBinop_5sUnBs4A_sendMessage);
}

void Heavy_simpleWind::cBinop_bKtq7nSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sXHFfO3Q, 4, m);
}

void Heavy_simpleWind::cBinop_QDP4a1fs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1gij5Yvz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GHgiPdmQ, HV_BINOP_ADD, 0, m, &cBinop_GHgiPdmQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_hwFdDnOR_sendMessage);
}

void Heavy_simpleWind::cBinop_xawwm4se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QDP4a1fs_sendMessage);
}

void Heavy_simpleWind::cBinop_SunTPbc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xawwm4se, HV_BINOP_DIVIDE, 1, m, &cBinop_xawwm4se_sendMessage);
}

void Heavy_simpleWind::cBinop_hwFdDnOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5sUnBs4A, HV_BINOP_MULTIPLY, 0, m, &cBinop_5sUnBs4A_sendMessage);
}

void Heavy_simpleWind::cBinop_5sgegJNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GHgiPdmQ, HV_BINOP_ADD, 1, m, &cBinop_GHgiPdmQ_sendMessage);
}

void Heavy_simpleWind::cUnop_oGrt12K5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_DALXMOTs_sendMessage);
}

void Heavy_simpleWind::cBinop_GWKn0ZtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_B8xxMvcW_sendMessage);
}

void Heavy_simpleWind::cCast_4UTMJI96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sV29vKkJ, 0, m, &cVar_sV29vKkJ_sendMessage);
}

void Heavy_simpleWind::cBinop_DALXMOTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_duj9Vzsa, HV_BINOP_MULTIPLY, 1, m, &cBinop_duj9Vzsa_sendMessage);
}

void Heavy_simpleWind::cBinop_5sUnBs4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sXHFfO3Q, 1, m);
}

void Heavy_simpleWind::cBinop_1gij5Yvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aqPsZuvz_sendMessage);
}

void Heavy_simpleWind::cVar_RKuXHjLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rGxV73Sc, 0, m, &cVar_rGxV73Sc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3d6iVWIq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PN6P17Jp, 0, m, &cVar_PN6P17Jp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hn7QnS1j_sendMessage);
}

void Heavy_simpleWind::cBinop_OH7InqxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jj3x8zHW, HV_BINOP_DIVIDE, 1, m, &cBinop_Jj3x8zHW_sendMessage);
}

void Heavy_simpleWind::cMsg_7H4n2H8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dkJfqr6y_sendMessage);
}

void Heavy_simpleWind::cSystem_dkJfqr6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cX4wdgmP, HV_BINOP_DIVIDE, 1, m, &cBinop_cX4wdgmP_sendMessage);
}

void Heavy_simpleWind::cBinop_OQc4Eh31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxhx5cMP, HV_BINOP_MULTIPLY, 1, m, &cBinop_zxhx5cMP_sendMessage);
}

void Heavy_simpleWind::cVar_PN6P17Jp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_OH7InqxW_sendMessage);
}

void Heavy_simpleWind::cBinop_3lyQUVNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tar7c5jV, 4, m);
}

void Heavy_simpleWind::cBinop_asjgeXP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HyJtdoqi, HV_BINOP_MULTIPLY, 0, m, &cBinop_HyJtdoqi_sendMessage);
}

void Heavy_simpleWind::cUnop_Gsokg6Wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_OQc4Eh31_sendMessage);
}

void Heavy_simpleWind::cBinop_MId9blJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HyJtdoqi, HV_BINOP_MULTIPLY, 1, m, &cBinop_HyJtdoqi_sendMessage);
}

void Heavy_simpleWind::cCast_Hn7QnS1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XE6cLVzR, 0, m, &cVar_XE6cLVzR_sendMessage);
}

void Heavy_simpleWind::cBinop_BVwUKxZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cX4wdgmP, HV_BINOP_DIVIDE, 0, m, &cBinop_cX4wdgmP_sendMessage);
}

void Heavy_simpleWind::cBinop_RVgL7XKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UgMUMfMq_sendMessage);
}

void Heavy_simpleWind::cBinop_MAzG1OpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MId9blJb, HV_BINOP_ADD, 1, m, &cBinop_MId9blJb_sendMessage);
}

void Heavy_simpleWind::cBinop_UgMUMfMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tar7c5jV, 5, m);
}

void Heavy_simpleWind::cBinop_DBzrryKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_r2qEYE1k_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxhx5cMP, HV_BINOP_MULTIPLY, 0, m, &cBinop_zxhx5cMP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MAzG1OpX, HV_BINOP_MULTIPLY, 0, m, &cBinop_MAzG1OpX_sendMessage);
}

void Heavy_simpleWind::cBinop_pmAvZCLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_DBzrryKD_sendMessage);
}

void Heavy_simpleWind::cBinop_HyJtdoqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tar7c5jV, 1, m);
}

void Heavy_simpleWind::cBinop_cX4wdgmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MAzG1OpX, HV_BINOP_MULTIPLY, 1, m, &cBinop_MAzG1OpX_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Gsokg6Wm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jj3x8zHW, HV_BINOP_DIVIDE, 0, m, &cBinop_Jj3x8zHW_sendMessage);
}

void Heavy_simpleWind::cBinop_Jj3x8zHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WfaAKmnL_sendMessage);
}

void Heavy_simpleWind::cBinop_r2qEYE1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RVgL7XKy_sendMessage);
}

void Heavy_simpleWind::cVar_XE6cLVzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_BVwUKxZs_sendMessage);
}

void Heavy_simpleWind::cBinop_zxhx5cMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3lyQUVNV_sendMessage);
}

void Heavy_simpleWind::cBinop_WfaAKmnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pmAvZCLv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MId9blJb, HV_BINOP_ADD, 0, m, &cBinop_MId9blJb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_asjgeXP8_sendMessage);
}

void Heavy_simpleWind::cReceive_2EnZ9wzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_scDLNTaT, 0, m, &cVar_scDLNTaT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_08BLB4hJ, 0, m, &cVar_08BLB4hJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RKuXHjLd, 0, m, &cVar_RKuXHjLd_sendMessage);
}

void Heavy_simpleWind::cBinop_UZ7DgDsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_jI3nRZ3I, 5, m);
}

void Heavy_simpleWind::cBinop_KIu4tBtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0EtPiUGl, HV_BINOP_MULTIPLY, 1, m, &cBinop_0EtPiUGl_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_LFLmCJ1Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_N5Z37uK9, HV_BINOP_DIVIDE, 0, m, &cBinop_N5Z37uK9_sendMessage);
}

void Heavy_simpleWind::cBinop_9UaI8X94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wFc3LBVU, HV_BINOP_MULTIPLY, 1, m, &cBinop_wFc3LBVU_sendMessage);
}

void Heavy_simpleWind::cBinop_GeTZbG9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ufgWJbPN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9UaI8X94, HV_BINOP_ADD, 0, m, &cBinop_9UaI8X94_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_u19ClEKl_sendMessage);
}

void Heavy_simpleWind::cBinop_91Q3Vlm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N5Z37uK9, HV_BINOP_DIVIDE, 1, m, &cBinop_N5Z37uK9_sendMessage);
}

void Heavy_simpleWind::cBinop_R1lQlkKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KIu4tBtN, HV_BINOP_DIVIDE, 0, m, &cBinop_KIu4tBtN_sendMessage);
}

void Heavy_simpleWind::cBinop_Wxpz8xdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_jI3nRZ3I, 4, m);
}

void Heavy_simpleWind::cBinop_wFc3LBVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_jI3nRZ3I, 1, m);
}

void Heavy_simpleWind::cBinop_u19ClEKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wFc3LBVU, HV_BINOP_MULTIPLY, 0, m, &cBinop_wFc3LBVU_sendMessage);
}

void Heavy_simpleWind::cBinop_ufgWJbPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wdXg9sSu_sendMessage);
}

void Heavy_simpleWind::cBinop_0EtPiUGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9UaI8X94, HV_BINOP_ADD, 1, m, &cBinop_9UaI8X94_sendMessage);
}

void Heavy_simpleWind::cBinop_ZDPEjJI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UZ7DgDsX_sendMessage);
}

void Heavy_simpleWind::cVar_PFjA3kUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_R1lQlkKU_sendMessage);
}

void Heavy_simpleWind::cBinop_j6raFRLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZDPEjJI5_sendMessage);
}

void Heavy_simpleWind::cCast_cOpO5W1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PFjA3kUE, 0, m, &cVar_PFjA3kUE_sendMessage);
}

void Heavy_simpleWind::cBinop_SRj0oqC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Wxpz8xdG_sendMessage);
}

void Heavy_simpleWind::cVar_04GU2JcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_91Q3Vlm5_sendMessage);
}

void Heavy_simpleWind::cBinop_N5Z37uK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_GeTZbG9G_sendMessage);
}

void Heavy_simpleWind::cMsg_USsAkyex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4Ne3hm7t_sendMessage);
}

void Heavy_simpleWind::cSystem_4Ne3hm7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KIu4tBtN, HV_BINOP_DIVIDE, 1, m, &cBinop_KIu4tBtN_sendMessage);
}

void Heavy_simpleWind::cBinop_wdXg9sSu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_j6raFRLU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SRj0oqC4, HV_BINOP_MULTIPLY, 0, m, &cBinop_SRj0oqC4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0EtPiUGl, HV_BINOP_MULTIPLY, 0, m, &cBinop_0EtPiUGl_sendMessage);
}

void Heavy_simpleWind::cBinop_8scupIu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SRj0oqC4, HV_BINOP_MULTIPLY, 1, m, &cBinop_SRj0oqC4_sendMessage);
}

void Heavy_simpleWind::cUnop_LFLmCJ1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_8scupIu8_sendMessage);
}

void Heavy_simpleWind::cVar_08BLB4hJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_04GU2JcG, 0, m, &cVar_04GU2JcG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cOpO5W1o_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PZqNkw5L, 0, m, &cVar_PZqNkw5L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4UTMJI96_sendMessage);
}

void Heavy_simpleWind::cReceive_UUyirtEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dUlpqATO, 0, m, &cVar_dUlpqATO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AHIbzr54, 0, m, &cVar_AHIbzr54_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GUjC9kah, 0, m, &cVar_GUjC9kah_sendMessage);
}

void Heavy_simpleWind::cVar_dUlpqATO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C4FFxZsY, 0, m, &cVar_C4FFxZsY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NHJrrzJX, 0, m, &cVar_NHJrrzJX_sendMessage);
}

void Heavy_simpleWind::cVar_scDLNTaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Nry2y47, 0, m, &cVar_9Nry2y47_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lbPEmnIy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WM44L5Vk, 0, m, &cVar_WM44L5Vk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9kwKhY4t_sendMessage);
}

void Heavy_simpleWind::cBinop_5D0S6jWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S3p3nSsZ_sendMessage);
}

void Heavy_simpleWind::cBinop_O8Q7Bf9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kp7dpvIA, HV_BINOP_MULTIPLY, 1, m, &cBinop_kp7dpvIA_sendMessage);
}

void Heavy_simpleWind::cVar_C4FFxZsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_iyKOlRMC_sendMessage);
}

void Heavy_simpleWind::cBinop_DsPcXYm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ejG9TU96_sendMessage);
}

void Heavy_simpleWind::cBinop_TzLDJGbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_vf1pzYkf, 5, m);
}

void Heavy_simpleWind::cSystem_uYS7T4kW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VYxQxxPq, HV_BINOP_DIVIDE, 1, m, &cBinop_VYxQxxPq_sendMessage);
}

void Heavy_simpleWind::cMsg_wuJ2UxHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uYS7T4kW_sendMessage);
}

void Heavy_simpleWind::cBinop_S3p3nSsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TzLDJGbC_sendMessage);
}

void Heavy_simpleWind::cBinop_AJn52BCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DsPcXYm5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_O8Q7Bf9l, HV_BINOP_ADD, 0, m, &cBinop_O8Q7Bf9l_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_y7Nz7ktL_sendMessage);
}

void Heavy_simpleWind::cBinop_KFpYiLtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nuBBhYSo, HV_BINOP_DIVIDE, 1, m, &cBinop_nuBBhYSo_sendMessage);
}

void Heavy_simpleWind::cBinop_iyKOlRMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VYxQxxPq, HV_BINOP_DIVIDE, 0, m, &cBinop_VYxQxxPq_sendMessage);
}

void Heavy_simpleWind::cBinop_GRJAoClQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uNTMeTgy_sendMessage);
}

void Heavy_simpleWind::cCast_lbPEmnIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C4FFxZsY, 0, m, &cVar_C4FFxZsY_sendMessage);
}

void Heavy_simpleWind::cUnop_QvplIukv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_kAFZa1KQ_sendMessage);
}

void Heavy_simpleWind::cBinop_uNTMeTgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_vf1pzYkf, 4, m);
}

void Heavy_simpleWind::cBinop_nuBBhYSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AJn52BCG_sendMessage);
}

void Heavy_simpleWind::cBinop_ejG9TU96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_5D0S6jWQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRJAoClQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_GRJAoClQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OJQCiJ3A, HV_BINOP_MULTIPLY, 0, m, &cBinop_OJQCiJ3A_sendMessage);
}

void Heavy_simpleWind::cBinop_OJQCiJ3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O8Q7Bf9l, HV_BINOP_ADD, 1, m, &cBinop_O8Q7Bf9l_sendMessage);
}

void Heavy_simpleWind::cVar_9Nry2y47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_KFpYiLtB_sendMessage);
}

void Heavy_simpleWind::cBinop_kAFZa1KQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRJAoClQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_GRJAoClQ_sendMessage);
}

void Heavy_simpleWind::cBinop_y7Nz7ktL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kp7dpvIA, HV_BINOP_MULTIPLY, 0, m, &cBinop_kp7dpvIA_sendMessage);
}

void Heavy_simpleWind::cBinop_kp7dpvIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_vf1pzYkf, 1, m);
}

void Heavy_simpleWind::cBinop_VYxQxxPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OJQCiJ3A, HV_BINOP_MULTIPLY, 1, m, &cBinop_OJQCiJ3A_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_QvplIukv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nuBBhYSo, HV_BINOP_DIVIDE, 0, m, &cBinop_nuBBhYSo_sendMessage);
}

void Heavy_simpleWind::cBinop_KavicZaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YiPqNUkR, HV_BINOP_DIVIDE, 0, m, &cBinop_YiPqNUkR_sendMessage);
}

void Heavy_simpleWind::cBinop_MnJFiYAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fZ6n5LMH, HV_BINOP_ADD, 1, m, &cBinop_fZ6n5LMH_sendMessage);
}

void Heavy_simpleWind::cBinop_ZrMYD9Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aqU6lklK_sendMessage);
}

void Heavy_simpleWind::cBinop_aqU6lklK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SNl7n2og, 5, m);
}

void Heavy_simpleWind::cBinop_7KkS7int_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hwQ22vSq, HV_BINOP_MULTIPLY, 1, m, &cBinop_hwQ22vSq_sendMessage);
}

void Heavy_simpleWind::cVar_WM44L5Vk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_SQXWgOR3_sendMessage);
}

void Heavy_simpleWind::cBinop_PvRE7osX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SNl7n2og, 1, m);
}

void Heavy_simpleWind::cBinop_QVm6HiMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vENaF9ci_sendMessage);
}

void Heavy_simpleWind::cSystem_GJdXbLwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YiPqNUkR, HV_BINOP_DIVIDE, 1, m, &cBinop_YiPqNUkR_sendMessage);
}

void Heavy_simpleWind::cMsg_qsp8fJ3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GJdXbLwp_sendMessage);
}

void Heavy_simpleWind::cBinop_rH5kTkdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QVm6HiMY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fZ6n5LMH, HV_BINOP_ADD, 0, m, &cBinop_fZ6n5LMH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_rPvHqTRV_sendMessage);
}

void Heavy_simpleWind::cBinop_YiPqNUkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MnJFiYAX, HV_BINOP_MULTIPLY, 1, m, &cBinop_MnJFiYAX_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_p7LgnoOd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YV4hIEni, HV_BINOP_DIVIDE, 0, m, &cBinop_YV4hIEni_sendMessage);
}

void Heavy_simpleWind::cBinop_vENaF9ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_cqU9VHDD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hwQ22vSq, HV_BINOP_MULTIPLY, 0, m, &cBinop_hwQ22vSq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MnJFiYAX, HV_BINOP_MULTIPLY, 0, m, &cBinop_MnJFiYAX_sendMessage);
}

void Heavy_simpleWind::cUnop_p7LgnoOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7KkS7int_sendMessage);
}

void Heavy_simpleWind::cBinop_cqU9VHDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZrMYD9Wk_sendMessage);
}

void Heavy_simpleWind::cBinop_yXgnLyP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SNl7n2og, 4, m);
}

void Heavy_simpleWind::cBinop_hwQ22vSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yXgnLyP6_sendMessage);
}

void Heavy_simpleWind::cBinop_rPvHqTRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PvRE7osX, HV_BINOP_MULTIPLY, 0, m, &cBinop_PvRE7osX_sendMessage);
}

void Heavy_simpleWind::cBinop_YV4hIEni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rH5kTkdl_sendMessage);
}

void Heavy_simpleWind::cBinop_SQXWgOR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YV4hIEni, HV_BINOP_DIVIDE, 1, m, &cBinop_YV4hIEni_sendMessage);
}

void Heavy_simpleWind::cVar_NHJrrzJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_KavicZaW_sendMessage);
}

void Heavy_simpleWind::cCast_9kwKhY4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NHJrrzJX, 0, m, &cVar_NHJrrzJX_sendMessage);
}

void Heavy_simpleWind::cBinop_fZ6n5LMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PvRE7osX, HV_BINOP_MULTIPLY, 1, m, &cBinop_PvRE7osX_sendMessage);
}

void Heavy_simpleWind::cUnop_tjerdydz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_f1cOvzsJ_sendMessage);
}

void Heavy_simpleWind::cBinop_hsqUZSED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HSDZgDOH, HV_BINOP_MULTIPLY, 1, m, &cBinop_HSDZgDOH_sendMessage);
}

void Heavy_simpleWind::cMsg_36iLMAXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XoyQF5MG_sendMessage);
}

void Heavy_simpleWind::cSystem_XoyQF5MG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EISSvgxs, HV_BINOP_DIVIDE, 1, m, &cBinop_EISSvgxs_sendMessage);
}

void Heavy_simpleWind::cBinop_f1cOvzsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKBusjyv, HV_BINOP_MULTIPLY, 1, m, &cBinop_BKBusjyv_sendMessage);
}

void Heavy_simpleWind::cBinop_6ROEk8KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yVOwK6mg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hsqUZSED, HV_BINOP_ADD, 0, m, &cBinop_hsqUZSED_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yqP0lt6k_sendMessage);
}

void Heavy_simpleWind::cBinop_yqP0lt6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HSDZgDOH, HV_BINOP_MULTIPLY, 0, m, &cBinop_HSDZgDOH_sendMessage);
}

void Heavy_simpleWind::cCast_3d6iVWIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XmHhEsRF, 0, m, &cVar_XmHhEsRF_sendMessage);
}

void Heavy_simpleWind::cBinop_faOBhJeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hcyasJ9m, 4, m);
}

void Heavy_simpleWind::cBinop_1LEJIlTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Bw2GipKX_sendMessage);
}

void Heavy_simpleWind::cBinop_XOa8f9q1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hsqUZSED, HV_BINOP_ADD, 1, m, &cBinop_hsqUZSED_sendMessage);
}

void Heavy_simpleWind::cBinop_zyOD6MwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6ROEk8KH_sendMessage);
}

void Heavy_simpleWind::cVar_rGxV73Sc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_fQYvGIjF_sendMessage);
}

void Heavy_simpleWind::cBinop_hgVc6Xg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EISSvgxs, HV_BINOP_DIVIDE, 0, m, &cBinop_EISSvgxs_sendMessage);
}

void Heavy_simpleWind::cBinop_EISSvgxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XOa8f9q1, HV_BINOP_MULTIPLY, 1, m, &cBinop_XOa8f9q1_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_tjerdydz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zyOD6MwC, HV_BINOP_DIVIDE, 0, m, &cBinop_zyOD6MwC_sendMessage);
}

void Heavy_simpleWind::cBinop_HSDZgDOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hcyasJ9m, 1, m);
}

void Heavy_simpleWind::cBinop_lkaKLdaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_otLHSXUm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKBusjyv, HV_BINOP_MULTIPLY, 0, m, &cBinop_BKBusjyv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XOa8f9q1, HV_BINOP_MULTIPLY, 0, m, &cBinop_XOa8f9q1_sendMessage);
}

void Heavy_simpleWind::cBinop_Bw2GipKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hcyasJ9m, 5, m);
}

void Heavy_simpleWind::cBinop_BKBusjyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_faOBhJeF_sendMessage);
}

void Heavy_simpleWind::cVar_XmHhEsRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_hgVc6Xg8_sendMessage);
}

void Heavy_simpleWind::cBinop_fQYvGIjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zyOD6MwC, HV_BINOP_DIVIDE, 1, m, &cBinop_zyOD6MwC_sendMessage);
}

void Heavy_simpleWind::cBinop_yVOwK6mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lkaKLdaq_sendMessage);
}

void Heavy_simpleWind::cBinop_otLHSXUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1LEJIlTD_sendMessage);
}

void Heavy_simpleWind::cVar_GUjC9kah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XmHhEsRF, 0, m, &cVar_XmHhEsRF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XE6cLVzR, 0, m, &cVar_XE6cLVzR_sendMessage);
}

void Heavy_simpleWind::cVar_AHIbzr54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PFjA3kUE, 0, m, &cVar_PFjA3kUE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sV29vKkJ, 0, m, &cVar_sV29vKkJ_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_simpleWind::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_i(&sVari_awkwSxvB, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_awkwSxvB, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_vf1pzYkf, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_SNl7n2og, VIf(Bf1), VOf(Bf1));
    __hv_varread_i(&sVari_VtfBrZPE, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_varwrite_i(&sVari_VtfBrZPE, VIi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_jI3nRZ3I, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_sXHFfO3Q, VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_i(&sVari_aut8Yt4Y, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_aut8Yt4Y, VIi(Bi1));
    __hv_biquad_k_f(&sBiquad_k_hcyasJ9m, VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_tar7c5jV, VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_simpleWind::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_simpleWind::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
