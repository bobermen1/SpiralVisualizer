#ifndef _GenerateNumbers_h_
#define _GenerateNumbers_h_

#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/freeglut.h>
#include "Globals.h"


using namespace std;

void setNumMax();

void GeneratePrimes(ll maxNumber);
bool twin(ll i, ll j);
void GenerateXPrimes(ll maxNumber, ll x, ll nums);
void PureRandomPercent(ll maxNumber, double percent);
void GenerateFibonacci(ll maxNumber);
void GenerateNums(ll maxNumber);


#endif
