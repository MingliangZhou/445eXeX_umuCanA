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

			cal_err_v(sys_c2_1sub[iV][iR],sys_v2_1sub[iV][iR],2);
			cal_err_v(sys_c4_1sub[iV][iR],sys_v4_1sub[iV][iR],4);
			cal_err_v(sys_c6_1sub[iV][iR],sys_v6_1sub[iV][iR],6);
			trim(sts_v2_1sub[iV][iR],sys_v2_1sub[iV][iR]);
			trim(sts_v4_1sub[iV][iR],sys_v4_1sub[iV][iR]);
			trim(sts_v6_1sub[iV][iR],sys_v6_1sub[iV][iR]);

			cal_err_cr(sys_v4_1sub[iV][iR],sys_v2_1sub[iV][iR],sys_cr42_1sub[iV][iR]);
			cal_err_cr(sys_v6_1sub[iV][iR],sys_v4_1sub[iV][iR],sys_cr64_1sub[iV][iR]);
			trim(sts_cr42_1sub[iV][iR],sys_cr42_1sub[iV][iR]);
			trim(sts_cr64_1sub[iV][iR],sys_cr64_1sub[iV][iR]);
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
			readHist_VR_Xe(fSts,sts_c2_1sub[iV][iR],"c2_1sub","sts_c2_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_c4_1sub[iV][iR],"c4_1sub","sts_c4_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_c6_1sub[iV][iR],"c6_1sub","sts_c6_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_nc4_1sub[iV][iR],"nc4_1sub","sts_nc4_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_nc6_1sub[iV][iR],"nc6_1sub","sts_nc6_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_v2_1sub[iV][iR],"v2_1sub","sts_v2_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_v4_1sub[iV][iR],"v4_1sub","sts_v4_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_v6_1sub[iV][iR],"v6_1sub","sts_v6_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_cr42_1sub[iV][iR],"cr42_1sub","sts_cr42_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_cr64_1sub[iV][iR],"cr64_1sub","sts_cr64_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_sc_1sub[iV][iR],"sc_1sub","sts_sc_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_nsc_1sub[iV][iR],"nsc_1sub","sts_nsc_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_ac_1sub[iV][iR],"ac_1sub","sts_ac_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_nac_1sub[iV][iR],"nac_1sub","sts_nac_1sub",iV,iR);
			readHist_VR_Xe(fSts,sts_c2_3sub[iV][iR],"c2_3sub","sts_c2_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_c4_3sub[iV][iR],"c4_3sub","sts_c4_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_v2_3sub[iV][iR],"v2_3sub","sts_v2_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_v4_3sub[iV][iR],"v4_3sub","sts_v4_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_sc_3sub[iV][iR],"sc_3sub","sts_sc_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_nsc_3sub[iV][iR],"nsc_3sub","sts_nsc_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_ac_3sub[iV][iR],"ac_3sub","sts_ac_3sub",iV,iR);
			readHist_VR_Xe(fSts,sts_nac_3sub[iV][iR],"nac_3sub","sts_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC_Xe(fSts,sts_vd2_1sub[iV][iR][iC],"vd2_1sub","sts_vd2_1sub",iV,iR,iC);
				readHist_VRC_Xe(fSts,sts_vd4_1sub[iV][iR][iC],"vd4_1sub","sts_vd4_1sub",iV,iR,iC);
			}
		}
	}

	sprintf(name,"../../SYS/CombSys/OUTPUT/Sys_bin0.root");
	TFile* fSysXe = new TFile(name,"READ");
	sprintf(name,"../../../AnaCumu_PbPb502/SYS/CombSys/OUTPUT/Sys_bin0.root");
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
			readHist_VR_Xe(fSysXe,sysUp_v2_1sub[iV][iR],"sysUp_v2_1sub","sysUp_v2_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysUp_v4_1sub[iV][iR],"sysUp_v4_1sub","sysUp_v4_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysUp_v6_1sub[iV][iR],"sysUp_v6_1sub","sysUp_v6_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysUp_cr42_1sub[iV][iR],"sysUp_cr42_1sub","sysUp_cr42_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysUp_cr64_1sub[iV][iR],"sysUp_cr64_1sub","sysUp_cr64_1sub",iV,iR);
			readHist_VR(fSys,sysUp_sc_1sub[iV][iR],"sysUp_sc_1sub","sysUp_sc_1sub",iV,iR);
			readHist_VR(fSys,sysUp_nsc_1sub[iV][iR],"sysUp_nsc_1sub","sysUp_nsc_1sub",iV,iR);
			readHist_VR(fSys,sysUp_ac_1sub[iV][iR],"sysUp_ac_1sub","sysUp_ac_1sub",iV,iR);
			readHist_VR(fSys,sysUp_nac_1sub[iV][iR],"sysUp_nac_1sub","sysUp_nac_1sub",iV,iR);
			readHist_VR(fSys,sysUp_c2_3sub[iV][iR],"sysUp_c2_3sub","sysUp_c2_3sub",iV,iR);
			readHist_VR(fSys,sysUp_c4_3sub[iV][iR],"sysUp_c4_3sub","sysUp_c4_3sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysUp_v2_3sub[iV][iR],"sysUp_v2_1sub","sysUp_v2_3sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysUp_v4_3sub[iV][iR],"sysUp_v4_1sub","sysUp_v4_3sub",iV,iR);
			readHist_VR(fSys,sysUp_sc_3sub[iV][iR],"sysUp_sc_3sub","sysUp_sc_3sub",iV,iR);
			readHist_VR(fSys,sysUp_nsc_3sub[iV][iR],"sysUp_nsc_3sub","sysUp_nsc_3sub",iV,iR);
			readHist_VR(fSys,sysUp_ac_3sub[iV][iR],"sysUp_ac_3sub","sysUp_ac_3sub",iV,iR);
			readHist_VR(fSys,sysUp_nac_3sub[iV][iR],"sysUp_nac_3sub","sysUp_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC_Xe(fSysXe,sysUp_vd2_1sub[iV][iR][iC],"sysUp_vd2_1sub","sysUp_vd2_1sub",iV,iR,iC);
				readHist_VRC_Xe(fSysXe,sysUp_vd4_1sub[iV][iR][iC],"sysUp_vd4_1sub","sysUp_vd4_1sub",iV,iR,iC);
			}
			
			readHist_VR(fSys,sysLw_c2_1sub[iV][iR],"sysLw_c2_1sub","sysLw_c2_1sub",iV,iR);
			readHist_VR(fSys,sysLw_c4_1sub[iV][iR],"sysLw_c4_1sub","sysLw_c4_1sub",iV,iR);
			readHist_VR(fSys,sysLw_c6_1sub[iV][iR],"sysLw_c6_1sub","sysLw_c6_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nc4_1sub[iV][iR],"sysLw_nc4_1sub","sysLw_nc4_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nc6_1sub[iV][iR],"sysLw_nc6_1sub","sysLw_nc6_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_v2_1sub[iV][iR],"sysLw_v2_1sub","sysLw_v2_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_v4_1sub[iV][iR],"sysLw_v4_1sub","sysLw_v4_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_v6_1sub[iV][iR],"sysLw_v6_1sub","sysLw_v6_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_cr42_1sub[iV][iR],"sysLw_cr42_1sub","sysLw_cr42_1sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_cr64_1sub[iV][iR],"sysLw_cr64_1sub","sysLw_cr64_1sub",iV,iR);
			readHist_VR(fSys,sysLw_sc_1sub[iV][iR],"sysLw_sc_1sub","sysLw_sc_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nsc_1sub[iV][iR],"sysLw_nsc_1sub","sysLw_nsc_1sub",iV,iR);
			readHist_VR(fSys,sysLw_ac_1sub[iV][iR],"sysLw_ac_1sub","sysLw_ac_1sub",iV,iR);
			readHist_VR(fSys,sysLw_nac_1sub[iV][iR],"sysLw_nac_1sub","sysLw_nac_1sub",iV,iR);
			readHist_VR(fSys,sysLw_c2_3sub[iV][iR],"sysLw_c2_3sub","sysLw_c2_3sub",iV,iR);
			readHist_VR(fSys,sysLw_c4_3sub[iV][iR],"sysLw_c4_3sub","sysLw_c4_3sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_v2_3sub[iV][iR],"sysLw_v2_1sub","sysLw_v2_3sub",iV,iR);
			readHist_VR_Xe(fSysXe,sysLw_v4_3sub[iV][iR],"sysLw_v4_1sub","sysLw_v4_3sub",iV,iR);
			readHist_VR(fSys,sysLw_sc_3sub[iV][iR],"sysLw_sc_3sub","sysLw_sc_3sub",iV,iR);
			readHist_VR(fSys,sysLw_nsc_3sub[iV][iR],"sysLw_nsc_3sub","sysLw_nsc_3sub",iV,iR);
			readHist_VR(fSys,sysLw_ac_3sub[iV][iR],"sysLw_ac_3sub","sysLw_ac_3sub",iV,iR);
			readHist_VR(fSys,sysLw_nac_3sub[iV][iR],"sysLw_nac_3sub","sysLw_nac_3sub",iV,iR);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				readHist_VRC_Xe(fSysXe,sysLw_vd2_1sub[iV][iR][iC],"sysLw_vd2_1sub","sysLw_vd2_1sub",iV,iR,iC);
				readHist_VRC_Xe(fSysXe,sysLw_vd4_1sub[iV][iR][iC],"sysLw_vd4_1sub","sysLw_vd4_1sub",iV,iR,iC);
			}
		}
	}

	for(unsigned int iV=0; iV<2; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			sprintf(name,"sysUp_sc_1sub_Har%d_PtRef%d",iV,iR); sysUp_sc_1sub[iV][iR] = (TGraphErrors*)sysUp_sc_1sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysLw_sc_1sub_Har%d_PtRef%d",iV,iR); sysLw_sc_1sub[iV][iR] = (TGraphErrors*)sysLw_sc_1sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysUp_nsc_1sub_Har%d_PtRef%d",iV,iR); sysUp_nsc_1sub[iV][iR] = (TGraphErrors*)sysUp_nsc_1sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysLw_nsc_1sub_Har%d_PtRef%d",iV,iR); sysLw_nsc_1sub[iV][iR] = (TGraphErrors*)sysLw_nsc_1sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysUp_sc_3sub_Har%d_PtRef%d",iV,iR); sysUp_sc_3sub[iV][iR] = (TGraphErrors*)sysUp_sc_3sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysLw_sc_3sub_Har%d_PtRef%d",iV,iR); sysLw_sc_3sub[iV][iR] = (TGraphErrors*)sysLw_sc_3sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysUp_nsc_3sub_Har%d_PtRef%d",iV,iR); sysUp_nsc_3sub[iV][iR] = (TGraphErrors*)sysUp_nsc_3sub[iV+2][iR]->Clone(name);
			sprintf(name,"sysLw_nsc_3sub_Har%d_PtRef%d",iV,iR); sysLw_nsc_3sub[iV][iR] = (TGraphErrors*)sysLw_nsc_3sub[iV+2][iR]->Clone(name);
		}
	}
}

void Phase4::finalize(unsigned int iBin)
{
	cout<<"finalize..."<<endl;

	sprintf(name,"../OUTPUT/Phase4/hist_PbPb502_binCent_bin%d.root",iBin);
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

void Phase4::cal_err_v(TGraphAsymmErrors* sys_c, TGraphAsymmErrors* sys_v, int iOpt)
{
	int NX = sys_c->GetN();
	for(int iX=0; iX<NX; iX++)
	{
		double x = 0;
		double y = 0;
		double yErrUp = 0;
		double yErrLw = 0;
		sys_c->GetPoint(iX,x,y);
		yErrUp = sys_c->GetErrorYhigh(iX);
		yErrLw = sys_c->GetErrorYlow(iX);
		if(iOpt==2)
		{
			if(y==0) continue;
			yErrUp = 0.5*pow(fabs(y),-0.5)*yErrUp;
			yErrLw = 0.5*pow(fabs(y),-0.5)*yErrLw;
		}
		if(iOpt==4)
		{
			if(y==0) continue;
			yErrUp = 0.25*pow(fabs(y),-0.75)*yErrUp;
			yErrLw = 0.25*pow(fabs(y),-0.75)*yErrLw;
		}
		if(iOpt==6)
		{
			if(y==0) continue;
			yErrUp = 1./6*pow(0.25,1./6)*pow(fabs(y),-5./6)*yErrUp;
			yErrLw = 1./6*pow(0.25,1./6)*pow(fabs(y),-5./6)*yErrLw;
		}
		sys_v->SetPointEYhigh(iX,yErrUp);
		sys_v->SetPointEYlow(iX,yErrLw);
	}
}

void Phase4::cal_err_cr(TGraphAsymmErrors* sys_cN, TGraphAsymmErrors* sys_cD, TGraphAsymmErrors* sys_cr)
{
	int NX = sys_cN->GetN();
	for(int iX=0; iX<NX; iX++)
	{
		double x = 0; double x1 = 0; double x2 = 0;
		double y = 0; double y1 = 0; double y2 = 0;
		double yErrUp = 0; double yErrUp1 = 0; double yErrUp2 = 0;
		double yErrLw = 0; double yErrLw1 = 0; double yErrLw2 = 0;
		sys_cr->GetPoint(iX,x,y);
		sys_cN->GetPoint(iX,x1,y1);
		sys_cD->GetPoint(iX,x2,y2);
		yErrUp = sys_cr->GetErrorYhigh(iX);
		yErrLw = sys_cr->GetErrorYlow(iX);
		yErrUp1 = sys_cN->GetErrorYhigh(iX);
		yErrLw1 = sys_cN->GetErrorYlow(iX);
		yErrUp2 = sys_cD->GetErrorYhigh(iX);
		yErrLw2 = sys_cD->GetErrorYlow(iX);

		if(y1==0 || y2==0) continue;
		yErrUp = fabs(y*(fabs(yErrUp1/y1)-fabs(yErrUp2/y2)));
		yErrLw = fabs(y*(fabs(yErrLw1/y1)-fabs(yErrLw2/y2)));

		sys_cr->SetPointEYhigh(iX,yErrUp);
		sys_cr->SetPointEYlow(iX,yErrLw);
	}
}

void Phase4::readHist_VR(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR)
{
	if(iR<2) sprintf(name,"%s_Har%d_Pt%d",hName,iV,iR);
	else sprintf(name,"%s_Har%d_Pt%d",hName,iV,1);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d",hNewName,iV,iR);
	hIn->SetName(name);
}

void Phase4::readHist_VR_Xe(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d",hNewName,iV,iR);
	hIn->SetName(name);
}

void Phase4::readHist_VRC_Xe(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hNewName,iV,iR,iC);
	hIn->SetName(name);
}








