#ifndef Phase4_H_
#define Phase4_H_

#include "Rule.h"

class Phase4
{
	private:
		TGraphErrors* sts_c2_1sub[NV][NR];
		TGraphErrors* sts_c4_1sub[NV][NR];
		TGraphErrors* sts_c6_1sub[NV][NR];
		TGraphErrors* sts_nc4_1sub[NV][NR];
		TGraphErrors* sts_nc6_1sub[NV][NR];
		TGraphErrors* sts_v2_1sub[NV][NR];
		TGraphErrors* sts_v4_1sub[NV][NR];
		TGraphErrors* sts_v6_1sub[NV][NR];
		TGraphErrors* sts_cr42_1sub[NV][NR];
		TGraphErrors* sts_cr64_1sub[NV][NR];
		TGraphErrors* sts_sc_1sub[NV][NR];
		TGraphErrors* sts_nsc_1sub[NV][NR];
		TGraphErrors* sts_ac_1sub[NV][NR];
		TGraphErrors* sts_nac_1sub[NV][NR];
		TGraphErrors* sts_vd2_1sub[NV][NR][nCent];
		TGraphErrors* sts_vd4_1sub[NV][NR][nCent];
		TGraphErrors* sts_c2_3sub[NV][NR];
		TGraphErrors* sts_c4_3sub[NV][NR];
		TGraphErrors* sts_v2_3sub[NV][NR];
		TGraphErrors* sts_v4_3sub[NV][NR];
		TGraphErrors* sts_sc_3sub[NV][NR];
		TGraphErrors* sts_nsc_3sub[NV][NR];
		TGraphErrors* sts_ac_3sub[NV][NR];
		TGraphErrors* sts_nac_3sub[NV][NR];
		
		TGraphErrors* sysUp_c2_1sub[NV][NR];
		TGraphErrors* sysUp_c4_1sub[NV][NR];
		TGraphErrors* sysUp_c6_1sub[NV][NR];
		TGraphErrors* sysUp_nc4_1sub[NV][NR];
		TGraphErrors* sysUp_nc6_1sub[NV][NR];
		TGraphErrors* sysUp_v2_1sub[NV][NR];
		TGraphErrors* sysUp_v4_1sub[NV][NR];
		TGraphErrors* sysUp_v6_1sub[NV][NR];
		TGraphErrors* sysUp_cr42_1sub[NV][NR];
		TGraphErrors* sysUp_cr64_1sub[NV][NR];
		TGraphErrors* sysUp_sc_1sub[NV][NR];
		TGraphErrors* sysUp_nsc_1sub[NV][NR];
		TGraphErrors* sysUp_ac_1sub[NV][NR];
		TGraphErrors* sysUp_nac_1sub[NV][NR];
		TGraphErrors* sysUp_vd2_1sub[NV][NR][nCent];
		TGraphErrors* sysUp_vd4_1sub[NV][NR][nCent];
		TGraphErrors* sysUp_c2_3sub[NV][NR];
		TGraphErrors* sysUp_c4_3sub[NV][NR];
		TGraphErrors* sysUp_v2_3sub[NV][NR];
		TGraphErrors* sysUp_v4_3sub[NV][NR];
		TGraphErrors* sysUp_sc_3sub[NV][NR];
		TGraphErrors* sysUp_nsc_3sub[NV][NR];
		TGraphErrors* sysUp_ac_3sub[NV][NR];
		TGraphErrors* sysUp_nac_3sub[NV][NR];
		
		TGraphErrors* sysLw_c2_1sub[NV][NR];
		TGraphErrors* sysLw_c4_1sub[NV][NR];
		TGraphErrors* sysLw_c6_1sub[NV][NR];
		TGraphErrors* sysLw_nc4_1sub[NV][NR];
		TGraphErrors* sysLw_nc6_1sub[NV][NR];
		TGraphErrors* sysLw_v2_1sub[NV][NR];
		TGraphErrors* sysLw_v4_1sub[NV][NR];
		TGraphErrors* sysLw_v6_1sub[NV][NR];
		TGraphErrors* sysLw_cr42_1sub[NV][NR];
		TGraphErrors* sysLw_cr64_1sub[NV][NR];
		TGraphErrors* sysLw_sc_1sub[NV][NR];
		TGraphErrors* sysLw_nsc_1sub[NV][NR];
		TGraphErrors* sysLw_ac_1sub[NV][NR];
		TGraphErrors* sysLw_nac_1sub[NV][NR];
		TGraphErrors* sysLw_vd2_1sub[NV][NR][nCent];
		TGraphErrors* sysLw_vd4_1sub[NV][NR][nCent];
		TGraphErrors* sysLw_c2_3sub[NV][NR];
		TGraphErrors* sysLw_c4_3sub[NV][NR];
		TGraphErrors* sysLw_v2_3sub[NV][NR];
		TGraphErrors* sysLw_v4_3sub[NV][NR];
		TGraphErrors* sysLw_sc_3sub[NV][NR];
		TGraphErrors* sysLw_nsc_3sub[NV][NR];
		TGraphErrors* sysLw_ac_3sub[NV][NR];
		TGraphErrors* sysLw_nac_3sub[NV][NR];
		
		TGraphAsymmErrors* sys_c2_1sub[NV][NR];
		TGraphAsymmErrors* sys_c4_1sub[NV][NR];
		TGraphAsymmErrors* sys_c6_1sub[NV][NR];
		TGraphAsymmErrors* sys_nc4_1sub[NV][NR];
		TGraphAsymmErrors* sys_nc6_1sub[NV][NR];
		TGraphAsymmErrors* sys_v2_1sub[NV][NR];
		TGraphAsymmErrors* sys_v4_1sub[NV][NR];
		TGraphAsymmErrors* sys_v6_1sub[NV][NR];
		TGraphAsymmErrors* sys_cr42_1sub[NV][NR];
		TGraphAsymmErrors* sys_cr64_1sub[NV][NR];
		TGraphAsymmErrors* sys_sc_1sub[NV][NR];
		TGraphAsymmErrors* sys_nsc_1sub[NV][NR];
		TGraphAsymmErrors* sys_ac_1sub[NV][NR];
		TGraphAsymmErrors* sys_nac_1sub[NV][NR];
		TGraphAsymmErrors* sys_vd2_1sub[NV][NR][nCent];
		TGraphAsymmErrors* sys_vd4_1sub[NV][NR][nCent];
		TGraphAsymmErrors* sys_c2_3sub[NV][NR];
		TGraphAsymmErrors* sys_c4_3sub[NV][NR];
		TGraphAsymmErrors* sys_v2_3sub[NV][NR];
		TGraphAsymmErrors* sys_v4_3sub[NV][NR];
		TGraphAsymmErrors* sys_sc_3sub[NV][NR];
		TGraphAsymmErrors* sys_nsc_3sub[NV][NR];
		TGraphAsymmErrors* sys_ac_3sub[NV][NR];
		TGraphAsymmErrors* sys_nac_3sub[NV][NR];

		void readHist_VR(TFile*, TGraphErrors*&, const char*, const char*, int iV, int iR);
		void readHist_VR_Xe(TFile*, TGraphErrors*&, const char*, const char*, int iV, int iR);
		void readHist_VRC_Xe(TFile*, TGraphErrors*&, const char*, const char*, int iV, int iR, int iC);
		void combine(TGraphErrors* gSts, TGraphErrors* gSysUp, TGraphErrors* gSysLw, TGraphAsymmErrors*& gSys, const char*, int iV, int iR, int iC=-1);
		void trim(TGraphErrors* gSts, TGraphAsymmErrors* gSys);
		void cal_err_v(TGraphAsymmErrors* sys_c, TGraphAsymmErrors* sys_v, int iOpt);
		void cal_err_cr(TGraphAsymmErrors* sys_cN, TGraphAsymmErrors* sys_cD, TGraphAsymmErrors* sys_cr);

	public:
		Phase4(unsigned int iBin);
		~Phase4();
		void initialize(unsigned int iBin);
		void execute();
		void finalize(unsigned int iBin);
};

#endif


