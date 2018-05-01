#ifndef CumuRbn_H_
#define CumuRbn_H_

#include "Rule.h"

enum {raw,rbn,cen};

class CumuRbn
{
	private:
		// input
		TH1D* cnt_1sub[NR];
		TH1D* pc2_1sub_mean[NV][NR];
		TH1D* pc2_1sub_wght[NV][NR];
		TH1D* pc4_1sub_mean[NV][NR];
		TH1D* pc4_1sub_wght[NV][NR];
		TH1D* pc6_1sub_mean[NV][NR];
		TH1D* pc6_1sub_wght[NV][NR];
		TH1D* psc4_1sub_mean[NV][NR];
		TH1D* psc4_1sub_wght[NV][NR];
		TH1D* pac3_1sub_mean[NV][NR];
		TH1D* pac3_1sub_wght[NV][NR];

		TH1D* cnt_1sub_diff[NR][NP];
		TH1D* pd2_1sub_mean[NV][NR][NP];
		TH1D* pd2_1sub_wght[NV][NR][NP];
		TH1D* pd4_1sub_mean[NV][NR][NP];
		TH1D* pd4_1sub_wght[NV][NR][NP];

		TH1D* cnt_3sub[NA][NR];
		TH1D* pc2_1_3sub_mean[NA][NV][NR];
		TH1D* pc2_1_3sub_wght[NA][NV][NR];
		TH1D* pc2_2_3sub_mean[NA][NV][NR];
		TH1D* pc2_2_3sub_wght[NA][NV][NR];
		TH1D* pc4_3sub_mean[NA][NV][NR];
		TH1D* pc4_3sub_wght[NA][NV][NR];
		TH1D* psc4_3sub_mean[NA][NV][NR];
		TH1D* psc4_3sub_wght[NA][NV][NR];
		TH1D* pac3_3sub_mean[NA][NV][NR];
		TH1D* pac3_3sub_wght[NA][NV][NR];

		// output
		TH1D* raw_c2_1sub[NV][NR];
		TH1D* rbn_c2_1sub[NV][NR];
		TH1D* cen_c2_1sub[NV][NR];
		TH1D* raw_c4_1sub[NV][NR];
		TH1D* rbn_c4_1sub[NV][NR];
		TH1D* cen_c4_1sub[NV][NR];
		TH1D* raw_c6_1sub[NV][NR];
		TH1D* rbn_c6_1sub[NV][NR];
		TH1D* raw_nc4_1sub[NV][NR];
		TH1D* rbn_nc4_1sub[NV][NR];
		TH1D* raw_nc6_1sub[NV][NR];
		TH1D* rbn_nc6_1sub[NV][NR];
		TH1D* raw_v2_1sub[NV][NR];
		TH1D* rbn_v2_1sub[NV][NR];
		TH1D* raw_v4_1sub[NV][NR];
		TH1D* rbn_v4_1sub[NV][NR];
		TH1D* raw_v6_1sub[NV][NR];
		TH1D* rbn_v6_1sub[NV][NR];
		TH1D* raw_cr42_1sub[NV][NR];
		TH1D* rbn_cr42_1sub[NV][NR];
		TH1D* raw_cr64_1sub[NV][NR];
		TH1D* rbn_cr64_1sub[NV][NR];
		TH1D* raw_sc_1sub[NV][NR];
		TH1D* rbn_sc_1sub[NV][NR];
		TH1D* raw_nsc_1sub[NV][NR];
		TH1D* rbn_nsc_1sub[NV][NR];
		TH1D* raw_ac_1sub[NV][NR];
		TH1D* rbn_ac_1sub[NV][NR];
		TH1D* raw_nac_1sub[NV][NR];
		TH1D* rbn_nac_1sub[NV][NR];

		TH1D* raw_d2_1sub[NV][NR][NP];
		TH1D* cen_d2_1sub[NV][NR][NP];
		TH1D* cen_vd2_1sub[NV][NR][NP];
		TH1D* raw_d4_1sub[NV][NR][NP];
		TH1D* cen_d4_1sub[NV][NR][NP];
		TH1D* cen_vd4_1sub[NV][NR][NP];

		TH1D* rbn_cnt_3sub[NA][NR];
		TH1D* raw_c2_3sub[NA][NV][NR];
		TH1D* rbn_c2_3sub[NA][NV][NR];
		TH1D* raw_c4_3sub[NA][NV][NR];
		TH1D* rbn_c4_3sub[NA][NV][NR];
		TH1D* raw_nc4_3sub[NA][NV][NR];
		TH1D* rbn_nc4_3sub[NA][NV][NR];
		TH1D* raw_v2_3sub[NA][NV][NR];
		TH1D* rbn_v2_3sub[NA][NV][NR];
		TH1D* raw_v4_3sub[NA][NV][NR];
		TH1D* rbn_v4_3sub[NA][NV][NR];
		TH1D* raw_sc_3sub[NA][NV][NR];
		TH1D* rbn_sc_3sub[NA][NV][NR];
		TH1D* raw_nsc_3sub[NA][NV][NR];
		TH1D* rbn_nsc_3sub[NA][NV][NR];
		TH1D* raw_ac_3sub[NA][NV][NR];
		TH1D* rbn_ac_3sub[NA][NV][NR];
		TH1D* raw_nac_3sub[NA][NV][NR];
		TH1D* rbn_nac_3sub[NA][NV][NR];

		TH1D* pT_vd2_1sub[NV][NR][nCent];
		TH1D* pT_vd4_1sub[NV][NR][nCent];

		void run_c();
		void run_d();
		void run_sc();
		void run_ac();
		void run_nc();
		void run_nsc();
		void run_nac();
		void run_cr();

		void cal_c_1sub(TH1D* pc2, TH1D* pc4, TH1D* pc6, TH1D* c2, TH1D* c4, TH1D* c6);
		void cal_d_1sub(TH1D* pd2, TH1D* pc2, TH1D* pd4, TH1D* d2, TH1D* d4);
		void cal_vd_1sub(TH1D* c2, TH1D* d2, TH1D* c4, TH1D* d4, TH1D* vd2, TH1D* vd4);
		void cal_ac(TH1D* pac3, TH1D* ac3);
		void cal_sc(TH1D* pc2_1, TH1D* pc2_2, TH1D* psc4, TH1D* sc4);
		void cal_c_3sub(TH1D* pc2_1, TH1D* pc2_2, TH1D* pc4, TH1D* c2, TH1D* c4);
		void cal_nc(TH1D* c2, TH1D* c4, TH1D* c6, TH1D* nc4, TH1D* nc6);
		void cal_nsc(TH1D* c2_1, TH1D* c2_2, TH1D* sc4, TH1D* nsc4);
		void cal_nac(TH1D* c4, TH1D* c2_1, TH1D* c2_2, TH1D* ac4, TH1D* nac4);
		void cal_v_1sub(TH1D* c2, TH1D* c4, TH1D* c6, TH1D* v2, TH1D* v4, TH1D* v6);
		void cal_v_3sub(TH1D* c2, TH1D* c4, TH1D* v2, TH1D* v4);
		void cal_cr(TH1D* v2, TH1D* v4, TH1D* v6, TH1D* cr42, TH1D* cr64);

		void rebin_cumu(TH1D* hIn, TH1D* hWght, TH1D* hOut);
		void merge3sub(TH1D* h1, TH1D* h1w, TH1D* h2, TH1D* h2w, TH1D* h3, TH1D* h3w);
		void cvt_cent_pt(vector<TH1D*> vIn, TH1D* hOut, int iC);
		
		void readHist_VR(TFile*, TH1D*&, const char*, int iV, int iR);
		void readHist_VRP(TFile*, TH1D*&, const char*, int iV, int iR, int iP);
		void readHist_AVR(TFile*, TH1D*&, const char*, int iA, int iV, int iR);
		void initHist_VR(TH1D*&, const char*, int iV, int iR, int iOpt, int iRebin);
		void initHist_VRP(TH1D*&, const char*, int iV, int iR, int iP, int iOpt, int iRebin);
		void initHist_AVR(TH1D*&, const char*, int iA, int iV, int iR, int iOpt, int iRebin);
		void initHist_VRC(TH1D*&, const char*, int iV, int iR, int iP);

	public:
		CumuRbn(TFile*, unsigned int iRebin);
		~CumuRbn();
		void cal_all();
		void writeHist(TFile*&);
};

#endif
