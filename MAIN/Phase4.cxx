#include "Phase4.h"

Phase4::Phase4(unsigned int iBin)
{
	initialize(iBin);
	execute();
	finalize(iBin);
}

Phase4::~Phase4()
{
}

void Phase4::execute()
{
	cout<<"execute..."<<endl;
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			combine(sts_c2_1sub[iV][iR],sysUp_c2_1sub[iV][iR],sysLw_c2_1sub[iV][iR],sys_c2_1sub[iV][iR],"sys_c2_1sub",iV,iR);
			combine(sts_c4_1sub[iV][iR],sysUp_c4_1sub[iV][iR],sysLw_c4_1sub[iV][iR],sys_c4_1sub[iV][iR],"sys_c4_1sub",iV,iR);
			combine(sts_c6_1sub[iV][iR],sysUp_c6_1sub[iV][iR],sysLw_c6_1sub[iV][iR],sys_c6_1sub[iV][iR],"sys_c6_1sub",iV,iR);
			combine(sts_nc4_1sub[iV][iR],sysUp_nc4_1sub[iV][iR],sysLw_nc4_1sub[iV][iR],sys_nc4_1sub[iV][iR],"sys_nc4_1sub",iV,iR);
			combine(sts_nc6_1sub[iV][iR],sysUp_nc6_1sub[iV][iR],sysLw_nc6_1sub[iV][iR],sys_nc6_1sub[iV][iR],"sys_nc6_1sub",iV,iR);
			combine(sts_v2_1sub[iV][iR],sysUp_v2_1sub[iV][iR],sysLw_v2_1sub[iV][iR],sys_v2_1sub[iV][iR],"sys_v2_1sub",iV,iR);
			combine(sts_v4_1sub[iV][iR],sysUp_v4_1sub[iV][iR],sysLw_v4_1sub[iV][iR],sys_v4_1sub[iV][iR],"sys_v4_1sub",iV,iR);
			combine(sts_v6_1sub[iV][iR],sysUp_v6_1sub[iV][iR],sysLw_v6_1sub[iV][iR],sys_v6_1sub[iV][iR],"sys_v6_1sub",iV,iR);
			combine(sts_cr42_1sub[iV][iR],sysUp_cr42_1sub[iV][iR],sysLw_cr42_1sub[iV][iR],sys_cr42_1sub[iV][iR],"sys_cr42_1sub",iV,iR);
			combine(sts_cr64_1sub[iV][iR],sysUp_cr64_1sub[iV][iR],sysLw_cr64_1sub[iV][iR],sys_cr64_1sub[iV][iR],"sys_cr64_1sub",iV,iR);
			combine(sts_sc_1sub[iV][iR],sysUp_sc_1sub[iV][iR],sysLw_sc_1sub[iV][iR],sys_sc_1sub[iV][iR],"sys_sc_1sub",iV,iR);
			combine(sts_nsc_1sub[iV][iR],sysUp_nsc_1sub[iV][iR],sysLw_nsc_1sub[iV][iR],sys_nsc_1sub[iV][iR],"sys_nsc_1sub",iV,iR);
			combine(sts_ac_1sub[iV][iR],sysUp_ac_1sub[iV][iR],sysLw_ac_1sub[iV][iR],sys_ac_1sub[iV][iR],"sys_ac_1sub",iV,iR);
			combine(sts_nac_1sub[iV][iR],sysUp_nac_1sub[iV][iR],sysLw_nac_1sub[iV][iR],sys_nac_1sub[iV][iR],"sys_nac_1sub",iV,iR);
			combine(sts_c2_3sub[iV][iR],sysUp_c2_3sub[iV][iR],sysLw_c2_3sub[iV][iR],sys_c2_3sub[iV][iR],"sys_c2_3sub",iV,iR);
			combine(sts_c4_3sub[iV][iR],sysUp_c4_3sub[iV][iR],sysLw_c4_3sub[iV][iR],sys_c4_3sub[iV][iR],"sys_c4_3sub",iV,iR);
			combine(sts_v2_3sub[iV][iR],sysUp_v2_3sub[iV][iR],sysLw_v2_3sub[iV][iR],sys_v2_3sub[iV][iR],"sys_v2_3sub",iV,iR);
			combine(sts_v4_3sub[iV][iR],sysUp_v4_3sub[iV][iR],sysLw_v4_3sub[iV][iR],sys_v4_3sub[iV][iR],"sys_v4_3sub",iV,iR);
			combine(sts_sc_3sub[iV][iR],sysUp_sc_3sub[iV][iR],sysLw_sc_3sub[iV][iR],sys_sc_3sub[iV][iR],"sys_sc_3sub",iV,iR);
			combine(sts_nsc_3sub[iV][iR],sysUp_nsc_3sub[iV][iR],sysLw_nsc_3sub[iV][iR],sys_nsc_3sub[iV][iR],"sys_nsc_3sub",iV,iR);
			combine(sts_ac_3sub[iV][iR],sysUp_ac_3sub[iV][iR],sysLw_ac_3sub[iV][iR],sys_ac_3sub[iV][iR],"sys_ac_3sub",iV,iR);
			combine(sts_nac_3sub[iV][iR],sysUp_nac_3sub[iV][iR],sysLw_nac_3sub[iV][iR],sys_nac_3sub[iV][iR],"sys_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				combine(sts_vd2_1sub[iV][iR][iC],sysUp_vd2_1sub[iV][iR][iC],sysLw_vd2_1sub[iV][iR][iC],sys_vd2_1sub[iV][iR][iC],"sys_vd2_1sub",iV,iR,iC);
				combine(sts_vd4_1sub[iV][iR][iC],sysUp_vd4_1sub[iV][iR][iC],sysLw_vd4_1sub[iV][iR][iC],sys_vd4_1sub[iV][iR][iC],"sys_vd4_1sub",iV,iR,iC);
			}

			trim(sts_c2_1sub[iV][iR],sys_c2_1sub[iV][iR]);
			trim(sts_c4_1sub[iV][iR],sys_c4_1sub[iV][iR]);
			trim(sts_c6_1sub[iV][iR],sys_c6_1sub[iV][iR]);
			trim(sts_nc4_1sub[iV][iR],sys_nc4_1sub[iV][iR]);
			trim(sts_nc6_1sub[iV][iR],sys_nc6_1sub[iV][iR]);
			trim(sts_v2_1sub[iV][iR],sys_v2_1sub[iV][iR]);
			trim(sts_v4_1sub[iV][iR],sys_v4_1sub[iV][iR]);
			trim(sts_v6_1sub[iV][iR],sys_v6_1sub[iV][iR]);
			trim(sts_cr42_1sub[iV][iR],sys_cr42_1sub[iV][iR]);
			trim(sts_cr64_1sub[iV][iR],sys_cr64_1sub[iV][iR]);
			trim(sts_sc_1sub[iV][iR],sys_sc_1sub[iV][iR]);
			trim(sts_nsc_1sub[iV][iR],sys_nsc_1sub[iV][iR]);
			trim(sts_ac_1sub[iV][iR],sys_ac_1sub[iV][iR]);
			trim(sts_nac_1sub[iV][iR],sys_nac_1sub[iV][iR]);
			trim(sts_c2_3sub[iV][iR],sys_c2_3sub[iV][iR]);
			trim(sts_c4_3sub[iV][iR],sys_c4_3sub[iV][iR]);
			trim(sts_v2_3sub[iV][iR],sys_v2_3sub[iV][iR]);
			trim(sts_v4_3sub[iV][iR],sys_v4_3sub[iV][iR]);
			trim(sts_sc_3sub[iV][iR],sys_sc_3sub[iV][iR]);
			trim(sts_nsc_3sub[iV][iR],sys_nsc_3sub[iV][iR]);
			trim(sts_ac_3sub[iV][iR],sys_ac_3sub[iV][iR]);
			trim(sts_nac_3sub[iV][iR],sys_nac_3sub[iV][iR]);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				trim(sts_vd2_1sub[iV][iR][iC],sys_vd2_1sub[iV][iR][iC]);
				trim(sts_vd4_1sub[iV][iR][iC],sys_vd4_1sub[iV][iR][iC]);
			}
		}
	}
}

void Phase4::initialize(unsigned int iBin)
{
	cout<<"initialize..."<<endl;

	sprintf(name,"../OUTPUT/Phase3/Phase3_bin%d.root",iBin);
	TFile* fSts = new TFile(name,"READ");
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			readHist_VR(fSts,sts_c2_1sub[iV][iR],"c2_1sub","sts_c2_1sub",iV,iR);
			readHist_VR(fSts,sts_c4_1sub[iV][iR],"c4_1sub","sts_c4_1sub",iV,iR);
			readHist_VR(fSts,sts_c6_1sub[iV][iR],"c6_1sub","sts_c6_1sub",iV,iR);
			readHist_VR(fSts,sts_nc4_1sub[iV][iR],"nc4_1sub","sts_nc4_1sub",iV,iR);
			readHist_VR(fSts,sts_nc6_1sub[iV][iR],"nc6_1sub","sts_nc6_1sub",iV,iR);
			readHist_VR(fSts,sts_v2_1sub[iV][iR],"v2_1sub","sts_v2_1sub",iV,iR);
			readHist_VR(fSts,sts_v4_1sub[iV][iR],"v4_1sub","sts_v4_1sub",iV,iR);
			readHist_VR(fSts,sts_v6_1sub[iV][iR],"v6_1sub","sts_v6_1sub",iV,iR);
			readHist_VR(fSts,sts_cr42_1sub[iV][iR],"cr42_1sub","sts_cr42_1sub",iV,iR);
			readHist_VR(fSts,sts_cr64_1sub[iV][iR],"cr64_1sub","sts_cr64_1sub",iV,iR);
			readHist_VR(fSts,sts_sc_1sub[iV][iR],"sc_1sub","sts_sc_1sub",iV,iR);
			readHist_VR(fSts,sts_nsc_1sub[iV][iR],"nsc_1sub","sts_nsc_1sub",iV,iR);
			readHist_VR(fSts,sts_ac_1sub[iV][iR],"ac_1sub","sts_ac_1sub",iV,iR);
			readHist_VR(fSts,sts_nac_1sub[iV][iR],"nac_1sub","sts_nac_1sub",iV,iR);
			readHist_VR(fSts,sts_c2_3sub[iV][iR],"c2_3sub","sts_c2_3sub",iV,iR);
			readHist_VR(fSts,sts_c4_3sub[iV][iR],"c4_3sub","sts_c4_3sub",iV,iR);
			readHist_VR(fSts,sts_v2_3sub[iV][iR],"v2_3sub","sts_v2_3sub",iV,iR);
			readHist_VR(fSts,sts_v4_3sub[iV][iR],"v4_3sub","sts_v4_3sub",iV,iR);
			readHist_VR(fSts,sts_sc_3sub[iV][iR],"sc_3sub","sts_sc_3sub",iV,iR);
			readHist_VR(fSts,sts_nsc_3sub[iV][iR],"nsc_3sub","sts_nsc_3sub",iV,iR);
			readHist_VR(fSts,sts_ac_3sub[iV][iR],"ac_3sub","sts_ac_3sub",iV,iR);
			readHist_VR(fSts,sts_nac_3sub[iV][iR],"nac_3sub","sts_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC(fSts,sts_vd2_1sub[iV][iR][iC],"vd2_1sub","sts_vd2_1sub",iV,iR,iC);
				readHist_VRC(fSts,sts_vd4_1sub[iV][iR][iC],"vd4_1sub","sts_vd4_1sub",iV,iR,iC);
			}
		}
	}

	sprintf(name,"../../SYS/CombSys/OUTPUT/Sys_bin0.root");
	TFile* fSys = new TFile(name,"READ");
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			readHist_VR(fSys,sysUp_c2_1sub[iV][iR],"sysUp_c2_1sub","sysUp_c2_1sub",iV,iR);
			readHist_VR(fSys,sysUp_c4_1sub[iV][iR],"sysUp_c4_1sub","sysUp_c4_1sub",iV,iR);
			readHist_VR(fSys,sysUp_c6_1sub[iV][iR],"sysUp_c6_1sub","sysUp_c6_1sub",iV,iR);
			readHist_VR(fSys,sysUp_nc4_1sub[iV][iR],"sysUp_nc4_1sub","sysUp_nc4_1sub",iV,iR);
			readHist_VR(fSys,sysUp_nc6_1sub[iV][iR],"sysUp_nc6_1sub","sysUp_nc6_1sub",iV,iR);
			readHist_VR(fSys,sysUp_v2_1sub[iV][iR],"sysUp_v2_1sub","sysUp_v2_1sub",iV,iR);
			readHist_VR(fSys,sysUp_v4_1sub[iV][iR],"sysUp_v4_1sub","sysUp_v4_1sub",iV,iR);
			readHist_VR(fSys,sysUp_v6_1sub[iV][iR],"sysUp_v6_1sub","sysUp_v6_1sub",iV,iR);
			readHist_VR(fSys,sysUp_cr42_1sub[iV][iR],"sysUp_cr42_1sub","sysUp_cr42_1sub",iV,iR);
			readHist_VR(fSys,sysUp_cr64_1sub[iV][iR],"sysUp_cr64_1sub","sysUp_cr64_1sub",iV,iR);
			readHist_VR(fSys,sysUp_sc_1sub[iV][iR],"sysUp_sc_1sub","sysUp_sc_1sub",iV,iR);
			readHist_VR(fSys,sysUp_nsc_1sub[iV][iR],"sysUp_nsc_1sub","sysUp_nsc_1sub",iV,iR);
			readHist_VR(fSys,sysUp_ac_1sub[iV][iR],"sysUp_ac_1sub","sysUp_ac_1sub",iV,iR);
			readHist_VR(fSys,sysUp_nac_1sub[iV][iR],"sysUp_nac_1sub","sysUp_nac_1sub",iV,iR);
			readHist_VR(fSys,sysUp_c2_3sub[iV][iR],"sysUp_c2_1sub","sysUp_c2_3sub",iV,iR);
			readHist_VR(fSys,sysUp_c4_3sub[iV][iR],"sysUp_c4_1sub","sysUp_c4_3sub",iV,iR);
			readHist_VR(fSys,sysUp_v2_3sub[iV][iR],"sysUp_v2_1sub","sysUp_v2_3sub",iV,iR);
			readHist_VR(fSys,sysUp_v4_3sub[iV][iR],"sysUp_v4_1sub","sysUp_v4_3sub",iV,iR);
			readHist_VR(fSys,sysUp_sc_3sub[iV][iR],"sysUp_sc_1sub","sysUp_sc_3sub",iV,iR);
			readHist_VR(fSys,sysUp_nsc_3sub[iV][iR],"sysUp_nsc_1sub","sysUp_nsc_3sub",iV,iR);
			readHist_VR(fSys,sysUp_ac_3sub[iV][iR],"sysUp_ac_1sub","sysUp_ac_3sub",iV,iR);
			readHist_VR(fSys,sysUp_nac_3sub[iV][iR],"sysUp_nac_1sub","sysUp_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC(fSys,sysUp_vd2_1sub[iV][iR][iC],"sysUp_vd2_1sub","sysUp_vd2_1sub",iV,iR,iC);
				readHist_VRC(fSys,sysUp_vd4_1sub[iV][iR][iC],"sysUp_vd4_1sub","sysUp_vd4_1sub",iV,iR,iC);
			}
			
			readHist_VR(fSys,sysLw_c2_1sub[iV][iR],"sysLw_c2_1sub","sysLw_c2_1sub",iV,iR);
			readHist_VR(fSys,sysLw_c4_1sub[iV][iR],"sysLw_c4_1sub","sysLw_c4_1sub",iV,iR);
			readHist_VR(fSys,sysLw_c6_1sub[iV][iR],"sysLw_c6_1sub","sysLw_c6_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nc4_1sub[iV][iR],"sysLw_nc4_1sub","sysLw_nc4_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nc6_1sub[iV][iR],"sysLw_nc6_1sub","sysLw_nc6_1sub",iV,iR);
			readHist_VR(fSys,sysLw_v2_1sub[iV][iR],"sysLw_v2_1sub","sysLw_v2_1sub",iV,iR);
			readHist_VR(fSys,sysLw_v4_1sub[iV][iR],"sysLw_v4_1sub","sysLw_v4_1sub",iV,iR);
			readHist_VR(fSys,sysLw_v6_1sub[iV][iR],"sysLw_v6_1sub","sysLw_v6_1sub",iV,iR);
			readHist_VR(fSys,sysLw_cr42_1sub[iV][iR],"sysLw_cr42_1sub","sysLw_cr42_1sub",iV,iR);
			readHist_VR(fSys,sysLw_cr64_1sub[iV][iR],"sysLw_cr64_1sub","sysLw_cr64_1sub",iV,iR);
			readHist_VR(fSys,sysLw_sc_1sub[iV][iR],"sysLw_sc_1sub","sysLw_sc_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nsc_1sub[iV][iR],"sysLw_nsc_1sub","sysLw_nsc_1sub",iV,iR);
			readHist_VR(fSys,sysLw_ac_1sub[iV][iR],"sysLw_ac_1sub","sysLw_ac_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nac_1sub[iV][iR],"sysLw_nac_1sub","sysLw_nac_1sub",iV,iR);
			readHist_VR(fSys,sysLw_c2_3sub[iV][iR],"sysLw_c2_1sub","sysLw_c2_3sub",iV,iR);
			readHist_VR(fSys,sysLw_c4_3sub[iV][iR],"sysLw_c4_1sub","sysLw_c4_3sub",iV,iR);
			readHist_VR(fSys,sysLw_v2_3sub[iV][iR],"sysLw_v2_1sub","sysLw_v2_3sub",iV,iR);
			readHist_VR(fSys,sysLw_v4_3sub[iV][iR],"sysLw_v4_1sub","sysLw_v4_3sub",iV,iR);
			readHist_VR(fSys,sysLw_sc_3sub[iV][iR],"sysLw_sc_1sub","sysLw_sc_3sub",iV,iR);
			readHist_VR(fSys,sysLw_nsc_3sub[iV][iR],"sysLw_nsc_1sub","sysLw_nsc_3sub",iV,iR);
			readHist_VR(fSys,sysLw_ac_3sub[iV][iR],"sysLw_ac_1sub","sysLw_ac_3sub",iV,iR);
			readHist_VR(fSys,sysLw_nac_3sub[iV][iR],"sysLw_nac_1sub","sysLw_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC(fSys,sysLw_vd2_1sub[iV][iR][iC],"sysLw_vd2_1sub","sysLw_vd2_1sub",iV,iR,iC);
				readHist_VRC(fSys,sysLw_vd4_1sub[iV][iR][iC],"sysLw_vd4_1sub","sysLw_vd4_1sub",iV,iR,iC);
			}
		}
	}
}

void Phase4::finalize(unsigned int iBin)
{
	cout<<"finalize..."<<endl;

	sprintf(name,"../OUTPUT/Phase4/hist_XeXe544_binCent_bin%d.root",iBin);
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

void Phase4::combine(TGraphErrors* gSts, TGraphErrors* gSysUp, TGraphErrors* gSysLw, TGraphAsymmErrors*& gSys, const char* hName, int iV, int iR, int iC)
{
	int NB = gSts->GetN();
	double x[NB];
	double xElw[NB];
	double xEup[NB];
	double y[NB];
	double yElw[NB];
	double yEup[NB];
	double xLw;
	double xUp;
	gSysLw->GetPoint(0,xLw,x[0]);
	gSysLw->GetPoint(gSysLw->GetN()-1,xUp,x[0]);
	for(int iB=0; iB<NB; iB++)
	{
		gSts->GetPoint(iB,x[iB],y[iB]);
		xElw[iB] = 0;
		xEup[iB] = 0;
		double xCvt = x[iB];
		if(xCvt<xLw) xCvt = xLw;
		if(xCvt>xUp) xCvt = xUp;
		yElw[iB] = fabs(y[iB]*gSysLw->Eval(xCvt));
		yEup[iB] = fabs(y[iB]*gSysUp->Eval(xCvt));
	}
	gSys = new TGraphAsymmErrors(NB,x,y,xElw,xEup,yElw,yEup);
	if(iC<0) sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	else sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	gSys->SetName(name);
}

void Phase4::trim(TGraphErrors* gSts, TGraphAsymmErrors* gSys)
{
	for(int i=0; i<gSts->GetN(); i++)
	{
		if(gSys->GetErrorYhigh(i)<0.2*gSts->GetErrorY(i)) gSys->SetPointEYhigh(i,0.2*gSts->GetErrorY(i));
		if(gSys->GetErrorYlow(i)< 0.2*gSts->GetErrorY(i)) gSys->SetPointEYlow(i,0.2*gSts->GetErrorY(i));
	}
}

void Phase4::readHist_VR(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d",hNewName,iV,iR);
	hIn->SetName(name);
}

void Phase4::readHist_VRC(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hNewName,iV,iR,iC);
	hIn->SetName(name);
}








