#include "Phase3.h"

Phase3::Phase3(unsigned int iBin)
{
	initialize(iBin);
	execute();
	finalize(iBin);
}

Phase3::~Phase3()
{
}

void Phase3::execute()
{
	cout<<"execute..."<<endl;

	vector<TH1D*> hSamples;
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c2_1sub[iSample][iV][iR]);
			cal_sts(hSamples,c2_1sub[iV][iR],"c2_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c4_1sub[iSample][iV][iR]);
			cal_sts(hSamples,c4_1sub[iV][iR],"c4_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c6_1sub[iSample][iV][iR]);
			cal_sts(hSamples,c6_1sub[iV][iR],"c6_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nc4_1sub[iSample][iV][iR]);
			cal_sts(hSamples,nc4_1sub[iV][iR],"nc4_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nc6_1sub[iSample][iV][iR]);
			cal_sts(hSamples,nc6_1sub[iV][iR],"nc6_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v2_1sub[iSample][iV][iR]);
			cal_sts(hSamples,v2_1sub[iV][iR],"v2_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v4_1sub[iSample][iV][iR]);
			cal_sts(hSamples,v4_1sub[iV][iR],"v4_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v6_1sub[iSample][iV][iR]);
			cal_sts(hSamples,v6_1sub[iV][iR],"v6_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_cr42_1sub[iSample][iV][iR]);
			cal_sts(hSamples,cr42_1sub[iV][iR],"cr42_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_cr64_1sub[iSample][iV][iR]);
			cal_sts(hSamples,cr64_1sub[iV][iR],"cr64_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_sc_1sub[iSample][iV][iR]);
			cal_sts(hSamples,sc_1sub[iV][iR],"sc_1sub",iV,iR); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nsc_1sub[iSample][iV][iR]);
			cal_sts(hSamples,nsc_1sub[iV][iR],"nsc_1sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_ac_1sub[iSample][iV][iR]);
			cal_sts(hSamples,ac_1sub[iV][iR],"ac_1sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nac_1sub[iSample][iV][iR]);
			cal_sts(hSamples,nac_1sub[iV][iR],"nac_1sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c2_3sub[iSample][iV][iR]);
			cal_sts(hSamples,c2_3sub[iV][iR],"c2_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c4_3sub[iSample][iV][iR]);
			cal_sts(hSamples,c4_3sub[iV][iR],"c4_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v2_3sub[iSample][iV][iR]);
			cal_sts(hSamples,v2_3sub[iV][iR],"v2_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v4_3sub[iSample][iV][iR]);
			cal_sts(hSamples,v4_3sub[iV][iR],"v4_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_sc_3sub[iSample][iV][iR]);
			cal_sts(hSamples,sc_3sub[iV][iR],"sc_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nsc_3sub[iSample][iV][iR]);
			cal_sts(hSamples,nsc_3sub[iV][iR],"nsc_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_ac_3sub[iSample][iV][iR]);
			cal_sts(hSamples,ac_3sub[iV][iR],"ac_3sub",iV,iR); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nac_3sub[iSample][iV][iR]);
			cal_sts(hSamples,nac_3sub[iV][iR],"nac_3sub",iV,iR); hSamples.clear();
		}
	}
}

void Phase3::initialize(unsigned int iBin)
{
	cout<<"initialize..."<<endl;

	TH1::AddDirectory(kFALSE);
	TFile* fIn[nSample+1];
	for(unsigned int iSample=0; iSample<=nSample; iSample++)
	{
		if(iSample<nSample) sprintf(name,"../OUTPUT/Phase2/bin%d/Phase2_Sample%d.root",iBin,iSample);
		else sprintf(name,"../OUTPUT/Phase2/bin%d/Phase2_All.root",iBin);
		fIn[iSample] = new TFile(name,"READ");
		for(unsigned int iV=0; iV<NV; iV++)
		{
			for(unsigned int iR=0; iR<NR; iR++)
			{
				readHist_VP(fIn[iSample],rbn_c2_1sub[iSample][iV][iR],"rbn_c2_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_c4_1sub[iSample][iV][iR],"rbn_c4_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_c6_1sub[iSample][iV][iR],"rbn_c6_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_nc4_1sub[iSample][iV][iR],"rbn_nc4_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_nc6_1sub[iSample][iV][iR],"rbn_nc6_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_v2_1sub[iSample][iV][iR],"rbn_v2_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_v4_1sub[iSample][iV][iR],"rbn_v4_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_v6_1sub[iSample][iV][iR],"rbn_v6_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_cr42_1sub[iSample][iV][iR],"rbn_cr42_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_cr64_1sub[iSample][iV][iR],"rbn_cr64_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_sc_1sub[iSample][iV][iR],"rbn_sc_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_nsc_1sub[iSample][iV][iR],"rbn_nsc_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_ac_1sub[iSample][iV][iR],"rbn_ac_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_nac_1sub[iSample][iV][iR],"rbn_nac_1sub",iV,iR);
				readHist_VP(fIn[iSample],rbn_c2_3sub[iSample][iV][iR],"rbn_c2_3sub_Pm1",iV,iR);
				readHist_VP(fIn[iSample],rbn_c4_3sub[iSample][iV][iR],"rbn_c4_3sub_Pm0",iV,iR);
				readHist_VP(fIn[iSample],rbn_v2_3sub[iSample][iV][iR],"rbn_v2_3sub_Pm1",iV,iR);
				readHist_VP(fIn[iSample],rbn_v4_3sub[iSample][iV][iR],"rbn_v4_3sub_Pm0",iV,iR);
				readHist_VP(fIn[iSample],rbn_sc_3sub[iSample][iV][iR],"rbn_sc_3sub_Pm0",iV,iR);
				readHist_VP(fIn[iSample],rbn_nsc_3sub[iSample][iV][iR],"rbn_nsc_3sub_Pm0",iV,iR);
				readHist_VP(fIn[iSample],rbn_ac_3sub[iSample][iV][iR],"rbn_ac_3sub_Pm0",iV,iR);
				readHist_VP(fIn[iSample],rbn_nac_3sub[iSample][iV][iR],"rbn_nac_3sub_Pm0",iV,iR);
			}
		}
	}
}

void Phase3::finalize(unsigned int iBin)
{
	cout<<"finalize..."<<endl;

	sprintf(name,"../OUTPUT/Phase3/Phase3_bin%d.root",iBin);
	TFile* fOut = new TFile(name,"RECREATE");
	fOut->cd();
	for(unsigned int iV=0; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<NR; iR++)
		{
			c2_1sub[iV][iR]->Write();
			c4_1sub[iV][iR]->Write();
			c6_1sub[iV][iR]->Write();
			nc4_1sub[iV][iR]->Write();
			nc6_1sub[iV][iR]->Write();
			v2_1sub[iV][iR]->Write();
			v4_1sub[iV][iR]->Write();
			v6_1sub[iV][iR]->Write();
			cr42_1sub[iV][iR]->Write();
			cr64_1sub[iV][iR]->Write();
			sc_1sub[iV][iR]->Write();
			nsc_1sub[iV][iR]->Write();
			ac_1sub[iV][iR]->Write();
			nac_1sub[iV][iR]->Write();
			c2_3sub[iV][iR]->Write();
			c4_3sub[iV][iR]->Write();
			v2_3sub[iV][iR]->Write();
			v4_3sub[iV][iR]->Write();
			sc_3sub[iV][iR]->Write();
			nsc_3sub[iV][iR]->Write();
			ac_3sub[iV][iR]->Write();
			nac_3sub[iV][iR]->Write();
		}
	}
	fOut->Close();
}

void Phase3::cal_sts(vector<TH1D*> vIn, TGraphErrors*& gOut, const char* gName, int iV, int iR)
{
	unsigned int NB = (vIn.at(0))->GetNbinsX();
	double x[NB];
	double y[NB];
	double xErr[NB];
	double yErr[NB];
	for(unsigned int iB=0; iB<NB; iB++)
	{
		x[iB] = (vIn.at(nSample))->GetBinCenter(iB+1);
		y[iB] = (vIn.at(nSample))->GetBinContent(iB+1);
		xErr[iB] = 0;
		double m1 = 0;
		double m2 = 0;
		for(unsigned int iS=0; iS<nSample; iS++)
		{
			m1 += pow((vIn.at(iS))->GetBinContent(iB+1),1);
			m2 += pow((vIn.at(iS))->GetBinContent(iB+1),2);
		}
		double mean = m1/nSample;
		double sigm = sqrt((m2-pow(m1,2)/nSample)/(nSample-1));
		double nS = 0;
		m1 = 0;
		m2 = 0;
		for(unsigned int iS=0; iS<nSample; iS++)
		{
			if(fabs((vIn.at(iS))->GetBinContent(iB+1)-mean)>2.5*sigm && fabs(mean)>1E-7) continue; // remove outliers
			m1 += pow((vIn.at(iS))->GetBinContent(iB+1),1);
			m2 += pow((vIn.at(iS))->GetBinContent(iB+1),2);
			nS ++;
		}
		if(nS<nSample-2 && iV!=0) cout<<iV<<" | "<<iR<<" || "<<iB<<" | "<<mean<<" | "<<sigm<<" | "<<(vIn.at(nSample))->GetBinContent(iB+1)<<": "<<nS<<endl;
		yErr[iB] = sqrt((m2-pow(m1,2)/nS)/nS/(nS-1));
	}
	gOut = new TGraphErrors(NB,x,y,xErr,yErr);
	sprintf(name,"%s_Har%d_PtRef%d",gName,iV,iR);
	gOut->SetName(name);
}

void Phase3::cleanPoint(TGraphErrors* gIn)
{
	for(int i=gIn->GetN(); i>=0; i--)
	{
		double x;
		double y;
		gIn->GetPoint(i,x,y);
		if(x<minBin || x>maxBin) gIn->RemovePoint(i);
	}
}

void Phase3::readHist_VP(TFile* fIn, TH1D*& hIn, const char* hName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TH1D*)fIn->Get(name);
}














