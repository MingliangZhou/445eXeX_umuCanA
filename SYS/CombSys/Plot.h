#ifndef Plot_H_
#define Plot_H_

#include "../default/Rule.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLine.h"

const unsigned int NS = 9; // number of systematic sources

const int mS[8] = {20,21,33,34,29,22,23,27};
const int mC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
const int lS[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
const int lC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};

class Plot
{
	private:
		TGraphErrors* v4_1sub[2][NS][NV][NR];
		TGraphErrors* nsc_1sub[2][NS][NV][NR];
		TGraphErrors* nac_1sub[2][NS][NV][NR];

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

		void readHist_FSVR(TFile*, TGraphErrors*&, const char*, int iF, int iS, int iV, int iR);
		void readHist_SVR(TFile*, TGraphErrors*&, const char*, int iS, int iV, int iR);
		void readHist_SVRC(TFile*, TGraphErrors*&, const char*, int iS, int iV, int iR, int iC);
		void readHist_VR(TFile*, TGraphErrors*&, const char*, int iV, int iR);
		void readHist_VRC(TFile*, TGraphErrors*&, const char*, int iV, int iR, int iC);
		void draw_graph(vector<TGraphErrors*>, int iV=-1, int iR=-1, int iC=-1, int iOpt=-1, unsigned int iBin=2);
		void draw_sepa(TGraphErrors* g0, TGraphErrors* g1, TGraphErrors* gR, int iS, int iV, int iR, int iOpt, unsigned int iBin=2);
		void styleGraph(TGraph*, int);
		void styleGraph(TH1D*, int);
		void getYrange(TGraph*, double&, double&, bool isCent);

	public:
		Plot(unsigned int iBin);
		~Plot();
		void initialize(unsigned int iBin);
		void execute(unsigned int iBin);
		void finalize();
};

#endif
