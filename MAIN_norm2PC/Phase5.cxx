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

	vector<TGraphErrors*> gVec;
	for(int i=0; i<3; i++) gVec.push_back(v2_2PC[i]);

	cal_norm(sts_cr42_1sub[2][0], sys_cr42_1sub[2][0], sts_v4_1sub[2][0], sts_v2_3sub[4][0], gVec, 0); // cr42
	cal_norm(sts_nsc_1sub[0][0], sys_nsc_1sub[0][0], sts_sc_1sub[0][0], sts_v2_3sub[4][0], gVec, 1); // sc_{2,3}
	cal_norm(sts_nsc_1sub[1][0], sys_nsc_1sub[1][0], sts_sc_1sub[1][0], sts_v2_3sub[4][0], gVec, 2); // sc_{2,4}
	cal_norm(sts_nac_1sub[2][0], sys_nac_1sub[2][0], sts_ac_1sub[2][0], sts_v2_3sub[4][0], gVec, 3); // ac_{2,4}
}

void Phase5::initialize(unsigned int iBin)
{
	cout<<"initialize..."<<endl;

	TFile* f2PC = new TFile("../INPUT/vn_2PC_graph.root","READ");
	v2_2PC[0] = (TGraphErrors*)f2PC->Get("vn_2PC_Har2");
	v2_2PC[1] = (TGraphErrors*)f2PC->Get("vn_2PC_Har3");
	v2_2PC[2] = (TGraphErrors*)f2PC->Get("vn_2PC_Har4");

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
			readHist_VR(fIn,sys_c2_3sub[iV][iR],"sys_c2_3sub","sys_c2_3sub",iV,iR);
			readHist_VR(fIn,sys_c4_3sub[iV][iR],"sys_c4_3sub","sys_c4_3sub",iV,iR);
			readHist_VR(fIn,sys_v2_3sub[iV][iR],"sys_v2_3sub","sys_v2_3sub",iV,iR);
			readHist_VR(fIn,sys_v4_3sub[iV][iR],"sys_v4_3sub","sys_v4_3sub",iV,iR);
			readHist_VR(fIn,sys_sc_3sub[iV][iR],"sys_sc_3sub","sys_sc_3sub",iV,iR);
			readHist_VR(fIn,sys_nsc_3sub[iV][iR],"sys_nsc_3sub","sys_nsc_3sub",iV,iR);
			readHist_VR(fIn,sys_ac_3sub[iV][iR],"sys_ac_3sub","sys_ac_3sub",iV,iR);
			readHist_VR(fIn,sys_nac_3sub[iV][iR],"sys_nac_3sub","sys_nac_3sub",iV,iR);
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
	fOut->Close();
}

void Phase5::cal_norm(TGraphErrors* gSts, TGraphAsymmErrors* gSys, TGraphErrors* gRef, TGraphErrors* gV4, vector<TGraphErrors*> gVec, int iOpt)
{
	int NB = gSts->GetN();
	for(int iB=0; iB<NB; iB++)
	{
		double x=0;
		double y=0;
		double ySts = 0;
		gSts->GetPoint(iB,x,ySts);
		gRef->GetPoint(iB,x,y);
		double v2 = fabs(gVec.at(0)->Eval(x));
		double v3 = fabs(gVec.at(1)->Eval(x));
		double v4 = fabs(gVec.at(2)->Eval(x));
		double v4_3sub = fabs(gV4->Eval(x));
		//cout<<iB<<": "<<v2<<" | "<<v3<<" | "<<v4<<" | "<<v4_3sub<<endl;
		if(iOpt==0 && v2!=0) y /= v2; // cr42
		if(iOpt==1 && v2*v3!=0) y /= pow(v2*v3,2); // sc_{2,3}
		if(iOpt==2 && v2*v4!=0) y /= pow(v2*v4,2); // sc_{2,4}
		if(iOpt==3 && v4!=0) y = ySts/(v4/v4_3sub); // ac_{2,4}
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







