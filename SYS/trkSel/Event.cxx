#include "Event.h"

Event::Event(TChain* treeIn)
{
	treeIn->SetBranchAddress("runNo",           &m_runNo);
	treeIn->SetBranchAddress("lbNo",            &m_lbNo);
	treeIn->SetBranchAddress("bcid",            &m_bcid);
	treeIn->SetBranchAddress("isPassGRL",       &m_isPassGRL);
	treeIn->SetBranchAddress("isPassErrState",  &m_isPassErrState);
	treeIn->SetBranchAddress("isPassPileup",    &m_isPassPileup);
	treeIn->SetBranchAddress("isPassVTE4",      &m_isPassVTE4);
	treeIn->SetBranchAddress("psVTE4",          &m_psVTE4);
	treeIn->SetBranchAddress("isPassTE4",       &m_isPassTE4);
	treeIn->SetBranchAddress("psTE4",           &m_psTE4);
	treeIn->SetBranchAddress("fcalEt",          &m_fcalEt);
	treeIn->SetBranchAddress("fcalEtA",         &m_fcalEtA);
	treeIn->SetBranchAddress("fcalEtC",         &m_fcalEtC);
	treeIn->SetBranchAddress("hasPriVtx",       &m_hasPriVtx);
	treeIn->SetBranchAddress("zPriVtx",         &m_zPriVtx);
	treeIn->SetBranchAddress("isPassGap",       &m_isPassGap);
	treeIn->SetBranchAddress("etaGap",          &m_etaGap);
	treeIn->SetBranchAddress("nTrk",            &m_nTrk);
	treeIn->SetBranchAddress("infoTrk",         m_infoTrk);

}

Event::~Event()
{
}

bool Event::isGoodEvent()
{
	if(!m_isPassGRL) return false;
	if(!m_isPassErrState) return false;
	if(!m_isPassPileup) return false;
	if(!m_isPassTE4) return false; // TE4 ONLY !
	if(!m_hasPriVtx) return false;
	if(fabs(m_zPriVtx)>=cutZvtx) return false;
	return true;
}

void Event::setEvent(Tool* tool)
{
	m_evtWght = 1.;

	m_cent = 0;
	for(int iC=0; iC<80; iC++)
	{
		if(m_fcalEt<cutCent[iC])
		{
			m_cent = 80-iC;
			break;
		}
	}

	unsigned int infoTmp = 0;
	double Qx[NVm][NR][NW] = {{{0}}}; 			double Qy[NVm][NR][NW] = {{{0}}};
	double px[NVm][NP][NW] = {{{0}}}; 			double py[NVm][NP][NW] = {{{0}}};
	double qx[NVm][NR][NP][NW] = {{{{0}}}}; double qy[NVm][NR][NP][NW] = {{{{0}}}};
	int tag3sub = 0; double Qx3sub[NVm][NR][3][NW] = {{{{0}}}}; double Qy3sub[NVm][NR][3][NW] = {{{{0}}}};
	memset(S,0,sizeof S); memset(m,0,sizeof m); memset(s,0,sizeof s);
	memset(nTrk3sub,0,sizeof nTrk3sub);
	for(unsigned int iT=0; iT<m_nTrk; iT++)
	{
		infoTmp = m_infoTrk[iT];
		m_trkPhi[iT] = detPhi(infoTmp & 0x3fff); infoTmp >>= 14;
		m_trkEta[iT] = detEta(infoTmp & 0xff);   infoTmp >>= 8;
		m_trkPt[iT]  = detPt(infoTmp & 0xff);    infoTmp >>= 8;
		m_trkQual[iT]= infoTmp & 0x1;            infoTmp >>= 1;
		m_trkChg[iT] = infoTmp & 0x1;

		double trkEff = tool->detTrkEff(m_cent,m_trkPt[iT],m_trkEta[iT]);
		double trkFak = tool->detTrkFak(m_cent,m_trkPt[iT],m_trkEta[iT]);
		double trkFla = tool->detFlat(m_cent,m_zPriVtx,m_trkChg[iT],m_trkPt[iT],m_trkEta[iT],m_trkPhi[iT]);
		m_trkWei[iT] = trkFla*(1-trkFak)/trkEff;

		if(fabs(m_trkEta[iT])>=cutEta) continue;
		//if(m_trkQual[iT]!=cutQual) continue; // loose track selection

		// Fill RFP
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iW=0; iW<NW; iW++)
			{
				if(m_trkPt[iT]<minPtRef[iR] || m_trkPt[iT]>=maxPtRef[iR]) continue;
				S[iR][iW] += pow(m_trkWei[iT],iW);
				tag3sub = detSubEvt(3,m_trkEta[iT]);
				if(tag3sub>=0) nTrk3sub[iR][tag3sub][iW] += pow(m_trkWei[iT],iW);
				for(unsigned int iV=0; iV<NVm; iV++)
				{
					Qx[iV][iR][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					Qy[iV][iR][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					if(tag3sub>=0)
					{
						Qx3sub[iV][iR][tag3sub][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
						Qy3sub[iV][iR][tag3sub][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					}
				}
			}
		}

		// Fill POI
		for(unsigned int iP=0; iP<NP; iP++)
		{
			if(m_trkPt[iT]<minPt[iP] || m_trkPt[iT]>=maxPt[iP]) continue;
			for(unsigned int iW=0; iW<NW; iW++)
			{
				m[iP][iW] += pow(m_trkWei[iT],iW);
				for(unsigned int iV=0; iV<NVm; iV++)
				{
					px[iV][iP][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					py[iV][iP][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
				}
			}
		}

		// Fill RFP&POI
		for(unsigned int iR=0; iR<NR; iR++)
		{
			if(m_trkPt[iT]<minPtRef[iR] || m_trkPt[iT]>=maxPtRef[iR]) continue;
			for(unsigned int iP=0; iP<NP; iP++)
			{
				if(m_trkPt[iT]<minPt[iP] || m_trkPt[iT]>=maxPt[iP]) continue;
				for(unsigned int iW=0; iW<NW; iW++)
				{
					s[iR][iP][iW] += pow(m_trkWei[iT],iW);
					for(unsigned int iV=0; iV<NVm; iV++)
					{
						qx[iV][iR][iP][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
						qy[iV][iR][iP][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					}
				}
			}
		}
	}

	for(unsigned int iV=0; iV<NVm; iV++)
	{
		for(unsigned int iW=0; iW<NW; iW++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				Q[iV][iR][iW] = TComplex(Qx[iV][iR][iW],Qy[iV][iR][iW]);
				for(int i=0; i<3; i++) Q3sub[iV][iR][i][iW] = TComplex(Qx3sub[iV][iR][i][iW],Qy3sub[iV][iR][i][iW]);
				for(unsigned int iP=0; iP<NP; iP++)
				{
					if(iR==0) p[iV][iP][iW] = TComplex(px[iV][iP][iW],py[iV][iP][iW]);
					q[iV][iR][iP][iW] = TComplex(qx[iV][iR][iP][iW],qy[iV][iR][iP][iW]);
				}
			}
		}
	}
}

int Event::detSubEvt(int numSubEvent, double eta)
{
	int tag = -1;
	switch(numSubEvent)
	{
		case 1:
			{
				tag = 0;
				return tag;
			}
		case 2:
			{
				if(eta<0-gapEta/2) tag = 0;
				else if(eta>=0+gapEta/2) tag = 1;
				else tag = -1;
				return tag;
			}
		case 3:
			{
				if(fabs(eta)<cutEta/3-gapEta/2) tag = 0;
				else if(eta< 0-cutEta/3.-gapEta/2.) tag = 1;
				else if(eta>=0+cutEta/3.+gapEta/2.) tag = 2;
				else tag = -1;
				return tag;
			}
		case 4:
			{
				if(eta<-cutEta/2.-gapEta/2.) tag = 0;
				else if(eta>=-cutEta/2.+gapEta/2. && eta<0-gapEta/2.) tag = 1;
				else if(eta>=0+gapEta/2. && eta<+cutEta/2.-gapEta/2.) tag = 2;
				else if(eta>=+cutEta/2.+gapEta/2.) tag = 3;
				else tag = -1;
				return tag;
			}
		default:
			{
				std::cout<<"Wrong number of subevents!"<<std::endl;
				return -1;
			}
	}
}
