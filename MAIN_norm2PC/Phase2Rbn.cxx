#include "Phase2Rbn.h"

Phase2Rbn::Phase2Rbn(unsigned int iBin, unsigned int iSample)
{
	initialize(iBin,iSample);
	execute();
	finalize(iBin,iSample);
}

Phase2Rbn::~Phase2Rbn()
{
	delete cumu;
}

void Phase2Rbn::execute()
{
	cout<<"execute..."<<endl;

	cumu->cal_all();
}

void Phase2Rbn::initialize(unsigned int iBin, unsigned int iSample)
{
	cout<<"initialize..."<<endl;

	if(iSample<nSample) sprintf(name,"../OUTPUT/Phase1/Phase1_Sample%d.root",iSample);
	else sprintf(name,"../OUTPUT/Phase1/Phase1_All.root");
	TFile* fIn = new TFile(name,"READ");
	cumu = new CumuRbn(fIn, iBin);
}

void Phase2Rbn::finalize(unsigned int iBin, unsigned int iSample)
{
	cout<<"finalize..."<<endl;

	if(iSample<nSample) sprintf(name,"../OUTPUT/Phase2/bin%d/Phase2_Sample%d.root",iBin,iSample);
	else sprintf(name,"../OUTPUT/Phase2/bin%d/Phase2_All.root",iBin);
	TFile* fOut = new TFile(name,"RECREATE");
	cumu->writeHist(fOut);
}
