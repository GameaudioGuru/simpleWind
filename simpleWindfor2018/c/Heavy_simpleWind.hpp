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
  static void cUnop_64WB82kK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Np2A0Hma_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MLl5jsqt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MKJjn0Sx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_1oarSilj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_34zJbigM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_bnsRVnsp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_16KBbHuy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_hDGCqg3z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BX2BM73a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_X3fUcOw4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rM26PKT8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TyPLDmk3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ym65bbOa_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_dHjPAE2h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_khAFsJvr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_zj7mX5Zl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uKqsmIC7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mrqNjPCT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iwdWSRnX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ltK4iqoa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_duj9Vzsa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sV29vKkJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YgJ9XK9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B8xxMvcW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PZqNkw5L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aqPsZuvz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XID8sJpX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8veCtKn3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GHgiPdmQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bKtq7nSs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QDP4a1fs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xawwm4se_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SunTPbc3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hwFdDnOR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5sgegJNE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_oGrt12K5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GWKn0ZtA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4UTMJI96_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DALXMOTs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5sUnBs4A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1gij5Yvz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RKuXHjLd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OH7InqxW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7H4n2H8V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dkJfqr6y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OQc4Eh31_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PN6P17Jp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3lyQUVNV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_asjgeXP8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Gsokg6Wm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MId9blJb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Hn7QnS1j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BVwUKxZs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RVgL7XKy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MAzG1OpX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UgMUMfMq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DBzrryKD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pmAvZCLv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HyJtdoqi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cX4wdgmP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jj3x8zHW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r2qEYE1k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XE6cLVzR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zxhx5cMP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WfaAKmnL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2EnZ9wzD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UZ7DgDsX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KIu4tBtN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9UaI8X94_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GeTZbG9G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_91Q3Vlm5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R1lQlkKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wxpz8xdG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wFc3LBVU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_u19ClEKl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ufgWJbPN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0EtPiUGl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZDPEjJI5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PFjA3kUE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j6raFRLU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cOpO5W1o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SRj0oqC4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_04GU2JcG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N5Z37uK9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_USsAkyex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4Ne3hm7t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wdXg9sSu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8scupIu8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_LFLmCJ1Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_08BLB4hJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_UUyirtEs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dUlpqATO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_scDLNTaT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5D0S6jWQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O8Q7Bf9l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C4FFxZsY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DsPcXYm5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TzLDJGbC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_uYS7T4kW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wuJ2UxHJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S3p3nSsZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AJn52BCG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KFpYiLtB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iyKOlRMC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GRJAoClQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lbPEmnIy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_QvplIukv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uNTMeTgy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nuBBhYSo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ejG9TU96_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OJQCiJ3A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9Nry2y47_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kAFZa1KQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y7Nz7ktL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kp7dpvIA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VYxQxxPq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KavicZaW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MnJFiYAX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZrMYD9Wk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aqU6lklK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7KkS7int_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WM44L5Vk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PvRE7osX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QVm6HiMY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GJdXbLwp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qsp8fJ3r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rH5kTkdl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YiPqNUkR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vENaF9ci_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_p7LgnoOd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cqU9VHDD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yXgnLyP6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hwQ22vSq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rPvHqTRV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YV4hIEni_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SQXWgOR3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NHJrrzJX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9kwKhY4t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fZ6n5LMH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_tjerdydz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hsqUZSED_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_36iLMAXw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_XoyQF5MG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_f1cOvzsJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6ROEk8KH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yqP0lt6k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3d6iVWIq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_faOBhJeF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1LEJIlTD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XOa8f9q1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zyOD6MwC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rGxV73Sc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hgVc6Xg8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EISSvgxs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HSDZgDOH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lkaKLdaq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Bw2GipKX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BKBusjyv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XmHhEsRF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fQYvGIjF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yVOwK6mg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_otLHSXUm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GUjC9kah_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AHIbzr54_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_vf1pzYkf;
  SignalBiquad_k sBiquad_k_SNl7n2og;
  SignalBiquad_k sBiquad_k_jI3nRZ3I;
  SignalBiquad_k sBiquad_k_sXHFfO3Q;
  SignalBiquad_k sBiquad_k_hcyasJ9m;
  SignalBiquad_k sBiquad_k_tar7c5jV;
  SignalVari sVari_aut8Yt4Y;
  ControlSlice cSlice_Np2A0Hma;
  ControlBinop cBinop_MLl5jsqt;
  ControlRandom cRandom_1oarSilj;
  ControlRandom cRandom_hDGCqg3z;
  ControlBinop cBinop_BX2BM73a;
  ControlSlice cSlice_X3fUcOw4;
  SignalVari sVari_VtfBrZPE;
  SignalVari sVari_awkwSxvB;
  ControlBinop cBinop_TyPLDmk3;
  ControlRandom cRandom_dHjPAE2h;
  ControlSlice cSlice_khAFsJvr;
  ControlBinop cBinop_duj9Vzsa;
  ControlVar cVar_sV29vKkJ;
  ControlBinop cBinop_YgJ9XK9f;
  ControlBinop cBinop_B8xxMvcW;
  ControlVar cVar_PZqNkw5L;
  ControlBinop cBinop_aqPsZuvz;
  ControlBinop cBinop_XID8sJpX;
  ControlBinop cBinop_8veCtKn3;
  ControlBinop cBinop_GHgiPdmQ;
  ControlBinop cBinop_bKtq7nSs;
  ControlBinop cBinop_QDP4a1fs;
  ControlBinop cBinop_xawwm4se;
  ControlBinop cBinop_SunTPbc3;
  ControlBinop cBinop_hwFdDnOR;
  ControlBinop cBinop_5sgegJNE;
  ControlBinop cBinop_GWKn0ZtA;
  ControlBinop cBinop_DALXMOTs;
  ControlBinop cBinop_5sUnBs4A;
  ControlBinop cBinop_1gij5Yvz;
  ControlVar cVar_RKuXHjLd;
  ControlBinop cBinop_OH7InqxW;
  ControlBinop cBinop_OQc4Eh31;
  ControlVar cVar_PN6P17Jp;
  ControlBinop cBinop_3lyQUVNV;
  ControlBinop cBinop_asjgeXP8;
  ControlBinop cBinop_MId9blJb;
  ControlBinop cBinop_BVwUKxZs;
  ControlBinop cBinop_RVgL7XKy;
  ControlBinop cBinop_MAzG1OpX;
  ControlBinop cBinop_UgMUMfMq;
  ControlBinop cBinop_DBzrryKD;
  ControlBinop cBinop_pmAvZCLv;
  ControlBinop cBinop_HyJtdoqi;
  ControlBinop cBinop_cX4wdgmP;
  ControlBinop cBinop_Jj3x8zHW;
  ControlBinop cBinop_r2qEYE1k;
  ControlVar cVar_XE6cLVzR;
  ControlBinop cBinop_zxhx5cMP;
  ControlBinop cBinop_WfaAKmnL;
  ControlBinop cBinop_UZ7DgDsX;
  ControlBinop cBinop_KIu4tBtN;
  ControlBinop cBinop_9UaI8X94;
  ControlBinop cBinop_GeTZbG9G;
  ControlBinop cBinop_91Q3Vlm5;
  ControlBinop cBinop_R1lQlkKU;
  ControlBinop cBinop_Wxpz8xdG;
  ControlBinop cBinop_wFc3LBVU;
  ControlBinop cBinop_u19ClEKl;
  ControlBinop cBinop_ufgWJbPN;
  ControlBinop cBinop_0EtPiUGl;
  ControlBinop cBinop_ZDPEjJI5;
  ControlVar cVar_PFjA3kUE;
  ControlBinop cBinop_j6raFRLU;
  ControlBinop cBinop_SRj0oqC4;
  ControlVar cVar_04GU2JcG;
  ControlBinop cBinop_N5Z37uK9;
  ControlBinop cBinop_wdXg9sSu;
  ControlBinop cBinop_8scupIu8;
  ControlVar cVar_08BLB4hJ;
  ControlVar cVar_dUlpqATO;
  ControlVar cVar_scDLNTaT;
  ControlBinop cBinop_5D0S6jWQ;
  ControlBinop cBinop_O8Q7Bf9l;
  ControlVar cVar_C4FFxZsY;
  ControlBinop cBinop_DsPcXYm5;
  ControlBinop cBinop_TzLDJGbC;
  ControlBinop cBinop_S3p3nSsZ;
  ControlBinop cBinop_AJn52BCG;
  ControlBinop cBinop_KFpYiLtB;
  ControlBinop cBinop_iyKOlRMC;
  ControlBinop cBinop_GRJAoClQ;
  ControlBinop cBinop_uNTMeTgy;
  ControlBinop cBinop_nuBBhYSo;
  ControlBinop cBinop_ejG9TU96;
  ControlBinop cBinop_OJQCiJ3A;
  ControlVar cVar_9Nry2y47;
  ControlBinop cBinop_kAFZa1KQ;
  ControlBinop cBinop_y7Nz7ktL;
  ControlBinop cBinop_kp7dpvIA;
  ControlBinop cBinop_VYxQxxPq;
  ControlBinop cBinop_KavicZaW;
  ControlBinop cBinop_MnJFiYAX;
  ControlBinop cBinop_ZrMYD9Wk;
  ControlBinop cBinop_aqU6lklK;
  ControlBinop cBinop_7KkS7int;
  ControlVar cVar_WM44L5Vk;
  ControlBinop cBinop_PvRE7osX;
  ControlBinop cBinop_QVm6HiMY;
  ControlBinop cBinop_rH5kTkdl;
  ControlBinop cBinop_YiPqNUkR;
  ControlBinop cBinop_vENaF9ci;
  ControlBinop cBinop_cqU9VHDD;
  ControlBinop cBinop_yXgnLyP6;
  ControlBinop cBinop_hwQ22vSq;
  ControlBinop cBinop_rPvHqTRV;
  ControlBinop cBinop_YV4hIEni;
  ControlBinop cBinop_SQXWgOR3;
  ControlVar cVar_NHJrrzJX;
  ControlBinop cBinop_fZ6n5LMH;
  ControlBinop cBinop_hsqUZSED;
  ControlBinop cBinop_f1cOvzsJ;
  ControlBinop cBinop_6ROEk8KH;
  ControlBinop cBinop_yqP0lt6k;
  ControlBinop cBinop_faOBhJeF;
  ControlBinop cBinop_1LEJIlTD;
  ControlBinop cBinop_XOa8f9q1;
  ControlBinop cBinop_zyOD6MwC;
  ControlVar cVar_rGxV73Sc;
  ControlBinop cBinop_hgVc6Xg8;
  ControlBinop cBinop_EISSvgxs;
  ControlBinop cBinop_HSDZgDOH;
  ControlBinop cBinop_lkaKLdaq;
  ControlBinop cBinop_Bw2GipKX;
  ControlBinop cBinop_BKBusjyv;
  ControlVar cVar_XmHhEsRF;
  ControlBinop cBinop_fQYvGIjF;
  ControlBinop cBinop_yVOwK6mg;
  ControlBinop cBinop_otLHSXUm;
  ControlVar cVar_GUjC9kah;
  ControlVar cVar_AHIbzr54;
};

#endif // _HEAVY_CONTEXT_SIMPLEWIND_HPP_
