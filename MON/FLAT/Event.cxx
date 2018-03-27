#include "Event.h"

Event::Event(TChain* treeIn)
{
	treeIn->SetBranchAddress("runNo",						&m_runNo);
	treeIn->SetBranchAddress("lbNo",						&m_lbNo);
	treeIn->SetBranchAddress("bcid",						&m_bcid);
	treeIn->SetBranchAddress("isPassGRL",				&m_isPassGRL);
	treeIn->SetBranchAddress("isPassErrState",	&m_isPassErrState);
	treeIn->SetBranchAddress("isPassPileup",		&m_isPassPileup);
	treeIn->SetBranchAddress("isPassVTE4",			&m_isPassVTE4);
	treeIn->SetBranchAddress("psVTE4",					&m_psVTE4);
	treeIn->SetBranchAddress("isPassTE4",				&m_isPassTE4);
	treeIn->SetBranchAddress("psTE4",						&m_psTE4);
	treeIn->SetBranchAddress("fcalEt",					&m_fcalEt);
	treeIn->SetBranchAddress("fcalEtA",					&m_fcalEtA);
	treeIn->SetBranchAddress("fcalEtC",					&m_fcalEtC);
	treeIn->SetBranchAddress("hasPriVtx",				&m_hasPriVtx);
	treeIn->SetBranchAddress("zPriVtx",					&m_zPriVtx);
	treeIn->SetBranchAddress("isPassGap",				&m_isPassGap);
	treeIn->SetBranchAddress("etaGap",					&m_etaGap);
	treeIn->SetBranchAddress("nTrk",						&m_nTrk);
	treeIn->SetBranchAddress("infoTrk",					m_infoTrk);
	
	mon_fcalEt = new TH1D("mon_fcalEt","",5000,-0.5,4.5);
	mon_cent = new TH1D("mon_cent","",100,0,100);
	mon_trkPt = new TH1D("mon_trkPt","",250,0,25);
	for(int iC=0; iC<NC; iC++)
	{
		for(int iZ=0; iZ<NZ; iZ++)
		{
			for(int iG=0; iG<NG; iG++)
			{
				for(int iP=0; iP<NP; iP++)
				{
					sprintf(name,"cor_eta_phi_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
					cor_eta_phi[iC][iZ][iG][iP] = new TH2D(name,"",50,-2.5,2.5,48,-TMath::Pi(),TMath::Pi());
					cor_eta_phi[iC][iZ][iG][iP]->Sumw2();
				}
			}
		}
	}
}

Event::~Event()
{
}

bool Event::isGoodEvent()
{
	if(!m_isPassGRL) return false;
	if(!m_isPassErrState) return false;
	if(!m_isPassPileup) return false;
	if(!m_isPassVTE4 && !m_isPassTE4) return false;
	if(!m_hasPriVtx) return false;
	if(fabs(m_zPriVtx)>=300) return false;
	if(!m_isPassGap) return false;
	return true;
}

void Event::setEvent()
{
	m_cent = 0;
	for(int iC=0; iC<80; iC++)
	{
		if(m_fcalEt<cutCent[iC]*0.65)
		{
			m_cent = 80-iC;
			break;
		}
	}

	unsigned int infoTmp = 0;
	for(int iT=0; iT<m_nTrk; iT++)
	{
		infoTmp = m_infoTrk[iT];
		m_trkPhi[iT] = detPhi(infoTmp & 0x3fff); infoTmp >>= 14;
		m_trkEta[iT] = detEta(infoTmp & 0xff);   infoTmp >>= 8;
		m_trkPt[iT]  = detPt(infoTmp & 0xff);    infoTmp >>= 8;
		m_trkQual[iT]= infoTmp & 0x1;            infoTmp >>= 1;
		m_trkChg[iT] = infoTmp & 0x1;
		m_trkWei[iT] = 1.;
	}
}

void Event::fillHist()
{
	int tagCent = -1;
	int tagZvtx = -1;
	int tagChg = -1;
	int tagPt = -1;
	for(int iC=0; iC<NC; iC++)
	{
		if(m_cent>=minCt[iC] && m_cent<maxCt[iC])
		{
			tagCent = iC;
			break;
		}
	}
	for(int iZ=0; iZ<NZ; iZ++)
	{
		if(m_zPriVtx>=minZv[iZ] && m_zPriVtx<maxZv[iZ])
		{
			tagZvtx = iZ;
			break;
		}
	}

	for(int iT=0; iT<m_nTrk; iT++)
	{
		if(fabs(m_trkEta[iT])>=cutEta) continue;
		if(m_trkQual[iT]!=1) continue;

		for(int iP=0; iP<NP; iP++)
		{
			if(m_trkPt[iT]>=minPt[iP] && m_trkPt[iT]<maxPt[iP])
			{
				tagPt = iP;
				break;
			}
		}
		tagChg = m_trkChg[iT];

		cor_eta_phi[tagCent][tagZvtx][tagChg][tagPt]->Fill(m_trkEta[iT],m_trkPhi[iT],m_trkWei[iT]);
		mon_trkPt->Fill(m_trkPt[iT]);
	}
	mon_fcalEt->Fill(m_fcalEt);
	mon_cent->Fill(m_cent);
}
