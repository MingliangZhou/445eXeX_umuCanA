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
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c2_1sub[iSample][iV][iP]);
			cal_sts(hSamples,c2_1sub[iV][iP],"c2_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c4_1sub[iSample][iV][iP]);
			cal_sts(hSamples,c4_1sub[iV][iP],"c4_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c6_1sub[iSample][iV][iP]);
			cal_sts(hSamples,c6_1sub[iV][iP],"c6_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nc4_1sub[iSample][iV][iP]);
			cal_sts(hSamples,nc4_1sub[iV][iP],"nc4_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nc6_1sub[iSample][iV][iP]);
			cal_sts(hSamples,nc6_1sub[iV][iP],"nc6_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v2_1sub[iSample][iV][iP]);
			cal_sts(hSamples,v2_1sub[iV][iP],"v2_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v4_1sub[iSample][iV][iP]);
			cal_sts(hSamples,v4_1sub[iV][iP],"v4_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v6_1sub[iSample][iV][iP]);
			cal_sts(hSamples,v6_1sub[iV][iP],"v6_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_cr42_1sub[iSample][iV][iP]);
			cal_sts(hSamples,cr42_1sub[iV][iP],"cr42_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_cr64_1sub[iSample][iV][iP]);
			cal_sts(hSamples,cr64_1sub[iV][iP],"cr64_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_sc_1sub[iSample][iV][iP]);
			cal_sts(hSamples,sc_1sub[iV][iP],"sc_1sub",iV,iP); hSamples.clear();
			
			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nsc_1sub[iSample][iV][iP]);
			cal_sts(hSamples,nsc_1sub[iV][iP],"nsc_1sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_ac_1sub[iSample][iV][iP]);
			cal_sts(hSamples,ac_1sub[iV][iP],"ac_1sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nac_1sub[iSample][iV][iP]);
			cal_sts(hSamples,nac_1sub[iV][iP],"nac_1sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c2_3sub[iSample][iV][iP]);
			cal_sts(hSamples,c2_3sub[iV][iP],"c2_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_c4_3sub[iSample][iV][iP]);
			cal_sts(hSamples,c4_3sub[iV][iP],"c4_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nc4_3sub[iSample][iV][iP]);
			cal_sts(hSamples,nc4_3sub[iV][iP],"nc4_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v2_3sub[iSample][iV][iP]);
			cal_sts(hSamples,v2_3sub[iV][iP],"v2_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_v4_3sub[iSample][iV][iP]);
			cal_sts(hSamples,v4_3sub[iV][iP],"v4_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_sc_3sub[iSample][iV][iP]);
			cal_sts(hSamples,sc_3sub[iV][iP],"sc_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nsc_3sub[iSample][iV][iP]);
			cal_sts(hSamples,nsc_3sub[iV][iP],"nsc_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_ac_3sub[iSample][iV][iP]);
			cal_sts(hSamples,ac_3sub[iV][iP],"ac_3sub",iV,iP); hSamples.clear();

			for(unsigned int iSample=0; iSample<=nSample; iSample++) hSamples.push_back(rbn_nac_3sub[iSample][iV][iP]);
			cal_sts(hSamples,nac_3sub[iV][iP],"nac_3sub",iV,iP); hSamples.clear();
		}
	}
}
