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

	// 0: v4_1sub
	for(unsigned int iS=1; iS<NS; iS++)
	{
		for(unsigned int iV=2; iV<4; iV++)
		{
			for(unsigned int iR=0; iR<1; iR++)
			{
				draw_sepa(v4_1sub[1][iS][iV][iR],v4_1sub[0][iS][iV][iR],ratio_v4_1sub[iS][iV][iR],iS,iV,iR,0,iBin);
			}
		}
	}

	// 1: nsc_1sub
	for(unsigned int iS=1; iS<NS; iS++)
	{
		for(unsigned int iV=0; iV<2; iV++)
		{
			for(unsigned int iR=0; iR<1; iR++)
			{
				draw_sepa(nsc_1sub[1][iS][iV][iR],nsc_1sub[0][iS][iV][iR],ratio_nsc_1sub[iS][iV][iR],iS,iV,iR,1,iBin);
			}
		}
	}

	// 2: nac_1sub
	for(unsigned int iS=1; iS<NS; iS++)
	{
		for(unsigned int iV=2; iV<3; iV++)
		{
			for(unsigned int iR=0; iR<1; iR++)
			{
				draw_sepa(nac_1sub[1][iS][iV][iR],nac_1sub[0][iS][iV][iR],ratio_nac_1sub[iS][iV][iR],iS,iV,iR,2,iBin);
			}
		}
	}


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

	for(unsigned int iF=0; iF<2; iF++)
	{
		for(unsigned int iS=0; iS<NS; iS++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				for(unsigned int iR=0; iR<NR; iR++)
				{
					readHist_FSVR(fIn,v4_1sub[iF][iS][iV][iR],"v4_1sub",iF,iS,iV,iR);
					readHist_FSVR(fIn,nsc_1sub[iF][iS][iV][iR],"nsc_3sub",iF,iS,iV,iR);
					readHist_FSVR(fIn,nac_1sub[iF][iS][iV][iR],"nac_3sub",iF,iS,iV,iR);
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
	TGraphErrors* gIn[15];
	for(int iG=0; iG<NG; iG++)
	{
		gIn[iG] = (TGraphErrors*)vIn.at(iG)->Clone("gIn");
		if(iG==0) styleGraph(gIn[iG],0);
		else styleGraph(gIn[iG],iG-1);
	}
	styleGraph(gIn[0],0);
	styleGraph(gIn[1],0);
	styleGraph(gIn[2],0);
	styleGraph(gIn[3],1);
	styleGraph(gIn[4],2);
	styleGraph(gIn[5],3);
	//styleGraph(gIn[6],4);
	styleGraph(gIn[7],2);
	//styleGraph(gIn[8],4);
	styleGraph(gIn[9],0);
	styleGraph(gIn[10],0);

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
	leg->AddEntry(gIn[1],"#font[42]{track eff.}","p");
	leg->AddEntry(gIn[3],"#font[42]{tight sel.}","p");
	leg->AddEntry(gIn[4],"#font[42]{cent. def.}","p");
	leg->AddEntry(gIn[5],"#font[42]{MC closure}","p");
	//leg->AddEntry(gIn[6],"#font[42]{event mix}","p");
	leg->AddEntry(gIn[9],"#font[42]{Combined}","L");

	double xMin =  0;
	double xMax =  80;
	double yMin =  1;
	double yMax = -1;
	bool isCent;
	if(iOpt<=13) isCent = true;
	else
	{
		isCent = false;
		xMin = 0.5;
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
	if(iOpt>13) gPad->SetLogx(1);
	else gPad->SetLogx(0);
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.075);
	gPad->SetBottomMargin(0.1);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.025);
	if(iOpt>13)
	{
		hAxis->GetXaxis()->SetMoreLogLabels();
		hAxis->GetXaxis()->SetNoExponent();
	}
	if(iOpt<=13) hAxis->GetXaxis()->SetTitle("Centrality [%]");
	else hAxis->GetXaxis()->SetTitle("p_{T} [GeV]");
	hAxis->GetXaxis()->SetTitleOffset(1.15);
	hAxis->GetXaxis()->SetRangeUser(xMin,xMax);
	if(iOpt==0) sprintf(name,"c_{%d}{2}",iV);
	if(iOpt==1) sprintf(name,"c_{%d}{4}",iV);
	if(iOpt==2) sprintf(name,"c_{%d}{6}",iV);
	if(iOpt==3) sprintf(name,"nc_{%d}{4}",iV);
	if(iOpt==4) sprintf(name,"nc_{%d}{6}",iV);
	if(iOpt==5) sprintf(name,"v_{%d}{2}",iV);
	if(iOpt==6) sprintf(name,"v_{%d}{4}",iV);
	if(iOpt==7) sprintf(name,"v_{%d}{6}",iV);
	if(iOpt==8) sprintf(name,"v_{%d}{4} / v_{%d}{2}",iV,iV);
	if(iOpt==9) sprintf(name,"v_{%d}{6} / v_{%d}{4}",iV,iV);
	if(iOpt==10)
	{
		if(iV==0) sprintf(name,"sc_{2,3}{4}");
		if(iV==1) sprintf(name,"sc_{2,4}{4}");
	}
	if(iOpt==11)
	{
		if(iV==0) sprintf(name,"nsc_{2,3}{4}");
		if(iV==1) sprintf(name,"nsc_{2,4}{4}");
	}
	if(iOpt==12)
	{
		if(iV==2) sprintf(name,"ac_{2,4}{3}");
	}
	if(iOpt==13)
	{
		if(iV==2) sprintf(name,"nac_{2,4}{3}");
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
	for(int iG=1; iG<NG-2; iG++)
	{
		if(iG==6 || iG==8) continue;
		gIn[iG]->Draw("PL");
	}
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

void Plot::draw_sepa(TGraphErrors* g0, TGraphErrors* g1, TGraphErrors* gR, int iS, int iV, int iR, int iOpt, unsigned int iBin)
{
	styleGraph(g0,0); styleGraph(g1,1); styleGraph(gR,0);
	for(int iB=0; iB<g1->GetN(); iB++)
	{
		double x; double y;
		g1->GetPoint(iB,x,y);
		x += 2;
		g1->SetPoint(iB,x,y);
	}

	TLatex* tex = new TLatex();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine* lin = new TLine();
	lin->SetLineColor(1);
	lin->SetLineStyle(2);
	lin->SetLineWidth(2);
	TLegend* leg = new TLegend(0.225,0.025,0.95,0.125);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->SetNColumns(2);
	if(iS==0)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{default}","p");
	}
	if(iS==1)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{low track eff.}","p");
	}
	if(iS==2)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{high track eff.}","p");
	}
	if(iS==3)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{tight track sel.}","p");
	}
	if(iS==4)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{83.5% cent.}","p");
	}
	if(iS==5)
	{
		leg->AddEntry(g0,"#font[42]{recon}","p");
		leg->AddEntry(g1,"#font[42]{truth}","p");
	}
	if(iS==6)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{mix narrow}","p");
	}
	if(iS==7)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{85.5% cent.}","p");
	}
	if(iS==8)
	{
		leg->AddEntry(g0,"#font[42]{default}","p");
		leg->AddEntry(g1,"#font[42]{mix wide}","p");
	}

	double xMin =  0;
	double xMax =  60;
	double yMin =  1;
	double yMax = -1;
	getYrange(g0,yMin,yMax,true);
	getYrange(g1,yMin,yMax,true);
	double diff = yMax-yMin;
	yMax += 0.5*diff;
	yMin -= 0.5*diff;

	TH1D* hAxis = new TH1D("hAxis","",1000,xMin,xMax);
	for(int i=0; i<1000; i++) hAxis->SetBinContent(i+1,1E9);
	styleGraph(hAxis,0);

	TCanvas* cOut = new TCanvas("cOut","",300,500);
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0.0001);
	cOut->cd();
	TPad* pad1 = new TPad("pad1","",0,0.3,1,1);
	pad1->Draw();
	pad1->cd();
	pad1->SetTicks(1,1);
	pad1->SetTopMargin(0.075);
	pad1->SetBottomMargin(0.01);
	pad1->SetLeftMargin(0.2);
	pad1->SetRightMargin(0.025);
	hAxis->GetXaxis()->SetTitle("Centrality [%]");
	hAxis->GetXaxis()->SetTitleOffset(5);
	hAxis->GetXaxis()->SetRangeUser(xMin,xMax);
	if(iOpt==0) sprintf(name,"v_{%d}{4}",iV);
	if(iOpt==1)
	{
		if(iV==0) sprintf(name,"nsc_{2,3}{4}");
		if(iV==1) sprintf(name,"nsc_{2,4}{4}");
	}
	if(iOpt==2)
	{
		if(iV==2) sprintf(name,"nac_{2,4}{3}");
	}
	hAxis->GetYaxis()->SetTitle(name);
	hAxis->GetYaxis()->SetTitleOffset(3.3);
	hAxis->GetYaxis()->SetRangeUser(yMin,yMax);
	hAxis->DrawCopy();
	g0->Draw("P");
	g1->Draw("P");
	tex->DrawLatex(0.25,0.875,"#font[72]{ATLAS} #font[62]{Internal}");
	tex->DrawLatex(0.25,0.82,"#font[42]{Xe+Xe #sqrt{s_{NN}}=5.44 TeV}");
	if(iOpt<=10) sprintf(name,"#font[42]{%.1f<p_{T}^{RFP}<%.1f GeV   standard}",minPtRef[iR],maxPtRef[iR]);
	else sprintf(name,"#font[42]{%.1f<p_{T}^{RFP}<%.1f GeV   3-subevent}",minPtRef[iR],maxPtRef[iR]);
	tex->DrawLatex(0.25,0.76,name);
	if(yMax>0 && yMin<0) lin->DrawLine(xMin,0,xMax,0);
	leg->Draw();
	cOut->cd();
	TPad* pad2 = new TPad("pad2","",0,0,1,0.3);
	pad2->Draw();
	pad2->cd();
	pad2->SetTicks(1,1);
	pad2->SetTopMargin(0.01);
	pad2->SetBottomMargin(0.2);
	pad2->SetLeftMargin(0.2);
	pad2->SetRightMargin(0.025);
	hAxis->GetXaxis()->SetTitle("Centrality [%]");
	hAxis->GetXaxis()->SetTitleOffset(2.7);
	hAxis->GetXaxis()->SetRangeUser(xMin,xMax);
	sprintf(name,"check / default - 1");
	hAxis->GetYaxis()->SetTitle(name);
	hAxis->GetYaxis()->SetTitleOffset(3.3);
	hAxis->GetYaxis()->SetRangeUser(-0.14,0.14);
	hAxis->DrawCopy();
	gR->Draw("P");
	lin->DrawLine(xMin,0,xMax,0);

	if(iOpt==0) sprintf(name,"../PLOT/bin%d/sys%d_v4_1sub_Har%d_PtRef%d.pdf",iBin,iS,iV,iR);
	if(iOpt==1) sprintf(name,"../PLOT/bin%d/sys%d_nsc_1sub_Har%d_PtRef%d.pdf",iBin,iS,iV,iR);
	if(iOpt==2) sprintf(name,"../PLOT/bin%d/sys%d_nac_1sub_Har%d_PtRef%d.pdf",iBin,iS,iV,iR);
	cOut->Print(name);
	if(iOpt==0) sprintf(name,"sys%d_v4_1sub_Har%d_PtRef%d",iS,iV,iR);
	if(iOpt==1) sprintf(name,"sys%d_nsc_1sub_Har%d_PtRef%d",iS,iV,iR);
	if(iOpt==2) sprintf(name,"sys%d_nac_1sub_Har%d_PtRef%d",iS,iV,iR);
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

void Plot::readHist_FSVR(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iF, int iS, int iV, int iR)
{
	sprintf(name,"%s_File%d_Sys%d_Har%d_PtRef%d",hName,iF,iS,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
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
