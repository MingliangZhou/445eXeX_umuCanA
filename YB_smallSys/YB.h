#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLine.h"

char name[200];
const unsigned int NF = 3;
const unsigned int NV = 2;
const unsigned int NP = 2;
double lumiRun2[NF] = {0.9, 0.9, 0.9};
double lumiRun3[NF] = {200, 200, 200};

const int mS[8] = {20,21,33,34,29,22,23,27};
const int mC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};
const int lS[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
const int lC[8] = {kBlue+2, kRed+2, kGreen+2, kYellow+2, kMagenta+2, kCyan+2, kOrange+2, 1};

TGraphErrors* cumu_1sub[2][NF][NV][NP];
TGraphErrors* cumu_3sub[2][NF][NV][NP];

void YB();
void initialize();
void detSts(TGraphErrors*, int);
void styleGraph(TH1D* hIn, int k);
void styleGraph(TGraph*, int);
void draw_graph(TGraphErrors* g1, TGraphErrors* g2, TGraphErrors* g3, int iF, int iV, int iP);

