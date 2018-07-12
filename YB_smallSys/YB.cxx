#include "YB.h"

void YB()
{
	initialize();

	for(unsigned int iF=0; iF<NF; iF++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iP=0; iP<NP; iP++)
			{
				detSts(cumu_1sub[1][iF][iV][iP],iF);
				detSts(cumu_3sub[1][iF][iV][iP],iF);
			}
		}
	}

	TFile* fOut = new TFile("PLOT/canvas.root","RECREATE");
	fOut->cd();
	for(unsigned int iF=0; iF<NF; iF++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iP=0; iP<NP; iP++)
			{
				draw_graph(cumu_1sub[0][iF][iV][iP],cumu_3sub[0][iF][iV][iP],cumu_3sub[1][iF][iV][iP],iF,iV,iP);
			}
		}
	}
	fOut->Close();
}

void initialize()
{
	TFile* fIn;
	for(unsigned int iF=0; iF<NF; iF++)
	{
		if(iF==0) fIn = new TFile("INPUT/5TeVplot.root","READ");
		if(iF==1) fIn = new TFile("INPUT/13TeVplot.root","READ");
		if(iF==2) fIn = new TFile("INPUT/5TeVpPbCombplot.root","READ");
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iP=0; iP<NP; iP++)
			{
				for(unsigned int iY=0; iY<2; iY++)
				{
					sprintf(name,"cNNNN_w1_h%d_pa%d_pb%d",iV,iP,0); cumu_1sub[iY][iF][iV][iP] = (TGraphErrors*)fIn->Get(name);
					sprintf(name,"cABAC_w1_h%d_pa%d_pb%d",iV,iP,0); cumu_3sub[iY][iF][iV][iP] = (TGraphErrors*)fIn->Get(name);
				}
			}
		}
	}
}

void detSts(TGraphErrors* gSts, int iF)
{
	double scaleFactor = pow(lumiRun3[iF]/lumiRun2[iF],1./2);
	for(int i=0; i<gSts->GetN(); i++)
	{
		double yErr = gSts->GetErrorY(i);
		gSts->SetPointError(i,0,scaleFactor*yErr);
	}
}

void draw_graph(TGraphErrors* g1, TGraphErrors* g2, TGraphErrors* g3, int iF, int iV, int iP)
{
	styleGraph(g1,0);
	styleGraph(g2,1);
	styleGraph(g3,2);

	TLatex* tex = new TLatex();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine* lin = new TLine();
	lin->SetLineColor(1);
	lin->SetLineStyle(2);
	lin->SetLineWidth(2);
	TLegend* leg = new TLegend(0.5, 0.5, 0.9, 0.9);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->SetTextFont(42);
	leg->AddEntry(g1,"Run 2 0.9 pb^{-1}, standard","lpfe");
	leg->AddEntry(g2,"Run 2 0.9 pb^{-1}, 3-subevent","lpfe");
	leg->AddEntry(g3,"Run 3,4 200 pb^{-1}, 3-subevent","lpfe");

	TH1D* hAxis = new TH1D("hAxis","",1000,0,200);
	for(int i=0; i<1000; i++) hAxis->SetBinContent(i+1,1E9);
	styleGraph(hAxis,0);
	TCanvas* cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0.0001);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.075);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.025);
	hAxis->GetXaxis()->SetTitle("N_{ch} (p_{T} > 0.4 GeV)");
	hAxis->GetXaxis()->SetTitleOffset(1.15);
	hAxis->GetXaxis()->SetRangeUser(0,200);
	sprintf(name,"c_{%d}{4}",iV+2);
	hAxis->GetYaxis()->SetTitle(name);
	hAxis->GetYaxis()->SetTitleOffset(1.6);
	hAxis->GetYaxis()->SetRangeUser(-4e-6, 5e-6);
	hAxis->Draw();
	g1->Draw("P");
	g2->Draw("P");
	g3->Draw("F");
	tex->DrawLatex(0.175,0.875,"#font[72]{ATLAS} #font[42]{Internal}");
	if(iF==0) tex->DrawLatex(0.175,0.82,"#font[42]{pp #sqrt{#it{s}}=5.02 TeV}");
	if(iF==1) tex->DrawLatex(0.175,0.82,"#font[42]{pp #sqrt{#it{s}}=13 TeV}");
	if(iF==2) tex->DrawLatex(0.175,0.82,"#font[42]{p+Pb #sqrt{#it{s}}=5.02 TeV}");
	if(iP==0) sprintf(name,"#font[42]{|#eta|<2.5   0.3<p_{T}<3.0 GeV}");
	if(iP==1) sprintf(name,"#font[42]{|#eta|<2.5   0.5<p_{T}<5.0 GeV}");
	tex->DrawLatex(0.175,0.76,name);
	lin->DrawLine(0,0,200,0);
	leg->Draw();

	sprintf(name,"PLOT/c_%d_4_Sys%d_Pt%d.pdf",iV,iF,iP);
	cOut->Print(name);
	sprintf(name,"c_%d_4_Sys%d_Pt%d",iV,iF,iP);
	cOut->SetName(name);
	cOut->Write();

	delete hAxis;
	delete cOut;
}


void styleGraph(TH1D* hIn, int k)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(18);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(18);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(18);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(18);
	hIn->SetMarkerStyle(mS[k]);
	hIn->SetMarkerColor(mC[k]);
	hIn->SetLineStyle(lS[k]);
	hIn->SetLineColor(lC[k]);
	hIn->SetLineWidth(2);
}

void styleGraph(TGraph* hIn, int k)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->SetNdivisions(505);
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
	hIn->SetMarkerStyle(mS[k]);
	hIn->SetMarkerColor(mC[k]);
	hIn->SetLineStyle(lS[k]);
	hIn->SetLineColor(lC[k]);
	hIn->SetLineWidth(2);
}
