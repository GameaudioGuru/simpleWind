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
  numBytes += sBiquad_k_init(&sBiquad_k_QfTjmGTD, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_M5yGLtzY, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_QBhdsHkS, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_EmnatVXj, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_VCTUoMqp, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_yaIFDEaX, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cRandom_init(&cRandom_QJIOEjh7, -562639574);
  numBytes += cSlice_init(&cSlice_kwzDyr9P, 1, 1);
  numBytes += sVari_init(&sVari_X3XrhYJB, 0, 0, false);
  numBytes += cBinop_init(&cBinop_8WWRDFQB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SsCx2YUz, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_IjQUsJ7F, 1.0f);
  numBytes += cBinop_init(&cBinop_HSGJ2awk, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xvbP0Hcq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_l2BNJrvr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_APxwyNC6, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_jmvwWAjK, 22050.0f);
  numBytes += cVar_init_f(&cVar_SZXuwwHc, 0.0f);
  numBytes += sVari_init(&sVari_WPjcDK8s, 0, 0, false);
  numBytes += cSlice_init(&cSlice_GXOgMFN1, 1, 1);
  numBytes += cRandom_init(&cRandom_eGJhjett, 2118105573);
  numBytes += cBinop_init(&cBinop_5eg2HhNN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8mynkLXO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_erbIINQW, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_CrUO3laM, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_bfzcLOJ3, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_4Es6Cffl, 1.0f);
  numBytes += cVar_init_f(&cVar_QCiWAB5N, 22050.0f);
  numBytes += cBinop_init(&cBinop_4Do5u31b, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_ZpKE5uGJ, 0.0f);
  numBytes += cVar_init_f(&cVar_otZW4ONo, 1.0f);
  numBytes += cBinop_init(&cBinop_c3jg9tBc, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_pskhyb4t, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_3b75ZkQE, 22050.0f);
  numBytes += cBinop_init(&cBinop_deKDZfDQ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_sSnmckYI, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9dnFzSQi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2Sw8A42q, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ORAFkQh5, 0.0f);
  numBytes += cVar_init_f(&cVar_BSJTOFA4, 22050.0f);
  numBytes += cVar_init_f(&cVar_rgktffkn, 1.0f);
  numBytes += cBinop_init(&cBinop_FBqyDj1Y, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_bNOVM3m0, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dXScyzra, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5URx3jOf, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_kPwHOBha, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LBdrrOlr, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dsISprKT, 0.0f);
  numBytes += cBinop_init(&cBinop_iMo5RKrU, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_qanPo7gp, 22050.0f);
  numBytes += cBinop_init(&cBinop_oXQkG5Ep, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JeeiiZZN, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_OUu7QZsX, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_mLVZcaxL, 1.0f);
  numBytes += cBinop_init(&cBinop_Oa4uejLm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_L27V85YA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6kojDcdL, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_bFUmZawM, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_LkcSI5Y0, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_4uMniPYC, 22050.0f);
  numBytes += cBinop_init(&cBinop_z9QSLveK, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_bZAHfMfM, 1.0f);
  numBytes += cBinop_init(&cBinop_34P3r1qN, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_q4APGVTH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_G808q4tv, 0.0f);
  numBytes += sVari_init(&sVari_L0TnpfOU, 0, 0, false);
  numBytes += cSlice_init(&cSlice_LdgblsnA, 1, 1);
  numBytes += cRandom_init(&cRandom_mvaz0omI, 1613173803);
  numBytes += cVar_init_f(&cVar_H0sYnmzj, 0.0f);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FuDH5hdr_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XOWWXm5P_sendMessage);
      break;
    }
    case 0x539436C5: { // centerFrequency_01
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E6UUQQPN_sendMessage);
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


void Heavy_simpleWind::cReceive_FuDH5hdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H0sYnmzj, 0, m, &cVar_H0sYnmzj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SZXuwwHc, 0, m, &cVar_SZXuwwHc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZpKE5uGJ, 0, m, &cVar_ZpKE5uGJ_sendMessage);
}

void Heavy_simpleWind::cUnop_oNg9Dn2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Eq0zlPQ7_sendMessage(_c, 0, m);
}

void Heavy_simpleWind::cBinop_0Qy4asB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_oNg9Dn2N_sendMessage);
}

void Heavy_simpleWind::cRandom_QJIOEjh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_0Qy4asB5_sendMessage);
}

void Heavy_simpleWind::cSlice_kwzDyr9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QJIOEjh7, 1, m, &cRandom_QJIOEjh7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simpleWind::cSwitchcase_bOFe9aG1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kwzDyr9P, 0, m, &cSlice_kwzDyr9P_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QJIOEjh7, 0, m, &cRandom_QJIOEjh7_sendMessage);
      break;
    }
  }
}

void Heavy_simpleWind::cMsg_Eq0zlPQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_X3XrhYJB, m);
}

void Heavy_simpleWind::cReceive_XOWWXm5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bOFe9aG1_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_LPpsAtFT_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_w2z0KVMP_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_IjQUsJ7F, 0, m, &cVar_IjQUsJ7F_sendMessage);
  cMsg_XcT5C1vY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jmvwWAjK, 0, m, &cVar_jmvwWAjK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bZAHfMfM, 0, m, &cVar_bZAHfMfM_sendMessage);
  cMsg_Day80bgK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4uMniPYC, 0, m, &cVar_4uMniPYC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4Es6Cffl, 0, m, &cVar_4Es6Cffl_sendMessage);
  cMsg_tXsJLOkp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QCiWAB5N, 0, m, &cVar_QCiWAB5N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_otZW4ONo, 0, m, &cVar_otZW4ONo_sendMessage);
  cMsg_iAwK3Wtt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3b75ZkQE, 0, m, &cVar_3b75ZkQE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rgktffkn, 0, m, &cVar_rgktffkn_sendMessage);
  cMsg_SolaOFKF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BSJTOFA4, 0, m, &cVar_BSJTOFA4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mLVZcaxL, 0, m, &cVar_mLVZcaxL_sendMessage);
  cMsg_eemwprx0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qanPo7gp, 0, m, &cVar_qanPo7gp_sendMessage);
}

void Heavy_simpleWind::cBinop_8WWRDFQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsCx2YUz, HV_BINOP_ADD, 1, m, &cBinop_SsCx2YUz_sendMessage);
}

void Heavy_simpleWind::cBinop_pBsXkfc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RB1qXltj_sendMessage);
}

void Heavy_simpleWind::cBinop_SsCx2YUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xvbP0Hcq, HV_BINOP_MULTIPLY, 1, m, &cBinop_xvbP0Hcq_sendMessage);
}

void Heavy_simpleWind::cSystem_i6RP9ebH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l2BNJrvr, HV_BINOP_DIVIDE, 1, m, &cBinop_l2BNJrvr_sendMessage);
}

void Heavy_simpleWind::cMsg_XcT5C1vY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i6RP9ebH_sendMessage);
}

void Heavy_simpleWind::cBinop_y8r263tc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_APxwyNC6, HV_BINOP_DIVIDE, 1, m, &cBinop_APxwyNC6_sendMessage);
}

void Heavy_simpleWind::cBinop_gb6RYexr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_b8EfnzBp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsCx2YUz, HV_BINOP_ADD, 0, m, &cBinop_SsCx2YUz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gCaBOfUL_sendMessage);
}

void Heavy_simpleWind::cBinop_2nfeGnui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l2BNJrvr, HV_BINOP_DIVIDE, 0, m, &cBinop_l2BNJrvr_sendMessage);
}

void Heavy_simpleWind::cBinop_RB1qXltj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_N75YLN96_sendMessage);
}

void Heavy_simpleWind::cCast_GAHE7Mue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jmvwWAjK, 0, m, &cVar_jmvwWAjK_sendMessage);
}

void Heavy_simpleWind::cVar_IjQUsJ7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_y8r263tc_sendMessage);
}

void Heavy_simpleWind::cBinop_HSGJ2awk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_q1vbRRCI_sendMessage);
}

void Heavy_simpleWind::cBinop_WYAJq78k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HSGJ2awk, HV_BINOP_MULTIPLY, 1, m, &cBinop_HSGJ2awk_sendMessage);
}

void Heavy_simpleWind::cBinop_xvbP0Hcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QfTjmGTD, 1, m);
}

void Heavy_simpleWind::cBinop_l2BNJrvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8WWRDFQB, HV_BINOP_MULTIPLY, 1, m, &cBinop_8WWRDFQB_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_hxFW8Hol_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_APxwyNC6, HV_BINOP_DIVIDE, 0, m, &cBinop_APxwyNC6_sendMessage);
}

void Heavy_simpleWind::cBinop_b8EfnzBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_kRxqqAVc_sendMessage);
}

void Heavy_simpleWind::cBinop_APxwyNC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gb6RYexr_sendMessage);
}

void Heavy_simpleWind::cUnop_hxFW8Hol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_WYAJq78k_sendMessage);
}

void Heavy_simpleWind::cBinop_q1vbRRCI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QfTjmGTD, 4, m);
}

void Heavy_simpleWind::cBinop_N75YLN96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QfTjmGTD, 5, m);
}

void Heavy_simpleWind::cBinop_kRxqqAVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_pBsXkfc5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HSGJ2awk, HV_BINOP_MULTIPLY, 0, m, &cBinop_HSGJ2awk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8WWRDFQB, HV_BINOP_MULTIPLY, 0, m, &cBinop_8WWRDFQB_sendMessage);
}

void Heavy_simpleWind::cBinop_gCaBOfUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xvbP0Hcq, HV_BINOP_MULTIPLY, 0, m, &cBinop_xvbP0Hcq_sendMessage);
}

void Heavy_simpleWind::cVar_jmvwWAjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_2nfeGnui_sendMessage);
}

void Heavy_simpleWind::cVar_SZXuwwHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bZAHfMfM, 0, m, &cVar_bZAHfMfM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cX5g8TfP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rgktffkn, 0, m, &cVar_rgktffkn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cUw4eJvk_sendMessage);
}

void Heavy_simpleWind::cMsg_qcKDGBBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_WPjcDK8s, m);
}

void Heavy_simpleWind::cSwitchcase_w2z0KVMP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GXOgMFN1, 0, m, &cSlice_GXOgMFN1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eGJhjett, 0, m, &cRandom_eGJhjett_sendMessage);
      break;
    }
  }
}

void Heavy_simpleWind::cSlice_GXOgMFN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eGJhjett, 1, m, &cRandom_eGJhjett_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simpleWind::cBinop_JYVzK0Bo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sdIo3TdH_sendMessage);
}

void Heavy_simpleWind::cUnop_sdIo3TdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qcKDGBBm_sendMessage(_c, 0, m);
}

void Heavy_simpleWind::cRandom_eGJhjett_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_JYVzK0Bo_sendMessage);
}

void Heavy_simpleWind::cReceive_E6UUQQPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dsISprKT, 0, m, &cVar_dsISprKT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G808q4tv, 0, m, &cVar_G808q4tv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ORAFkQh5, 0, m, &cVar_ORAFkQh5_sendMessage);
}

void Heavy_simpleWind::cBinop_DgWUCTVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CrUO3laM, HV_BINOP_DIVIDE, 1, m, &cBinop_CrUO3laM_sendMessage);
}

void Heavy_simpleWind::cBinop_aWHhVfUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VCTUoMqp, 4, m);
}

void Heavy_simpleWind::cBinop_LNy8ZzXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VCTUoMqp, 5, m);
}

void Heavy_simpleWind::cBinop_5eg2HhNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bfzcLOJ3, HV_BINOP_ADD, 1, m, &cBinop_bfzcLOJ3_sendMessage);
}

void Heavy_simpleWind::cBinop_ymIreWNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mynkLXO, HV_BINOP_MULTIPLY, 1, m, &cBinop_8mynkLXO_sendMessage);
}

void Heavy_simpleWind::cCast_9zr5y7Mo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QCiWAB5N, 0, m, &cVar_QCiWAB5N_sendMessage);
}

void Heavy_simpleWind::cBinop_m7A85gM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Do5u31b, HV_BINOP_DIVIDE, 0, m, &cBinop_4Do5u31b_sendMessage);
}

void Heavy_simpleWind::cUnop_ZCOJjA2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ymIreWNU_sendMessage);
}

void Heavy_simpleWind::cBinop_8mynkLXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aWHhVfUU_sendMessage);
}

void Heavy_simpleWind::cBinop_gKB76ajn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_erbIINQW, HV_BINOP_MULTIPLY, 0, m, &cBinop_erbIINQW_sendMessage);
}

void Heavy_simpleWind::cBinop_ttyx5TjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WoDK3jEM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bfzcLOJ3, HV_BINOP_ADD, 0, m, &cBinop_bfzcLOJ3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gKB76ajn_sendMessage);
}

void Heavy_simpleWind::cSystem_B9B6hYtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Do5u31b, HV_BINOP_DIVIDE, 1, m, &cBinop_4Do5u31b_sendMessage);
}

void Heavy_simpleWind::cMsg_tXsJLOkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B9B6hYtc_sendMessage);
}

void Heavy_simpleWind::cBinop_yJXVIkGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LNy8ZzXx_sendMessage);
}

void Heavy_simpleWind::cBinop_erbIINQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VCTUoMqp, 1, m);
}

void Heavy_simpleWind::cBinop_CrUO3laM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ttyx5TjT_sendMessage);
}

void Heavy_simpleWind::cBinop_WoDK3jEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yt0caYBU_sendMessage);
}

void Heavy_simpleWind::cBinop_bfzcLOJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_erbIINQW, HV_BINOP_MULTIPLY, 1, m, &cBinop_erbIINQW_sendMessage);
}

void Heavy_simpleWind::cVar_4Es6Cffl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_DgWUCTVG_sendMessage);
}

void Heavy_simpleWind::cBinop_yt0caYBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_OyezJPFr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mynkLXO, HV_BINOP_MULTIPLY, 0, m, &cBinop_8mynkLXO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5eg2HhNN, HV_BINOP_MULTIPLY, 0, m, &cBinop_5eg2HhNN_sendMessage);
}

void Heavy_simpleWind::cVar_QCiWAB5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_m7A85gM9_sendMessage);
}

void Heavy_simpleWind::cBinop_4Do5u31b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5eg2HhNN, HV_BINOP_MULTIPLY, 1, m, &cBinop_5eg2HhNN_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_ZCOJjA2a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CrUO3laM, HV_BINOP_DIVIDE, 0, m, &cBinop_CrUO3laM_sendMessage);
}

void Heavy_simpleWind::cBinop_OyezJPFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yJXVIkGM_sendMessage);
}

void Heavy_simpleWind::cVar_ZpKE5uGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4Es6Cffl, 0, m, &cVar_4Es6Cffl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9zr5y7Mo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mLVZcaxL, 0, m, &cVar_mLVZcaxL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uriKMdkw_sendMessage);
}

void Heavy_simpleWind::cVar_otZW4ONo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_xnwOjg6W_sendMessage);
}

void Heavy_simpleWind::cBinop_c3jg9tBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tZZtuQwg_sendMessage);
}

void Heavy_simpleWind::cBinop_ofWrOto9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_nlORhbIm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Sw8A42q, HV_BINOP_MULTIPLY, 0, m, &cBinop_2Sw8A42q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sSnmckYI, HV_BINOP_MULTIPLY, 0, m, &cBinop_sSnmckYI_sendMessage);
}

void Heavy_simpleWind::cBinop_DZN5BtRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4SLjugnN_sendMessage);
}

void Heavy_simpleWind::cBinop_SlCo1VhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_M5yGLtzY, 4, m);
}

void Heavy_simpleWind::cBinop_Ux2w9fXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pskhyb4t, HV_BINOP_DIVIDE, 0, m, &cBinop_pskhyb4t_sendMessage);
}

void Heavy_simpleWind::cUnop_h3WgOeFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_e6hP2vkA_sendMessage);
}

void Heavy_simpleWind::cBinop_pskhyb4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sSnmckYI, HV_BINOP_MULTIPLY, 1, m, &cBinop_sSnmckYI_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_h3WgOeFv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_c3jg9tBc, HV_BINOP_DIVIDE, 0, m, &cBinop_c3jg9tBc_sendMessage);
}

void Heavy_simpleWind::cVar_3b75ZkQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Ux2w9fXr_sendMessage);
}

void Heavy_simpleWind::cBinop_tZZtuQwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3AtD5WRZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_deKDZfDQ, HV_BINOP_ADD, 0, m, &cBinop_deKDZfDQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_KyXMIKBL_sendMessage);
}

void Heavy_simpleWind::cBinop_4SLjugnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_M5yGLtzY, 5, m);
}

void Heavy_simpleWind::cBinop_nlORhbIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DZN5BtRh_sendMessage);
}

void Heavy_simpleWind::cBinop_xnwOjg6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c3jg9tBc, HV_BINOP_DIVIDE, 1, m, &cBinop_c3jg9tBc_sendMessage);
}

void Heavy_simpleWind::cBinop_deKDZfDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9dnFzSQi, HV_BINOP_MULTIPLY, 1, m, &cBinop_9dnFzSQi_sendMessage);
}

void Heavy_simpleWind::cBinop_sSnmckYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_deKDZfDQ, HV_BINOP_ADD, 1, m, &cBinop_deKDZfDQ_sendMessage);
}

void Heavy_simpleWind::cBinop_9dnFzSQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_M5yGLtzY, 1, m);
}

void Heavy_simpleWind::cCast_iVG06sOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3b75ZkQE, 0, m, &cVar_3b75ZkQE_sendMessage);
}

void Heavy_simpleWind::cBinop_e6hP2vkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Sw8A42q, HV_BINOP_MULTIPLY, 1, m, &cBinop_2Sw8A42q_sendMessage);
}

void Heavy_simpleWind::cBinop_3AtD5WRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ofWrOto9_sendMessage);
}

void Heavy_simpleWind::cSystem_2nG9ChzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pskhyb4t, HV_BINOP_DIVIDE, 1, m, &cBinop_pskhyb4t_sendMessage);
}

void Heavy_simpleWind::cMsg_iAwK3Wtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2nG9ChzW_sendMessage);
}

void Heavy_simpleWind::cBinop_2Sw8A42q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SlCo1VhS_sendMessage);
}

void Heavy_simpleWind::cBinop_KyXMIKBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9dnFzSQi, HV_BINOP_MULTIPLY, 0, m, &cBinop_9dnFzSQi_sendMessage);
}

void Heavy_simpleWind::cVar_ORAFkQh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QCiWAB5N, 0, m, &cVar_QCiWAB5N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qanPo7gp, 0, m, &cVar_qanPo7gp_sendMessage);
}

void Heavy_simpleWind::cBinop_9g374jGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EmnatVXj, 5, m);
}

void Heavy_simpleWind::cBinop_7d9ZozRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kPwHOBha, HV_BINOP_MULTIPLY, 0, m, &cBinop_kPwHOBha_sendMessage);
}

void Heavy_simpleWind::cBinop_N3FaicVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EmnatVXj, 4, m);
}

void Heavy_simpleWind::cBinop_gh3wvj9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FBqyDj1Y, HV_BINOP_DIVIDE, 0, m, &cBinop_FBqyDj1Y_sendMessage);
}

void Heavy_simpleWind::cVar_BSJTOFA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_gh3wvj9J_sendMessage);
}

void Heavy_simpleWind::cBinop_q3U1m60j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iZ4mkpGa_sendMessage);
}

void Heavy_simpleWind::cVar_rgktffkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_UzZNRyuG_sendMessage);
}

void Heavy_simpleWind::cBinop_6BtPQonk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ielrURUx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNOVM3m0, HV_BINOP_ADD, 0, m, &cBinop_bNOVM3m0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7d9ZozRp_sendMessage);
}

void Heavy_simpleWind::cBinop_FBqyDj1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LBdrrOlr, HV_BINOP_MULTIPLY, 1, m, &cBinop_LBdrrOlr_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_mPdhMqa4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5URx3jOf, HV_BINOP_DIVIDE, 0, m, &cBinop_5URx3jOf_sendMessage);
}

void Heavy_simpleWind::cUnop_mPdhMqa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_4b0kFviA_sendMessage);
}

void Heavy_simpleWind::cBinop_bNOVM3m0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kPwHOBha, HV_BINOP_MULTIPLY, 1, m, &cBinop_kPwHOBha_sendMessage);
}

void Heavy_simpleWind::cBinop_4b0kFviA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dXScyzra, HV_BINOP_MULTIPLY, 1, m, &cBinop_dXScyzra_sendMessage);
}

void Heavy_simpleWind::cBinop_ielrURUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rCAG7sAe_sendMessage);
}

void Heavy_simpleWind::cBinop_dXScyzra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_N3FaicVy_sendMessage);
}

void Heavy_simpleWind::cBinop_UzZNRyuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5URx3jOf, HV_BINOP_DIVIDE, 1, m, &cBinop_5URx3jOf_sendMessage);
}

void Heavy_simpleWind::cCast_cUw4eJvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BSJTOFA4, 0, m, &cVar_BSJTOFA4_sendMessage);
}

void Heavy_simpleWind::cBinop_5URx3jOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6BtPQonk_sendMessage);
}

void Heavy_simpleWind::cBinop_rCAG7sAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_q3U1m60j_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dXScyzra, HV_BINOP_MULTIPLY, 0, m, &cBinop_dXScyzra_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LBdrrOlr, HV_BINOP_MULTIPLY, 0, m, &cBinop_LBdrrOlr_sendMessage);
}

void Heavy_simpleWind::cMsg_SolaOFKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iKAWNITO_sendMessage);
}

void Heavy_simpleWind::cSystem_iKAWNITO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FBqyDj1Y, HV_BINOP_DIVIDE, 1, m, &cBinop_FBqyDj1Y_sendMessage);
}

void Heavy_simpleWind::cBinop_iZ4mkpGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9g374jGJ_sendMessage);
}

void Heavy_simpleWind::cBinop_kPwHOBha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EmnatVXj, 1, m);
}

void Heavy_simpleWind::cBinop_LBdrrOlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNOVM3m0, HV_BINOP_ADD, 1, m, &cBinop_bNOVM3m0_sendMessage);
}

void Heavy_simpleWind::cVar_dsISprKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jmvwWAjK, 0, m, &cVar_jmvwWAjK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3b75ZkQE, 0, m, &cVar_3b75ZkQE_sendMessage);
}

void Heavy_simpleWind::cBinop_iMo5RKrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Vo7Lf39Y_sendMessage);
}

void Heavy_simpleWind::cVar_qanPo7gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_bfKqdeBx_sendMessage);
}

void Heavy_simpleWind::cBinop_oXQkG5Ep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oa4uejLm, HV_BINOP_ADD, 1, m, &cBinop_Oa4uejLm_sendMessage);
}

void Heavy_simpleWind::cBinop_TzYOBufw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_yaIFDEaX, 4, m);
}

void Heavy_simpleWind::cBinop_sfRBXbgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L27V85YA, HV_BINOP_MULTIPLY, 0, m, &cBinop_L27V85YA_sendMessage);
}

void Heavy_simpleWind::cBinop_JeeiiZZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oXQkG5Ep, HV_BINOP_MULTIPLY, 1, m, &cBinop_oXQkG5Ep_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Apxfvzyk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMo5RKrU, HV_BINOP_DIVIDE, 0, m, &cBinop_iMo5RKrU_sendMessage);
}

void Heavy_simpleWind::cBinop_OUu7QZsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TzYOBufw_sendMessage);
}

void Heavy_simpleWind::cBinop_M6SjqtQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMo5RKrU, HV_BINOP_DIVIDE, 1, m, &cBinop_iMo5RKrU_sendMessage);
}

void Heavy_simpleWind::cBinop_BQD9OJbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NnYjaOTy_sendMessage);
}

void Heavy_simpleWind::cCast_uriKMdkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qanPo7gp, 0, m, &cVar_qanPo7gp_sendMessage);
}

void Heavy_simpleWind::cBinop_cInahsy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_tF7zJm9D_sendMessage);
}

void Heavy_simpleWind::cVar_mLVZcaxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_M6SjqtQO_sendMessage);
}

void Heavy_simpleWind::cBinop_Oa4uejLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L27V85YA, HV_BINOP_MULTIPLY, 1, m, &cBinop_L27V85YA_sendMessage);
}

void Heavy_simpleWind::cBinop_tF7zJm9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_Q46Cv7z5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OUu7QZsX, HV_BINOP_MULTIPLY, 0, m, &cBinop_OUu7QZsX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oXQkG5Ep, HV_BINOP_MULTIPLY, 0, m, &cBinop_oXQkG5Ep_sendMessage);
}

void Heavy_simpleWind::cSystem_WnOIuxLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeeiiZZN, HV_BINOP_DIVIDE, 1, m, &cBinop_JeeiiZZN_sendMessage);
}

void Heavy_simpleWind::cMsg_eemwprx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WnOIuxLr_sendMessage);
}

void Heavy_simpleWind::cBinop_Vo7Lf39Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cInahsy6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oa4uejLm, HV_BINOP_ADD, 0, m, &cBinop_Oa4uejLm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_sfRBXbgg_sendMessage);
}

void Heavy_simpleWind::cBinop_Q46Cv7z5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BQD9OJbo_sendMessage);
}

void Heavy_simpleWind::cBinop_VJCeCGfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OUu7QZsX, HV_BINOP_MULTIPLY, 1, m, &cBinop_OUu7QZsX_sendMessage);
}

void Heavy_simpleWind::cUnop_Apxfvzyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_VJCeCGfl_sendMessage);
}

void Heavy_simpleWind::cBinop_bfKqdeBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeeiiZZN, HV_BINOP_DIVIDE, 0, m, &cBinop_JeeiiZZN_sendMessage);
}

void Heavy_simpleWind::cBinop_L27V85YA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_yaIFDEaX, 1, m);
}

void Heavy_simpleWind::cBinop_NnYjaOTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_yaIFDEaX, 5, m);
}

void Heavy_simpleWind::cBinop_xN9YLQLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z9QSLveK, HV_BINOP_MULTIPLY, 1, m, &cBinop_z9QSLveK_sendMessage);
}

void Heavy_simpleWind::cBinop_6kojDcdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LkcSI5Y0, HV_BINOP_MULTIPLY, 1, m, &cBinop_LkcSI5Y0_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_9zQzOtf2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_34P3r1qN, HV_BINOP_DIVIDE, 0, m, &cBinop_34P3r1qN_sendMessage);
}

void Heavy_simpleWind::cBinop_9dG06kSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YbXvCzB4_sendMessage);
}

void Heavy_simpleWind::cBinop_bFUmZawM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q4APGVTH, HV_BINOP_MULTIPLY, 1, m, &cBinop_q4APGVTH_sendMessage);
}

void Heavy_simpleWind::cBinop_LkcSI5Y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bFUmZawM, HV_BINOP_ADD, 1, m, &cBinop_bFUmZawM_sendMessage);
}

void Heavy_simpleWind::cUnop_9zQzOtf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_xN9YLQLy_sendMessage);
}

void Heavy_simpleWind::cBinop_YbXvCzB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_xvMZmyjZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_z9QSLveK, HV_BINOP_MULTIPLY, 0, m, &cBinop_z9QSLveK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LkcSI5Y0, HV_BINOP_MULTIPLY, 0, m, &cBinop_LkcSI5Y0_sendMessage);
}

void Heavy_simpleWind::cBinop_xvMZmyjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rk3R6BTf_sendMessage);
}

void Heavy_simpleWind::cVar_4uMniPYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_FKtkr1Mk_sendMessage);
}

void Heavy_simpleWind::cBinop_z9QSLveK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kHlTqYLu_sendMessage);
}

void Heavy_simpleWind::cBinop_rk3R6BTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_O0sabPd7_sendMessage);
}

void Heavy_simpleWind::cBinop_O0sabPd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QBhdsHkS, 5, m);
}

void Heavy_simpleWind::cVar_bZAHfMfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_5jF8eiHs_sendMessage);
}

void Heavy_simpleWind::cSystem_di4lQ7AH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6kojDcdL, HV_BINOP_DIVIDE, 1, m, &cBinop_6kojDcdL_sendMessage);
}

void Heavy_simpleWind::cMsg_Day80bgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_di4lQ7AH_sendMessage);
}

void Heavy_simpleWind::cBinop_LCrFtw5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9dG06kSD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bFUmZawM, HV_BINOP_ADD, 0, m, &cBinop_bFUmZawM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Iany5wqW_sendMessage);
}

void Heavy_simpleWind::cBinop_34P3r1qN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LCrFtw5H_sendMessage);
}

void Heavy_simpleWind::cBinop_5jF8eiHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_34P3r1qN, HV_BINOP_DIVIDE, 1, m, &cBinop_34P3r1qN_sendMessage);
}

void Heavy_simpleWind::cBinop_kHlTqYLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QBhdsHkS, 4, m);
}

void Heavy_simpleWind::cBinop_FKtkr1Mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6kojDcdL, HV_BINOP_DIVIDE, 0, m, &cBinop_6kojDcdL_sendMessage);
}

void Heavy_simpleWind::cCast_cX5g8TfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4uMniPYC, 0, m, &cVar_4uMniPYC_sendMessage);
}

void Heavy_simpleWind::cBinop_q4APGVTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QBhdsHkS, 1, m);
}

void Heavy_simpleWind::cBinop_Iany5wqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q4APGVTH, HV_BINOP_MULTIPLY, 0, m, &cBinop_q4APGVTH_sendMessage);
}

void Heavy_simpleWind::cVar_G808q4tv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4uMniPYC, 0, m, &cVar_4uMniPYC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BSJTOFA4, 0, m, &cVar_BSJTOFA4_sendMessage);
}

void Heavy_simpleWind::cSlice_LdgblsnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mvaz0omI, 1, m, &cRandom_mvaz0omI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simpleWind::cRandom_mvaz0omI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_djX30oKt_sendMessage);
}

void Heavy_simpleWind::cBinop_djX30oKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_JEyhNoOf_sendMessage);
}

void Heavy_simpleWind::cSwitchcase_LPpsAtFT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LdgblsnA, 0, m, &cSlice_LdgblsnA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mvaz0omI, 0, m, &cRandom_mvaz0omI_sendMessage);
      break;
    }
  }
}

void Heavy_simpleWind::cUnop_JEyhNoOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1EN69e0d_sendMessage(_c, 0, m);
}

void Heavy_simpleWind::cMsg_1EN69e0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_L0TnpfOU, m);
}

void Heavy_simpleWind::cVar_H0sYnmzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IjQUsJ7F, 0, m, &cVar_IjQUsJ7F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GAHE7Mue_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_otZW4ONo, 0, m, &cVar_otZW4ONo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iVG06sOv_sendMessage);
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
    __hv_varread_i(&sVari_X3XrhYJB, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_X3XrhYJB, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_QfTjmGTD, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_M5yGLtzY, VIf(Bf1), VOf(Bf1));
    __hv_varread_i(&sVari_L0TnpfOU, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_varwrite_i(&sVari_L0TnpfOU, VIi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_QBhdsHkS, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_EmnatVXj, VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_i(&sVari_WPjcDK8s, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_WPjcDK8s, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_VCTUoMqp, VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_yaIFDEaX, VIf(Bf0), VOf(Bf0));
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
