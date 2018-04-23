#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TH1.h"
#include "TGraph.h"
#include "TGraphErrors.h"

void cvt_graph()
{
	char name[200];

	TH1D* hVn[3];
	TFile* fIn = new TFile("vn_2PC.root","READ");
	for(int iV=0; iV<3; iV++)
	{
		sprintf(name,"v%d_2PC",iV+2);
		hVn[iV] = (TH1D*)fIn->Get(name);
	}

	TGraphErrors* gVn[3];
	int NB = hVn[0]->GetNbinsX();
	double x[NB];
	double y[NB];
	double xErr[NB];
	double yErr[NB];
	for(int iV=0; iV<3; iV++)
	{
		for(int iB=0; iB<NB; iB++)
		{
			x[iB] = hVn[iV]->GetBinCenter(iB+1);
			y[iB] = hVn[iV]->GetBinContent(iB+1);
			xErr[iB] = 0;
			yErr[iB] = hVn[iV]->GetBinError(iB+1);
		}
		gVn[iV] = new TGraphErrors(NB,x,y,xErr,yErr);
		sprintf(name,"vn_2PC_Har%d",iV+2);
		gVn[iV]->SetName(name);
	}

	TFile* fOut = new TFile("vn_2PC_graph.root","RECREATE");
	fOut->cd();
	for(int iV=0; iV<3; iV++)
	{
		hVn[iV]->Write();
		gVn[iV]->Write();
	}
	fOut->Close();
}







