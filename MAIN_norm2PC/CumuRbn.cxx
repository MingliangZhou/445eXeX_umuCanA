#include "CumuRbn.h"

CumuRbn::CumuRbn(TFile* fIn, unsigned int iRebin)
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		sprintf(name,"cnt_1sub_PtRef%d",iR);
		cnt_1sub[iR] = (TH1D*)fIn->Get(name);
		for(unsigned int iV=0; iV<NV; iV++)
		{
			readHist_VR(fIn,pc2_1sub_mean[iV][iR],"pc2_1sub_mean",iV,iR);
			readHist_VR(fIn,pc2_1sub_wght[iV][iR],"pc2_1sub_wght",iV,iR);
			readHist_VR(fIn,pc4_1sub_mean[iV][iR],"pc4_1sub_mean",iV,iR);
			readHist_VR(fIn,pc4_1sub_wght[iV][iR],"pc4_1sub_wght",iV,iR);
			readHist_VR(fIn,pc6_1sub_mean[iV][iR],"pc6_1sub_mean",iV,iR);
			readHist_VR(fIn,pc6_1sub_wght[iV][iR],"pc6_1sub_wght",iV,iR);
			readHist_VR(fIn,psc4_1sub_mean[iV][iR],"psc4_1sub_mean",iV,iR);
			readHist_VR(fIn,psc4_1sub_wght[iV][iR],"psc4_1sub_wght",iV,iR);
			readHist_VR(fIn,pac3_1sub_mean[iV][iR],"pac3_1sub_mean",iV,iR);
			readHist_VR(fIn,pac3_1sub_wght[iV][iR],"pac3_1sub_wght",iV,iR);
		}
		for(unsigned int iP=0; iP<NP; iP++)
		{
			sprintf(name,"cnt_1sub_diff_PtRef%d_Pt%d",iR,iP);
			cnt_1sub_diff[iR][iP] = (TH1D*)fIn->Get(name);
			for(unsigned int iV=0; iV<NV; iV++)
			{
				readHist_VRP(fIn,pd2_1sub_mean[iV][iR][iP],"pd2_1sub_mean",iV,iR,iP);
				readHist_VRP(fIn,pd2_1sub_wght[iV][iR][iP],"pd2_1sub_wght",iV,iR,iP);
				readHist_VRP(fIn,pd4_1sub_mean[iV][iR][iP],"pd4_1sub_mean",iV,iR,iP);
				readHist_VRP(fIn,pd4_1sub_wght[iV][iR][iP],"pd4_1sub_wght",iV,iR,iP);
			}
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			sprintf(name,"cnt_3sub_Pm%d_PtRef%d",iA,iR);
			cnt_3sub[iA][iR] = (TH1D*)fIn->Get(name);
			sprintf(name,"rbn_cnt_3sub_Pm%d_Pt%d",iA,iR);
			rbn_cnt_3sub[iA][iR] = (TH1D*)cnt_3sub[iA][iR]->Clone(name);
			rbn_cnt_3sub[iA][iR]->Rebin(nRebin[iRebin],"",xRebin[iRebin]);
			for(unsigned int iV=0; iV<NV; iV++)
			{
				readHist_AVR(fIn,pc2_1_3sub_mean[iA][iV][iR],"pc2_1_3sub_mean",iA,iV,iR);
				readHist_AVR(fIn,pc2_1_3sub_wght[iA][iV][iR],"pc2_1_3sub_wght",iA,iV,iR);
				readHist_AVR(fIn,pc2_2_3sub_mean[iA][iV][iR],"pc2_2_3sub_mean",iA,iV,iR);
				readHist_AVR(fIn,pc2_2_3sub_wght[iA][iV][iR],"pc2_2_3sub_wght",iA,iV,iR);
				readHist_AVR(fIn,pc4_3sub_mean[iA][iV][iR],"pc4_3sub_mean",iA,iV,iR);
				readHist_AVR(fIn,pc4_3sub_wght[iA][iV][iR],"pc4_3sub_wght",iA,iV,iR);
				readHist_AVR(fIn,psc4_3sub_mean[iA][iV][iR],"psc4_3sub_mean",iA,iV,iR);
				readHist_AVR(fIn,psc4_3sub_wght[iA][iV][iR],"psc4_3sub_wght",iA,iV,iR);
				readHist_AVR(fIn,pac3_3sub_mean[iA][iV][iR],"pac3_3sub_mean",iA,iV,iR);
				readHist_AVR(fIn,pac3_3sub_wght[iA][iV][iR],"pac3_3sub_wght",iA,iV,iR);
			}
		}
	}

	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			initHist_VR(raw_c2_1sub[iV][iR],"raw_c2_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_c2_1sub[iV][iR],"rbn_c2_1sub",iV,iR,rbn,iRebin);
			initHist_VR(cen_c2_1sub[iV][iR],"cen_c2_1sub",iV,iR,cen,iRebin);
			initHist_VR(raw_c4_1sub[iV][iR],"raw_c4_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_c4_1sub[iV][iR],"rbn_c4_1sub",iV,iR,rbn,iRebin);
			initHist_VR(cen_c4_1sub[iV][iR],"cen_c4_1sub",iV,iR,cen,iRebin);
			initHist_VR(raw_c6_1sub[iV][iR],"raw_c6_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_c6_1sub[iV][iR],"rbn_c6_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_nc4_1sub[iV][iR],"raw_nc4_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_nc4_1sub[iV][iR],"rbn_nc4_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_nc6_1sub[iV][iR],"raw_nc6_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_nc6_1sub[iV][iR],"rbn_nc6_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_v2_1sub[iV][iR],"raw_v2_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_v2_1sub[iV][iR],"rbn_v2_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_v4_1sub[iV][iR],"raw_v4_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_v4_1sub[iV][iR],"rbn_v4_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_v6_1sub[iV][iR],"raw_v6_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_v6_1sub[iV][iR],"rbn_v6_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_cr42_1sub[iV][iR],"raw_cr42_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_cr42_1sub[iV][iR],"rbn_cr42_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_cr64_1sub[iV][iR],"raw_cr64_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_cr64_1sub[iV][iR],"rbn_cr64_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_sc_1sub[iV][iR],"raw_sc_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_sc_1sub[iV][iR],"rbn_sc_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_nsc_1sub[iV][iR],"raw_nsc_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_nsc_1sub[iV][iR],"rbn_nsc_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_ac_1sub[iV][iR],"raw_ac_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_ac_1sub[iV][iR],"rbn_ac_1sub",iV,iR,rbn,iRebin);
			initHist_VR(raw_nac_1sub[iV][iR],"raw_nac_1sub",iV,iR,raw,iRebin);
			initHist_VR(rbn_nac_1sub[iV][iR],"rbn_nac_1sub",iV,iR,rbn,iRebin);
		}
		for(unsigned int iP=0; iP<NP; iP++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				initHist_VRP(raw_d2_1sub[iV][iR][iP],"raw_d2_1sub",iV,iR,iP,raw,iRebin);
				initHist_VRP(cen_d2_1sub[iV][iR][iP],"cen_d2_1sub",iV,iR,iP,cen,iRebin);
				initHist_VRP(cen_vd2_1sub[iV][iR][iP],"cen_vd2_1sub",iV,iR,iP,cen,iRebin);
				initHist_VRP(raw_d4_1sub[iV][iR][iP],"raw_d4_1sub",iV,iR,iP,raw,iRebin);
				initHist_VRP(cen_d4_1sub[iV][iR][iP],"cen_d4_1sub",iV,iR,iP,cen,iRebin);
				initHist_VRP(cen_vd4_1sub[iV][iR][iP],"cen_vd4_1sub",iV,iR,iP,cen,iRebin);
			}
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				initHist_AVR(raw_c2_3sub[iA][iV][iR],"raw_c2_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_c2_3sub[iA][iV][iR],"rbn_c2_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_c4_3sub[iA][iV][iR],"raw_c4_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_c4_3sub[iA][iV][iR],"rbn_c4_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_v2_3sub[iA][iV][iR],"raw_v2_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_v2_3sub[iA][iV][iR],"rbn_v2_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_v4_3sub[iA][iV][iR],"raw_v4_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_v4_3sub[iA][iV][iR],"rbn_v4_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_sc_3sub[iA][iV][iR],"raw_sc_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_sc_3sub[iA][iV][iR],"rbn_sc_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_nsc_3sub[iA][iV][iR],"raw_nsc_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_nsc_3sub[iA][iV][iR],"rbn_nsc_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_ac_3sub[iA][iV][iR],"raw_ac_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_ac_3sub[iA][iV][iR],"rbn_ac_3sub",iA,iV,iR,rbn,iRebin);
				initHist_AVR(raw_nac_3sub[iA][iV][iR],"raw_nac_3sub",iA,iV,iR,raw,iRebin);
				initHist_AVR(rbn_nac_3sub[iA][iV][iR],"rbn_nac_3sub",iA,iV,iR,rbn,iRebin);
			}
		}
	}
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				initHist_VRC(pT_vd2_1sub[iV][iR][iC],"pT_vd2_1sub",iV,iR,iC);
				initHist_VRC(pT_vd4_1sub[iV][iR][iC],"pT_vd4_1sub",iV,iR,iC);
			}
		}
	}
}

CumuRbn::~CumuRbn()
{
}

void CumuRbn::cal_all()
{
	run_c();
	run_d();
	run_sc();
	run_ac();
	run_nc();
	run_nsc();
	run_nac();
	run_cr();
}

void CumuRbn::run_c()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			pc2_1sub_mean[iV][iR]->Divide(pc2_1sub_wght[iV][iR]);
			pc4_1sub_mean[iV][iR]->Divide(pc4_1sub_wght[iV][iR]);
			pc6_1sub_mean[iV][iR]->Divide(pc6_1sub_wght[iV][iR]);

			cal_c_1sub(pc2_1sub_mean[iV][iR],pc4_1sub_mean[iV][iR],pc6_1sub_mean[iV][iR],raw_c2_1sub[iV][iR],raw_c4_1sub[iV][iR],raw_c6_1sub[iV][iR]);

			rebin_cumu(raw_c2_1sub[iV][iR],cnt_1sub[iR],rbn_c2_1sub[iV][iR]);
			rebin_cumu(raw_c2_1sub[iV][iR],cnt_1sub[iR],cen_c2_1sub[iV][iR]);
			rebin_cumu(raw_c4_1sub[iV][iR],cnt_1sub[iR],rbn_c4_1sub[iV][iR]);
			rebin_cumu(raw_c4_1sub[iV][iR],cnt_1sub[iR],cen_c4_1sub[iV][iR]);
			rebin_cumu(raw_c6_1sub[iV][iR],cnt_1sub[iR],rbn_c6_1sub[iV][iR]);
		}
		for(unsigned int iP=0; iP<NP; iP++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				pd2_1sub_mean[iV][iR][iP]->Divide(pd2_1sub_wght[iV][iR][iP]);
				pd4_1sub_mean[iV][iR][iP]->Divide(pd4_1sub_wght[iV][iR][iP]);

				cal_d_1sub(pd2_1sub_mean[iV][iR][iP],pc2_1sub_mean[iV][iR],pd4_1sub_mean[iV][iR][iP],raw_d2_1sub[iV][iR][iP],raw_d4_1sub[iV][iR][iP]);

				rebin_cumu(raw_d2_1sub[iV][iR][iP],cnt_1sub_diff[iR][iP],cen_d2_1sub[iV][iR][iP]);
				rebin_cumu(raw_d4_1sub[iV][iR][iP],cnt_1sub_diff[iR][iP],cen_d4_1sub[iV][iR][iP]);

				cal_vd_1sub(cen_c2_1sub[iV][iR],cen_d2_1sub[iV][iR][iP],cen_c4_1sub[iV][iR],cen_d4_1sub[iV][iR][iP],cen_vd2_1sub[iV][iR][iP],cen_vd4_1sub[iV][iR][iP]);
			}
		}
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iA=0; iA<NA; iA++)
			{
				pc2_1_3sub_mean[iA][iV][iR]->Divide(pc2_1_3sub_wght[iA][iV][iR]);
				pc2_2_3sub_mean[iA][iV][iR]->Divide(pc2_2_3sub_wght[iA][iV][iR]);
				pc4_3sub_mean[iA][iV][iR]->Divide(pc4_3sub_wght[iA][iV][iR]);

				cal_c_3sub(pc2_1_3sub_mean[iA][iV][iR],pc2_2_3sub_mean[iA][iV][iR],pc4_3sub_mean[iA][iV][iR],raw_c2_3sub[iA][iV][iR],raw_c4_3sub[iA][iV][iR]);

				rebin_cumu(raw_c2_3sub[iA][iV][iR],cnt_3sub[iA][iR],rbn_c2_3sub[iA][iV][iR]);
				rebin_cumu(raw_c4_3sub[iA][iV][iR],cnt_3sub[iA][iR],rbn_c4_3sub[iA][iV][iR]);
			}
			merge3sub(raw_c4_3sub[0][iV][iR],cnt_3sub[0][iR],raw_c4_3sub[1][iV][iR],cnt_3sub[1][iR],raw_c4_3sub[2][iV][iR],cnt_3sub[2][iR]);
			merge3sub(rbn_c4_3sub[0][iV][iR],rbn_cnt_3sub[0][iR],rbn_c4_3sub[1][iV][iR],rbn_cnt_3sub[1][iR],rbn_c4_3sub[2][iV][iR],rbn_cnt_3sub[2][iR]);
		}
	}
}

void CumuRbn::run_d()
{
	vector<TH1D*> hPts;
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iP=0; iP<NP; iP++) hPts.push_back(cen_vd2_1sub[iV][iR][iP]);
			for(unsigned int iC=0; iC<nCent; iC++) cvt_cent_pt(hPts,pT_vd2_1sub[iV][iR][iC],iC);
			hPts.clear();
			for(unsigned int iP=0; iP<NP; iP++) hPts.push_back(cen_vd4_1sub[iV][iR][iP]);
			for(unsigned int iC=0; iC<nCent; iC++) cvt_cent_pt(hPts,pT_vd4_1sub[iV][iR][iC],iC);
			hPts.clear();
		}
	}
}

void CumuRbn::run_sc()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			psc4_1sub_mean[iV][iR]->Divide(psc4_1sub_wght[iV][iR]);

			if(iV==0) cal_sc(pc2_1sub_mean[2][iR],pc2_1sub_mean[3][iR],psc4_1sub_mean[iV][iR],raw_sc_1sub[iV][iR]);
			if(iV==1) cal_sc(pc2_1sub_mean[2][iR],pc2_1sub_mean[4][iR],psc4_1sub_mean[iV][iR],raw_sc_1sub[iV][iR]);

			rebin_cumu(raw_sc_1sub[iV][iR],cnt_1sub[iR],rbn_sc_1sub[iV][iR]);
		}
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iA=0; iA<NA; iA++)
			{
				psc4_3sub_mean[iA][iV][iR]->Divide(psc4_3sub_wght[iA][iV][iR]);

				if(iV==0)cal_sc(pc2_1_3sub_mean[iA][2][iR],pc2_2_3sub_mean[iA][3][iR],psc4_3sub_mean[iA][iV][iR],raw_sc_3sub[iA][iV][iR]);
				if(iV==1)cal_sc(pc2_1_3sub_mean[iA][2][iR],pc2_2_3sub_mean[iA][4][iR],psc4_3sub_mean[iA][iV][iR],raw_sc_3sub[iA][iV][iR]);

				rebin_cumu(raw_sc_3sub[iA][iV][iR],cnt_3sub[iA][iR],rbn_sc_3sub[iA][iV][iR]);
			}
			merge3sub(raw_sc_3sub[0][iV][iR],cnt_3sub[0][iR],raw_sc_3sub[1][iV][iR],cnt_3sub[1][iR],raw_sc_3sub[2][iV][iR],cnt_3sub[2][iR]);
			merge3sub(rbn_sc_3sub[0][iV][iR],rbn_cnt_3sub[0][iR],rbn_sc_3sub[1][iV][iR],rbn_cnt_3sub[1][iR],rbn_sc_3sub[2][iV][iR],rbn_cnt_3sub[2][iR]);
		}
	}
}

void CumuRbn::run_ac()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			pac3_1sub_mean[iV][iR]->Divide(pac3_1sub_wght[iV][iR]);

			cal_ac(pac3_1sub_mean[iV][iR],raw_ac_1sub[iV][iR]);

			rebin_cumu(raw_ac_1sub[iV][iR],cnt_1sub[iR],rbn_ac_1sub[iV][iR]);
		}
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iA=0; iA<NA; iA++)
			{
				pac3_3sub_mean[iA][iV][iR]->Divide(pac3_3sub_wght[iA][iV][iR]);

				cal_ac(pac3_3sub_mean[iA][iV][iR],raw_ac_3sub[iA][iV][iR]);

				rebin_cumu(raw_ac_3sub[iA][iV][iR],cnt_3sub[iA][iV],rbn_ac_3sub[iA][iV][iR]);
			}
			merge3sub(raw_ac_3sub[0][iV][iR],cnt_3sub[0][iV],raw_ac_3sub[1][iV][iR],cnt_3sub[1][iV],raw_ac_3sub[2][iV][iR],cnt_3sub[2][iV]);
			merge3sub(rbn_ac_3sub[0][iV][iR],rbn_cnt_3sub[0][iV],rbn_ac_3sub[1][iV][iR],rbn_cnt_3sub[1][iV],rbn_ac_3sub[2][iV][iR],rbn_cnt_3sub[2][iV]);
		}
	}
}

void CumuRbn::run_nc()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			cal_nc(raw_c2_3sub[1][iV][iR],raw_c4_1sub[iV][iR],raw_c6_1sub[iV][iR],raw_nc4_1sub[iV][iR],raw_nc6_1sub[iV][iR]);
			cal_nc(rbn_c2_3sub[1][iV][iR],rbn_c4_1sub[iV][iR],rbn_c6_1sub[iV][iR],rbn_nc4_1sub[iV][iR],rbn_nc6_1sub[iV][iR]);
		}
	}
}

void CumuRbn::run_nsc()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			if(iV==0)
			{
				cal_nsc(raw_c2_3sub[1][2][iR],raw_c2_3sub[1][3][iR],raw_sc_1sub[iV][iR],raw_nsc_1sub[iV][iR]);
				cal_nsc(rbn_c2_3sub[1][2][iR],rbn_c2_3sub[1][3][iR],rbn_sc_1sub[iV][iR],rbn_nsc_1sub[iV][iR]);
			}
			if(iV==1)
			{
				cal_nsc(raw_c2_3sub[1][2][iR],raw_c2_3sub[1][4][iR],raw_sc_1sub[iV][iR],raw_nsc_1sub[iV][iR]);
				cal_nsc(rbn_c2_3sub[1][2][iR],rbn_c2_3sub[1][4][iR],rbn_sc_1sub[iV][iR],rbn_nsc_1sub[iV][iR]);
			}
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				if(iV==0)
				{
					cal_nsc(raw_c2_3sub[1][2][iR],raw_c2_3sub[1][3][iR],raw_sc_3sub[iA][iV][iR],raw_nsc_3sub[iA][iV][iR]);
					cal_nsc(rbn_c2_3sub[1][2][iR],rbn_c2_3sub[1][3][iR],rbn_sc_3sub[iA][iV][iR],rbn_nsc_3sub[iA][iV][iR]);
				}
				if(iV==1)
				{
					cal_nsc(raw_c2_3sub[1][2][iR],raw_c2_3sub[1][4][iR],raw_sc_3sub[iA][iV][iR],raw_nsc_3sub[iA][iV][iR]);
					cal_nsc(rbn_c2_3sub[1][2][iR],rbn_c2_3sub[1][4][iR],rbn_sc_3sub[iA][iV][iR],rbn_nsc_3sub[iA][iV][iR]);
				}
			}
		}
	}
}

void CumuRbn::run_nac()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			if(iV==0)
			{
				cal_nac(raw_c4_3sub[0][1][iR],raw_c2_3sub[1][1][iR],raw_c2_3sub[1][2][iR],raw_ac_1sub[iV][iR],raw_nac_1sub[iV][iR]);
				cal_nac(rbn_c4_3sub[0][1][iR],rbn_c2_3sub[1][1][iR],rbn_c2_3sub[1][2][iR],rbn_ac_1sub[iV][iR],rbn_nac_1sub[iV][iR]);
			}
			if(iV==1)
			{
				cal_nac(raw_c4_3sub[0][1][iR],raw_c2_3sub[1][1][iR],raw_c2_3sub[1][3][iR],raw_ac_1sub[iV][iR],raw_nac_1sub[iV][iR]);
				cal_nac(rbn_c4_3sub[0][1][iR],rbn_c2_3sub[1][1][iR],rbn_c2_3sub[1][3][iR],rbn_ac_1sub[iV][iR],rbn_nac_1sub[iV][iR]);
			}
			if(iV==2)
			{
				cal_nac(raw_c4_3sub[0][2][iR],raw_c2_3sub[1][2][iR],raw_c2_3sub[1][4][iR],raw_ac_1sub[iV][iR],raw_nac_1sub[iV][iR]);
				cal_nac(rbn_c4_3sub[0][2][iR],rbn_c2_3sub[1][2][iR],rbn_c2_3sub[1][4][iR],rbn_ac_1sub[iV][iR],rbn_nac_1sub[iV][iR]);
			}
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				if(iV==0)
				{
					cal_nac(raw_c4_3sub[0][1][iR],raw_c2_3sub[1][1][iR],raw_c2_3sub[1][2][iR],raw_ac_3sub[iA][iV][iR],raw_nac_3sub[iA][iV][iR]);
					cal_nac(rbn_c4_3sub[0][1][iR],rbn_c2_3sub[1][1][iR],rbn_c2_3sub[1][2][iR],rbn_ac_3sub[iA][iV][iR],rbn_nac_3sub[iA][iV][iR]);
				}
				if(iV==1)
				{
					cal_nac(raw_c4_3sub[0][1][iR],raw_c2_3sub[1][1][iR],raw_c2_3sub[1][3][iR],raw_ac_3sub[iA][iV][iR],raw_nac_3sub[iA][iV][iR]);
					cal_nac(rbn_c4_3sub[0][1][iR],rbn_c2_3sub[1][1][iR],rbn_c2_3sub[1][3][iR],rbn_ac_3sub[iA][iV][iR],rbn_nac_3sub[iA][iV][iR]);
				}
				if(iV==2)
				{
					cal_nac(raw_c4_3sub[0][2][iR],raw_c2_3sub[1][2][iR],raw_c2_3sub[1][4][iR],raw_ac_3sub[iA][iV][iR],raw_nac_3sub[iA][iV][iR]);
					cal_nac(rbn_c4_3sub[0][2][iR],rbn_c2_3sub[1][2][iR],rbn_c2_3sub[1][4][iR],rbn_ac_3sub[iA][iV][iR],rbn_nac_3sub[iA][iV][iR]);
				}
			}
		}
	}
}

void CumuRbn::run_cr()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			cal_v_1sub(raw_c2_1sub[iV][iR],raw_c4_1sub[iV][iR],raw_c6_1sub[iV][iR],raw_v2_1sub[iV][iR],raw_v4_1sub[iV][iR],raw_v6_1sub[iV][iR]);
			cal_v_1sub(rbn_c2_1sub[iV][iR],rbn_c4_1sub[iV][iR],rbn_c6_1sub[iV][iR],rbn_v2_1sub[iV][iR],rbn_v4_1sub[iV][iR],rbn_v6_1sub[iV][iR]);
		}
	}
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iA=0; iA<NA; iA++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				cal_v_3sub(raw_c2_3sub[iA][iV][iR],raw_c4_3sub[iA][iV][iR],raw_v2_3sub[iA][iV][iR],raw_v4_3sub[iA][iV][iR]);
				cal_v_3sub(rbn_c2_3sub[iA][iV][iR],rbn_c4_3sub[iA][iV][iR],rbn_v2_3sub[iA][iV][iR],rbn_v4_3sub[iA][iV][iR]);
			}
		}
	}
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			cal_cr(raw_v2_3sub[1][iV][iR],raw_v4_1sub[iV][iR],raw_v6_1sub[iV][iR],raw_cr42_1sub[iV][iR],raw_cr64_1sub[iV][iR]);
			cal_cr(rbn_v2_3sub[1][iV][iR],rbn_v4_1sub[iV][iR],rbn_v6_1sub[iV][iR],rbn_cr42_1sub[iV][iR],rbn_cr64_1sub[iV][iR]);
		}
	}
}

void CumuRbn::cal_c_1sub(TH1D* pc2, TH1D* pc4, TH1D* pc6, TH1D* c2, TH1D* c4, TH1D* c6)
{
	int NX = c2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2 = pc2->GetBinContent(iX+1);
		double p4 = pc4->GetBinContent(iX+1);
		double p6 = pc6->GetBinContent(iX+1);
		c2->SetBinContent(iX+1,p2);
		c4->SetBinContent(iX+1,p4-2.*pow(p2,2));
		c6->SetBinContent(iX+1,p6-9.*p4*p2+12.*pow(p2,3));
	}
}

void CumuRbn::cal_d_1sub(TH1D* pd2, TH1D* pc2, TH1D* pd4, TH1D* d2, TH1D* d4)
{
	int NX = d2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2d = pd2->GetBinContent(iX+1);
		double p2c = pc2->GetBinContent(iX+1);
		double p4 = pd4->GetBinContent(iX+1);
		d2->SetBinContent(iX+1,p2d);
		d4->SetBinContent(iX+1,p4-2.*p2d*p2c);
	}
}

void CumuRbn::cal_vd_1sub(TH1D* c2, TH1D* d2, TH1D* c4, TH1D* d4, TH1D* vd2, TH1D* vd4)
{
	int NX = vd2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double c2v = c2->GetBinContent(iX+1);
		double d2v = d2->GetBinContent(iX+1);
		double c4v = c4->GetBinContent(iX+1);
		double d4v = d4->GetBinContent(iX+1);
		double vd2v = 0;
		double vd4v = 0;
		if(c2v>0) vd2v = d2v/sqrt(c2v);
		else if(c2v<0) vd2v = -d2v/sqrt(-c2v);
		if(c4v>0) vd4v = d4v/pow(c4v,3./4);
		else if(c4v<0) vd4v = -d4v/pow(-c4v,3./4);

		vd2->SetBinContent(iX+1,vd2v);
		vd4->SetBinContent(iX+1,vd4v);
	}
}

void CumuRbn::cal_c_3sub(TH1D* pc2_1, TH1D* pc2_2, TH1D* pc4, TH1D* c2, TH1D* c4)
{
	int NX = pc2_1->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2_1 = pc2_1->GetBinContent(iX+1);
		double p2_2 = pc2_2->GetBinContent(iX+1);
		double p4 = pc4->GetBinContent(iX+1);
		c2->SetBinContent(iX+1,p2_1);
		c4->SetBinContent(iX+1,p4-2.*p2_1*p2_2);
	}
}

void CumuRbn::cal_sc(TH1D* pc2_1, TH1D* pc2_2, TH1D* psc4, TH1D* sc4)
{
	int NX = pc2_1->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2_1 = pc2_1->GetBinContent(iX+1);
		double p2_2 = pc2_2->GetBinContent(iX+1);
		double p4 = psc4->GetBinContent(iX+1);
		sc4->SetBinContent(iX+1,p4-p2_1*p2_2);
	}
}

void CumuRbn::cal_ac(TH1D* pac3, TH1D* ac3)
{
	int NX = ac3->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p3 = pac3->GetBinContent(iX+1);
		ac3->SetBinContent(iX+1,p3);
	}
}

void CumuRbn::cal_nc(TH1D* c2, TH1D* c4, TH1D* c6, TH1D* nc4, TH1D* nc6)
{
	int NX = c2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2 = c2->GetBinContent(iX+1);
		double p4 = c4->GetBinContent(iX+1);
		double p6 = c6->GetBinContent(iX+1);
		if(c2==0) continue;
		double pc4 = p4/pow(p2,2);
		double pc6 = p6/pow(p2,3)/4;
		nc4->SetBinContent(iX+1,pc4);
		nc6->SetBinContent(iX+1,pc6);
	}
}

void CumuRbn::cal_nsc(TH1D* c2_1, TH1D* c2_2, TH1D* sc4, TH1D* nsc4)
{
	int NX = c2_1->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2_1 = c2_1->GetBinContent(iX+1);
		double p2_2 = c2_2->GetBinContent(iX+1);
		double p4 = sc4->GetBinContent(iX+1);
		if(p2_1!=0 && p2_2!=0) nsc4->SetBinContent(iX+1,p4/p2_1/p2_2);
	}
}

void CumuRbn::cal_nac(TH1D* c4, TH1D* c2_1, TH1D* c2_2, TH1D* ac3, TH1D* nac3)
{
	int NX = c4->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p4 = c4->GetBinContent(iX+1);
		double p2_1 = c2_1->GetBinContent(iX+1);
		double p2_2 = c2_2->GetBinContent(iX+1);
		double pa3 = ac3->GetBinContent(iX+1);
		p4 += 2.*pow(p2_1,2);
		if(p4*p2_2>0) nac3->SetBinContent(iX+1,pa3/sqrt(p4*p2_2));
		else if(p4*p2_2<0) nac3->SetBinContent(iX+1,pa3/sqrt(-p4*p2_2));
	}
}

void CumuRbn::cal_v_1sub(TH1D* c2, TH1D* c4, TH1D* c6, TH1D* v2, TH1D* v4, TH1D* v6)
{
	int NX = c2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2 = c2->GetBinContent(iX+1);
		double p4 = c4->GetBinContent(iX+1);
		double p6 = c6->GetBinContent(iX+1);
		double pv2 = 0;
		double pv4 = 0;
		double pv6 = 0;
		if(p2>=0) pv2 = pow(p2,1./2);
		else pv2 = pow(-p2,1./2);
		if(p4>=0) pv4 = -pow(p4,1./4);
		else pv4 = pow(-p4,1./4);
		if(p6>=0) pv6 = pow(p6/4.,1./6);
		else pv6 = pow(-p6/4.,1./6);

		v2->SetBinContent(iX+1,pv2);
		v4->SetBinContent(iX+1,pv4);
		v6->SetBinContent(iX+1,pv6);
	}
}

void CumuRbn::cal_v_3sub(TH1D* c2, TH1D* c4, TH1D* v2, TH1D* v4)
{
	int NX = c2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double p2 = c2->GetBinContent(iX+1);
		double p4 = c4->GetBinContent(iX+1);
		double pv2 = 0;
		double pv4 = 0;
		if(p2>=0) pv2 = pow(p2,1./2);
		else pv2 = pow(-p2,1./2);
		if(p4>=0) pv4 = -pow(p4,1./4);
		else pv4 = pow(-p4,1./4);

		v2->SetBinContent(iX+1,pv2);
		v4->SetBinContent(iX+1,pv4);
	}
}

void CumuRbn::cal_cr(TH1D* v2, TH1D* v4, TH1D* v6, TH1D* cr42, TH1D* cr64)
{
	int NX = v2->GetNbinsX();
	for(int iX=0; iX<NX; iX++)
	{
		double pv2 = v2->GetBinContent(iX+1);
		double pv4 = v4->GetBinContent(iX+1);
		double pv6 = v6->GetBinContent(iX+1);
		double pcr42 = 0;
		double pcr64 = 0;
		if(pv2!=0) pcr42 = pv4/pv2;
		if(pv4!=0) pcr64 = pv6/pv4;

		cr42->SetBinContent(iX+1,pcr42);
		cr64->SetBinContent(iX+1,pcr64);
	}
}

void CumuRbn::rebin_cumu(TH1D* hIn, TH1D* hWght, TH1D* hOut)
{
	unsigned int nBins = hIn->GetNbinsX();
	unsigned int nRebins = hOut->GetNbinsX();
	double sum;
	double cnt;
	for(unsigned int iB=0; iB<nRebins; iB++)
	{
		sum = 0;
		cnt = 0;
		for(unsigned int i=0; i<nBins; i++)
		{
			double xLw = hOut->GetBinCenter(iB+1)-0.5*hOut->GetBinWidth(iB+1);
			double xUp = hOut->GetBinCenter(iB+1)+0.5*hOut->GetBinWidth(iB+1);
			if(hIn->GetBinCenter(i+1)<xLw || hIn->GetBinCenter(i+1)>=xUp) continue;
			sum += hWght->GetBinContent(i+1)*hIn->GetBinContent(i+1);
			cnt += hWght->GetBinContent(i+1);
		}
		if(cnt>0) hOut->SetBinContent(iB+1,sum/cnt);
		else hOut->SetBinContent(iB+1,0);
	}
}

void CumuRbn::merge3sub(TH1D* h1, TH1D* h1w, TH1D* h2, TH1D* h2w, TH1D* h3, TH1D* h3w)
{
	unsigned int nBins = h1->GetNbinsX();
	double sum;
	double cnt;
	for(unsigned int iB=0; iB<nBins; iB++)
	{
		sum = 0;
		cnt = 0;

		sum += h1w->GetBinContent(iB+1)*h1->GetBinContent(iB+1);
		sum += h2w->GetBinContent(iB+1)*h2->GetBinContent(iB+1);
		sum += h3w->GetBinContent(iB+1)*h3->GetBinContent(iB+1);
		cnt += h1w->GetBinContent(iB+1);
		cnt += h2w->GetBinContent(iB+1);
		cnt += h3w->GetBinContent(iB+1);

		if(cnt>0) h1->SetBinContent(iB+1,sum/cnt);
		else h1->SetBinContent(iB+1,0);
	}
}

void CumuRbn::cvt_cent_pt(vector<TH1D*> vIn, TH1D* hOut, int iC)
{
	for(unsigned int iP=0; iP<NP; iP++)
	{
		double y = (vIn.at(iP))->GetBinContent(iC+1);
		hOut->SetBinContent(iP+1,y);
	}
}

void CumuRbn::writeHist(TFile*& fIn)
{
  fIn->cd();
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			raw_c2_1sub[iV][iR]->Write();
			rbn_c2_1sub[iV][iR]->Write();
			cen_c2_1sub[iV][iR]->Write();
			raw_c4_1sub[iV][iR]->Write();
			rbn_c4_1sub[iV][iR]->Write();
			cen_c4_1sub[iV][iR]->Write();
			raw_c6_1sub[iV][iR]->Write();
			rbn_c6_1sub[iV][iR]->Write();
			raw_nc4_1sub[iV][iR]->Write();
			rbn_nc4_1sub[iV][iR]->Write();
			raw_nc6_1sub[iV][iR]->Write();
			rbn_nc6_1sub[iV][iR]->Write();
			raw_v2_1sub[iV][iR]->Write();
			rbn_v2_1sub[iV][iR]->Write();
			raw_v4_1sub[iV][iR]->Write();
			rbn_v4_1sub[iV][iR]->Write();
			raw_v6_1sub[iV][iR]->Write();
			rbn_v6_1sub[iV][iR]->Write();
			raw_cr42_1sub[iV][iR]->Write();
			rbn_cr42_1sub[iV][iR]->Write();
			raw_cr64_1sub[iV][iR]->Write();
			rbn_cr64_1sub[iV][iR]->Write();
			raw_sc_1sub[iV][iR]->Write();
			rbn_sc_1sub[iV][iR]->Write();
			raw_nsc_1sub[iV][iR]->Write();
			rbn_nsc_1sub[iV][iR]->Write();
			raw_ac_1sub[iV][iR]->Write();
			rbn_ac_1sub[iV][iR]->Write();
			raw_nac_1sub[iV][iR]->Write();
			rbn_nac_1sub[iV][iR]->Write();
		}
		for(unsigned int iP=0; iP<NP; iP++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				raw_d2_1sub[iV][iR][iP]->Write();
				cen_d2_1sub[iV][iR][iP]->Write();
				cen_vd2_1sub[iV][iR][iP]->Write();
				raw_d4_1sub[iV][iR][iP]->Write();
				cen_d4_1sub[iV][iR][iP]->Write();
				cen_vd4_1sub[iV][iR][iP]->Write();
			}
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			for(unsigned int iV=0; iV<NV; iV++)
			{
				raw_c2_3sub[iA][iV][iR]->Write();
				rbn_c2_3sub[iA][iV][iR]->Write();
				raw_c4_3sub[iA][iV][iR]->Write();
				rbn_c4_3sub[iA][iV][iR]->Write();
				raw_v2_3sub[iA][iV][iR]->Write();
				rbn_v2_3sub[iA][iV][iR]->Write();
				raw_v4_3sub[iA][iV][iR]->Write();
				rbn_v4_3sub[iA][iV][iR]->Write();
				raw_sc_3sub[iA][iV][iR]->Write();
				rbn_sc_3sub[iA][iV][iR]->Write();
				raw_nsc_3sub[iA][iV][iR]->Write();
				rbn_nsc_3sub[iA][iV][iR]->Write();
				raw_ac_3sub[iA][iV][iR]->Write();
				rbn_ac_3sub[iA][iV][iR]->Write();
				raw_nac_3sub[iA][iV][iR]->Write();
				rbn_nac_3sub[iA][iV][iR]->Write();
			}
		}
	}
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iC=0; iC<nCent; iC++)
			{
				pT_vd2_1sub[iV][iR][iC]->Write();
				pT_vd4_1sub[iV][iR][iC]->Write();
			}
		}
	}
  fIn->Close();
}

void CumuRbn::readHist_VR(TFile* fIn, TH1D*& hIn, const char* hName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TH1D*)fIn->Get(name);
}

void CumuRbn::readHist_VRP(TFile* fIn, TH1D*& hIn, const char* hName, int iV, int iR, int iP)
{
	sprintf(name,"%s_Har%d_PtRef%d_Pt%d",hName,iV,iR,iP);
	hIn = (TH1D*)fIn->Get(name);
}

void CumuRbn::readHist_AVR(TFile* fIn, TH1D*& hIn, const char* hName, int iA, int iV, int iR)
{
	sprintf(name,"%s_Pm%d_Har%d_PtRef%d",hName,iA,iV,iR);
	hIn = (TH1D*)fIn->Get(name);
}

void CumuRbn::initHist_VR(TH1D*& hIn, const char* hName, int iV, int iR, int iOpt, int iRebin)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	if(iOpt==raw) hIn = new TH1D(name,"",nBin,minBin,maxBin);
	if(iOpt==rbn) hIn = new TH1D(name,"",nRebin[iRebin],xRebin[iRebin]);
	if(iOpt==cen) hIn = new TH1D(name,"",nCent,xCent);
}

void CumuRbn::initHist_VRP(TH1D*& hIn, const char* hName, int iV, int iR, int iP, int iOpt, int iRebin)
{
	sprintf(name,"%s_Har%d_PtRef%d_Pt%d",hName,iV,iR,iP);
	if(iOpt==raw) hIn = new TH1D(name,"",nBin,minBin,maxBin);
	if(iOpt==rbn) hIn = new TH1D(name,"",nRebin[iRebin],xRebin[iRebin]);
	if(iOpt==cen) hIn = new TH1D(name,"",nCent,xCent);
}

void CumuRbn::initHist_AVR(TH1D*& hIn, const char* hName, int iA, int iV, int iR, int iOpt, int iRebin)
{
	sprintf(name,"%s_Pm%d_Har%d_PtRef%d",hName,iA,iV,iR);
	if(iOpt==raw) hIn = new TH1D(name,"",nBin,minBin,maxBin);
	if(iOpt==rbn) hIn = new TH1D(name,"",nRebin[iRebin],xRebin[iRebin]);
}

void CumuRbn::initHist_VRC(TH1D*& hIn, const char* hName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = new TH1D(name,"",NP,xPt);
}
