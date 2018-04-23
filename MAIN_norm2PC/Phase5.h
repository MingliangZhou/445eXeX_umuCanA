#ifndef Phase4_H_
#define Phase4_H_

#include "Rule.h"

class Phase5
{
	private:
		TGraphErrors* v2_2PC[3];

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
		void readHist_VR(TFile*, TGraphAsymmErrors*&, const char*, const char*, int iV, int iR);
		void readHist_VRC(TFile*, TGraphErrors*&, const char*, const char*, int iV, int iR, int iC);
		void readHist_VRC(TFile*, TGraphAsymmErrors*&, const char*, const char*, int iV, int iR, int iC);
		void cal_norm(TGraphErrors* gSts, TGraphAsymmErrors* gSys, TGraphErrors* gRef, TGraphErrors* gV4, vector<TGraphErrors*> gVec, int iOpt);

	public:
		Phase5(unsigned int iBin);
		~Phase5();
		void initialize(unsigned int iBin);
		void execute();
		void finalize(unsigned int iBin);
};

#endif


