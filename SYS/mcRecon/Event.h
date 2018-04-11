#ifndef Event_H_
#define Event_H_

#include "Tool.h"

class Event
{
	private:
		unsigned int m_runNo;
		unsigned int m_lbNo;
		unsigned int m_bcid;
		bool m_isPassGRL;
		bool m_isPassErrState;
		bool m_isPassPileup;
		bool m_isPassVTE4;
		double m_psVTE4;
		bool m_isPassTE4;
		double m_psTE4;
		double m_fcalEt;
		float m_fcalEtA;
		float m_fcalEtC;
		bool m_hasPriVtx;
		double m_zPriVtx;
		bool m_isPassGap;
		double m_etaGap;
		unsigned int m_nTrk;
		unsigned int m_infoTrk[maxNtrk];

		double m_evtWght;
		double m_cent;
		double m_trkWei[maxNtrk]; // track weight
		double m_trkPt[maxNtrk]; // track pT
		double m_trkEta[maxNtrk]; // track eta
		double m_trkPhi[maxNtrk]; // track phi
		unsigned int m_trkQual[maxNtrk]; // track quality: &2 loose, &4 tight
		unsigned int m_trkChg[maxNtrk]; // track charge

		double detPt(unsigned int pt) { return (pt+0.5)/10.; }
		double detEta(unsigned int eta) { return (eta+0.5)/250.*2*cutEta-cutEta; }
		double detPhi(unsigned int phi) { return (phi+0.5)/pow(2,14)*2*TMath::Pi()-TMath::Pi(); }
		int detSubEvt(int, double); // determine the subevent tag: B, A, C


	public:
		double S[NR][NW]; 		TComplex Q[NVm][NR][NW]; // RFP
		double m[NP][NW]; 		TComplex p[NVm][NP][NW]; // POI
		double s[NR][NP][NW]; TComplex q[NVm][NR][NP][NW]; // RFP&POI
		double nTrk3sub[NR][3][NW]; TComplex Q3sub[NVm][NR][3][NW]; // harmonic | subevt | power of weight

		Event(TChain*);
		~Event();
		bool isGoodEvent();
		void setEvent(Tool*);
		double evtZvtx() const { return m_zPriVtx; }
		double evtCls() const { return m_cent; }
		double evtWght() const { return m_evtWght; }
};

#endif
