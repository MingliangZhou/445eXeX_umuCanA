#ifndef Phase1_H_
#define Phase1_H_

#include "Event.h"

TChain* treeIn;
Event* evt;

class Phase1
{
	public:
		Phase1(int);
		~Phase1();
		void initialize(int);
		void execute();
		void finalize(int);
};

#endif
