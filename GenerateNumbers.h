#ifndef _GenerateNumbers_h_
#define _GenerateNumbers_h_

#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <GL/freeglut.h>
#include "Globals.h"


using namespace std;

void setNumMax();

bool twin(ll i, ll j);
void GenerateXPrimes(ll maxNumber, ll x, ll nums);

void PureRandomPercent(ll maxNumber, double percent);
void OddRandomPercent(ll maxNumber);

void GenerateFibonacci(ll maxNumber);
void GenerateSquares(ll maxNumber);
void GenerateEveryKth(ll maxNumber);
void GenerateHappyNumbers(ll maxNumber);
enum classification {ABUNDANT, DEFICIENT};
void GenerateAbundantDeficient(ll maxNumber, classification cl);

void GenerateNums(ll maxNumber);


#endif
