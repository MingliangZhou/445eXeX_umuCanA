#ifndef Plot_H_
#define Plot_H_

#include "../MAIN/Rule.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLine.h"
///* 2PC style 
const int mS[8] = {kFullCircle,kOpenCircle,kOpenSquare,kOpenDiamond,29,22,23,27};
const int mC[8] = {kBlack, kRed, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
const int fC[8] = {kGray,  kRed-10, kGreen-10, kYellow-10, kMagenta+2, kCyan+2, kOrange+2, 1};
const int lS[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
const int lC[8] = {kBlack, kRed, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
//*/

/* my style
const int mS[8] = {20,21,33,34,29,22,23,27};
const int mC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
const int lS[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
const int lC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
*/

const double np_cent[25] = {
 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
 10, 15, 20, 25, 30, 35, 40, 45, 50, 55,
 60, 65, 70, 75, 80};
 const double np_np[24] = {
 402.933, 395.072, 385.430, 374.886, 364.150, 353.660, 343.259, 332.954, 322.768, 312.917,
 285.244, 242.921, 205.637, 172.808, 144.107, 118.754, 96.6306, 77.4079, 60.9290, 46.9523,
 35.2932, 25.8426, 18.2855, 12.5347};

const unsigned int NF = 2;

class Plot
{
	private:
		TGraphErrors* sts_c2_1sub[NF][2][NV][NR];
		TGraphErrors* sts_c4_1sub[NF][2][NV][NR];
		TGraphErrors* sts_c6_1sub[NF][2][NV][NR];
		TGraphErrors* sts_nc4_1sub[NF][2][NV][NR];
		TGraphErrors* sts_nc6_1sub[NF][2][NV][NR];
		TGraphErrors* sts_v2_1sub[NF][2][NV][NR];
		TGraphErrors* sts_v4_1sub[NF][2][NV][NR];
		TGraphErrors* sts_v6_1sub[NF][2][NV][NR];
		TGraphErrors* sts_cr42_1sub[NF][2][NV][NR];
		TGraphErrors* sts_cr64_1sub[NF][2][NV][NR];
		TGraphErrors* sts_sc_1sub[NF][2][NV][NR];
		TGraphErrors* sts_nsc_1sub[NF][2][NV][NR];
		TGraphErrors* sts_ac_1sub[NF][2][NV][NR];
		TGraphErrors* sts_nac_1sub[NF][2][NV][NR];
		TGraphErrors* sts_vd2_1sub[NF][2][NV][NR][nCent];
		TGraphErrors* sts_vd4_1sub[NF][2][NV][NR][nCent];
		TGraphErrors* sts_c2_3sub[NF][2][NV][NR];
		TGraphErrors* sts_c4_3sub[NF][2][NV][NR];
		TGraphErrors* sts_v2_3sub[NF][2][NV][NR];
		TGraphErrors* sts_v4_3sub[NF][2][NV][NR];
		TGraphErrors* sts_sc_3sub[NF][2][NV][NR];
		TGraphErrors* sts_nsc_3sub[NF][2][NV][NR];
		TGraphErrors* sts_ac_3sub[NF][2][NV][NR];
		TGraphErrors* sts_nac_3sub[NF][2][NV][NR];
		
		TGraphAsymmErrors* sys_c2_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_c4_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_c6_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_nc4_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_nc6_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_v2_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_v4_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_v6_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_cr42_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_cr64_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_sc_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_nsc_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_ac_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_nac_1sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_vd2_1sub[NF][2][NV][NR][nCent];
		TGraphAsymmErrors* sys_vd4_1sub[NF][2][NV][NR][nCent];
		TGraphAsymmErrors* sys_c2_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_c4_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_v2_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_v4_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_sc_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_nsc_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_ac_3sub[NF][2][NV][NR];
		TGraphAsymmErrors* sys_nac_3sub[NF][2][NV][NR];

		TGraph* gCvt_Cent_Npart;

		void readHist_VR(TFile*, TGraphErrors*&, const char*, int iV, int iR);
		void readHist_VR(TFile*, TGraphAsymmErrors*&, const char*, int iV, int iR);
		void readHist_VRC(TFile*, TGraphErrors*&, const char*, int iV, int iR, int iC);
		void readHist_VRC(TFile*, TGraphAsymmErrors*&, const char*, int iV, int iR, int iC);
		void draw_graph(vector<TGraphErrors*>, vector<TGraphAsymmErrors*>, int iV=-1, int iR=-1, int iC=-1, int iOpt=-1);
		void draw_graphComp(vector<TGraphErrors*>, vector<TGraphAsymmErrors*>, int iV=-1, int iR=-1, int iC=-1, int iOpt=-1);
		void styleGraph(TGraph*, int);
		void styleGraph(TH1D*, int);
		void getYrange(TGraph*, double&, double&, int);
		void cvt_Npart(TGraph* gCvt, TGraphErrors* gSts, TGraphAsymmErrors* gSys);

	public:
		Plot();
		~Plot();
		void initialize();
		void execute();
		void finalize();
};

#endif
