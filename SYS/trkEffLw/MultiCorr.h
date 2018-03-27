#ifndef MultiCorr_H_
#define MultiCorr_H_

#include "Event.h"

class MultiCorr
{
	private:
		void initHist_VR(TH1D*&, const char*, int iV, int iR); // initialize cumulant from reference
		void initHist_VRP(TH1D*&, const char*, int iV, int iR, int iP); // initialize cumulant from differential
		void initHist_AVR(TH1D*&, const char*, int iA, int iV, int iR); // initialize cumulant from 3-subevent

		double cal_2pc_1sub(Event*, int iV, int iR);
		double cal_w2pc_1sub(Event*, int iR);
		double cal_4pc_1sub(Event*, int iV, int iR);
		double cal_w4pc_1sub(Event*, int iR);
		double cal_6pc_1sub(Event*, int iV, int iR);
		double cal_w6pc_1sub(Event*, int iR);
		double cal_4psc_1sub(Event*, int iV, int iR);
		double cal_3pac_1sub(Event*, int iV, int iR);
		double cal_w3pc_1sub(Event*, int iR);

		double cal_2pc_1sub_BG(Event* evt1, Event* evt2, int iV, int iR);
		double cal_w2pc_1sub_BG(Event* evt1, Event* evt2, int iR);
		double cal_4pc_1sub_BG(Event* evt1, Event* evt2, Event* evt3, Event* evt4, int iV, int iR);
		double cal_w4pc_1sub_BG(Event* evt1, Event* evt2, Event* evt3, Event* evt4, int iR);

		double cal_2pd_1sub(Event*, int iV, int iR, int iP);
		double cal_w2pd_1sub(Event*, int iR, int iP);
		double cal_4pd_1sub(Event*, int iV, int iR, int iP);
		double cal_w4pd_1sub(Event*, int iR, int iP);

		double cal_2pc_3sub(Event*, int iV, int iR, int iO);
		double cal_w2pc_3sub(Event*, int iR, int iO);
		double cal_4pc_3sub(Event*, int iV, int iR);
		double cal_w4pc_3sub(Event*, int iR);
		double cal_4psc_3sub(Event*, int iV, int iR);
		double cal_3pac_3sub(Event*, int iV, int iR);
		double cal_w3pc_3sub(Event*, int iR);

		void swap(double&, double&, double&);
		void swap(TComplex&, TComplex&, TComplex&);
		void swap(Event*& evt1, Event*& evt2, Event*& evt3);

public:
		// reference
		TH1D* cnt_1sub[NR]; // number of events
		TH1D* pc2_1sub_mean[NV][NR]; // mean of <corr2>_{n|n}
		TH1D* pc2_1sub_wght[NV][NR]; // weight of <corr2>_{n|n}
		TH1D* pc4_1sub_mean[NV][NR]; // mean of <corr4>_{n|n}
		TH1D* pc4_1sub_wght[NV][NR]; // weight of <corr4>_{n|n}
		TH1D* pc6_1sub_mean[NV][NR]; // mean of <corr6>_{n|n}
		TH1D* pc6_1sub_wght[NV][NR]; // weight of <corr6>_{n|n}
		TH1D* psc4_1sub_mean[NV][NR];
		TH1D* psc4_1sub_wght[NV][NR];
		TH1D* pac3_1sub_mean[NV][NR];
		TH1D* pac3_1sub_wght[NV][NR];
		
		TH1D* pc2_1_1sub_BG_mean[NA][NV][NR];
		TH1D* pc2_1_1sub_BG_wght[NA][NV][NR];
		TH1D* pc2_2_1sub_BG_mean[NA][NV][NR];
		TH1D* pc2_2_1sub_BG_wght[NA][NV][NR];
		TH1D* pc2_3_1sub_BG_mean[NA][NV][NR];
		TH1D* pc2_3_1sub_BG_wght[NA][NV][NR];
		TH1D* pc2_4_1sub_BG_mean[NA][NV][NR];
		TH1D* pc2_4_1sub_BG_wght[NA][NV][NR];
		TH1D* pc4_1sub_BG_mean[NA][NV][NR];
		TH1D* pc4_1sub_BG_wght[NA][NV][NR];

		// differential
		TH1D* cnt_1sub_diff[NR][NP]; // number of events
		TH1D* pd2_1sub_mean[NV][NR][NP]; // mean of <dcorr2>_{n|n}
		TH1D* pd2_1sub_wght[NV][NR][NP]; // wght of <dcorr2>_{n|n}
		TH1D* pd4_1sub_mean[NV][NR][NP]; // mean of <dcorr4>_{n|n}
		TH1D* pd4_1sub_wght[NV][NR][NP]; // wght of <dcorr4>_{n|n}

		// 3-subevent
		TH1D* cnt_3sub[NA][NR];
		TH1D* pc2_1_3sub_mean[NA][NV][NR]; // mean of <2>_{a|b}
		TH1D* pc2_1_3sub_wght[NA][NV][NR]; // weight for <2>_{a|b}
		TH1D* pc2_2_3sub_mean[NA][NV][NR]; // mean of <2>_{a|c}
		TH1D* pc2_2_3sub_wght[NA][NV][NR]; // weight for <2>_{a|c}
		TH1D* pc4_3sub_mean[NA][NV][NR]; // mean of <4>_{a,a|b,c}
		TH1D* pc4_3sub_wght[NA][NV][NR]; // weight of <4>_{a,a|b,c}
		TH1D* psc4_3sub_mean[NA][NV][NR]; // mean of <4>_{a,a|b,c}
		TH1D* psc4_3sub_wght[NA][NV][NR]; // weight of <4>_{a,a|b,c}
		TH1D* pac3_3sub_mean[NA][NV][NR]; // mean of <4>_{a,a|b,c}
		TH1D* pac3_3sub_wght[NA][NV][NR]; // weight of <4>_{a,a|b,c}

		MultiCorr();
		~MultiCorr();
		void fill_1sub(Event*);
		void fill_1sub_BG(vector<Event*>);
		void fill_1sub_diff(Event*);
		void fill_3sub(Event*);
		void writeHist(TFile*&);
};

#endif
