#include "CombSys.h"

CombSys::CombSys(unsigned int iBin)
{
	initialize(iBin);
	execute();
	finalize(iBin);
}

CombSys::~CombSys()
{
}

void CombSys::execute()
{
	cout<<"execute..."<<endl;

	for(unsigned int iS=0; iS<NS; iS++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				cal_ratio(c2_1sub[0][iS][iV][iR],c2_1sub[1][iS][iV][iR],ratio_c2_1sub[iS][iV][iR],"ratio_c2_1sub",iS,iV,iR);
				cal_ratio(c4_1sub[0][iS][iV][iR],c4_1sub[1][iS][iV][iR],ratio_c4_1sub[iS][iV][iR],"ratio_c4_1sub",iS,iV,iR);
				cal_ratio(c6_1sub[0][iS][iV][iR],c6_1sub[1][iS][iV][iR],ratio_c6_1sub[iS][iV][iR],"ratio_c6_1sub",iS,iV,iR);
				cal_ratio(nc4_1sub[0][iS][iV][iR],nc4_1sub[1][iS][iV][iR],ratio_nc4_1sub[iS][iV][iR],"ratio_nc4_1sub",iS,iV,iR);
				cal_ratio(nc6_1sub[0][iS][iV][iR],nc6_1sub[1][iS][iV][iR],ratio_nc6_1sub[iS][iV][iR],"ratio_nc6_1sub",iS,iV,iR);
				cal_ratio(v2_1sub[0][iS][iV][iR],v2_1sub[1][iS][iV][iR],ratio_v2_1sub[iS][iV][iR],"ratio_v2_1sub",iS,iV,iR);
				cal_ratio(v4_1sub[0][iS][iV][iR],v4_1sub[1][iS][iV][iR],ratio_v4_1sub[iS][iV][iR],"ratio_v4_1sub",iS,iV,iR);
				cal_ratio(v6_1sub[0][iS][iV][iR],v6_1sub[1][iS][iV][iR],ratio_v6_1sub[iS][iV][iR],"ratio_v6_1sub",iS,iV,iR);
				cal_ratio(cr42_1sub[0][iS][iV][iR],cr42_1sub[1][iS][iV][iR],ratio_cr42_1sub[iS][iV][iR],"ratio_cr42_1sub",iS,iV,iR);
				cal_ratio(cr64_1sub[0][iS][iV][iR],cr64_1sub[1][iS][iV][iR],ratio_cr64_1sub[iS][iV][iR],"ratio_cr64_1sub",iS,iV,iR);
				cal_ratio(sc_1sub[0][iS][iV][iR],sc_1sub[1][iS][iV][iR],ratio_sc_1sub[iS][iV][iR],"ratio_sc_1sub",iS,iV,iR);
				cal_ratio(nsc_1sub[0][iS][iV][iR],nsc_1sub[1][iS][iV][iR],ratio_nsc_1sub[iS][iV][iR],"ratio_nsc_1sub",iS,iV,iR);
				cal_ratio(ac_1sub[0][iS][iV][iR],ac_1sub[1][iS][iV][iR],ratio_ac_1sub[iS][iV][iR],"ratio_ac_1sub",iS,iV,iR);
				cal_ratio(nac_1sub[0][iS][iV][iR],nac_1sub[1][iS][iV][iR],ratio_nac_1sub[iS][iV][iR],"ratio_nac_1sub",iS,iV,iR);
				cal_ratio(c2_3sub[0][iS][iV][iR],c2_3sub[1][iS][iV][iR],ratio_c2_3sub[iS][iV][iR],"ratio_c2_3sub",iS,iV,iR);
				cal_ratio(c4_3sub[0][iS][iV][iR],c4_3sub[1][iS][iV][iR],ratio_c4_3sub[iS][iV][iR],"ratio_c4_3sub",iS,iV,iR);
				cal_ratio(v2_3sub[0][iS][iV][iR],v2_3sub[1][iS][iV][iR],ratio_v2_3sub[iS][iV][iR],"ratio_v2_3sub",iS,iV,iR);
				cal_ratio(v4_3sub[0][iS][iV][iR],v4_3sub[1][iS][iV][iR],ratio_v4_3sub[iS][iV][iR],"ratio_v4_3sub",iS,iV,iR);
				cal_ratio(sc_3sub[0][iS][iV][iR],sc_3sub[1][iS][iV][iR],ratio_sc_3sub[iS][iV][iR],"ratio_sc_3sub",iS,iV,iR);
				cal_ratio(nsc_3sub[0][iS][iV][iR],nsc_3sub[1][iS][iV][iR],ratio_nsc_3sub[iS][iV][iR],"ratio_nsc_3sub",iS,iV,iR);
				cal_ratio(ac_3sub[0][iS][iV][iR],ac_3sub[1][iS][iV][iR],ratio_ac_3sub[iS][iV][iR],"ratio_ac_3sub",iS,iV,iR);
				cal_ratio(nac_3sub[0][iS][iV][iR],nac_3sub[1][iS][iV][iR],ratio_nac_3sub[iS][iV][iR],"ratio_nac_3sub",iS,iV,iR);
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					cal_ratio(vd2_1sub[0][iS][iV][iR][iC],vd2_1sub[1][iS][iV][iR][iC],ratio_vd2_1sub[iS][iV][iR][iC],"ratio_vd2_1sub",iS,iV,iR,iC);
					cal_ratio(vd4_1sub[0][iS][iV][iR][iC],vd4_1sub[1][iS][iV][iR][iC],ratio_vd4_1sub[iS][iV][iR][iC],"ratio_vd4_1sub",iS,iV,iR,iC);
				}
			}
		}
	}

	smooth();

	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			// centrality definition
			set_sys(ratio_c2_1sub[4][iV][iR], +2); set_sys(ratio_c2_1sub[7][iV][iR], -2);
			set_sys(ratio_c4_1sub[4][iV][iR], +4); set_sys(ratio_c4_1sub[7][iV][iR], -4);
			set_sys(ratio_c6_1sub[4][iV][iR], +6); set_sys(ratio_c6_1sub[7][iV][iR], -6);
			set_sys(ratio_v2_3sub[4][iV][iR], +1); set_sys(ratio_v2_3sub[7][iV][iR], -1);
			set_sys(ratio_v4_1sub[4][iV][iR], +1); set_sys(ratio_v4_1sub[7][iV][iR], -1);
			set_sys(ratio_v6_1sub[4][iV][iR], +1); set_sys(ratio_v6_1sub[7][iV][iR], -1);
			set_sys(ratio_cr42_1sub[4][iV][iR], +0); set_sys(ratio_cr42_1sub[7][iV][iR], -0);
			set_sys(ratio_cr64_1sub[4][iV][iR], +0); set_sys(ratio_cr64_1sub[7][iV][iR], -0);
			set_sys(ratio_sc_1sub[4][iV][iR], +4); set_sys(ratio_sc_1sub[7][iV][iR], -4);
			set_sys(ratio_ac_1sub[4][iV][iR], +4); set_sys(ratio_ac_1sub[7][iV][iR], -4);
			set_sys(ratio_nsc_1sub[4][iV][iR], +4); set_sys(ratio_nsc_1sub[7][iV][iR], -4);
			set_sys(ratio_nac_1sub[4][iV][iR], +4); set_sys(ratio_nac_1sub[7][iV][iR], -4);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				set_sys(ratio_vd2_1sub[4][iV][iR][iC], +1, +1); set_sys(ratio_vd2_1sub[7][iV][iR][iC], -1, -1);
				set_sys(ratio_vd4_1sub[4][iV][iR][iC], +1, +1); set_sys(ratio_vd4_1sub[7][iV][iR][iC], -1, -1);
			}

			// event mixing
			/*
			set_sys(ratio_c2_1sub[6][iV][iR], +2); set_sys(ratio_c2_1sub[8][iV][iR], -2);
			set_sys(ratio_c4_1sub[6][iV][iR], +4); set_sys(ratio_c4_1sub[8][iV][iR], -4);
			set_sys(ratio_c6_1sub[6][iV][iR], +6); set_sys(ratio_c6_1sub[8][iV][iR], -6);
			set_sys(ratio_v2_3sub[6][iV][iR], +1); set_sys(ratio_v2_3sub[8][iV][iR], -1);
			set_sys(ratio_v4_1sub[6][iV][iR], +1); set_sys(ratio_v4_1sub[8][iV][iR], -1);
			set_sys(ratio_v6_1sub[6][iV][iR], +1); set_sys(ratio_v6_1sub[8][iV][iR], -1);
			set_sys(ratio_cr42_1sub[6][iV][iR], +1); set_sys(ratio_cr42_1sub[8][iV][iR], -1);
			set_sys(ratio_cr64_1sub[6][iV][iR], +1); set_sys(ratio_cr64_1sub[8][iV][iR], -1);
			set_sys(ratio_sc_1sub[6][iV][iR], +4); set_sys(ratio_sc_1sub[8][iV][iR], -4);
			set_sys(ratio_ac_1sub[6][iV][iR], +4); set_sys(ratio_ac_1sub[8][iV][iR], -4);
			set_sys(ratio_nsc_1sub[6][iV][iR], +4); set_sys(ratio_nsc_1sub[8][iV][iR], -4);
			set_sys(ratio_nac_1sub[6][iV][iR], +4); set_sys(ratio_nac_1sub[8][iV][iR], -4);
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				set_sys(ratio_vd2_1sub[6][iV][iR][iC], +1, +3); set_sys(ratio_vd2_1sub[8][iV][iR][iC], -1, -3);
				set_sys(ratio_vd4_1sub[6][iV][iR][iC], +1, +3); set_sys(ratio_vd4_1sub[8][iV][iR][iC], -1, -3);
			}
			*/
		}
	}

	vector<TGraphErrors*> gVec;
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c2_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_c2_1sub[iV][iR],sysLw_c2_1sub[iV][iR],"c2_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c4_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_c4_1sub[iV][iR],sysLw_c4_1sub[iV][iR],"c4_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c6_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_c6_1sub[iV][iR],sysLw_c6_1sub[iV][iR],"c6_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nc4_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_nc4_1sub[iV][iR],sysLw_nc4_1sub[iV][iR],"nc4_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nc6_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_nc6_1sub[iV][iR],sysLw_nc6_1sub[iV][iR],"nc6_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v2_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_v2_1sub[iV][iR],sysLw_v2_1sub[iV][iR],"v2_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v4_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_v4_1sub[iV][iR],sysLw_v4_1sub[iV][iR],"v4_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v6_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_v6_1sub[iV][iR],sysLw_v6_1sub[iV][iR],"v6_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_cr42_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_cr42_1sub[iV][iR],sysLw_cr42_1sub[iV][iR],"cr42_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_cr64_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_cr64_1sub[iV][iR],sysLw_cr64_1sub[iV][iR],"cr64_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_sc_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_sc_1sub[iV][iR],sysLw_sc_1sub[iV][iR],"sc_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nsc_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_nsc_1sub[iV][iR],sysLw_nsc_1sub[iV][iR],"nsc_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_ac_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_ac_1sub[iV][iR],sysLw_ac_1sub[iV][iR],"ac_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nac_1sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_nac_1sub[iV][iR],sysLw_nac_1sub[iV][iR],"nac_1sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c2_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_c2_3sub[iV][iR],sysLw_c2_3sub[iV][iR],"c2_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_c4_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_c4_3sub[iV][iR],sysLw_c4_3sub[iV][iR],"c4_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v2_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_v2_3sub[iV][iR],sysLw_v2_3sub[iV][iR],"v2_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_v4_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_v4_3sub[iV][iR],sysLw_v4_3sub[iV][iR],"v4_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_sc_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_sc_3sub[iV][iR],sysLw_sc_3sub[iV][iR],"sc_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nsc_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_nsc_3sub[iV][iR],sysLw_nsc_3sub[iV][iR],"nsc_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_ac_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_ac_3sub[iV][iR],sysLw_ac_3sub[iV][iR],"ac_3sub",iV,iR); gVec.clear();

			for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_nac_3sub[iS][iV][iR]);
			cal_comb(gVec,sysUp_nac_3sub[iV][iR],sysLw_nac_3sub[iV][iR],"nac_3sub",iV,iR); gVec.clear();
			
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_vd2_1sub[iS][iV][iR][iC]);
				cal_comb(gVec,sysUp_vd2_1sub[iV][iR][iC],sysLw_vd2_1sub[iV][iR][iC],"vd2_1sub",iV,iR,iC); gVec.clear();
				
				for(unsigned int iS=0; iS<NS; iS++) gVec.push_back(ratio_vd4_1sub[iS][iV][iR][iC]);
				cal_comb(gVec,sysUp_vd4_1sub[iV][iR][iC],sysLw_vd4_1sub[iV][iR][iC],"vd4_1sub",iV,iR,iC); gVec.clear();
			}
		}
	}

}

void CombSys::initialize(unsigned int iBin)
{
	cout<<"initialize..."<<endl;

	TFile* fIn[2][NS];
	for(unsigned int iF=0; iF<2; iF++)
	{
		for(unsigned int iS=0; iS<NS; iS++)
		{
			if(iF==0 && iS==0) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==1) sprintf(name,"../../trkEffLw/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==2) sprintf(name,"../../trkEffUp/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==3) sprintf(name,"../../trkSel/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==4) sprintf(name,"../../pileup/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==5) sprintf(name,"../../mcTruth/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==6) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin); // no flattening systematics
			if(iF==0 && iS==7) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==0 && iS==8) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);

			if(iF==1 && iS==0) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==1) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==2) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==3) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==4) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==5) sprintf(name,"../../mcRecon/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==6) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==7) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);
			if(iF==1 && iS==8) sprintf(name,"../../default/OUTPUT/Phase3/Phase3_bin%d.root",iBin);

			fIn[iF][iS] = new TFile(name,"READ");

			for(unsigned int iV=0; iV<NV; iV++)
			{
				for(unsigned int iR=0; iR<NR; iR++)
				{
					readHist_VR(fIn[iF][iS],c2_1sub[iF][iS][iV][iR],"c2_1sub","c2_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],c4_1sub[iF][iS][iV][iR],"c4_1sub","c4_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],c6_1sub[iF][iS][iV][iR],"c6_1sub","c6_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],nc4_1sub[iF][iS][iV][iR],"nc4_1sub","nc4_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],nc6_1sub[iF][iS][iV][iR],"nc6_1sub","nc6_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],v2_1sub[iF][iS][iV][iR],"v2_1sub","v2_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],v4_1sub[iF][iS][iV][iR],"v4_1sub","v4_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],v6_1sub[iF][iS][iV][iR],"v6_1sub","v6_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],cr42_1sub[iF][iS][iV][iR],"cr42_1sub","cr42_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],cr64_1sub[iF][iS][iV][iR],"cr64_1sub","cr64_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],sc_1sub[iF][iS][iV][iR],"sc_1sub","sc_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],nsc_1sub[iF][iS][iV][iR],"nsc_1sub","nsc_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],ac_1sub[iF][iS][iV][iR],"ac_1sub","ac_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],nac_1sub[iF][iS][iV][iR],"nac_1sub","nac_1sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],c2_3sub[iF][iS][iV][iR],"c2_3sub","c2_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],c4_3sub[iF][iS][iV][iR],"c4_3sub","c4_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],v2_3sub[iF][iS][iV][iR],"v2_3sub","v2_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],v4_3sub[iF][iS][iV][iR],"v4_3sub","v4_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],sc_3sub[iF][iS][iV][iR],"sc_3sub","sc_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],nsc_3sub[iF][iS][iV][iR],"nsc_3sub","nsc_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],ac_3sub[iF][iS][iV][iR],"ac_3sub","ac_3sub",iF,iS,iV,iR);
					readHist_VR(fIn[iF][iS],nac_3sub[iF][iS][iV][iR],"nac_3sub","nac_3sub",iF,iS,iV,iR);
					for(unsigned int iC=0; iC<nCent; iC++)
					{
						readHist_VRC(fIn[iF][iS],vd2_1sub[iF][iS][iV][iR][iC],"vd2_1sub","vd2_1sub",iF,iS,iV,iR,iC);
						readHist_VRC(fIn[iF][iS],vd4_1sub[iF][iS][iV][iR][iC],"vd4_1sub","vd4_1sub",iF,iS,iV,iR,iC);
					}
				}
			}
		}
	}
}

void CombSys::finalize(unsigned int iBin)
{
	cout<<"finalize..."<<endl;

	sprintf(name,"../OUTPUT/Sys_bin%d.root",iBin);
	TFile* fOut = new TFile(name,"RECREATE");
	fOut->cd();
	for(unsigned int iF=0; iF<2; iF++)
	{
		for(unsigned int iS=0; iS<NS; iS++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				for(unsigned int iR=0; iR<NR; iR++)
				{
					c2_1sub[iF][iS][iV][iR]->Write();
					c4_1sub[iF][iS][iV][iR]->Write();
					c6_1sub[iF][iS][iV][iR]->Write();
					nc4_1sub[iF][iS][iV][iR]->Write();
					nc6_1sub[iF][iS][iV][iR]->Write();
					v2_1sub[iF][iS][iV][iR]->Write();
					v4_1sub[iF][iS][iV][iR]->Write();
					v6_1sub[iF][iS][iV][iR]->Write();
					cr42_1sub[iF][iS][iV][iR]->Write();
					cr64_1sub[iF][iS][iV][iR]->Write();
					sc_1sub[iF][iS][iV][iR]->Write();
					nsc_1sub[iF][iS][iV][iR]->Write();
					ac_1sub[iF][iS][iV][iR]->Write();
					nac_1sub[iF][iS][iV][iR]->Write();
					c2_3sub[iF][iS][iV][iR]->Write();
					c4_3sub[iF][iS][iV][iR]->Write();
					v2_3sub[iF][iS][iV][iR]->Write();
					v4_3sub[iF][iS][iV][iR]->Write();
					sc_3sub[iF][iS][iV][iR]->Write();
					nsc_3sub[iF][iS][iV][iR]->Write();
					ac_3sub[iF][iS][iV][iR]->Write();
					nac_3sub[iF][iS][iV][iR]->Write();
					for(unsigned int iC=0; iC<nCent; iC++)
					{
						vd2_1sub[iF][iS][iV][iR][iC]->Write();
						vd4_1sub[iF][iS][iV][iR][iC]->Write();
					}
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
				ratio_c2_1sub[iS][iV][iR]->Write();
				ratio_c4_1sub[iS][iV][iR]->Write();
				ratio_c6_1sub[iS][iV][iR]->Write();
				ratio_nc4_1sub[iS][iV][iR]->Write();
				ratio_nc6_1sub[iS][iV][iR]->Write();
				ratio_v2_1sub[iS][iV][iR]->Write();
				ratio_v4_1sub[iS][iV][iR]->Write();
				ratio_v6_1sub[iS][iV][iR]->Write();
				ratio_cr42_1sub[iS][iV][iR]->Write();
				ratio_cr64_1sub[iS][iV][iR]->Write();
				ratio_sc_1sub[iS][iV][iR]->Write();
				ratio_nsc_1sub[iS][iV][iR]->Write();
				ratio_ac_1sub[iS][iV][iR]->Write();
				ratio_nac_1sub[iS][iV][iR]->Write();
				ratio_c2_3sub[iS][iV][iR]->Write();
				ratio_c4_3sub[iS][iV][iR]->Write();
				ratio_v2_3sub[iS][iV][iR]->Write();
				ratio_v4_3sub[iS][iV][iR]->Write();
				ratio_sc_3sub[iS][iV][iR]->Write();
				ratio_nsc_3sub[iS][iV][iR]->Write();
				ratio_ac_3sub[iS][iV][iR]->Write();
				ratio_nac_3sub[iS][iV][iR]->Write();
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					ratio_vd2_1sub[iS][iV][iR][iC]->Write();
					ratio_vd4_1sub[iS][iV][iR][iC]->Write();
				}
			}
		}
	}
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			sysUp_c2_1sub[iV][iR]->Write();
			sysUp_c4_1sub[iV][iR]->Write();
			sysUp_c6_1sub[iV][iR]->Write();
			sysUp_nc4_1sub[iV][iR]->Write();
			sysUp_nc6_1sub[iV][iR]->Write();
			sysUp_v2_1sub[iV][iR]->Write();
			sysUp_v4_1sub[iV][iR]->Write();
			sysUp_v6_1sub[iV][iR]->Write();
			sysUp_cr42_1sub[iV][iR]->Write();
			sysUp_cr64_1sub[iV][iR]->Write();
			sysUp_sc_1sub[iV][iR]->Write();
			sysUp_nsc_1sub[iV][iR]->Write();
			sysUp_ac_1sub[iV][iR]->Write();
			sysUp_nac_1sub[iV][iR]->Write();
			sysUp_c2_3sub[iV][iR]->Write();
			sysUp_c4_3sub[iV][iR]->Write();
			sysUp_v2_3sub[iV][iR]->Write();
			sysUp_v4_3sub[iV][iR]->Write();
			sysUp_sc_3sub[iV][iR]->Write();
			sysUp_nsc_3sub[iV][iR]->Write();
			sysUp_ac_3sub[iV][iR]->Write();
			sysUp_nac_3sub[iV][iR]->Write();
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				sysUp_vd2_1sub[iV][iR][iC]->Write();
				sysUp_vd4_1sub[iV][iR][iC]->Write();
			}
		}
	}
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			sysLw_c2_1sub[iV][iR]->Write();
			sysLw_c4_1sub[iV][iR]->Write();
			sysLw_c6_1sub[iV][iR]->Write();
			sysLw_nc4_1sub[iV][iR]->Write();
			sysLw_nc6_1sub[iV][iR]->Write();
			sysLw_v2_1sub[iV][iR]->Write();
			sysLw_v4_1sub[iV][iR]->Write();
			sysLw_v6_1sub[iV][iR]->Write();
			sysLw_cr42_1sub[iV][iR]->Write();
			sysLw_cr64_1sub[iV][iR]->Write();
			sysLw_sc_1sub[iV][iR]->Write();
			sysLw_nsc_1sub[iV][iR]->Write();
			sysLw_ac_1sub[iV][iR]->Write();
			sysLw_nac_1sub[iV][iR]->Write();
			sysLw_c2_3sub[iV][iR]->Write();
			sysLw_c4_3sub[iV][iR]->Write();
			sysLw_v2_3sub[iV][iR]->Write();
			sysLw_v4_3sub[iV][iR]->Write();
			sysLw_sc_3sub[iV][iR]->Write();
			sysLw_nsc_3sub[iV][iR]->Write();
			sysLw_ac_3sub[iV][iR]->Write();
			sysLw_nac_3sub[iV][iR]->Write();
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				sysLw_vd2_1sub[iV][iR][iC]->Write();
				sysLw_vd4_1sub[iV][iR][iC]->Write();
			}
		}
	}
	fOut->Close();
}

void CombSys::cal_ratio(TGraphErrors* gChk, TGraphErrors* gDef, TGraphErrors*& gRatio, const char* gName, int iS, int iV, int iR, int iC)
{
	int NB = gDef->GetN();
	double x[NB];
	double y[NB];
	double xErr[NB];
	double yErr[NB];
	for(int iB=0; iB<NB; iB++)
	{
		double yDef = 0;
		double yChk = 0;
		double eDef = 0;
		double eChk = 0;
		gChk->GetPoint(iB,x[iB],yChk);
		gDef->GetPoint(iB,x[iB],yDef);
		eChk = gChk->GetErrorY(iB);
		eDef = gDef->GetErrorY(iB);

		xErr[iB] = 0;
		if(yDef!=0) y[iB] = yChk/yDef - 1.;
		else y[iB] = 0;
		if(yDef!=0 && yChk!=0) yErr[iB] = fabs(yChk/yDef*sqrt(pow(eChk/yChk,2)+pow(eDef/yDef,2)));
		else yErr[iB] = 0;
	}
	gRatio = new TGraphErrors(NB,x,y,xErr,yErr);
	if(iC<0) sprintf(name,"%s_Sys%d_Har%d_PtRef%d",gName,iS,iV,iR);
	else sprintf(name,"%s_Sys%d_Har%d_PtRef%d_Cent%d",gName,iS,iV,iR,iC);
	gRatio->SetName(name);
}

void CombSys::smooth_ratio(TGraphErrors* gRatio, int iB, double percent)
{
	double x; double y;
	gRatio->GetPoint(iB,x,y);
	double yErr = gRatio->GetErrorY(iB);
	if(y>0)
	{
		if(fabs(y-percent*yErr)<yErr) y = percent*yErr;
		else y -= yErr;
	}
	else
	{
		if(fabs(y-percent*yErr)<yErr) y = -percent*yErr;
		else y += yErr;
	}
	gRatio->SetPoint(iB,x,y);
}

void CombSys::reduce_ratio(TGraphErrors* gRatio, int iB, double percent)
{
	double x; double y;
	gRatio->GetPoint(iB,x,y);
	y *= percent;
	gRatio->SetPoint(iB,x,y);
}

void CombSys::cal_comb(vector<TGraphErrors*> gVec, TGraphErrors*& gSysUp, TGraphErrors*& gSysLw, const char* gName, int iV, int iR, int iC)
{
	int NB = gVec.at(0)->GetN();
	double x[NB];
	double xErr[NB];
	double yUp[NB];
	double yLw[NB];
	double yUpErr[NB];
	double yLwErr[NB];
	for(int iB=0; iB<NB; iB++)
	{
		gVec.at(0)->GetPoint(iB,x[iB],yUp[iB]);
		xErr[iB] = 0;
		yUp[iB] = 0;
		yLw[iB] = 0;
		yUpErr[iB] = 0;
		yLwErr[iB] = 0;
		for(unsigned int iS=1; iS<NS; iS++)
		{
			double yTmp; double eTmp;
			gVec.at(iS)->GetPoint(iB,eTmp,yTmp);
			eTmp = gVec.at(iS)->GetErrorY(iB);
			if(yTmp>=0)
			{
				yUp[iB] += pow(yTmp,2);
				yUpErr[iB] += pow(eTmp,2);
			}
			else
			{
				yLw[iB] += pow(yTmp,2);
				yLwErr[iB] += pow(eTmp,2);
			}
		}
		yUp[iB] = +sqrt(yUp[iB]);
		yLw[iB] = -sqrt(yLw[iB]);
		yUpErr[iB] = sqrt(yUpErr[iB]);
		yLwErr[iB] = sqrt(yLwErr[iB]);
	}

	gSysUp = new TGraphErrors(NB,x,yUp,xErr,yUpErr);
	if(iC<0) sprintf(name,"sysUp_%s_Har%d_PtRef%d",gName,iV,iR);
	else sprintf(name,"sysUp_%s_Har%d_PtRef%d_Cent%d",gName,iV,iR,iC);
	gSysUp->SetName(name);

	gSysLw = new TGraphErrors(NB,x,yLw,xErr,yLwErr);
	if(iC<0) sprintf(name,"sysLw_%s_Har%d_PtRef%d",gName,iV,iR);
	else sprintf(name,"sysLw_%s_Har%d_PtRef%d_Cent%d",gName,iV,iR,iC);
	gSysLw->SetName(name);
}

void CombSys::readHist_VR(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iF, int iS, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_File%d_Sys%d_Har%d_PtRef%d",hNewName,iF,iS,iV,iR);
	hIn->SetName(name);
}

void CombSys::readHist_VRC(TFile* fIn, TGraphErrors*& hIn, const char* hName, const char* hNewName, int iF, int iS, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
	sprintf(name,"%s_File%d_Sys%d_Har%d_PtRef%d_Cent%d",hNewName,iF,iS,iV,iR,iC);
	hIn->SetName(name);
}

void CombSys::set_sys(TGraphErrors* gRatio, double sys1, double sys2)
{
	int NX = gRatio->GetN();
	for(int iX=0; iX<NX; iX++)
	{
		double x = 0;
		double y = 0;
		gRatio->GetPoint(iX,x,y);
		if(sys2!=0 && x>=9) y = sys2;
		else y = sys1;
		gRatio->SetPoint(iX,x,y/100);
	}
}

void CombSys::smooth()
{
	// special smoothing for MC closure
	for(unsigned int iS=5; iS<6; iS++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				for(unsigned int iB=0; iB<nCent; iB++)
				{
					reduce_ratio(ratio_c4_1sub[iS][iV][iR],iB,0.5);
					reduce_ratio(ratio_c6_1sub[iS][iV][iR],iB,0.5);
					reduce_ratio(ratio_nc4_1sub[iS][iV][iR],iB,0.5);
					reduce_ratio(ratio_nc6_1sub[iS][iV][iR],iB,0.5);
					
					reduce_ratio(ratio_sc_1sub[iS][iV][iR],iB,1e-9);
					reduce_ratio(ratio_ac_1sub[iS][iV][iR],iB,1e-9);
					reduce_ratio(ratio_nsc_1sub[iS][iV][iR],iB,1e-9);
					reduce_ratio(ratio_nac_1sub[iS][iV][iR],iB,1e-9);
				}
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					for(unsigned int iB=0; iB<NP; iB++)
					{
						reduce_ratio(ratio_vd4_1sub[iS][iV][iR][iC],iB,0.5);
					}
				}
				for(unsigned int iC=0; iC<nCent; iC++)
				{
					reduce_ratio(ratio_vd2_1sub[iS][iV][iR][iC],5,0.2);
					reduce_ratio(ratio_vd4_1sub[iS][iV][iR][iC],5,0.2);
				}
			}
		}
	}

	// sys_c2_1sub_Har3_PtRef0
	for(unsigned int iB=0; iB<nCent; iB++) reduce_ratio(ratio_c2_1sub[3][3][0],iB,0.5);

	// sys_c4_1sub_Har2_PtRef0
	smooth_ratio(ratio_c4_1sub[4][2][0],0,0.2);
	smooth_ratio(ratio_c4_1sub[6][2][0],0,0.2);

	// sys_c4_1sub_Har3_PtRef0
	smooth_ratio(ratio_c4_1sub[3][3][0],0,0.1);
	smooth_ratio(ratio_c4_1sub[6][3][0],0,0.2);
	smooth_ratio(ratio_c4_1sub[3][3][0],5,0.2);

	// sys_c4_1sub_Har4_PtRef0
	smooth_ratio(ratio_c4_1sub[3][4][0],0,0.2);
	smooth_ratio(ratio_c4_1sub[6][4][0],2,0.1);
	reduce_ratio(ratio_c4_1sub[1][4][0],2,0.5);
	reduce_ratio(ratio_c4_1sub[2][4][0],2,0.5);
	reduce_ratio(ratio_c4_1sub[3][4][0],2,0.2);
	reduce_ratio(ratio_c4_1sub[6][4][0],2,0.1);
	smooth_ratio(ratio_c4_1sub[3][4][0],3,0.2);
	reduce_ratio(ratio_c4_1sub[3][4][0],5,0.3);
	smooth_ratio(ratio_c4_1sub[6][4][0],6,0.2);
	reduce_ratio(ratio_c4_1sub[5][4][0],6,0.5);
	reduce_ratio(ratio_c4_1sub[6][4][0],6,0.5);

	// sys_c6_1sub_Har2_PtRef0
	smooth_ratio(ratio_c6_1sub[4][2][0],0,0.2);
	reduce_ratio(ratio_c6_1sub[4][2][0],0,0.5);
	smooth_ratio(ratio_c6_1sub[6][2][0],0,0.2);
	smooth_ratio(ratio_c6_1sub[6][2][0],6,0.2);

	// sys_c6_1sub_Har3_PtRef0
	smooth_ratio(ratio_c6_1sub[3][3][0],0,0.2);
	smooth_ratio(ratio_c6_1sub[3][3][0],1,0.2);
	smooth_ratio(ratio_c6_1sub[6][3][0],1,0.2);
	smooth_ratio(ratio_c6_1sub[3][3][0],6,0.2);
	reduce_ratio(ratio_c6_1sub[3][3][0],6,0.3);

	// sys_v2_1sub_Har3_PtRef0
	for(int i=0; i<7; i++) reduce_ratio(ratio_v2_1sub[3][3][0],i,0.3);

	// sys_v4_1sub_Har2_PtRef0
	smooth_ratio(ratio_v4_1sub[6][2][0],0,0.2);

	// sys_v4_1sub_Har3_PtRef0
	smooth_ratio(ratio_v4_1sub[3][3][0],0,0.2);
	smooth_ratio(ratio_v4_1sub[4][3][0],0,0.2);
	smooth_ratio(ratio_v4_1sub[6][3][0],0,0.2);
	smooth_ratio(ratio_v4_1sub[3][3][0],5,0.2);
	smooth_ratio(ratio_v4_1sub[6][3][0],5,0.2);
	smooth_ratio(ratio_v4_1sub[3][3][0],6,0.2);
	smooth_ratio(ratio_v4_1sub[6][3][0],6,0.2);
	reduce_ratio(ratio_v4_1sub[3][3][0],0,0.3);
	reduce_ratio(ratio_v4_1sub[4][3][0],0,0.5);
	reduce_ratio(ratio_v4_1sub[6][3][0],0,0.5);
	reduce_ratio(ratio_v4_1sub[6][3][0],6,0.3);

	// sys_v4_1sub_Har4_PtRef0
	smooth_ratio(ratio_v4_1sub[6][4][0],0,0.2);
	smooth_ratio(ratio_v4_1sub[6][4][0],2,0.2);
	smooth_ratio(ratio_v4_1sub[6][4][0],5,0.2);
	smooth_ratio(ratio_v4_1sub[2][4][0],6,0.2);
	smooth_ratio(ratio_v4_1sub[3][4][0],6,0.2);

	// sys_v6_1sub_Har2_PtRef0
	smooth_ratio(ratio_v6_1sub[4][2][0],0,0.2);

	// sys_v6_1sub_Har3_PtRef0
	reduce_ratio(ratio_v6_1sub[3][3][0],0,0.5);
	smooth_ratio(ratio_v6_1sub[3][3][0],1,0.2);
	reduce_ratio(ratio_v6_1sub[3][3][0],1,0.5);
	for(int i=0; i<7; i++) reduce_ratio(ratio_v6_1sub[6][3][0],i,0.5);

	// sys_v6_1sub_Har4_PtRef0
	for(int i=0; i<7; i++) reduce_ratio(ratio_v6_1sub[6][4][0],i,0.4);
	
	// sys_cr42_1sub_Har2_PtRef0
	reduce_ratio(ratio_cr42_1sub[3][2][0],6,0.1);

	// sys_sc_1sub_Har0_PtRef0
	smooth_ratio(ratio_sc_1sub[3][0][0],1,0.2);
	smooth_ratio(ratio_sc_1sub[3][0][0],6,0.2);
	reduce_ratio(ratio_sc_1sub[5][0][0],6,0.2);
	smooth_ratio(ratio_sc_1sub[6][0][0],6,0.2);

	// sys_sc_1sub_Har1_PtRef0
	reduce_ratio(ratio_sc_1sub[5][1][0],6,0.5);
	smooth_ratio(ratio_sc_1sub[6][1][0],6,0.2);

	// sys_nsc_1sub_Har0_PtRef0
	smooth_ratio(ratio_nsc_1sub[3][0][0],6,0.2);
	reduce_ratio(ratio_nsc_1sub[3][0][0],6,0.5);
	smooth_ratio(ratio_nsc_1sub[6][0][0],6,0.2);
	reduce_ratio(ratio_nsc_1sub[5][0][0],6,0.3);
	reduce_ratio(ratio_nsc_1sub[6][0][0],6,0.3);

	// sys_nsc_1sub_Har1_PtRef0
	for(int i=0; i<7; i++) reduce_ratio(ratio_nsc_1sub[6][1][0],i,0.01);
	reduce_ratio(ratio_nsc_1sub[2][1][0],6,0.3);
	smooth_ratio(ratio_nsc_1sub[3][1][0],6,0.2);

	// sys_nac_1sub_Har2_PtRef0
	for(int i=0; i<7; i++) reduce_ratio(ratio_nac_1sub[6][2][0],i,0.01);
	smooth_ratio(ratio_nac_1sub[3][2][0],6,0.2);
	reduce_ratio(ratio_nac_1sub[2][2][0],6,0.2);
	reduce_ratio(ratio_nac_1sub[3][2][0],6,0.5);
	
	// sys_vd2_1sub_Har3_PtRef0_CentX
	for(unsigned int iC=0; iC<nCent; iC++)
	{
		for(int i=0; i<7; i++) reduce_ratio(ratio_vd2_1sub[3][3][0][iC],i,0.3);
	}

	// sys_vd4_1sub_Har2_PtRef0_Cent0
	reduce_ratio(ratio_vd4_1sub[3][2][0][0],4,0.5);
	reduce_ratio(ratio_vd4_1sub[6][2][0][0],4,0.5);
	reduce_ratio(ratio_vd4_1sub[6][2][0][0],5,0.5);

	// sys_vd4_1sub_Har2_PtRef0_Cent2
	reduce_ratio(ratio_vd4_1sub[3][2][0][2],5,0.5);
	reduce_ratio(ratio_vd4_1sub[6][2][0][2],5,0.5);

	// sys_vd4_1sub_Har2_PtRef0_Cent4
	reduce_ratio(ratio_vd4_1sub[3][2][0][4],5,0.5);
	reduce_ratio(ratio_vd4_1sub[6][2][0][4],5,0.5);

	// sys_vd4_1sub_Har2_PtRef0_Cent5
	reduce_ratio(ratio_vd4_1sub[3][2][0][5],5,0.5);
	reduce_ratio(ratio_vd4_1sub[6][2][0][5],5,0.5);

	// sys_vd4_1sub_Har3_PtRef0_Cent0
	for(int i=0; i<6; i++) reduce_ratio(ratio_vd4_1sub[3][3][0][0],i,0.4);
	reduce_ratio(ratio_vd4_1sub[6][3][0][0],3,0.5);
	reduce_ratio(ratio_vd4_1sub[6][3][0][0],4,0.2);
	reduce_ratio(ratio_vd4_1sub[6][3][0][0],5,0.5);

	// sys_vd4_1sub_Har3_PtRef0_Cent1
	for(int i=0; i<6; i++) reduce_ratio(ratio_vd4_1sub[3][3][0][1],i,0.3);
	reduce_ratio(ratio_vd4_1sub[6][3][0][1],4,0.2);

	// sys_vd4_1sub_Har3_PtRef0_Cent2
	reduce_ratio(ratio_vd4_1sub[3][3][0][2],4,0.5);
	reduce_ratio(ratio_vd4_1sub[3][3][0][2],5,0.3);

	// sys_vd4_1sub_Har3_PtRef0_Cent3
	reduce_ratio(ratio_vd4_1sub[6][3][0][3],4,0.3);
	reduce_ratio(ratio_vd4_1sub[6][3][0][3],5,0.3);

	// sys_vd4_1sub_Har3_PtRef0_Cent4
	for(int i=0; i<6; i++) reduce_ratio(ratio_vd4_1sub[6][3][0][4],i,0.5);
	reduce_ratio(ratio_vd4_1sub[3][3][0][4],0,0.5);
	reduce_ratio(ratio_vd4_1sub[3][3][0][4],1,0.2);
	reduce_ratio(ratio_vd4_1sub[3][3][0][4],5,0.5);

	// sys_vd4_1sub_Har3_PtRef0_Cent5
	reduce_ratio(ratio_vd4_1sub[3][3][0][5],4,0.3);
	reduce_ratio(ratio_vd4_1sub[3][3][0][5],5,0.3);
	reduce_ratio(ratio_vd4_1sub[6][3][0][5],0,0.5);
	reduce_ratio(ratio_vd4_1sub[6][3][0][5],3,0.2);
	reduce_ratio(ratio_vd4_1sub[5][3][0][5],0,0.1);
	reduce_ratio(ratio_vd4_1sub[5][3][0][5],2,0.2);

/*
*/
}




