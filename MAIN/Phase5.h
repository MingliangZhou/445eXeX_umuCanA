#ifndef Phase4_H_
#define Phase4_H_

#include "Rule.h"

const double np_cent[25] = {
 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
10, 15, 20, 25, 30, 35, 40, 45, 50, 55,
60, 65, 70, 75, 80};
const double np_np[24] = {
247.042, 242.599, 237.930, 232.588, 226.708, 220.641, 214.596, 208.584, 202.609, 196.646,
179.691, 153.447, 130.146, 109.637, 91.5528, 75.6057, 61.6532, 49.5029, 39.2177, 30.5018,
23.3594, 17.2835, 12.5505, 8.94715
};

class Phase5
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

		TGraph* gCvt_Cent_Npart;

		void cvt_Npart(TGraph* gCvt, TGraphErrors* gSts, TGraphAsymmErrors* gSys);
		void readHist_VR(TFile*, TGraphErrors*&, const char*, const char*, int iV, int iR);
		void readHist_VR(TFile*, TGraphAsymmErrors*&, const char*, const char*, int iV, int iR);
		void readHist_VRC(TFile*, TGraphErrors*&, const char*, const char*, int iV, int iR, int iC);
		void readHist_VRC(TFile*, TGraphAsymmErrors*&, const char*, const char*, int iV, int iR, int iC);

	public:
		Phase5(unsigned int iBin);
		~Phase5();
		void initialize(unsigned int iBin);
		void execute();
		void finalize(unsigned int iBin);
};

#endif


