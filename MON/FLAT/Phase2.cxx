#include "Phase2.h"

Phase2::Phase2()
{
	initialize();
	execute();
	finalize();
}

Phase2::~Phase2()
{
}

void Phase2::execute()
{
	cout<<"execute..."<<endl;

	for(int iC=0; iC<NC; iC++)
	{
		for(int iZ=0; iZ<NZ; iZ++)
		{
			for(int iG=0; iG<NG; iG++)
			{
				for(int iP=0; iP<NP; iP++)
				{
					cal_flat(cor_eta_phi[iC][iZ][iG][iP],crr_eta_phi[iC][iZ][iG][iP]);
					chk_flat(cor_eta_phi[iC][iZ][iG][iP],crr_eta_phi[iC][iZ][iG][iP],chk_eta_phi[iC][iZ][iG][iP]);
				}
			}
		}
	}
}

void Phase2::initialize()
{
	cout<<"initialize..."<<endl;

	TFile* fIn = new TFile("OUTPUT_Phase1/Phase1_All.root","READ");
	for(int iC=0; iC<NC; iC++)
	{
		for(int iZ=0; iZ<NZ; iZ++)
		{
			for(int iG=0; iG<NG; iG++)
			{
				for(int iP=0; iP<NP; iP++)
				{
					sprintf(name,"cor_eta_phi_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
					cor_eta_phi[iC][iZ][iG][iP] = (TH2D*)fIn->Get(name);
					sprintf(name,"crr_eta_phi_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
					crr_eta_phi[iC][iZ][iG][iP] = (TH2D*)cor_eta_phi[iC][iZ][iG][iP]->Clone(name);
					crr_eta_phi[iC][iZ][iG][iP]->Reset();
					sprintf(name,"chk_eta_phi_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
					chk_eta_phi[iC][iZ][iG][iP] = (TH2D*)cor_eta_phi[iC][iZ][iG][iP]->Clone(name);
					chk_eta_phi[iC][iZ][iG][iP]->Reset();

					//cout<<minCt[iC]<<","<<maxCt[iC]<<" | "<<minZv[iZ]<<","<<maxZv[iZ]<<" | "<<iG<<" | "<<minPt[iP]<<","<<maxPt[iP]<<" : "<<cor_eta_phi[iC][iZ][iG][iP]->GetEntries()<<endl;
				}
			}
		}
	}
}

void Phase2::finalize()
{
	cout<<"finalize..."<<endl;

	sprintf(name,"OUTPUT_Phase2/Phase2_All.root");
	TFile* fOut = new TFile(name,"RECREATE");
	fOut->cd();
	for(int iC=0; iC<NC; iC++)
	{
		for(int iZ=0; iZ<NZ; iZ++)
		{
			for(int iG=0; iG<NG; iG++)
			{
				for(int iP=0; iP<NP; iP++)
				{
					cor_eta_phi[iC][iZ][iG][iP]->Write();
					crr_eta_phi[iC][iZ][iG][iP]->Write();
					chk_eta_phi[iC][iZ][iG][iP]->Write();
				}
			}
		}
	}
	fOut->Close();
}

void Phase2::cal_flat(TH2D* hCor, TH2D* hCrr)
{
	int NX = hCor->GetNbinsX();
	int NY = hCor->GetNbinsY();
	for(int iX=0; iX<NX; iX++)
	{
		double sum = 0;
		for(int iY=0; iY<NY; iY++) sum += hCor->GetBinContent(iX+1,iY+1)/NY;
		for(int iY=0; iY<NY; iY++)
		{
			hCrr->SetBinContent(iX+1,iY+1,sum/hCor->GetBinContent(iX+1,iY+1));
		}
	}
}

void Phase2::chk_flat(TH2D* hCor, TH2D* hCrr, TH2D* hChk)
{
	int NX = hCor->GetNbinsX();
	int NY = hCor->GetNbinsY();
	for(int iX=0; iX<NX; iX++)
	{
		for(int iY=0; iY<NY; iY++)
		{
			double var = hCor->GetBinContent(iX+1,iY+1);
			double wei = hCrr->GetBinContent(iX+1,iY+1);
			hChk->SetBinContent(iX+1,iY+1,var*wei);
		}
	}
}






