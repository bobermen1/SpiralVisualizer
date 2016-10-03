#ifndef _Globals_h_
#define _Globals_h_

#include <vector>
#include <cmath>
#include <string>
#include <GL/freeglut.h>

using namespace std;

typedef long long ll;

extern int ScreenWidth;
extern int ScreenHeight;

const string PROGRAM_NAME = "Spirals";

extern ll numMax;

extern int startNum;

enum generator {PRIMES, TWIN_PRIMES, TRIPLET_PRIMES,SEPARATED_BY_FOUR,
                SEPARATED_BY_SIX, SEPARATED_BY_TWELVE, FIBONACCI, TEN_PERCENT,
                TWENTY_PERCENT, THIRTY_PERCENT, FOURTY_PERCENT, FIFTY_PERCENT,
                FIVE_PERCENT, FIFTEEN_PERCENT, RANDOM_ODDS, SQUARES, KTH_VALUE,
                HAPPY, ABUNDANTS, DEFICIENTS, LUCKY};

extern ll kVal;

extern generator currentGen;

enum draw {SQUARE_SPIRAL, CIRCLE_SPIRAL};

extern draw drawType;

extern vector<ll> numbers;

#endif
