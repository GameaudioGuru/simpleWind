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

#ifndef _HEAVY_CONTEXT_SIMPLEWIND_HPP_
#define _HEAVY_CONTEXT_SIMPLEWIND_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalBiquad.h"
#include "HvMath.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"

class Heavy_simpleWind : public HeavyContext {

 public:
  Heavy_simpleWind(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_simpleWind();

  const char *getName() override { return "simpleWind"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        Q = 0xF3BA5CD4, // Q
        CENTERFREQUENCY_01 = 0x539436C5, // centerFrequency_01
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cReceive_FuDH5hdr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_oNg9Dn2N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0Qy4asB5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_QJIOEjh7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_kwzDyr9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bOFe9aG1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_Eq0zlPQ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_XOWWXm5P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8WWRDFQB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pBsXkfc5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SsCx2YUz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_i6RP9ebH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XcT5C1vY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y8r263tc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gb6RYexr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2nfeGnui_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RB1qXltj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GAHE7Mue_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IjQUsJ7F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HSGJ2awk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WYAJq78k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xvbP0Hcq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l2BNJrvr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b8EfnzBp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_APxwyNC6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_hxFW8Hol_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q1vbRRCI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N75YLN96_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kRxqqAVc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gCaBOfUL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jmvwWAjK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SZXuwwHc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qcKDGBBm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_w2z0KVMP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_GXOgMFN1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JYVzK0Bo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_sdIo3TdH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_eGJhjett_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_E6UUQQPN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DgWUCTVG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aWHhVfUU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LNy8ZzXx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5eg2HhNN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ymIreWNU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9zr5y7Mo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m7A85gM9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ZCOJjA2a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8mynkLXO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gKB76ajn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ttyx5TjT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_B9B6hYtc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tXsJLOkp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yJXVIkGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_erbIINQW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CrUO3laM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WoDK3jEM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bfzcLOJ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4Es6Cffl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yt0caYBU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QCiWAB5N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4Do5u31b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OyezJPFr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZpKE5uGJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_otZW4ONo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_c3jg9tBc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ofWrOto9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DZN5BtRh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SlCo1VhS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ux2w9fXr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_h3WgOeFv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pskhyb4t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3b75ZkQE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tZZtuQwg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4SLjugnN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nlORhbIm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xnwOjg6W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_deKDZfDQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sSnmckYI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9dnFzSQi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iVG06sOv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e6hP2vkA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3AtD5WRZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2nG9ChzW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iAwK3Wtt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2Sw8A42q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KyXMIKBL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ORAFkQh5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9g374jGJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7d9ZozRp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N3FaicVy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gh3wvj9J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BSJTOFA4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q3U1m60j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rgktffkn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6BtPQonk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FBqyDj1Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_mPdhMqa4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bNOVM3m0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4b0kFviA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ielrURUx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dXScyzra_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UzZNRyuG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cUw4eJvk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5URx3jOf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rCAG7sAe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SolaOFKF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_iKAWNITO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iZ4mkpGa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kPwHOBha_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LBdrrOlr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dsISprKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iMo5RKrU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qanPo7gp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oXQkG5Ep_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TzYOBufw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sfRBXbgg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JeeiiZZN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OUu7QZsX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M6SjqtQO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BQD9OJbo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uriKMdkw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cInahsy6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mLVZcaxL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Oa4uejLm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tF7zJm9D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WnOIuxLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eemwprx0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vo7Lf39Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q46Cv7z5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VJCeCGfl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Apxfvzyk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bfKqdeBx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L27V85YA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NnYjaOTy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xN9YLQLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6kojDcdL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9dG06kSD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bFUmZawM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LkcSI5Y0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_9zQzOtf2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YbXvCzB4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xvMZmyjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4uMniPYC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z9QSLveK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rk3R6BTf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O0sabPd7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bZAHfMfM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_di4lQ7AH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Day80bgK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LCrFtw5H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_34P3r1qN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5jF8eiHs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kHlTqYLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FKtkr1Mk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cX5g8TfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q4APGVTH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Iany5wqW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_G808q4tv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LdgblsnA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_mvaz0omI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_djX30oKt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_LPpsAtFT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_JEyhNoOf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1EN69e0d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H0sYnmzj_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_QfTjmGTD;
  SignalBiquad_k sBiquad_k_M5yGLtzY;
  SignalBiquad_k sBiquad_k_QBhdsHkS;
  SignalBiquad_k sBiquad_k_EmnatVXj;
  SignalBiquad_k sBiquad_k_VCTUoMqp;
  SignalBiquad_k sBiquad_k_yaIFDEaX;
  ControlBinop cBinop_0Qy4asB5;
  ControlRandom cRandom_QJIOEjh7;
  ControlSlice cSlice_kwzDyr9P;
  SignalVari sVari_X3XrhYJB;
  ControlBinop cBinop_8WWRDFQB;
  ControlBinop cBinop_pBsXkfc5;
  ControlBinop cBinop_SsCx2YUz;
  ControlBinop cBinop_y8r263tc;
  ControlBinop cBinop_gb6RYexr;
  ControlBinop cBinop_2nfeGnui;
  ControlBinop cBinop_RB1qXltj;
  ControlVar cVar_IjQUsJ7F;
  ControlBinop cBinop_HSGJ2awk;
  ControlBinop cBinop_WYAJq78k;
  ControlBinop cBinop_xvbP0Hcq;
  ControlBinop cBinop_l2BNJrvr;
  ControlBinop cBinop_b8EfnzBp;
  ControlBinop cBinop_APxwyNC6;
  ControlBinop cBinop_q1vbRRCI;
  ControlBinop cBinop_N75YLN96;
  ControlBinop cBinop_kRxqqAVc;
  ControlBinop cBinop_gCaBOfUL;
  ControlVar cVar_jmvwWAjK;
  ControlVar cVar_SZXuwwHc;
  SignalVari sVari_WPjcDK8s;
  ControlSlice cSlice_GXOgMFN1;
  ControlBinop cBinop_JYVzK0Bo;
  ControlRandom cRandom_eGJhjett;
  ControlBinop cBinop_DgWUCTVG;
  ControlBinop cBinop_aWHhVfUU;
  ControlBinop cBinop_LNy8ZzXx;
  ControlBinop cBinop_5eg2HhNN;
  ControlBinop cBinop_ymIreWNU;
  ControlBinop cBinop_m7A85gM9;
  ControlBinop cBinop_8mynkLXO;
  ControlBinop cBinop_gKB76ajn;
  ControlBinop cBinop_ttyx5TjT;
  ControlBinop cBinop_yJXVIkGM;
  ControlBinop cBinop_erbIINQW;
  ControlBinop cBinop_CrUO3laM;
  ControlBinop cBinop_WoDK3jEM;
  ControlBinop cBinop_bfzcLOJ3;
  ControlVar cVar_4Es6Cffl;
  ControlBinop cBinop_yt0caYBU;
  ControlVar cVar_QCiWAB5N;
  ControlBinop cBinop_4Do5u31b;
  ControlBinop cBinop_OyezJPFr;
  ControlVar cVar_ZpKE5uGJ;
  ControlVar cVar_otZW4ONo;
  ControlBinop cBinop_c3jg9tBc;
  ControlBinop cBinop_ofWrOto9;
  ControlBinop cBinop_DZN5BtRh;
  ControlBinop cBinop_SlCo1VhS;
  ControlBinop cBinop_Ux2w9fXr;
  ControlBinop cBinop_pskhyb4t;
  ControlVar cVar_3b75ZkQE;
  ControlBinop cBinop_tZZtuQwg;
  ControlBinop cBinop_4SLjugnN;
  ControlBinop cBinop_nlORhbIm;
  ControlBinop cBinop_xnwOjg6W;
  ControlBinop cBinop_deKDZfDQ;
  ControlBinop cBinop_sSnmckYI;
  ControlBinop cBinop_9dnFzSQi;
  ControlBinop cBinop_e6hP2vkA;
  ControlBinop cBinop_3AtD5WRZ;
  ControlBinop cBinop_2Sw8A42q;
  ControlBinop cBinop_KyXMIKBL;
  ControlVar cVar_ORAFkQh5;
  ControlBinop cBinop_9g374jGJ;
  ControlBinop cBinop_7d9ZozRp;
  ControlBinop cBinop_N3FaicVy;
  ControlBinop cBinop_gh3wvj9J;
  ControlVar cVar_BSJTOFA4;
  ControlBinop cBinop_q3U1m60j;
  ControlVar cVar_rgktffkn;
  ControlBinop cBinop_6BtPQonk;
  ControlBinop cBinop_FBqyDj1Y;
  ControlBinop cBinop_bNOVM3m0;
  ControlBinop cBinop_4b0kFviA;
  ControlBinop cBinop_ielrURUx;
  ControlBinop cBinop_dXScyzra;
  ControlBinop cBinop_UzZNRyuG;
  ControlBinop cBinop_5URx3jOf;
  ControlBinop cBinop_rCAG7sAe;
  ControlBinop cBinop_iZ4mkpGa;
  ControlBinop cBinop_kPwHOBha;
  ControlBinop cBinop_LBdrrOlr;
  ControlVar cVar_dsISprKT;
  ControlBinop cBinop_iMo5RKrU;
  ControlVar cVar_qanPo7gp;
  ControlBinop cBinop_oXQkG5Ep;
  ControlBinop cBinop_TzYOBufw;
  ControlBinop cBinop_sfRBXbgg;
  ControlBinop cBinop_JeeiiZZN;
  ControlBinop cBinop_OUu7QZsX;
  ControlBinop cBinop_M6SjqtQO;
  ControlBinop cBinop_BQD9OJbo;
  ControlBinop cBinop_cInahsy6;
  ControlVar cVar_mLVZcaxL;
  ControlBinop cBinop_Oa4uejLm;
  ControlBinop cBinop_tF7zJm9D;
  ControlBinop cBinop_Vo7Lf39Y;
  ControlBinop cBinop_Q46Cv7z5;
  ControlBinop cBinop_VJCeCGfl;
  ControlBinop cBinop_bfKqdeBx;
  ControlBinop cBinop_L27V85YA;
  ControlBinop cBinop_NnYjaOTy;
  ControlBinop cBinop_xN9YLQLy;
  ControlBinop cBinop_6kojDcdL;
  ControlBinop cBinop_9dG06kSD;
  ControlBinop cBinop_bFUmZawM;
  ControlBinop cBinop_LkcSI5Y0;
  ControlBinop cBinop_YbXvCzB4;
  ControlBinop cBinop_xvMZmyjZ;
  ControlVar cVar_4uMniPYC;
  ControlBinop cBinop_z9QSLveK;
  ControlBinop cBinop_rk3R6BTf;
  ControlBinop cBinop_O0sabPd7;
  ControlVar cVar_bZAHfMfM;
  ControlBinop cBinop_LCrFtw5H;
  ControlBinop cBinop_34P3r1qN;
  ControlBinop cBinop_5jF8eiHs;
  ControlBinop cBinop_kHlTqYLu;
  ControlBinop cBinop_FKtkr1Mk;
  ControlBinop cBinop_q4APGVTH;
  ControlBinop cBinop_Iany5wqW;
  ControlVar cVar_G808q4tv;
  SignalVari sVari_L0TnpfOU;
  ControlSlice cSlice_LdgblsnA;
  ControlRandom cRandom_mvaz0omI;
  ControlBinop cBinop_djX30oKt;
  ControlVar cVar_H0sYnmzj;
};

#endif // _HEAVY_CONTEXT_SIMPLEWIND_HPP_
