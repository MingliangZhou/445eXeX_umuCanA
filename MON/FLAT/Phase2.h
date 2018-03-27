#ifndef Phase2_H_
#define Phase2_H_

#include "Rule.h"

class Phase2
{
	private:
		TH2D* cor_eta_phi[NC][NZ][NG][NP];
		TH2D* crr_eta_phi[NC][NZ][NG][NP];
		TH2D* chk_eta_phi[NC][NZ][NG][NP];
		void cal_flat(TH2D*, TH2D*);
		void chk_flat(TH2D*, TH2D*, TH2D*);

	public:
		Phase2();
		~Phase2();
		void initialize();
		void execute();
		void finalize();
};

#endif
