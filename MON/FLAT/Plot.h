#ifndef Plot_H_
#define Plot_H_

#include "Rule.h"
#include "TGraph2D.h"
#include "TGraph2DErrors.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLine.h"

const int mS[7] = {20,21,33,34,29,22,23};
const int mC[7] = {kBlue+1, kRed+1, kGreen+1, kYellow+1, kMagenta+1, kCyan+1, kOrange+1};
const int lS[7] = { 1, 1, 1, 1, 1, 1, 1};
const int lC[7] = {kBlue+1, kRed+1, kGreen+1, kYellow+1, kMagenta+1, kCyan+1, kOrange+1};

class Plot
{
	private:
		TH2D* cor_eta_phi[NC][NZ][NG][NP];
		TH2D* crr_eta_phi[NC][NZ][NG][NP];
		TH2D* chk_eta_phi[NC][NZ][NG][NP];
		void draw_2D(TH2D*, TH2D*, TH2D*, int, int, int, int);
		void setStyle(TH2D*);

	public:
		Plot();
		~Plot();
		void initialize();
		void execute();
		void finalize();
};

#endif
