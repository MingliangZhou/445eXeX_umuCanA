#ifndef Phase2Rbn_H_
#define Phase2Rbn_H_

#include "CumuRbn.h"

CumuRbn* cumu;

class Phase2Rbn
{
	public:
		Phase2Rbn(unsigned int iBin, unsigned int iSample);
		~Phase2Rbn();
		void initialize(unsigned int iBin, unsigned int iSample);
		void execute();
		void finalize(unsigned int iBin, unsigned int iSample);
};

#endif
