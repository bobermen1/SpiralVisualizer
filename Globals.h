#ifndef _Globals_h_
#define _Globals_h_

#include <vector>
#include <cmath>
#include <GL/freeglut.h>

using namespace std;

typedef long long ll;

extern int ScreenWidth;
extern int ScreenHeight;

extern int startNum;

enum generator {PRIMES, FIBONACCI};

extern generator currentGen;

extern vector<ll> numbers;

#endif
