#include "Tool.h"



Tool::Tool()
{
	TFile* fInFlat = new TFile("../../../../MON/FLAT/OUTPUT_Phase2/Phase2_All.root","READ");
	for(unsigned int iC=0; iC<NC_Flat; iC++)
	{
		for(unsigned int iZ=0; iZ<NZ_Flat; iZ++)
		{
			for(unsigned int iG=0; iG<NG_Flat; iG++)
			{
				for(unsigned int iP=0; iP<NP_Flat; iP++)
				{
					sprintf(name,"crr_eta_phi_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
					crrFlat_eta_phi[iC][iZ][iG][iP] = (TH2D*)fInFlat->Get(name);
				}
			}
		}
	}

	TFile* fInEff = new TFile("../../../../INPUT/trkEff.root","READ");
	allTrue = (TH3D*)fInEff->Get("allTrue");
	allReco = (TH3D*)fInEff->Get("allReco");
	matchedReco = (TH3D*)fInEff->Get("matchedReco");
	unMatchedReco = (TH3D*)fInEff->Get("unMatchedReco");
	matchedReco->Divide(allTrue);
	unMatchedReco->Divide(allReco);
}

Tool::~Tool()
{
}

double Tool::detFlat(double cent, double zVtx, int chg, double pt, double eta, double phi)
{
	int tagCent = -1;
	int tagZvtx = -1;
	int tagChg = -1;
	int tagPt = -1;
	int tagEta = -1;
	int tagPhi = -1;

	for(unsigned int iC=0; iC<NC_Flat; iC++)
	{
		if(cent>=minCt_Flat[iC] && cent<maxCt_Flat[iC])
		{
			tagCent = iC;
			break;
		}
	}
	if(tagCent<0) return 1;

	for(unsigned int iZ=0; iZ<NZ_Flat; iZ++)
	{
		if(zVtx>=minZv_Flat[iZ] && zVtx<maxZv_Flat[iZ])
		{
			tagZvtx = iZ;
			break;
		}
	}
	if(tagZvtx<0) return 1;

	tagChg = chg;

	for(unsigned int iP=0; iP<NP_Flat; iP++)
	{
		if(pt>=minPt_Flat[iP] && pt<maxPt_Flat[iP])
		{
			tagPt = iP;
			break;
		}
	}
	if(tagPt<0) return 1;

	int NETA = crrFlat_eta_phi[0][0][0][0]->GetNbinsX();
	int NPHI = crrFlat_eta_phi[0][0][0][0]->GetNbinsY(); 
	tagEta = int((eta+cutEta)/2./cutEta*NETA);
	if(tagEta<0 || tagEta>=NETA) return 1;
	tagPhi = int((phi+TMath::Pi())/2./TMath::Pi()*NPHI);
	if(tagPhi<0 || tagPhi>=NPHI) return 1;

	double weight = crrFlat_eta_phi[tagCent][tagZvtx][tagChg][tagPt]->GetBinContent(tagEta+1,tagPhi+1);
	if(weight<=0) return 1;
	else return weight;
}

double Tool::detTrkEff(double cent, double pt, double eta)
{
	if(cent>80) cent=80;
	double fcalEt = (cutCent[80-int(cent)]+cutCent[80-int(cent)+1])/2;

	if(pt<=0.5) return 0.4; // FIX
	if(pt>=10) return 0.75; // FIX

	int tagFcalEt = 0;
	int tagPt = 0;
	int tagEta = 0;
	for(int i=matchedReco->GetNbinsX(); i>0; i--)
	{
		if(fcalEt>matchedReco->GetXaxis()->GetBinLowEdge(i))
		{
			tagFcalEt = i-1;
			break;
		}
	}
	for(int i=matchedReco->GetNbinsY(); i>0; i--)
	{
		if(pt>matchedReco->GetYaxis()->GetBinLowEdge(i))
		{
			tagPt = i-1;
			break;
		}
	}
	for(int i=matchedReco->GetNbinsZ(); i>0; i--)
	{
		if(eta>matchedReco->GetZaxis()->GetBinLowEdge(i))
		{
			tagEta = i-1;
			break;
		}
	}

	return matchedReco->GetBinContent(tagFcalEt+1,tagPt+1,tagEta+1);
}

double Tool::detTrkFak(double cent, double pt, double eta)
{
	if(cent>80) cent=80;
	double fcalEt = (cutCent[80-int(cent)]+cutCent[80-int(cent)+1])/2;
	
	if(pt<=0.5) return 0; // FIX
	if(pt>=10) return 0; // FIX

	int tagFcalEt = 0;
	int tagPt = 0;
	int tagEta = 0;
	for(int i=unMatchedReco->GetNbinsX(); i>0; i--)
	{
		if(fcalEt>unMatchedReco->GetXaxis()->GetBinLowEdge(i))
		{
			tagFcalEt = i-1;
			break;
		}
	}
	for(int i=unMatchedReco->GetNbinsY(); i>0; i--)
	{
		if(pt>unMatchedReco->GetYaxis()->GetBinLowEdge(i))
		{
			tagPt = i-1;
			break;
		}
	}
	for(int i=unMatchedReco->GetNbinsZ(); i>0; i--)
	{
		if(eta>unMatchedReco->GetZaxis()->GetBinLowEdge(i))
		{
			tagEta = i-1;
			break;
		}
	}

	return unMatchedReco->GetBinContent(tagFcalEt+1,tagPt+1,tagEta+1);
}
