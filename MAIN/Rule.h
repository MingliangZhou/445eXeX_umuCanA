#ifndef Rule_H_
#define Rule_H_

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

const double cutCent[80] = { // centrality from 5.44 TeV Xe+Xe
0.049,    0.05317,  0.0576,   0.06233,  0.06734,  0.07266,  0.07833,  0.08435,  0.09074,  0.09749,
0.10461,  0.11213,  0.12006,  0.12843,  0.13725,  0.14653,  0.15627,  0.16646,  0.17722,  0.18854,
0.20038,  0.2127,   0.22567,  0.23913,  0.25316,  0.26785,  0.28314,  0.29915,  0.31578,  0.3331,
0.35113,  0.36972,  0.38904,  0.40917,  0.43001,  0.45155,  0.47396,  0.49721,  0.52125,  0.54619,
0.57184,  0.59847,  0.62591,  0.65421,  0.68344,  0.71376,  0.74505,  0.77738,  0.81063,  0.84512,
0.88055,  0.91707,  0.95471,  0.99358,  1.03359,  1.07498,  1.11755,  1.16155,  1.20703,  1.25404,
1.30248,  1.35255,  1.40429,  1.45772,  1.51282,  1.56988,  1.62866,  1.68991,  1.75344,  1.8191,
1.88743,  1.95875,  2.03308,  2.11048,  2.19142,  2.27602,  2.3653,   2.45935,  2.5599,   2.67806
};

const unsigned int maxNtrk = 10000;
const double cutEta = 2.5;
const double gapEta = 0.;
const double cutZvtx = 100;
const double cutQual = 1;

const unsigned int nBin = 80;
const double minBin = 0;
const double maxBin = 80;
const unsigned int nRebin[2] = {20,16}; // 24, 11
const double xRebin[2][21] = // 25
{
	{0, 1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80},
	{0, 5,10,15,20,25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95,100}
/*
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,12,14,16,18,20,25,30,35,40,45,50,60,70,80},
	{ 0, 2, 4, 6, 8,10,15,20,30,40,60,80,81,82,83,84,85,86,87,88,89,90,91,92,93}
*/
};

const unsigned int nCent = 6; // for pT measurements
const double xCent[nCent+1] = {0,5,10,20,40,60,80};

const unsigned int NV = 5; // harmonics from v0 to v4
const unsigned int NVm = 13; // higher harmonics for Q-cumulant with weights, from v0 to v12
const unsigned int NP = 12; // number of pT cuts for differential particles
const double minPt[NP] = {0.5, 0.6, 0.8, 1.0, 1.2, 1.5, 2.0, 3.0, 4.0, 5.0, 7.0, 10.0};
const double maxPt[NP] = {0.6, 0.8, 1.0, 1.2, 1.5, 2.0, 3.0, 4.0, 5.0, 7.0,10.0, 20.0};
const double xPt[NP+1] = {0.5, 0.6, 0.8, 1.0, 1.2, 1.5, 2.0, 3.0, 4.0, 5.0, 7.0, 10.0, 20.0};
const unsigned int NR = 4; // number of pT cuts for reference particles
const double minPtRef[NR] = {0.5, 1.0, 1.5, 2.0}; // minimum pT for reference particles
const double maxPtRef[NR] = {5.0, 5.0, 5.0, 5.0}; // maximum pT for reference particles
const unsigned int NW = 7; // power of weights for Q-cumulant calcualtion: 0 to 6
const unsigned int NA = 3; // number of permutation for 3-subevent

const unsigned int nMixZvtx = 10; // number of zvtx bins for mixed events
const unsigned int nMixCent = 10; // number of centralities for mixed events
const unsigned int nDepth = 4; // depth of mix event pool

const unsigned int nSample = 10; // number of samples for statistical errors
const unsigned int nFile = 4; // number of files per bundle to calculate statistical errors

#endif
