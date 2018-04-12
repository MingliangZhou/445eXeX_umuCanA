#include "Phase5.h"

Phase5::Phase5(unsigned int iBin)
{
	initialize(iBin);
	execute();
	finalize(iBin);
}

Phase5::~Phase5()
{
}

void Phase5::execute()
{
	cout<<"execute..."<<endl;

	double x[24] = {0};
	double y[24] = {0};
	for(int i=0; i<24; i++)
	{
		x[i] = (np_cent[i]+np_cent[i+1])/2;
		y[i] = np_np[i];
	}
	gCvt_Cent_Npart = new TGraph(24,x,y);
	gCvt_Cent_Npart->SetName("gCvt_Cent_Npart");


	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			cvt_Npart(gCvt_Cent_Npart,sts_c2_1sub[iV][iR],sys_c2_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_c4_1sub[iV][iR],sys_c4_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_c6_1sub[iV][iR],sys_c6_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_nc4_1sub[iV][iR],sys_nc4_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_nc6_1sub[iV][iR],sys_nc6_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_v2_1sub[iV][iR],sys_v2_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_v4_1sub[iV][iR],sys_v4_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_v6_1sub[iV][iR],sys_v6_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_cr42_1sub[iV][iR],sys_cr42_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_cr64_1sub[iV][iR],sys_cr64_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_sc_1sub[iV][iR],sys_sc_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_nsc_1sub[iV][iR],sys_nsc_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_ac_1sub[iV][iR],sys_ac_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_nac_1sub[iV][iR],sys_nac_1sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_c2_3sub[iV][iR],sys_c2_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_c4_3sub[iV][iR],sys_c4_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_v2_3sub[iV][iR],sys_v2_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_v4_3sub[iV][iR],sys_v4_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_sc_3sub[iV][iR],sys_sc_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_nsc_3sub[iV][iR],sys_nsc_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_ac_3sub[iV][iR],sys_ac_3sub[iV][iR]);
			cvt_Npart(gCvt_Cent_Npart,sts_nac_3sub[iV][iR],sys_nac_3sub[iV][iR]);
		}
	}
}

void Phase5::initialize(unsigned int iBin)
{
	cout<<"initialize..."<<endl;

	sprintf(name,"../OUTPUT/Phase4/hist_XeXe544_binCent_bin%d.root",iBin);
	TFile* fIn = new TFile(name,"READ");
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			readHist_VR(fIn,sts_c2_1sub[iV][iR],"sts_c2_1sub","sts_c2_1sub",iV,iR);
			readHist_VR(fIn,sts_c4_1sub[iV][iR],"sts_c4_1sub","sts_c4_1sub",iV,iR);
			readHist_VR(fIn,sts_c6_1sub[iV][iR],"sts_c6_1sub","sts_c6_1sub",iV,iR);
			readHist_VR(fIn,sts_nc4_1sub[iV][iR],"sts_nc4_1sub","sts_nc4_1sub",iV,iR);
			readHist_VR(fIn,sts_nc6_1sub[iV][iR],"sts_nc6_1sub","sts_nc6_1sub",iV,iR);
			readHist_VR(fIn,sts_v2_1sub[iV][iR],"sts_v2_1sub","sts_v2_1sub",iV,iR);
			readHist_VR(fIn,sts_v4_1sub[iV][iR],"sts_v4_1sub","sts_v4_1sub",iV,iR);
			readHist_VR(fIn,sts_v6_1sub[iV][iR],"sts_v6_1sub","sts_v6_1sub",iV,iR);
			readHist_VR(fIn,sts_cr42_1sub[iV][iR],"sts_cr42_1sub","sts_cr42_1sub",iV,iR);
			readHist_VR(fIn,sts_cr64_1sub[iV][iR],"sts_cr64_1sub","sts_cr64_1sub",iV,iR);
			readHist_VR(fIn,sts_sc_1sub[iV][iR],"sts_sc_1sub","sts_sc_1sub",iV,iR);
			readHist_VR(fIn,sts_nsc_1sub[iV][iR],"sts_nsc_1sub","sts_nsc_1sub",iV,iR);
			readHist_VR(fIn,sts_ac_1sub[iV][iR],"sts_ac_1sub","sts_ac_1sub",iV,iR);
			readHist_VR(fIn,sts_nac_1sub[iV][iR],"sts_nac_1sub","sts_nac_1sub",iV,iR);
			readHist_VR(fIn,sts_c2_3sub[iV][iR],"sts_c2_3sub","sts_c2_3sub",iV,iR);
			readHist_VR(fIn,sts_c4_3sub[iV][iR],"sts_c4_3sub","sts_c4_3sub",iV,iR);
			readHist_VR(fIn,sts_v2_3sub[iV][iR],"sts_v2_3sub","sts_v2_3sub",iV,iR);
			readHist_VR(fIn,sts_v4_3sub[iV][iR],"sts_v4_3sub","sts_v4_3sub",iV,iR);
			readHist_VR(fIn,sts_sc_3sub[iV][iR],"sts_sc_3sub","sts_sc_3sub",iV,iR);
			readHist_VR(fIn,sts_nsc_3sub[iV][iR],"sts_nsc_3sub","sts_nsc_3sub",iV,iR);
			readHist_VR(fIn,sts_ac_3sub[iV][iR],"sts_ac_3sub","sts_ac_3sub",iV,iR);
			readHist_VR(fIn,sts_nac_3sub[iV][iR],"sts_nac_3sub","sts_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC(fIn,sts_vd2_1sub[iV][iR][iC],"sts_vd2_1sub","sts_vd2_1sub",iV,iR,iC);
				readHist_VRC(fIn,sts_vd4_1sub[iV][iR][iC],"sts_vd4_1sub","sts_vd4_1sub",iV,iR,iC);
			}
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			readHist_VR(fIn,sys_c2_1sub[iV][iR],"sys_c2_1sub","sys_c2_1sub",iV,iR);
			readHist_VR(fIn,sys_c4_1sub[iV][iR],"sys_c4_1sub","sys_c4_1sub",iV,iR);
			readHist_VR(fIn,sys_c6_1sub[iV][iR],"sys_c6_1sub","sys_c6_1sub",iV,iR);
			readHist_VR(fIn,sys_nc4_1sub[iV][iR],"sys_nc4_1sub","sys_nc4_1sub",iV,iR);
			readHist_VR(fIn,sys_nc6_1sub[iV][iR],"sys_nc6_1sub","sys_nc6_1sub",iV,iR);
			readHist_VR(fIn,sys_v2_1sub[iV][iR],"sys_v2_1sub","sys_v2_1sub",iV,iR);
			readHist_VR(fIn,sys_v4_1sub[iV][iR],"sys_v4_1sub","sys_v4_1sub",iV,iR);
			readHist_VR(fIn,sys_v6_1sub[iV][iR],"sys_v6_1sub","sys_v6_1sub",iV,iR);
			readHist_VR(fIn,sys_cr42_1sub[iV][iR],"sys_cr42_1sub","sys_cr42_1sub",iV,iR);
			readHist_VR(fIn,sys_cr64_1sub[iV][iR],"sys_cr64_1sub","sys_cr64_1sub",iV,iR);
			readHist_VR(fIn,sys_sc_1sub[iV][iR],"sys_sc_1sub","sys_sc_1sub",iV,iR);
			readHist_VR(fIn,sys_nsc_1sub[iV][iR],"sys_nsc_1sub","sys_nsc_1sub",iV,iR);
			readHist_VR(fIn,sys_ac_1sub[iV][iR],"sys_ac_1sub","sys_ac_1sub",iV,iR);
			readHist_VR(fIn,sys_nac_1sub[iV][iR],"sys_nac_1sub","sys_nac_1sub",iV,iR);
			readHist_VR(fIn,sys_c2_3sub[iV][iR],"sys_c2_1sub","sys_c2_3sub",iV,iR);
			readHist_VR(fIn,sys_c4_3sub[iV][iR],"sys_c4_1sub","sys_c4_3sub",iV,iR);
			readHist_VR(fIn,sys_v2_3sub[iV][iR],"sys_v2_1sub","sys_v2_3sub",iV,iR);
			readHist_VR(fIn,sys_v4_3sub[iV][iR],"sys_v4_1sub","sys_v4_3sub",iV,iR);
			readHist_VR(fIn,sys_sc_3sub[iV][iR],"sys_sc_1sub","sys_sc_3sub",iV,iR);
			readHist_VR(fIn,sys_nsc_3sub[iV][iR],"sys_nsc_1sub","sys_nsc_3sub",iV,iR);
			readHist_VR(fIn,sys_ac_3sub[iV][iR],"sys_ac_1sub","sys_ac_3sub",iV,iR);
			readHist_VR(fIn,sys_nac_3sub[iV][iR],"sys_nac_1sub","sys_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC(fIn,sys_vd2_1sub[iV][iR][iC],"sys_vd2_1sub","sys_vd2_1sub",iV,iR,iC);
				readHist_VRC(fIn,sys_vd4_1sub[iV][iR][iC],"sys_vd4_1sub","sys_vd4_1sub",iV,iR,iC);
			}
		}
	}
}

void Phase5::finalize(unsigned int iBin)
{
	cout<<"finalize..."<<endl;

	sprintf(name,"../OUTPUT/Phase5/hist_XeXe544_binCent_bin%d.root",iBin);
	TFile* fOut = new TFile(name,"RECREATE");
	fOut->cd();
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			sts_c2_1sub[iV][iR]->Write();
			sts_c4_1sub[iV][iR]->Write();
			sts_c6_1sub[iV][iR]->Write();
			sts_nc4_1sub[iV][iR]->Write();
			sts_nc6_1sub[iV][iR]->Write();
			sts_v2_1sub[iV][iR]->Write();
			sts_v4_1sub[iV][iR]->Write();
			sts_v6_1sub[iV][iR]->Write();
			sts_cr42_1sub[iV][iR]->Write();
			sts_cr64_1sub[iV][iR]->Write();
			sts_sc_1sub[iV][iR]->Write();
			sts_nsc_1sub[iV][iR]->Write();
			sts_ac_1sub[iV][iR]->Write();
			sts_nac_1sub[iV][iR]->Write();
			sts_c2_3sub[iV][iR]->Write();
			sts_c4_3sub[iV][iR]->Write();
			sts_v2_3sub[iV][iR]->Write();
			sts_v4_3sub[iV][iR]->Write();
			sts_sc_3sub[iV][iR]->Write();
			sts_nsc_3sub[iV][iR]->Write();
			sts_ac_3sub[iV][iR]->Write();
			sts_nac_3sub[iV][iR]->Write();
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				sts_vd2_1sub[iV][iR][iC]->Write();
				sts_vd4_1sub[iV][iR][iC]->Write();
			}
			
			sys_c2_1sub[iV][iR]->Write();
			sys_c4_1sub[iV][iR]->Write();
			sys_c6_1sub[iV][iR]->Write();
			sys_nc4_1sub[iV][iR]->Write();
			sys_nc6_1sub[iV][iR]->Write();
			sys_v2_1sub[iV][iR]->Write();
			sys_v4_1sub[iV][iR]->Write();
			sys_v6_1sub[iV][iR]->Write();
			sys_cr42_1sub[iV][iR]->Write();
			sys_cr64_1sub[iV][iR]->Write();
			sys_sc_1sub[iV][iR]->Write();
			sys_nsc_1sub[iV][iR]->Write();
			sys_ac_1sub[iV][iR]->Write();
			sys_nac_1sub[iV][iR]->Write();
			sys_c2_3sub[iV][iR]->Write();
			sys_c4_3sub[iV][iR]->Write();
			sys_v2_3sub[iV][iR]->Write();
			sys_v4_3sub[iV][iR]->Write();
			sys_sc_3sub[iV][iR]->Write();
			sys_nsc_3sub[iV][iR]->Write();
			sys_ac_3sub[iV][iR]->Write();
			sys_nac_3sub[iV][iR]->Write();
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				sys_vd2_1sub[iV][iR][iC]->Write();
				sys_vd4_1sub[iV][iR][iC]->Write();
			}
		}
	}
	gCvt_Cent_Npart->Write();
	fOut->Close();
}

void Phase5::cvt_Npart(TGraph* gCvt, TGraphErrors* gSts, TGraphAsymmErrors* gSys)
{
	int NB = gSts->GetN();
	for(int iB=0; iB<NB; iB++)
	{
		double x=0;
		double y=0;
		gSts->GetPoint(iB,x,y);
		x = gCvt->Eval(x);
		gSts->SetPoint(iB,x,y);
		gSys->SetPoint(iB,x,y);
	}
}

void Phase5::readHist_VR(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d",hNewName,iV,iR);
	hIn->SetName(name);
}

void Phase5::readHist_VR(TFile* fIn, TGraphAsymmErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphAsymmErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d",hNewName,iV,iR);
	hIn->SetName(name);
}

void Phase5::readHist_VRC(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hNewName,iV,iR,iC);
	hIn->SetName(name);
}

void Phase5::readHist_VRC(TFile* fIn, TGraphAsymmErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphAsymmErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hNewName,iV,iR,iC);
	hIn->SetName(name);
}







