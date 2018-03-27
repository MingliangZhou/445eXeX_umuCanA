#include "MultiCorr.h"

MultiCorr::MultiCorr()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		sprintf(name,"cnt_1sub_PtRef%d",iR);
		cnt_1sub[iR] = new TH1D(name,"",nBin,minBin,maxBin);
		for(unsigned int iP=0; iP<NP; iP++)
		{
			sprintf(name,"cnt_1sub_diff_PtRef%d_Pt%d",iR,iP);
			cnt_1sub_diff[iR][iP] = new TH1D(name,"",nBin,minBin,maxBin);
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			sprintf(name,"cnt_3sub_Pm%d_PtRef%d",iA,iR);
			cnt_3sub[iA][iR] = new TH1D(name,"",nBin,minBin,maxBin);
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			initHist_VR(pc2_1sub_mean[iV][iR],"pc2_1sub_mean",iV,iR);
			initHist_VR(pc2_1sub_wght[iV][iR],"pc2_1sub_wght",iV,iR);
			initHist_VR(pc4_1sub_mean[iV][iR],"pc4_1sub_mean",iV,iR);
			initHist_VR(pc4_1sub_wght[iV][iR],"pc4_1sub_wght",iV,iR);
			initHist_VR(pc6_1sub_mean[iV][iR],"pc6_1sub_mean",iV,iR);
			initHist_VR(pc6_1sub_wght[iV][iR],"pc6_1sub_wght",iV,iR);
			initHist_VR(psc4_1sub_mean[iV][iR],"psc4_1sub_mean",iV,iR);
			initHist_VR(psc4_1sub_wght[iV][iR],"psc4_1sub_wght",iV,iR);
			initHist_VR(pac3_1sub_mean[iV][iR],"pac3_1sub_mean",iV,iR);
			initHist_VR(pac3_1sub_wght[iV][iR],"pac3_1sub_wght",iV,iR);
		}
	}

	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				initHist_AVR(pc2_1_1sub_BG_mean[iA][iV][iR],"pc2_1_1sub_BG_mean",iA,iV,iR);
				initHist_AVR(pc2_1_1sub_BG_wght[iA][iV][iR],"pc2_1_1sub_BG_wght",iA,iV,iR);
				initHist_AVR(pc2_2_1sub_BG_mean[iA][iV][iR],"pc2_2_1sub_BG_mean",iA,iV,iR);
				initHist_AVR(pc2_2_1sub_BG_wght[iA][iV][iR],"pc2_2_1sub_BG_wght",iA,iV,iR);
				initHist_AVR(pc2_3_1sub_BG_mean[iA][iV][iR],"pc2_3_1sub_BG_mean",iA,iV,iR);
				initHist_AVR(pc2_3_1sub_BG_wght[iA][iV][iR],"pc2_3_1sub_BG_wght",iA,iV,iR);
				initHist_AVR(pc2_4_1sub_BG_mean[iA][iV][iR],"pc2_4_1sub_BG_mean",iA,iV,iR);
				initHist_AVR(pc2_4_1sub_BG_wght[iA][iV][iR],"pc2_4_1sub_BG_wght",iA,iV,iR);
				initHist_AVR(pc4_1sub_BG_mean[iA][iV][iR],"pc4_1sub_BG_mean",iA,iV,iR);
				initHist_AVR(pc4_1sub_BG_wght[iA][iV][iR],"pc4_1sub_BG_wght",iA,iV,iR);
			}
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iP=0; iP<NP; iP++)
			{
				initHist_VRP(pd2_1sub_mean[iV][iR][iP],"pd2_1sub_mean",iV,iR,iP);
				initHist_VRP(pd2_1sub_wght[iV][iR][iP],"pd2_1sub_wght",iV,iR,iP);
				initHist_VRP(pd4_1sub_mean[iV][iR][iP],"pd4_1sub_mean",iV,iR,iP);
				initHist_VRP(pd4_1sub_wght[iV][iR][iP],"pd4_1sub_wght",iV,iR,iP);
			}
		}
	}

	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				initHist_AVR(pc2_1_3sub_mean[iA][iV][iR],"pc2_1_3sub_mean",iA,iV,iR);
				initHist_AVR(pc2_1_3sub_wght[iA][iV][iR],"pc2_1_3sub_wght",iA,iV,iR);
				initHist_AVR(pc2_2_3sub_mean[iA][iV][iR],"pc2_2_3sub_mean",iA,iV,iR);
				initHist_AVR(pc2_2_3sub_wght[iA][iV][iR],"pc2_2_3sub_wght",iA,iV,iR);
				initHist_AVR(pc4_3sub_mean[iA][iV][iR],"pc4_3sub_mean",iA,iV,iR);
				initHist_AVR(pc4_3sub_wght[iA][iV][iR],"pc4_3sub_wght",iA,iV,iR);
				initHist_AVR(psc4_3sub_mean[iA][iV][iR],"psc4_3sub_mean",iA,iV,iR);
				initHist_AVR(psc4_3sub_wght[iA][iV][iR],"psc4_3sub_wght",iA,iV,iR);
				initHist_AVR(pac3_3sub_mean[iA][iV][iR],"pac3_3sub_mean",iA,iV,iR);
				initHist_AVR(pac3_3sub_wght[iA][iV][iR],"pac3_3sub_wght",iA,iV,iR);
			}
		}
	}
}

MultiCorr::~MultiCorr()
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		delete cnt_1sub[iR];
		for(unsigned int iP=0; iP<NP; iP++)
		{
			delete cnt_1sub_diff[iR][iP];
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			delete cnt_3sub[iA][iR];
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			delete pc2_1sub_mean[iV][iR];
			delete pc2_1sub_wght[iV][iR];
			delete pc4_1sub_mean[iV][iR];
			delete pc4_1sub_wght[iV][iR];
			delete pc6_1sub_mean[iV][iR];
			delete pc6_1sub_wght[iV][iR];
			delete psc4_1sub_mean[iV][iR];
			delete psc4_1sub_wght[iV][iR];
			delete pac3_1sub_mean[iV][iR];
			delete pac3_1sub_wght[iV][iR];
		}
	}

	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				delete pc2_1_1sub_BG_mean[iA][iV][iR];
				delete pc2_1_1sub_BG_wght[iA][iV][iR];
				delete pc2_2_1sub_BG_mean[iA][iV][iR];
				delete pc2_2_1sub_BG_wght[iA][iV][iR];
				delete pc2_3_1sub_BG_mean[iA][iV][iR];
				delete pc2_3_1sub_BG_wght[iA][iV][iR];
				delete pc2_4_1sub_BG_mean[iA][iV][iR];
				delete pc2_4_1sub_BG_wght[iA][iV][iR];
				delete pc4_1sub_BG_mean[iA][iV][iR];
				delete pc4_1sub_BG_wght[iA][iV][iR];
			}
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iP=0; iP<NP; iP++)
			{
				delete pd2_1sub_mean[iV][iR][iP];
				delete pd2_1sub_wght[iV][iR][iP];
				delete pd4_1sub_mean[iV][iR][iP];
				delete pd4_1sub_wght[iV][iR][iP];
			}
		}
	}

	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				delete pc2_1_3sub_mean[iA][iV][iR];
				delete pc2_1_3sub_wght[iA][iV][iR];
				delete pc2_2_3sub_mean[iA][iV][iR];
				delete pc2_2_3sub_wght[iA][iV][iR];
				delete pc4_3sub_mean[iA][iV][iR];
				delete pc4_3sub_wght[iA][iV][iR];
				delete psc4_3sub_mean[iA][iV][iR];
				delete psc4_3sub_wght[iA][iV][iR];
				delete pac3_3sub_mean[iA][iV][iR];
				delete pac3_3sub_wght[iA][iV][iR];
			}
		}
	}
}

void MultiCorr::fill_1sub(Event* evt)
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		double w2pc = cal_w2pc_1sub(evt,iR);
		double w3pc = cal_w3pc_1sub(evt,iR);
		double w4pc = cal_w4pc_1sub(evt,iR);
		double w6pc = cal_w6pc_1sub(evt,iR);
		if(w2pc>1e-6 && w3pc>1e-6 && w4pc>1e-6 && w6pc>1e-6)
		{
			cnt_1sub[iR]->Fill(evt->evtCls(),evt->evtWght());
			for(unsigned int iV=0; iV<NV; iV++)
			{
				pc2_1sub_mean[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w2pc*cal_2pc_1sub(evt,iV,iR));
				pc2_1sub_wght[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w2pc);
				pc4_1sub_mean[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc*cal_4pc_1sub(evt,iV,iR));
				pc4_1sub_wght[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc);
				pc6_1sub_mean[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w6pc*cal_6pc_1sub(evt,iV,iR));
				pc6_1sub_wght[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w6pc);
				psc4_1sub_mean[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc*cal_4psc_1sub(evt,iV,iR));
				psc4_1sub_wght[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc);
				pac3_1sub_mean[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w3pc*cal_3pac_1sub(evt,iV,iR));
				pac3_1sub_wght[iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w3pc);
			}
		}
	}
}

void MultiCorr::fill_1sub_BG(vector<Event*> pool)
{
	unsigned int A = nDepth-1;
	unsigned int B = nDepth-2;
	unsigned int C = nDepth-3;
	unsigned int D = nDepth-4;
	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			double w2pc1 = cal_w2pc_1sub_BG(pool.at(A),pool.at(C),iR);
			double w2pc2 = cal_w2pc_1sub_BG(pool.at(B),pool.at(D),iR);
			double w2pc3 = cal_w2pc_1sub_BG(pool.at(A),pool.at(D),iR);
			double w2pc4 = cal_w2pc_1sub_BG(pool.at(B),pool.at(C),iR);
			double w4pc = cal_w4pc_1sub_BG(pool.at(A),pool.at(B),pool.at(C),pool.at(D),iR);
			if(w2pc1>1e-6 && w2pc2>1e-6 && w2pc3>1e-6 && w2pc4>1e-6 && w4pc>1e-6)
			{
				for(unsigned int iV=0; iV<NV; iV++)
				{
					pc2_1_1sub_BG_mean[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc1*cal_2pc_1sub_BG(pool.at(A),pool.at(C),iV,iR));
					pc2_1_1sub_BG_wght[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc1);
					pc2_2_1sub_BG_mean[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc2*cal_2pc_1sub_BG(pool.at(B),pool.at(D),iV,iR));
					pc2_2_1sub_BG_wght[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc2);
					pc2_3_1sub_BG_mean[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc3*cal_2pc_1sub_BG(pool.at(A),pool.at(D),iV,iR));
					pc2_3_1sub_BG_wght[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc3);
					pc2_4_1sub_BG_mean[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc4*cal_2pc_1sub_BG(pool.at(B),pool.at(C),iV,iR));
					pc2_4_1sub_BG_wght[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w2pc4);
					pc4_1sub_BG_mean[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w4pc*cal_4pc_1sub_BG(pool.at(A),pool.at(B),pool.at(C),pool.at(D),iV,iR));
					pc4_1sub_BG_wght[iA][iV][iR]->Fill(pool.at(A)->evtCls(),pool.at(A)->evtWght()*w4pc);
				}
			}
			swap(pool.at(B),pool.at(C),pool.at(D));
		}
	}
}

void MultiCorr::fill_1sub_diff(Event* evt)
{
	for(unsigned int iR=0; iR<NR; iR++)
	{
		for(unsigned int iP=0; iP<NP; iP++)
		{
			double w2pc = cal_w2pd_1sub(evt,iR,iP);
			double w4pc = cal_w2pd_1sub(evt,iR,iP);
			if(w2pc>1e-6 && w4pc>1e-6)
			{
				cnt_1sub_diff[iR][iP]->Fill(evt->evtCls(),evt->evtWght());
				for(unsigned int iV=0; iV<NV; iV++)
				{
					pd2_1sub_mean[iV][iR][iP]->Fill(evt->evtCls(),evt->evtWght()*w2pc*cal_2pd_1sub(evt,iV,iR,iP));
					pd2_1sub_wght[iV][iR][iP]->Fill(evt->evtCls(),evt->evtWght()*w2pc);
					pd4_1sub_mean[iV][iR][iP]->Fill(evt->evtCls(),evt->evtWght()*w4pc*cal_4pd_1sub(evt,iV,iR,iP));
					pd4_1sub_wght[iV][iR][iP]->Fill(evt->evtCls(),evt->evtWght()*w4pc);
				}
			}
		}
	}
}

void MultiCorr::fill_3sub(Event* evt)
{
	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			double w2pc1 = cal_w2pc_3sub(evt,iR,1);
			double w2pc2 = cal_w2pc_3sub(evt,iR,2);
			double w3pc  = cal_w3pc_3sub(evt,iR);
			double w4pc  = cal_w4pc_3sub(evt,iR);
			if(w2pc1>1e-6 && w2pc2>1e-6 && w3pc>1e-6 && w4pc>1e-6)
			{
				cnt_3sub[iA][iR]->Fill(evt->evtCls(),evt->evtWght());
				for(unsigned int iV=0; iV<NV; iV++)
				{
					pc2_1_3sub_mean[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w2pc1*cal_2pc_3sub(evt,iV,iR,1));
					pc2_1_3sub_wght[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w2pc1);
					pc2_2_3sub_mean[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w2pc2*cal_2pc_3sub(evt,iV,iR,2));
					pc2_2_3sub_wght[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w2pc2);
					pc4_3sub_mean[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc*cal_4pc_3sub(evt,iV,iR));
					pc4_3sub_wght[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc);
					psc4_3sub_mean[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc*cal_4psc_3sub(evt,iV,iR));
					psc4_3sub_wght[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w4pc);
					pac3_3sub_mean[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w3pc*cal_3pac_3sub(evt,iV,iR));
					pac3_3sub_wght[iA][iV][iR]->Fill(evt->evtCls(),evt->evtWght()*w3pc);
				}
			}
			for(unsigned int iW=0; iW<NW; iW++)
			{
				swap(evt->nTrk3sub[iR][0][iW],evt->nTrk3sub[iR][1][iW],evt->nTrk3sub[iR][2][iW]);
				for(unsigned int iV=0; iV<NVm; iV++)
				{
					swap(evt->Q3sub[iV][iR][0][iW],evt->Q3sub[iV][iR][1][iW],evt->Q3sub[iV][iR][2][iW]);
				}
			}
		}
	}
}

void MultiCorr::writeHist(TFile*& fOut)
{
	fOut->cd();
	for(unsigned int iR=0; iR<NR; iR++)
	{
		cnt_1sub[iR]->Write();
		for(unsigned int iP=0; iP<NP; iP++)
		{
			cnt_1sub_diff[iR][iP]->Write();
		}
		for(unsigned int iA=0; iA<NA; iA++)
		{
			cnt_3sub[iA][iR]->Write();
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			pc2_1sub_mean[iV][iR]->Write();
			pc2_1sub_wght[iV][iR]->Write();
			pc4_1sub_mean[iV][iR]->Write();
			pc4_1sub_wght[iV][iR]->Write();
			pc6_1sub_mean[iV][iR]->Write();
			pc6_1sub_wght[iV][iR]->Write();
			psc4_1sub_mean[iV][iR]->Write();
			psc4_1sub_wght[iV][iR]->Write();
			pac3_1sub_mean[iV][iR]->Write();
			pac3_1sub_wght[iV][iR]->Write();
		}
	}

	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				pc2_1_1sub_BG_mean[iA][iV][iR]->Write();
				pc2_1_1sub_BG_wght[iA][iV][iR]->Write();
				pc2_2_1sub_BG_mean[iA][iV][iR]->Write();
				pc2_2_1sub_BG_wght[iA][iV][iR]->Write();
				pc2_3_1sub_BG_mean[iA][iV][iR]->Write();
				pc2_3_1sub_BG_wght[iA][iV][iR]->Write();
				pc2_4_1sub_BG_mean[iA][iV][iR]->Write();
				pc2_4_1sub_BG_wght[iA][iV][iR]->Write();
				pc4_1sub_BG_mean[iA][iV][iR]->Write();
				pc4_1sub_BG_wght[iA][iV][iR]->Write();
			}
		}
	}

	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iP=0; iP<NP; iP++)
			{
				pd2_1sub_mean[iV][iR][iP]->Write();
				pd2_1sub_wght[iV][iR][iP]->Write();
				pd4_1sub_mean[iV][iR][iP]->Write();
				pd4_1sub_wght[iV][iR][iP]->Write();
			}
		}
	}

	for(unsigned int iA=0; iA<NA; iA++)
	{
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				pc2_1_3sub_mean[iA][iV][iR]->Write();
				pc2_1_3sub_wght[iA][iV][iR]->Write();
				pc2_2_3sub_mean[iA][iV][iR]->Write();
				pc2_2_3sub_wght[iA][iV][iR]->Write();
				pc4_3sub_mean[iA][iV][iR]->Write();
				pc4_3sub_wght[iA][iV][iR]->Write();
				psc4_3sub_mean[iA][iV][iR]->Write();
				psc4_3sub_wght[iA][iV][iR]->Write();
				pac3_3sub_mean[iA][iV][iR]->Write();
				pac3_3sub_wght[iA][iV][iR]->Write();
			}
		}
	}
  fOut->Close();
}

double MultiCorr::cal_2pc_1sub(Event* evt, int iV, int iR)
{
	TComplex Q11 = evt->Q[1*iV][iR][1];
	double S21 = pow(evt->S[iR][1],2);
	double S12 = pow(evt->S[iR][2],1);
	return ((Q11*TComplex::Conjugate(Q11)).Re()-S12)/(S21-S12);
}

double MultiCorr::cal_w2pc_1sub(Event* evt, int iR)
{
	double S21 = pow(evt->S[iR][1],2);
	double S12 = pow(evt->S[iR][2],1);
	return S21-S12;
}

double MultiCorr::cal_4pc_1sub(Event* evt, int iV, int iR)
{
	TComplex Q11 = evt->Q[1*iV][iR][1];
	TComplex Q13 = evt->Q[1*iV][iR][3];
	TComplex Q22 = evt->Q[2*iV][iR][2];
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S14 = pow(evt->S[iR][4],1);
	double S21 = pow(evt->S[iR][1],2);
	double S22 = pow(evt->S[iR][2],2);
	double S41 = pow(evt->S[iR][1],4);
	return (pow((Q11*TComplex::Conjugate(Q11)).Re(),2)+(Q22*TComplex::Conjugate(Q22)).Re()-2*(Q22*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()+8*(Q13*TComplex::Conjugate(Q11)).Re()-4*S12*(Q11*TComplex::Conjugate(Q11)).Re()+2*S22-6*S14)/(S41+8*S13*S11-6*S12*S21+3*S22-6*S14);
}

double MultiCorr::cal_w4pc_1sub(Event* evt, int iR)
{
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S14 = pow(evt->S[iR][4],1);
	double S21 = pow(evt->S[iR][1],2);
	double S22 = pow(evt->S[iR][2],2);
	double S41 = pow(evt->S[iR][1],4);
	return S41+8*S13*S11-6*S12*S21+3*S22-6*S14;
}

double MultiCorr::cal_6pc_1sub(Event* evt, int iV, int iR)
{
	TComplex Q11 = evt->Q[1*iV][iR][1];
	TComplex Q13 = evt->Q[1*iV][iR][3];
	TComplex Q15 = evt->Q[1*iV][iR][5];
	TComplex Q22 = evt->Q[2*iV][iR][2];
	TComplex Q24 = evt->Q[2*iV][iR][4];
	TComplex Q33 = evt->Q[3*iV][iR][3];
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S14 = pow(evt->S[iR][4],1);
	double S15 = pow(evt->S[iR][5],1);
	double S16 = pow(evt->S[iR][6],1);
	double S21 = pow(evt->S[iR][1],2);
	double S22 = pow(evt->S[iR][2],2);
	double S23 = pow(evt->S[iR][3],2);
	double S31 = pow(evt->S[iR][1],3);
	double S32 = pow(evt->S[iR][2],3);
	double S41 = pow(evt->S[iR][1],4);
	double S61 = pow(evt->S[iR][1],6);
	return (pow((Q11*TComplex::Conjugate(Q11)).Re(),3)-6*(Q11*TComplex::Conjugate(Q11)).Re()*(Q22*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()+9*(Q22*TComplex::Conjugate(Q22)).Re()*(Q11*TComplex::Conjugate(Q11)).Re()+4*(Q33*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()+18*S12*(Q22*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()-36*(Q24*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()-36*(Q13*Q11*TComplex::Conjugate(Q22)).Re()+18*S22*(Q11*TComplex::Conjugate(Q11)).Re()-54*S14*(Q11*TComplex::Conjugate(Q11)).Re()-72*S12*(Q13*TComplex::Conjugate(Q11)).Re()+36*(Q13*TComplex::Conjugate(Q13)).Re()+144*(Q15*TComplex::Conjugate(Q11)).Re()-9*S12*pow((Q11*TComplex::Conjugate(Q11)).Re(),2)+36*(Q11*TComplex::Conjugate(Q11)).Re()*(Q13*TComplex::Conjugate(Q11)).Re()-9*S12*(Q22*TComplex::Conjugate(Q22)).Re()+36*(Q24*TComplex::Conjugate(Q22)).Re()-12*(Q33*TComplex::Conjugate(Q22)*TComplex::Conjugate(Q11)).Re()+4*(Q33*TComplex::Conjugate(Q33)).Re()+54*S14*S12-6*S32-120*S16)/(S61-15*S12*S41+40*S13*S31+45*S22*S21-90*S14*S21-120*S13*S12*S11-15*S32+144*S15*S11+90*S14*S12+40*S23-120*S16);
}

double MultiCorr::cal_w6pc_1sub(Event* evt, int iR)
{
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S14 = pow(evt->S[iR][4],1);
	double S15 = pow(evt->S[iR][5],1);
	double S16 = pow(evt->S[iR][6],1);
	double S21 = pow(evt->S[iR][1],2);
	double S22 = pow(evt->S[iR][2],2);
	double S23 = pow(evt->S[iR][3],2);
	double S31 = pow(evt->S[iR][1],3);
	double S32 = pow(evt->S[iR][2],3);
	double S41 = pow(evt->S[iR][1],4);
	double S61 = pow(evt->S[iR][1],6);
	return S61-15*S12*S41+40*S13*S31+45*S22*S21-90*S14*S21-120*S13*S12*S11-15*S32+144*S15*S11+90*S14*S12+40*S23-120*S16;
}

double MultiCorr::cal_4psc_1sub(Event* evt, int iV, int iR)
{
	TComplex M11;
	TComplex M13;
	TComplex N11;
	TComplex N13;
	TComplex MN2;
	TComplex NM2;
	if(iV==0)
	{
		M11 = evt->Q[2][iR][1];
		M13 = evt->Q[2][iR][3];
		N11 = evt->Q[3][iR][1];
		N13 = evt->Q[3][iR][3];
		MN2 = evt->Q[5][iR][2];
		NM2 = evt->Q[1][iR][2];
	}
	if(iV==1)
	{
		M11 = evt->Q[2][iR][1];
		M13 = evt->Q[2][iR][3];
		N11 = evt->Q[4][iR][1];
		N13 = evt->Q[4][iR][3];
		MN2 = evt->Q[6][iR][2];
		NM2 = evt->Q[2][iR][2];
	}
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S14 = pow(evt->S[iR][4],1);
	double S21 = pow(evt->S[iR][1],2);
	double S22 = pow(evt->S[iR][2],2);
	double S41 = pow(evt->S[iR][1],4);
	return ((M11*TComplex::Conjugate(M11)*N11*TComplex::Conjugate(N11)).Re()-2*(MN2*TComplex::Conjugate(M11)*TComplex::Conjugate(N11)).Re()-2*(NM2*M11*TComplex::Conjugate(N11)).Re()+(MN2*TComplex::Conjugate(MN2)).Re()+(NM2*TComplex::Conjugate(NM2)).Re()+4*(M13*TComplex::Conjugate(M11)+N13*TComplex::Conjugate(N11)).Re()-S12*(M11*TComplex::Conjugate(M11)+N11*TComplex::Conjugate(N11)).Re()+S22-6*S14)/(S41+8*S13*S11-6*S12*S21+3*S22-6*S14);
}

double MultiCorr::cal_3pac_1sub(Event* evt, int iV, int iP)
{
	TComplex M11;
	TComplex M12;
	TComplex N11;
	TComplex N12;
	TComplex MN1;
	TComplex MN2;
	if(iV==0) // (1+1-2)
	{
		M11 = evt->Q[1][iP][1];
		M12 = evt->Q[1][iP][2];
		N11 = evt->Q[1][iP][1];
		N12 = evt->Q[1][iP][2];
		MN1 = evt->Q[2][iP][1];
		MN2 = evt->Q[2][iP][2];
	}
	if(iV==1) // (1+2-3)
	{
		M11 = evt->Q[1][iP][1];
		M12 = evt->Q[1][iP][2];
		N11 = evt->Q[2][iP][1];
		N12 = evt->Q[2][iP][2];
		MN1 = evt->Q[3][iP][1];
		MN2 = evt->Q[3][iP][2];
	}
	if(iV==2) // (2+2-4)
	{
		M11 = evt->Q[2][iP][1];
		M12 = evt->Q[2][iP][2];
		N11 = evt->Q[2][iP][1];
		N12 = evt->Q[2][iP][2];
		MN1 = evt->Q[4][iP][1];
		MN2 = evt->Q[4][iP][2];
	}
	double S11 = pow(evt->S[iP][1],1);
	double S12 = pow(evt->S[iP][2],1);
	double S13 = pow(evt->S[iP][3],1);
	double S31 = pow(evt->S[iP][1],3);
	return ((M11*N11*TComplex::Conjugate(MN1)).Re()-(MN1*TComplex::Conjugate(MN2)).Re()-(M11*TComplex::Conjugate(M12)).Re()-(N11*TComplex::Conjugate(N12)).Re()+2*S13)/(S31-3*S12*S11+2*S13);
}

double MultiCorr::cal_w3pc_1sub(Event* evt, int iP)
{
	double S11 = pow(evt->S[iP][1],1);
	double S12 = pow(evt->S[iP][2],1);
	double S13 = pow(evt->S[iP][3],1);
	double S31 = pow(evt->S[iP][1],3);
	return S31-3*S12*S11+2*S13;
}

double MultiCorr::cal_2pc_1sub_BG(Event* evt1, Event* evt2, int iV, int iR)
{
	TComplex Q11_1 = evt1->Q[1*iV][iR][1];
	TComplex Q11_2 = evt2->Q[1*iV][iR][1];
	double S11_1 = pow(evt1->S[iR][1],1);
	double S11_2 = pow(evt2->S[iR][1],1);
	return (Q11_1*TComplex::Conjugate(Q11_2)).Re()/(S11_1*S11_2);
}

double MultiCorr::cal_w2pc_1sub_BG(Event* evt1, Event* evt2, int iR)
{
	double S11_1 = pow(evt1->S[iR][1],1);
	double S11_2 = pow(evt2->S[iR][1],1);
	return S11_1*S11_2;
}

double MultiCorr::cal_4pc_1sub_BG(Event* evt1, Event* evt2, Event* evt3, Event* evt4, int iV, int iR)
{
	TComplex Q11_1 = evt1->Q[1*iV][iR][1];
	TComplex Q11_2 = evt2->Q[1*iV][iR][1];
	TComplex Q11_3 = evt3->Q[1*iV][iR][1];
	TComplex Q11_4 = evt4->Q[1*iV][iR][1];
	double S11_1 = pow(evt1->S[iR][1],1);
	double S11_2 = pow(evt2->S[iR][1],1);
	double S11_3 = pow(evt3->S[iR][1],1);
	double S11_4 = pow(evt4->S[iR][1],1);
	return (Q11_1*Q11_2*TComplex::Conjugate(Q11_3)*TComplex::Conjugate(Q11_4)).Re()/(S11_1*S11_2*S11_3*S11_4);
}

double MultiCorr::cal_w4pc_1sub_BG(Event* evt1, Event* evt2, Event* evt3, Event* evt4, int iR)
{
	double S11_1 = pow(evt1->S[iR][1],1);
	double S11_2 = pow(evt2->S[iR][1],1);
	double S11_3 = pow(evt3->S[iR][1],1);
	double S11_4 = pow(evt4->S[iR][1],1);
	return S11_1*S11_2*S11_3*S11_4;
}

double MultiCorr::cal_2pd_1sub(Event* evt, int iV, int iR, int iP)
{
	TComplex Q11 = evt->Q[1*iV][iR][1];
	TComplex p10 = evt->p[1*iV][iP][0];
	double S11 = pow(evt->S[iR][1],1);
	double m10 = pow(evt->m[iP][0],1);
	double s11 = pow(evt->s[iR][iP][1],1);
	return ((p10*TComplex::Conjugate(Q11)).Re()-s11)/(m10*S11-s11);
}

double MultiCorr::cal_w2pd_1sub(Event* evt, int iR, int iP)
{
	double S11 = pow(evt->S[iR][1],1);
	double m10 = pow(evt->m[iP][0],1);
	double s11 = pow(evt->s[iR][iP][1],1);
	return m10*S11-s11;
}

double MultiCorr::cal_4pd_1sub(Event* evt, int iV, int iR, int iP)
{
	TComplex Q11 = evt->Q[1*iV][iR][1];
	TComplex Q13 = evt->Q[1*iV][iR][3];
	TComplex Q22 = evt->Q[2*iV][iR][2];
	TComplex p10 = evt->p[1*iV][iP][0];
	TComplex q12 = evt->q[1*iV][iR][iP][2];
	TComplex q21 = evt->q[2*iV][iR][iP][1];
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S21 = pow(evt->S[iR][1],2);
	double S31 = pow(evt->S[iR][1],3);
	double m10 = pow(evt->m[iP][0],1);
	double s11 = pow(evt->s[iR][iP][1],1);
	double s12 = pow(evt->s[iR][iP][2],1);
	double s13 = pow(evt->s[iR][iP][3],1);
	return ((p10*Q11*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()-(q21*TComplex::Conjugate(Q11)*TComplex::Conjugate(Q11)).Re()-(p10*Q11*TComplex::Conjugate(Q22)).Re()-2.*S12*(p10*TComplex::Conjugate(Q11)).Re()-2.*s11*(Q11*TComplex::Conjugate(Q11)).Re()+7.*(q12*TComplex::Conjugate(Q11)).Re()-(Q11*TComplex::Conjugate(q12)).Re()+(q21*TComplex::Conjugate(Q22)).Re()+2.*(p10*TComplex::Conjugate(Q13)).Re()+2.*s11*S12-6.*s13)/(m10*S31-3.*m10*S11*S12+2.*m10*S13-3.*s11*S21+3.*s11*S12-6.*s13+6.*s12*S11);
}

double MultiCorr::cal_w4pd_1sub(Event* evt, int iR, int iP)
{
	double S11 = pow(evt->S[iR][1],1);
	double S12 = pow(evt->S[iR][2],1);
	double S13 = pow(evt->S[iR][3],1);
	double S21 = pow(evt->S[iR][1],2);
	double S31 = pow(evt->S[iR][1],3);
	double m10 = pow(evt->m[iP][0],1);
	double s11 = pow(evt->s[iR][iP][1],1);
	double s12 = pow(evt->s[iR][iP][2],1);
	double s13 = pow(evt->s[iR][iP][3],1);
	return m10*S31-3.*m10*S11*S12+2.*m10*S13-3.*s11*S21+3.*s11*S12-6.*s13+6.*s12*S11;
}

double MultiCorr::cal_2pc_3sub(Event* evt, int iV, int iR, int iMode)
{
	TComplex A11 = evt->Q3sub[1*iV][iR][0][1];
	TComplex B11;
	if(iMode==1) B11 = evt->Q3sub[1*iV][iR][1][1];
	if(iMode==2) B11 = evt->Q3sub[1*iV][iR][2][1];
	double a11 = pow(evt->nTrk3sub[iR][0][1],1);
	double b11 = 0;
	if(iMode==1) b11 = pow(evt->nTrk3sub[iR][1][1],1);
	if(iMode==2) b11 = pow(evt->nTrk3sub[iR][2][1],1);
	return (A11*TComplex::Conjugate(B11)).Re()/(a11*b11);
}

double MultiCorr::cal_w2pc_3sub(Event* evt, int iR, int iMode)
{
	double a11 = pow(evt->nTrk3sub[iR][0][1],1);
	double b11 = 0;
	if(iMode==1) b11 = pow(evt->nTrk3sub[iR][1][1],1);
	if(iMode==2) b11 = pow(evt->nTrk3sub[iR][2][1],1);
	return a11*b11;
}

double MultiCorr::cal_4pc_3sub(Event* evt, int iV, int iR)
{
	TComplex A11 = evt->Q3sub[1*iV][iR][0][1];
	TComplex A22 = evt->Q3sub[2*iV][iR][0][2];
	TComplex B11 = evt->Q3sub[1*iV][iR][1][1];
	TComplex C11 = evt->Q3sub[1*iV][iR][2][1];
	double a12 = pow(evt->nTrk3sub[iR][0][2],1);
	double a21 = pow(evt->nTrk3sub[iR][0][1],2);
	double b11 = pow(evt->nTrk3sub[iR][1][1],1);
	double c11 = pow(evt->nTrk3sub[iR][2][1],1);
	return ((A11*TComplex::Conjugate(B11)*A11*TComplex::Conjugate(C11)).Re()-(A22*TComplex::Conjugate(B11)*TComplex::Conjugate(C11)).Re())/((a21-a12)*b11*c11);
}

double MultiCorr::cal_w4pc_3sub(Event* evt, int iR)
{
	double a12 = pow(evt->nTrk3sub[iR][0][2],1);
	double a21 = pow(evt->nTrk3sub[iR][0][1],2);
	double b11 = pow(evt->nTrk3sub[iR][1][1],1);
	double c11 = pow(evt->nTrk3sub[iR][2][1],1);
	return (a21-a12)*b11*c11;
}

double MultiCorr::cal_4psc_3sub(Event* evt, int iV, int iR)
{
	TComplex M11;
	TComplex N11;
	TComplex MN2;
	TComplex B11;
	TComplex C11;
	if(iV==0)
	{
		M11 = evt->Q3sub[2][iR][0][1];
		N11 = evt->Q3sub[3][iR][0][1];
		MN2 = evt->Q3sub[5][iR][0][2];
		B11 = evt->Q3sub[2][iR][1][1];
		C11 = evt->Q3sub[3][iR][2][1];
	}
	if(iV==1)
	{
		M11 = evt->Q3sub[2][iR][0][1];
		N11 = evt->Q3sub[4][iR][0][1];
		MN2 = evt->Q3sub[6][iR][0][2];
		B11 = evt->Q3sub[2][iR][1][1];
		C11 = evt->Q3sub[4][iR][2][1];
	}
	double a12 = pow(evt->nTrk3sub[iR][0][2],1);
	double a21 = pow(evt->nTrk3sub[iR][0][1],2);
	double b11 = pow(evt->nTrk3sub[iR][1][1],1);
	double c11 = pow(evt->nTrk3sub[iR][2][1],1);
	return ((M11*TComplex::Conjugate(B11)*N11*TComplex::Conjugate(C11)).Re()-(MN2*TComplex::Conjugate(B11)*TComplex::Conjugate(C11)).Re())/((a21-a12)*b11*c11);
}

double MultiCorr::cal_3pac_3sub(Event* evt, int iV, int iP)
{
	TComplex A11;
	TComplex B11;
	TComplex C11;
	if(iV==0) // (1+1-2)
	{
		A11 = evt->Q3sub[1][iP][0][1];
		B11 = evt->Q3sub[1][iP][1][1];
		C11 = evt->Q3sub[2][iP][2][1];
	}
	if(iV==1) // (1+2-3)
	{
		A11 = evt->Q3sub[1][iP][0][1];
		B11 = evt->Q3sub[2][iP][1][1];
		C11 = evt->Q3sub[3][iP][2][1];
	}
	if(iV==2) // (2+2-4)
	{
		A11 = evt->Q3sub[2][iP][0][1];
		B11 = evt->Q3sub[2][iP][1][1];
		C11 = evt->Q3sub[4][iP][2][1];
	}
	double a11 = pow(evt->nTrk3sub[iP][0][1],1);
	double b11 = pow(evt->nTrk3sub[iP][1][1],1);
	double c11 = pow(evt->nTrk3sub[iP][2][1],1);
	return ((A11*B11*TComplex::Conjugate(C11)).Re())/(a11*b11*c11);
}

double MultiCorr::cal_w3pc_3sub(Event* evt, int iP)
{
	double a11 = pow(evt->nTrk3sub[iP][0][1],1);
	double b11 = pow(evt->nTrk3sub[iP][1][1],1);
	double c11 = pow(evt->nTrk3sub[iP][2][1],1);
	return a11*b11*c11;
}

void MultiCorr::swap(double& val1, double& val2, double& val3)
{
	double tmp = 0;
	tmp = val1;
	val1 = val2;
	val2 = val3;
	val3 = tmp;
}

void MultiCorr::swap(TComplex& val1, TComplex& val2, TComplex& val3)
{
	TComplex tmp;
	tmp = val1;
	val1 = val2;
	val2 = val3;
	val3 = tmp;
}

void MultiCorr::swap(Event*& evt1, Event*& evt2, Event*& evt3)
{
	Event* tmp = new Event(*evt1);
	*evt1 = *evt2;
	*evt2 = *evt3;
	*evt3 = *tmp;
	delete tmp;
}

void MultiCorr::initHist_VR(TH1D*& hIn, const char* hName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
}

void MultiCorr::initHist_VRP(TH1D*& hIn, const char* hName, int iV, int iR, int iP)
{
	sprintf(name,"%s_Har%d_PtRef%d_Pt%d",hName,iV,iR,iP);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
}

void MultiCorr::initHist_AVR(TH1D*& hIn, const char* hName, int iA, int iV, int iR)
{
	sprintf(name,"%s_Pm%d_Har%d_PtRef%d",hName,iA,iV,iR);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
}

