#include "Globals.h"

using namespace std;

//typedef for long long
typedef long long ll;

//used for storing working area width and height
int ScreenWidth = 400;
int ScreenHeight = 400;

int startNum = 1;

ll numMax = ScreenHeight * ScreenHeight;

ll kVal;

generator currentGen = PRIMES;

draw drawType = SQUARE_SPIRAL;

//stores the number in the sequence
vector<ll> numbers;
