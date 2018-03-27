#include "Plot.h"

Plot::Plot()
{
	initialize();
	execute();
	finalize();
}

Plot::~Plot()
{
}

void Plot::execute()
{
	TFile* fOut = new TFile("PLOT/canvas.root","RECREATE");
	fOut->cd();
	for(int iC=0; iC<NC; iC++)
	{
		for(int iZ=0; iZ<NZ; iZ++)
		{
			for(int iG=0; iG<NG; iG++)
			{
				for(int iP=0; iP<NP; iP++)
				{
					draw_2D(cor_eta_phi[iC][iZ][iG][iP],crr_eta_phi[iC][iZ][iG][iP],chk_eta_phi[iC][iZ][iG][iP],iC,iZ,iG,iP);
				}
			}
		}
	}
	fOut->Close();
}

void Plot::initialize()
{
	cout<<"initialize..."<<endl;

	TFile* fIn = new TFile("OUTPUT_Phase2/Phase2_All.root","READ");
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
					crr_eta_phi[iC][iZ][iG][iP] = (TH2D*)fIn->Get(name);
					sprintf(name,"chk_eta_phi_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
					chk_eta_phi[iC][iZ][iG][iP] = (TH2D*)fIn->Get(name);
				}
			}
		}
	}
}

void Plot::finalize()
{
	cout<<"finalize..."<<endl;
}

void Plot::draw_2D(TH2D* h0, TH2D* h1, TH2D* h2, int iC, int iZ, int iG, int iP)
{
	TH2D* hIn[3];
	hIn[0] = (TH2D*)h0->Clone("hIn_0");
	hIn[1] = (TH2D*)h1->Clone("hIn_1");
	hIn[2] = (TH2D*)h2->Clone("hIn_2");
	for(int i=0; i<3; i++) setStyle(hIn[i]);

	TLatex* tex = new TLatex();
	tex->SetTextSize(0.05);
	tex->SetTextAlign(12);
	tex->SetNDC(1);

	TCanvas* cOut = new TCanvas("cOut","",900,300);
	cOut->Divide(3,1,1E-4,1E-4);
	for(int iCan=0; iCan<3; iCan++)
	{
		cOut->cd(iCan+1);
		gStyle->SetOptStat(0);
		gStyle->SetNumberContours(100);
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.075);
		gPad->SetBottomMargin(0.15);
		gPad->SetLeftMargin(0.175);
		gPad->SetRightMargin(0.125);
		hIn[iCan]->GetXaxis()->SetTitle("#eta");
		hIn[iCan]->GetXaxis()->SetTitleOffset(1.1);
		hIn[iCan]->GetYaxis()->SetTitle("#phi");
		hIn[iCan]->GetYaxis()->SetTitleOffset(1.5);
		if(iCan==1) hIn[iCan]->GetZaxis()->SetRangeUser(0.76,1.3);
		hIn[iCan]->Draw("colz");
		tex->DrawLatex(0.2,0.875,"#font[72]{ATLAS} #font[42]{Internal}");
		if(iCan==0) tex->DrawLatex(0.2,0.825,"#font[42]{5.44 TeV Xe+Xe   Raw}");
		if(iCan==1) tex->DrawLatex(0.2,0.825,"#font[42]{5.44 TeV Xe+Xe   Weight}");
		if(iCan==2) tex->DrawLatex(0.2,0.825,"#font[42]{5.44 TeV Xe+Xe   Corrected}");
		sprintf(name,"#font[42]{(%d,%d) %d<z_{vtx}<%d %.1f<p_T<%.1f}",int(minCt[iC]),int(maxCt[iC]),int(minZv[iZ]),int(maxZv[iZ]),minPt[iP],maxPt[iP]);
		tex->DrawLatex(0.2,0.765,name);
	}

	sprintf(name,"PLOT/cumuFlat_Cent%d_Zvtx%d_Chg%d_Pt%d.pdf",iC,iZ,iG,iP);
	cOut->Print(name);
	sprintf(name,"cumuFlat_Cent%d_Zvtx%d_Chg%d_Pt%d",iC,iZ,iG,iP);
	cOut->SetName(name);
	cOut->Write();

	delete cOut;
}

void Plot::setStyle(TH2D* hIn)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->SetNdivisions(505);
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetNdivisions(505);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
}
