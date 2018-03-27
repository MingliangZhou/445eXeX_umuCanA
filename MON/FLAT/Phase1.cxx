#include "Phase1.h"

Phase1::Phase1(int iSample)
{
	initialize(iSample);
	execute();
	finalize(iSample);
}

Phase1::~Phase1()
{
}

void Phase1::execute()
{
	cout<<"execute..."<<endl;

	for(int iEvt=0; iEvt<treeIn->GetEntries(); iEvt++)
	{
		if(iEvt%10000==0)
		{
			for(int i=0; i<100.*iEvt/treeIn->GetEntries(); i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/treeIn->GetEntries(); i<100-1; i++) cout<<"-";
			cout<<'\r';
		}
		treeIn->GetEntry(iEvt);

		if(!(evt->isGoodEvent())) continue;

		evt->setEvent();
		evt->fillHist();
	}
}

void Phase1::initialize(int iSample)
{
	cout<<"initialize..."<<endl;

	treeIn = new TChain("tree");
	sprintf(name,"flist_XeXe5.txt");
	ifstream lis(name);
	int cnt = 0;
	while(!lis.eof())
	{
		string fName;
		lis >> fName;
		if(cnt==iSample)
		{
			sprintf(name,"%s",fName.c_str());
			cout<<name<<endl;
			if(!fName.empty()) treeIn->Add(name);
			else break;
		}
		cnt++;
	}

	evt = new Event(treeIn);
}

void Phase1::finalize(int iSample)
{
	cout<<"finalize..."<<endl;

	char name[300];
	sprintf(name,"OUTPUT_Phase1/Phase1_Sample%d.root",iSample);
	TFile* fOut = new TFile(name,"RECREATE");
	fOut->cd();
	evt->mon_fcalEt->Write();
	evt->mon_cent->Write();
	evt->mon_trkPt->Write();
	for(int iC=0; iC<NC; iC++)
	{
		for(int iZ=0; iZ<NZ; iZ++)
		{
			for(int iG=0; iG<NG; iG++)
			{
				for(int iP=0; iP<NP; iP++)
				{
					evt->cor_eta_phi[iC][iZ][iG][iP]->Write();
				}
			}
		}
	}
	fOut->Close();

	delete evt;
}
