#ifndef CombSys_H_
#define CombSys_H_

#include "../default/Rule.h"

const unsigned int NS = 9; // number of systematic sources
// 0: default for statistical errors
// 1: low tracking efficiency
// 2: high tracking efficiency
// 3: tight track selection
// 4: loose pileup rejection -> centrality definition Up
// 5: MC closure
// 6: no flattening -> event mixing Up
// 7: centrality definition Lw
// 8: event mixing Lw

class CombSys
{
  private:
		TGraphErrors* c2_1sub[2][NS][NV][NR];
		TGraphErrors* c4_1sub[2][NS][NV][NR];
		TGraphErrors* c6_1sub[2][NS][NV][NR];
		TGraphErrors* nc4_1sub[2][NS][NV][NR];
		TGraphErrors* nc6_1sub[2][NS][NV][NR];
		TGraphErrors* v2_1sub[2][NS][NV][NR];
		TGraphErrors* v4_1sub[2][NS][NV][NR];
		TGraphErrors* v6_1sub[2][NS][NV][NR];
		TGraphErrors* cr42_1sub[2][NS][NV][NR];
		TGraphErrors* cr64_1sub[2][NS][NV][NR];
		TGraphErrors* sc_1sub[2][NS][NV][NR];
		TGraphErrors* nsc_1sub[2][NS][NV][NR];
		TGraphErrors* ac_1sub[2][NS][NV][NR];
		TGraphErrors* nac_1sub[2][NS][NV][NR];
		TGraphErrors* c2_3sub[2][NS][NV][NR];
		TGraphErrors* c4_3sub[2][NS][NV][NR];
		TGraphErrors* v2_3sub[2][NS][NV][NR];
		TGraphErrors* v4_3sub[2][NS][NV][NR];
		TGraphErrors* sc_3sub[2][NS][NV][NR];
		TGraphErrors* nsc_3sub[2][NS][NV][NR];
		TGraphErrors* ac_3sub[2][NS][NV][NR];
		TGraphErrors* nac_3sub[2][NS][NV][NR];
		TGraphErrors* vd2_1sub[2][NS][NV][NR][nCent];
		TGraphErrors* vd4_1sub[2][NS][NV][NR][nCent];
		
		TGraphErrors* ratio_c2_1sub[NS][NV][NR];
		TGraphErrors* ratio_c4_1sub[NS][NV][NR];
		TGraphErrors* ratio_c6_1sub[NS][NV][NR];
		TGraphErrors* ratio_nc4_1sub[NS][NV][NR];
		TGraphErrors* ratio_nc6_1sub[NS][NV][NR];
		TGraphErrors* ratio_v2_1sub[NS][NV][NR];
		TGraphErrors* ratio_v4_1sub[NS][NV][NR];
		TGraphErrors* ratio_v6_1sub[NS][NV][NR];
		TGraphErrors* ratio_cr42_1sub[NS][NV][NR];
		TGraphErrors* ratio_cr64_1sub[NS][NV][NR];
		TGraphErrors* ratio_sc_1sub[NS][NV][NR];
		TGraphErrors* ratio_nsc_1sub[NS][NV][NR];
		TGraphErrors* ratio_ac_1sub[NS][NV][NR];
		TGraphErrors* ratio_nac_1sub[NS][NV][NR];
		TGraphErrors* ratio_c2_3sub[NS][NV][NR];
		TGraphErrors* ratio_c4_3sub[NS][NV][NR];
		TGraphErrors* ratio_v2_3sub[NS][NV][NR];
		TGraphErrors* ratio_v4_3sub[NS][NV][NR];
		TGraphErrors* ratio_sc_3sub[NS][NV][NR];
		TGraphErrors* ratio_nsc_3sub[NS][NV][NR];
		TGraphErrors* ratio_ac_3sub[NS][NV][NR];
		TGraphErrors* ratio_nac_3sub[NS][NV][NR];
		TGraphErrors* ratio_vd2_1sub[NS][NV][NR][nCent];
		TGraphErrors* ratio_vd4_1sub[NS][NV][NR][nCent];
		
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
		TGraphErrors* sysUp_c2_3sub[NV][NR];
		TGraphErrors* sysUp_c4_3sub[NV][NR];
		TGraphErrors* sysUp_v2_3sub[NV][NR];
		TGraphErrors* sysUp_v4_3sub[NV][NR];
		TGraphErrors* sysUp_sc_3sub[NV][NR];
		TGraphErrors* sysUp_nsc_3sub[NV][NR];
		TGraphErrors* sysUp_ac_3sub[NV][NR];
		TGraphErrors* sysUp_nac_3sub[NV][NR];
		TGraphErrors* sysUp_vd2_1sub[NV][NR][nCent];
		TGraphErrors* sysUp_vd4_1sub[NV][NR][nCent];
		
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
		TGraphErrors* sysLw_c2_3sub[NV][NR];
		TGraphErrors* sysLw_c4_3sub[NV][NR];
		TGraphErrors* sysLw_v2_3sub[NV][NR];
		TGraphErrors* sysLw_v4_3sub[NV][NR];
		TGraphErrors* sysLw_sc_3sub[NV][NR];
		TGraphErrors* sysLw_nsc_3sub[NV][NR];
		TGraphErrors* sysLw_ac_3sub[NV][NR];
		TGraphErrors* sysLw_nac_3sub[NV][NR];
		TGraphErrors* sysLw_vd2_1sub[NV][NR][nCent];
		TGraphErrors* sysLw_vd4_1sub[NV][NR][nCent];

		void readHist_VR(TFile*, TGraphErrors*&, const char*, const char*, int iF, int iS, int iV, int iR);
		void readHist_VRC(TFile*, TGraphErrors*&, const char*, const char*, int iF, int iS, int iV, int iR, int iC);
		void cal_ratio(TGraphErrors* gChk, TGraphErrors* gDef, TGraphErrors*& gRatio, const char*, int iS, int iV, int iR, int iC=-1);
		void smooth_ratio(TGraphErrors* gRatio, int iB, double percent);
		void reduce_ratio(TGraphErrors* gRatio, int iB, double percent);
		void cal_comb(vector<TGraphErrors*> gVec, TGraphErrors*& gSysUp, TGraphErrors*& gSysLw, const char*, int iV, int iR, int iC=-1);
		void set_sys(TGraphErrors* gRatio, double sys1, double sys2=0);
		void smooth();

	public:
		CombSys(unsigned int iBin);
		~CombSys();
		void initialize(unsigned int iBin);
		void execute();
		void finalize(unsigned int iBin);
};

#endif
