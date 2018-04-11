#ifndef Tool_H_
#define Tool_H_

#include "Rule.h"

const unsigned int NC_Flat = 5; // centrality
const double minCt_Flat[NC_Flat] = { 0, 20, 40, 60,  80};
const double maxCt_Flat[NC_Flat] = {20, 40, 60, 80, 100};
const unsigned int NZ_Flat = 10; // Zvtx
const double minZv_Flat[NZ_Flat] = {-300, -200, -150, -100, -50,  0,  50, 100, 150, 200};
const double maxZv_Flat[NZ_Flat] = {-200, -150, -100,  -50,   0, 50, 100, 150, 200, 300};
const unsigned int NG_Flat = 2; // charge
const unsigned int NP_Flat = 7; // pT
const double minPt_Flat[NP_Flat] = {0.3, 0.5, 0.7, 1.0, 1.5, 2.0, 5.0};
const double maxPt_Flat[NP_Flat] = {0.5, 0.7, 1.0, 1.5, 2.0, 5.0, 1E9};

class Tool
{
	private:
		TH2D* crrFlat_eta_phi[NC_Flat][NZ_Flat][NG_Flat][NP_Flat]; // eta-phi map for flattening
		TH3D* allTrue; // truth tracks
		TH3D* allReco; // recon tracks
		TH3D* matchedReco; // recon tracks that matched to truth
		TH3D* unMatchedReco; // recon tracks that unmatched to truth

	public:
		Tool();
		~Tool();
		double detFlat(double cent, double zVtx, int chg, double pt, double eta, double phi); // determine flattening correction
		double detTrkEff(double cent, double pt, double eta); // determine tracking efficiency
		double detTrkFak(double cent, double pt, double eta); // determine fake rates
};



#endif
