#ifndef Plot_H_
#define Plot_H_

#include "../MAIN/Rule.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLine.h"

const int mS[8] = {20,21,33,34,29,22,23,27};
const int mC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
const int lS[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
const int lC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};

class Plot
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

		void readHist_VR(TFile*, TGraphErrors*&, const char*, int iV, int iR);
		void readHist_VR(TFile*, TGraphAsymmErrors*&, const char*, int iV, int iR);
		void readHist_VRC(TFile*, TGraphErrors*&, const char*, int iV, int iR, int iC);
		void readHist_VRC(TFile*, TGraphAsymmErrors*&, const char*, int iV, int iR, int iC);
		void draw_graph(vector<TGraphErrors*>, vector<TGraphAsymmErrors*>, int iV=-1, int iR=-1, int iC=-1, int iOpt=-1, unsigned int iBin=0);
		void styleGraph(TGraph*, int);
		void styleGraph(TH1D*, int);
		void getYrange(TGraph*, double&, double&, int);

	public:
		Plot(unsigned int iBin);
		~Plot();
		void initialize(unsigned int iBin);
		void execute(unsigned int iBin);
		void finalize();
};

#endif
