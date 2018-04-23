#include "Phase1.h"

Phase1::Phase1(int iJob)
{
	initialize(iJob);
	execute(iJob);
	finalize(iJob);
}

Phase1::~Phase1()
{
	delete tool;
	delete corr;
}

void Phase1::execute(int iJob)
{
	cout<<"execute..."<<endl;

	TRandom3 ran(42);
	Event* evt = new Event(treeIn);
	for(int iEvt=0; iEvt<treeIn->GetEntries(); iEvt++)
	{
		if(iEvt%1000==1)
		{
			for(int i=0; i<100.*iEvt/treeIn->GetEntries(); i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/treeIn->GetEntries(); i<100-1; i++) cout<<"-";
			cout<<'\r';
		}
		if(int(ran.Rndm()*nSample)!=int(iJob%nSample)) continue;
		treeIn->GetEntry(iEvt);

		if(!(evt->isGoodEvent())) continue;
		evt->setEvent(tool);

		//int tagMixZvtx = 0; int tagMixCent = 0;
		//if(!detMixZvtxCent(evt->evtZvtx(),evt->evtCls(),tagMixZvtx,tagMixCent)) continue;

		//Event* evtTmp = new Event(*evt);
		//EventPool[tagMixZvtx][tagMixCent].push_back(evtTmp);
		//if(EventPool[tagMixZvtx][tagMixCent].size()<nDepth) continue;

		corr->fill_1sub(evt);
		//corr->fill_c_BG(EventPool[tagMixZvtx][tagMixCent]);
		corr->fill_1sub_diff(evt);
		corr->fill_3sub(evt);

		//delete EventPool[tagMixZvtx][tagMixCent].at(0);
		//EventPool[tagMixZvtx][tagMixCent].erase( EventPool[tagMixZvtx][tagMixCent].begin() );
	}
	delete evt;
}

void Phase1::initialize(int iJob)
{
	cout<<"initialize..."<<endl;

	treeIn = new TChain("tree");
	ifstream lis("../../../INPUT/flist_XeXe5.txt");
	int cnt = 0;
	while(!lis.eof())
	{
		string fName;
		lis >> fName;
		if(cnt>=int(1.*iJob/nSample)*21./nFile && cnt<int(1.*iJob/nSample+1)*21./nFile) // 21 is # of rows in flist.txt
		{
			cout<<fName.c_str()<<endl;
			if(!fName.empty()) treeIn->Add(fName.c_str());
			else break;
		}
		cnt++;
	}

	tool = new Tool();
	corr = new MultiCorr();
}

void Phase1::finalize(int iJob)
{
	cout<<"finalize..."<<endl;

	sprintf(name,"../../OUTPUT/Phase1/Phase1_Sample%d_File%d.root",iJob%nSample,int(1.*iJob/nSample));
	TFile* fOut = new TFile(name,"RECREATE");
	corr->writeHist(fOut);
}

bool Phase1::detMixZvtxCent(double zVtx, double cent, int& tagZvtx, int& tagCent)
{
	tagZvtx = -1;
	tagCent = -1;

	tagZvtx = int((zVtx+100)/(200./nMixZvtx));
	tagCent = int(cent/(100./nMixCent));

	if(tagZvtx<0 || tagZvtx>=int(nMixZvtx)) return false;
	if(tagCent<0 || tagCent>=int(nMixCent)) return false;

	return true;
}


