#ifndef Phase3_H_
#define Phase3_H_

#include "Rule.h"

class Phase3
{
  private:
		// input
		TH1D* cnt_1sub[NR];
		TH1D* rbn_c2_1sub[nSample+1][NV][NR];
		TH1D* rbn_c4_1sub[nSample+1][NV][NR];
		TH1D* rbn_c6_1sub[nSample+1][NV][NR];
		TH1D* rbn_nc4_1sub[nSample+1][NV][NR];
		TH1D* rbn_nc6_1sub[nSample+1][NV][NR];
		TH1D* rbn_v2_1sub[nSample+1][NV][NR];
		TH1D* rbn_v4_1sub[nSample+1][NV][NR];
		TH1D* rbn_v6_1sub[nSample+1][NV][NR];
		TH1D* rbn_cr42_1sub[nSample+1][NV][NR];
		TH1D* rbn_cr64_1sub[nSample+1][NV][NR];
		TH1D* rbn_sc_1sub[nSample+1][NV][NR];
		TH1D* rbn_nsc_1sub[nSample+1][NV][NR];
		TH1D* rbn_ac_1sub[nSample+1][NV][NR];
		TH1D* rbn_nac_1sub[nSample+1][NV][NR];

		TH1D* pT_vd2_1sub[nSample+1][NV][NR][nCent];
		TH1D* pT_vd4_1sub[nSample+1][NV][NR][nCent];

		TH1D* cnt_3sub[NR];
		TH1D* rbn_c2_3sub[nSample+1][NV][NR];
		TH1D* rbn_c4_3sub[nSample+1][NV][NR];
		TH1D* rbn_nc4_3sub[nSample+1][NV][NR];
		TH1D* rbn_v2_3sub[nSample+1][NV][NR];
		TH1D* rbn_v4_3sub[nSample+1][NV][NR];
		TH1D* rbn_sc_3sub[nSample+1][NV][NR];
		TH1D* rbn_nsc_3sub[nSample+1][NV][NR];
		TH1D* rbn_ac_3sub[nSample+1][NV][NR];
		TH1D* rbn_nac_3sub[nSample+1][NV][NR];

		// output
		TGraphErrors* c2_1sub[NV][NR];
		TGraphErrors* c4_1sub[NV][NR];
		TGraphErrors* c6_1sub[NV][NR];
		TGraphErrors* nc4_1sub[NV][NR];
		TGraphErrors* nc6_1sub[NV][NR];
		TGraphErrors* v2_1sub[NV][NR];
		TGraphErrors* v4_1sub[NV][NR];
		TGraphErrors* v6_1sub[NV][NR];
		TGraphErrors* cr42_1sub[NV][NR];
		TGraphErrors* cr64_1sub[NV][NR];
		TGraphErrors* sc_1sub[NV][NR];
		TGraphErrors* nsc_1sub[NV][NR];
		TGraphErrors* ac_1sub[NV][NR];
		TGraphErrors* nac_1sub[NV][NR];

		TGraphErrors* vd2_1sub[NV][NR][nCent];
		TGraphErrors* vd4_1sub[NV][NR][nCent];

		TGraphErrors* c2_3sub[NV][NR];
		TGraphErrors* c4_3sub[NV][NR];
		TGraphErrors* v2_3sub[NV][NR];
		TGraphErrors* v4_3sub[NV][NR];
		TGraphErrors* sc_3sub[NV][NR];
		TGraphErrors* nsc_3sub[NV][NR];
		TGraphErrors* ac_3sub[NV][NR];
		TGraphErrors* nac_3sub[NV][NR];

		void cal_sts(vector<TH1D*>, TGraphErrors*&, const char*, int iV=-1, int iR=-1, int iC=-1);
		void cleanPoint(TGraphErrors*);
		void readHist_VR(TFile*, TH1D*&, const char*, int iV, int iR);
		void readHist_VRC(TFile*, TH1D*&, const char*, int iV, int iR, int iC);

	public:
		Phase3(unsigned int iBin);
		~Phase3();
		void initialize(unsigned int iBin);
		void execute();
		void finalize(unsigned int iBin);
};

#endif
