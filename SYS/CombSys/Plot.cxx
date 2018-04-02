#include "Plot.h"

Plot::Plot(unsigned int iBin)
{
	initialize(iBin);
	execute(iBin);
	finalize();
}

Plot::~Plot()
{
}

void Plot::execute(unsigned int iBin)
{
	cout<<"execute..."<<endl;

	sprintf(name,"../PLOT/bin%d/canvas.root",iBin);
	TFile* fOut = new TFile(name,"RECREATE");
	fOut->cd();
	vector<TGraphErrors*> gVec;

	// 0: c2_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c2_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_c2_1sub[iV][iR]);
			gVec.push_back(sysLw_c2_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,0,iBin);
			gVec.clear();
		}
	}

	// 1: c4_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c4_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_c4_1sub[iV][iR]);
			gVec.push_back(sysLw_c4_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,1,iBin);
			gVec.clear();
		}
	}

	// 2: c6_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c6_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_c6_1sub[iV][iR]);
			gVec.push_back(sysLw_c6_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,2,iBin);
			gVec.clear();
		}
	}

	// 3: nc4_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nc4_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_nc4_1sub[iV][iR]);
			gVec.push_back(sysLw_nc4_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,3,iBin);
			gVec.clear();
		}
	}

	// 4: nc6_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nc6_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_nc6_1sub[iV][iR]);
			gVec.push_back(sysLw_nc6_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,4,iBin);
			gVec.clear();
		}
	}

	// 5: v2_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v2_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_v2_1sub[iV][iR]);
			gVec.push_back(sysLw_v2_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,5,iBin);
			gVec.clear();
		}
	}

	// 6: v4_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v4_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_v4_1sub[iV][iR]);
			gVec.push_back(sysLw_v4_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,6,iBin);
			gVec.clear();
		}
	}

	// 7: v6_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v6_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_v6_1sub[iV][iR]);
			gVec.push_back(sysLw_v6_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,7,iBin);
			gVec.clear();
		}
	}

	// 8: cr42_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_cr42_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_cr42_1sub[iV][iR]);
			gVec.push_back(sysLw_cr42_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,8,iBin);
			gVec.clear();
		}
	}

	// 9: cr64_1sub
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_cr64_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_cr64_1sub[iV][iR]);
			gVec.push_back(sysLw_cr64_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,9,iBin);
			gVec.clear();
		}
	}

	// 10: sc_1sub
	for(unsigned int iV=0; iV<2; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_sc_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_sc_1sub[iV][iR]);
			gVec.push_back(sysLw_sc_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,10,iBin);
			gVec.clear();
		}
	}

	// 11: nsc_1sub
	for(unsigned int iV=0; iV<2; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nsc_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_nsc_1sub[iV][iR]);
			gVec.push_back(sysLw_nsc_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,11,iBin);
			gVec.clear();
		}
	}

	// 12: ac_1sub
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_ac_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_ac_1sub[iV][iR]);
			gVec.push_back(sysLw_ac_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,12,iBin);
			gVec.clear();
		}
	}

	// 13: nac_1sub
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nac_1sub[iS][iV][iR]);
			gVec.push_back(sysUp_nac_1sub[iV][iR]);
			gVec.push_back(sysLw_nac_1sub[iV][iR]);
			draw_graph(gVec,iV,iR,-1,13,iBin);
			gVec.clear();
		}
	}

	// 14: vd2_1sub
	for(unsigned int iV=2; iV<4; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_vd2_1sub[iS][iV][iR][iC]);
				gVec.push_back(sysUp_vd2_1sub[iV][iR][iC]);
				gVec.push_back(sysLw_vd2_1sub[iV][iR][iC]);
				draw_graph(gVec,iV,iR,iC,14,iBin);
				gVec.clear();
			}
		}
	}

	// 15: vd4_1sub
	for(unsigned int iV=2; iV<4; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_vd4_1sub[iS][iV][iR][iC]);
				gVec.push_back(sysUp_vd4_1sub[iV][iR][iC]);
				gVec.push_back(sysLw_vd4_1sub[iV][iR][iC]);
				draw_graph(gVec,iV,iR,iC,15,iBin);
				gVec.clear();
			}
		}
	}

	fOut->Close();
}

void Plot::initialize(unsigned int iBin)
{
	cout<<"initialize..."<<endl;

	sprintf(name,"../OUTPUT/Sys_bin%d.root",iBin);
	TFile* fIn = new TFile(name,"READ");

	for(unsigned int iS=0; iS<NS; iS++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				readHist_SVR(fIn,ratio_c2_1sub[iS][iV][iR],"ratio_c2_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_c4_1sub[iS][iV][iR],"ratio_c4_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_c6_1sub[iS][iV][iR],"ratio_c6_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_nc4_1sub[iS][iV][iR],"ratio_nc4_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_nc6_1sub[iS][iV][iR],"ratio_nc6_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_v2_1sub[iS][iV][iR],"ratio_v2_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_v4_1sub[iS][iV][iR],"ratio_v4_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_v6_1sub[iS][iV][iR],"ratio_v6_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_cr42_1sub[iS][iV][iR],"ratio_cr42_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_cr64_1sub[iS][iV][iR],"ratio_cr64_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_sc_1sub[iS][iV][iR],"ratio_sc_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_nsc_1sub[iS][iV][iR],"ratio_nsc_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_ac_1sub[iS][iV][iR],"ratio_ac_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_nac_1sub[iS][iV][iR],"ratio_nac_1sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_c2_3sub[iS][iV][iR],"ratio_c2_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_c4_3sub[iS][iV][iR],"ratio_c4_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_v2_3sub[iS][iV][iR],"ratio_v2_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_v4_3sub[iS][iV][iR],"ratio_v4_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_sc_3sub[iS][iV][iR],"ratio_sc_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_nsc_3sub[iS][iV][iR],"ratio_nsc_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_ac_3sub[iS][iV][iR],"ratio_ac_3sub",iS,iV,iR);
				readHist_SVR(fIn,ratio_nac_3sub[iS][iV][iR],"ratio_nac_3sub",iS,iV,iR);
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					readHist_SVRC(fIn,ratio_vd2_1sub[iS][iV][iR][iC],"ratio_vd2_1sub",iS,iV,iR,iC);
					readHist_SVRC(fIn,ratio_vd4_1sub[iS][iV][iR][iC],"ratio_vd4_1sub",iS,iV,iR,iC);
				}
			}
		}
	}

	for(unsigned int iS=0; iS<NS; iS++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				readHist_VR(fIn,sysUp_c2_1sub[iV][iR],"sysUp_c2_1sub",iV,iR);
				readHist_VR(fIn,sysUp_c4_1sub[iV][iR],"sysUp_c4_1sub",iV,iR);
				readHist_VR(fIn,sysUp_c6_1sub[iV][iR],"sysUp_c6_1sub",iV,iR);
				readHist_VR(fIn,sysUp_nc4_1sub[iV][iR],"sysUp_nc4_1sub",iV,iR);
				readHist_VR(fIn,sysUp_nc6_1sub[iV][iR],"sysUp_nc6_1sub",iV,iR);
				readHist_VR(fIn,sysUp_v2_1sub[iV][iR],"sysUp_v2_1sub",iV,iR);
				readHist_VR(fIn,sysUp_v4_1sub[iV][iR],"sysUp_v4_1sub",iV,iR);
				readHist_VR(fIn,sysUp_v6_1sub[iV][iR],"sysUp_v6_1sub",iV,iR);
				readHist_VR(fIn,sysUp_cr42_1sub[iV][iR],"sysUp_cr42_1sub",iV,iR);
				readHist_VR(fIn,sysUp_cr64_1sub[iV][iR],"sysUp_cr64_1sub",iV,iR);
				readHist_VR(fIn,sysUp_sc_1sub[iV][iR],"sysUp_sc_1sub",iV,iR);
				readHist_VR(fIn,sysUp_nsc_1sub[iV][iR],"sysUp_nsc_1sub",iV,iR);
				readHist_VR(fIn,sysUp_ac_1sub[iV][iR],"sysUp_ac_1sub",iV,iR);
				readHist_VR(fIn,sysUp_nac_1sub[iV][iR],"sysUp_nac_1sub",iV,iR);
				readHist_VR(fIn,sysUp_c2_3sub[iV][iR],"sysUp_c2_3sub",iV,iR);
				readHist_VR(fIn,sysUp_c4_3sub[iV][iR],"sysUp_c4_3sub",iV,iR);
				readHist_VR(fIn,sysUp_v2_3sub[iV][iR],"sysUp_v2_3sub",iV,iR);
				readHist_VR(fIn,sysUp_v4_3sub[iV][iR],"sysUp_v4_3sub",iV,iR);
				readHist_VR(fIn,sysUp_sc_3sub[iV][iR],"sysUp_sc_3sub",iV,iR);
				readHist_VR(fIn,sysUp_nsc_3sub[iV][iR],"sysUp_nsc_3sub",iV,iR);
				readHist_VR(fIn,sysUp_ac_3sub[iV][iR],"sysUp_ac_3sub",iV,iR);
				readHist_VR(fIn,sysUp_nac_3sub[iV][iR],"sysUp_nac_3sub",iV,iR);
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					readHist_VRC(fIn,sysUp_vd2_1sub[iV][iR][iC],"sysUp_vd2_1sub",iV,iR,iC);
					readHist_VRC(fIn,sysUp_vd4_1sub[iV][iR][iC],"sysUp_vd4_1sub",iV,iR,iC);
				}
				
				readHist_VR(fIn,sysLw_c2_1sub[iV][iR],"sysLw_c2_1sub",iV,iR);
				readHist_VR(fIn,sysLw_c4_1sub[iV][iR],"sysLw_c4_1sub",iV,iR);
				readHist_VR(fIn,sysLw_c6_1sub[iV][iR],"sysLw_c6_1sub",iV,iR);
				readHist_VR(fIn,sysLw_nc4_1sub[iV][iR],"sysLw_nc4_1sub",iV,iR);
				readHist_VR(fIn,sysLw_nc6_1sub[iV][iR],"sysLw_nc6_1sub",iV,iR);
				readHist_VR(fIn,sysLw_v2_1sub[iV][iR],"sysLw_v2_1sub",iV,iR);
				readHist_VR(fIn,sysLw_v4_1sub[iV][iR],"sysLw_v4_1sub",iV,iR);
				readHist_VR(fIn,sysLw_v6_1sub[iV][iR],"sysLw_v6_1sub",iV,iR);
				readHist_VR(fIn,sysLw_cr42_1sub[iV][iR],"sysLw_cr42_1sub",iV,iR);
				readHist_VR(fIn,sysLw_cr64_1sub[iV][iR],"sysLw_cr64_1sub",iV,iR);
				readHist_VR(fIn,sysLw_sc_1sub[iV][iR],"sysLw_sc_1sub",iV,iR);
				readHist_VR(fIn,sysLw_nsc_1sub[iV][iR],"sysLw_nsc_1sub",iV,iR);
				readHist_VR(fIn,sysLw_ac_1sub[iV][iR],"sysLw_ac_1sub",iV,iR);
				readHist_VR(fIn,sysLw_nac_1sub[iV][iR],"sysLw_nac_1sub",iV,iR);
				readHist_VR(fIn,sysLw_c2_3sub[iV][iR],"sysLw_c2_3sub",iV,iR);
				readHist_VR(fIn,sysLw_c4_3sub[iV][iR],"sysLw_c4_3sub",iV,iR);
				readHist_VR(fIn,sysLw_v2_3sub[iV][iR],"sysLw_v2_3sub",iV,iR);
				readHist_VR(fIn,sysLw_v4_3sub[iV][iR],"sysLw_v4_3sub",iV,iR);
				readHist_VR(fIn,sysLw_sc_3sub[iV][iR],"sysLw_sc_3sub",iV,iR);
				readHist_VR(fIn,sysLw_nsc_3sub[iV][iR],"sysLw_nsc_3sub",iV,iR);
				readHist_VR(fIn,sysLw_ac_3sub[iV][iR],"sysLw_ac_3sub",iV,iR);
				readHist_VR(fIn,sysLw_nac_3sub[iV][iR],"sysLw_nac_3sub",iV,iR);
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					readHist_VRC(fIn,sysLw_vd2_1sub[iV][iR][iC],"sysLw_vd2_1sub",iV,iR,iC);
					readHist_VRC(fIn,sysLw_vd4_1sub[iV][iR][iC],"sysLw_vd4_1sub",iV,iR,iC);
				}
			}
		}
	}
}

void Plot::finalize()
{
	cout<<"finalize..."<<endl;
}

void Plot::draw_graph(vector<TGraphErrors*> vIn, int iV, int iR, int iC, int iOpt, unsigned int iBin)
{
	int NG = vIn.size();
	TGraphErrors* gIn[10];
	for(int iG=0; iG<NG; iG++)
	{
		gIn[iG] = (TGraphErrors*)vIn.at(iG)->Clone("gIn");
		if(iG==0) styleGraph(gIn[iG],0);
		else styleGraph(gIn[iG],iG-1);
	}
	for(int iG=1; iG<NG; iG++)
	{
		for(int iB=0; iB<gIn[0]->GetN(); iB++) gIn[iG]->SetPointError(iB,0,0);
	}
	gIn[NG-2]->SetLineColor(kBlack);  gIn[NG-2]->SetLineWidth(4);
	gIn[NG-1]->SetLineColor(kBlack);  gIn[NG-1]->SetLineWidth(4);

	TLatex* tex = new TLatex();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine* lin = new TLine();
	lin->SetLineColor(1);
	lin->SetLineStyle(2);
	lin->SetLineWidth(2);
	TLegend* leg = new TLegend(0.15,0.125,0.95,0.25);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->SetNColumns(3);
	leg->AddEntry(gIn[0],"#font[42]{stat. err}","f");
	leg->AddEntry(gIn[1],"#font[42]{lower eff.}","p");
	leg->AddEntry(gIn[2],"#font[42]{higher eff.}","p");
	leg->AddEntry(gIn[3],"#font[42]{tight sel.}","p");
	leg->AddEntry(gIn[4],"#font[42]{pileup}","p");
	leg->AddEntry(gIn[5],"#font[42]{MC closure}","p");
	leg->AddEntry(gIn[6],"#font[42]{flattening}","p");
	leg->AddEntry(gIn[7],"#font[42]{Combined}","L");

	double xMin =  0;
	double xMax =  80;
	double yMin =  1;
	double yMax = -1;
	bool isCent;
	if(iOpt<=13) isCent = true;
	else
	{
		isCent = false;
		xMin = 0;
		xMax = 16;
	}
	for(int iG=0; iG<NG; iG++) getYrange(gIn[iG],yMin,yMax,isCent);
	double diff = yMax-yMin;
	yMax += 0.5*diff;
	yMin -= 0.5*diff;

	TH1D* hAxis = new TH1D("hAxis","",1000,xMin,xMax);
	for(int i=0; i<1000; i++) hAxis->SetBinContent(i+1,1E9);
	styleGraph(hAxis,0);

	TCanvas* cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0.0001);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.075);
	gPad->SetBottomMargin(0.1);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.025);
	if(iOpt<=13) hAxis->GetXaxis()->SetTitle("Centrality / %");
	else hAxis->GetXaxis()->SetTitle("p_{T} / GeV");
	hAxis->GetXaxis()->SetTitleOffset(1.15);
	hAxis->GetXaxis()->SetRangeUser(xMin,xMax);
	if(iOpt==0) sprintf(name,"c_{%d}{2}",iV);
	if(iOpt==1) sprintf(name,"c_{%d}{4}",iV);
	if(iOpt==2) sprintf(name,"c_{%d}{6}",iV);
	if(iOpt==3) sprintf(name,"#hat{c}_{%d}{4}",iV);
	if(iOpt==4) sprintf(name,"#hat{c}_{%d}{6}",iV);
	if(iOpt==5) sprintf(name,"v_{%d}{2}",iV);
	if(iOpt==6) sprintf(name,"v_{%d}{4}",iV);
	if(iOpt==7) sprintf(name,"v_{%d}{6}",iV);
	if(iOpt==8) sprintf(name,"v_{%d}{4} / v_{%d}{2}",iV,iV);
	if(iOpt==9) sprintf(name,"v_{%d}{6} / v_{%d}{4}",iV,iV);
	if(iOpt==10)
	{
		if(iV==0) sprintf(name,"SC(2,3)");
		if(iV==1) sprintf(name,"SC(2,4)");
	}
	if(iOpt==11)
	{
		if(iV==0) sprintf(name,"NSC(2,3)");
		if(iV==1) sprintf(name,"NSC(2,4)");
	}
	if(iOpt==12)
	{
		if(iV==2) sprintf(name,"AC(2,2,4)");
	}
	if(iOpt==13)
	{
		if(iV==2) sprintf(name,"NAC(2,2,4)");
	}
	if(iOpt==14) sprintf(name,"v_{%d}'{2}",iV);
	if(iOpt==15) sprintf(name,"v_{%d}'{4}",iV);
	hAxis->GetYaxis()->SetTitle(name);
	hAxis->GetYaxis()->SetTitleOffset(1.6);
	hAxis->GetYaxis()->SetRangeUser(yMin,yMax);
	hAxis->Draw();
	gIn[0]->SetFillColor(1);
	gIn[0]->SetFillStyle(3004);
	gIn[0]->Draw("E3");
	for(int iG=1; iG<NG-2; iG++) gIn[iG]->Draw("PL");
	gIn[NG-2]->Draw("L");
	gIn[NG-1]->Draw("L");
	tex->DrawLatex(0.175,0.875,"#font[72]{ATLAS} #font[62]{Internal}");
	tex->DrawLatex(0.175,0.82,"#font[42]{Xe+Xe #sqrt{s_{NN}}=5.44 TeV}");
	if(iOpt<=13) sprintf(name,"#font[42]{%.1f<p_{T}^{RFP}<%.1f GeV   standard}",minPtRef[iR],maxPtRef[iR]);
	else sprintf(name,"#font[42]{%.1f<p_{T}^{RFP}<%.1f GeV   (%d,%d)}",minPtRef[iR],maxPtRef[iR],int(xCent[iC]),int(xCent[iC+1]));
	tex->DrawLatex(0.175,0.76,name);
	lin->DrawLine(xMin,0,xMax,0);
	leg->Draw();

	if(iOpt==0) sprintf(name,"../PLOT/bin%d/sys_c2_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==1) sprintf(name,"../PLOT/bin%d/sys_c4_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==2) sprintf(name,"../PLOT/bin%d/sys_c6_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==3) sprintf(name,"../PLOT/bin%d/sys_nc4_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==4) sprintf(name,"../PLOT/bin%d/sys_nc6_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==5) sprintf(name,"../PLOT/bin%d/sys_v2_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==6) sprintf(name,"../PLOT/bin%d/sys_v4_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==7) sprintf(name,"../PLOT/bin%d/sys_v6_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==8) sprintf(name,"../PLOT/bin%d/sys_cr42_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==9) sprintf(name,"../PLOT/bin%d/sys_cr64_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==10) sprintf(name,"../PLOT/bin%d/sys_sc_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==11) sprintf(name,"../PLOT/bin%d/sys_nsc_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==12) sprintf(name,"../PLOT/bin%d/sys_ac_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==13) sprintf(name,"../PLOT/bin%d/sys_nac_1sub_Har%d_PtRef%d.pdf",iBin,iV,iR);
	if(iOpt==14) sprintf(name,"../PLOT/bin%d/sys_vd2_1sub_Har%d_PtRef%d_Cent%d.pdf",iBin,iV,iR,iC);
	if(iOpt==15) sprintf(name,"../PLOT/bin%d/sys_vd4_1sub_Har%d_PtRef%d_Cent%d.pdf",iBin,iV,iR,iC);
	cOut->Print(name);
	if(iOpt==0) sprintf(name,"sys_c2_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==1) sprintf(name,"sys_c4_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==2) sprintf(name,"sys_c6_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==3) sprintf(name,"sys_nc4_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==4) sprintf(name,"sys_nc6_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==5) sprintf(name,"sys_v2_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==6) sprintf(name,"sys_v4_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==7) sprintf(name,"sys_v6_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==8) sprintf(name,"sys_cr42_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==9) sprintf(name,"sys_cr64_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==10) sprintf(name,"sys_sc_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==11) sprintf(name,"sys_nsc_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==12) sprintf(name,"sys_ac_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==13) sprintf(name,"sys_nac_1sub_Har%d_PtRef%d",iV,iR);
	if(iOpt==14) sprintf(name,"sys_vd2_1sub_Har%d_PtRef%d_Cent%d",iV,iR,iC);
	if(iOpt==15) sprintf(name,"sys_vd4_1sub_Har%d_PtRef%d_Cent%d",iV,iR,iC);
	cOut->SetName(name);
	cOut->Write();

	delete hAxis;
	delete cOut;
}

void Plot::styleGraph(TGraph* hIn, int k)
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
	hIn->SetMarkerSize(1.2);
	hIn->SetLineWidth(2);
}

void Plot::styleGraph(TH1D* hIn, int k)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
	hIn->SetMarkerStyle(mS[k]);
	hIn->SetMarkerColor(mC[k]);
	hIn->SetLineStyle(lS[k]);
	hIn->SetLineColor(lC[k]);
	hIn->SetMarkerSize(1.2);
	hIn->SetLineWidth(2);
}

void Plot::getYrange(TGraph* hIn, double& yMin, double& yMax, bool isCent)
{
	double x; double y;
	for(int i=0; i<hIn->GetN(); i++)
	{
		hIn->GetPoint(i,x,y);
		if(isCent && x>80) continue;
		if(!isCent && x>20) continue;
		if(y<yMin) yMin = y;
		if(y>yMax) yMax = y;
	}
}

void Plot::readHist_SVR(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iS, int iV, int iR)
{
	sprintf(name,"%s_Sys%d_Har%d_PtRef%d",hName,iS,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
}

void Plot::readHist_SVRC(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iS, int iV, int iR, int iC)
{
	sprintf(name,"%s_Sys%d_Har%d_PtRef%d_Cent%d",hName,iS,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
}

void Plot::readHist_VR(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
}

void Plot::readHist_VRC(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
}
