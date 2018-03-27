#include <iostream>
#include <fstream>
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TFile.h"
#include "TChain.h"
#include "TComplex.h"
#include "TMath.h"
#include "TRandom3.h"

char name[300];

const int maxNtrk = 10000;
const double cutEta = 2.5;

const int NC = 5; // centrality
const double minCt[NC] = { 0, 20, 40, 60,  80};
const double maxCt[NC] = {20, 40, 60, 80, 100};
const int NZ = 10; // Zvtx
const double minZv[NZ] = {-300, -200, -150, -100, -50,  0,  50, 100, 150, 200};
const double maxZv[NZ] = {-200, -150, -100,  -50,   0, 50, 100, 150, 200, 300};
const int NG = 2; // charge
const int NP = 7; // pT
const double minPt[NP] = {0.3, 0.5, 0.7, 1.0, 1.5, 2.0, 5.0};
const double maxPt[NP] = {0.5, 0.7, 1.0, 1.5, 2.0, 5.0, 1E9};

const double cutCent[80] = { // centrality cut from Pb+Pb
0.063719, 0.06956,  0.075838, 0.082548, 0.089723, 0.097388, 0.105619, 0.114352, 0.123657, 0.133573,
0.14414,  0.155307, 0.167193, 0.179776, 0.193096, 0.207148, 0.22199,  0.237615, 0.25407,  0.27137,
0.289595, 0.308686, 0.328744, 0.349697, 0.371561, 0.394518, 0.418573, 0.443549, 0.46959,  0.49675,
0.525092, 0.554569, 0.585275, 0.617108, 0.65018,  0.684377, 0.719896, 0.756791, 0.795018, 0.834538,
0.87541,  0.917795, 0.961609, 1.0068,   1.05367,  1.10211,  1.15214,  1.20373,  1.25693,  1.31197,
1.36875,  1.42719,  1.48744,  1.55005,  1.61434,  1.68058,  1.74932,  1.81997,  1.89316,  1.96859,
2.04651,  2.12711,  2.21002,  2.29572,  2.38468,  2.47658,  2.57162,  2.66999,  2.77237,  2.87864,
2.98931,  3.10407,  3.22397,  3.34945,  3.48077,  3.61844,  3.7635,   3.91763,  4.08137,  4.26258};
