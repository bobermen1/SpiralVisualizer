#include "GenerateNumbers.h"

using namespace std;

//sets the maximum number to be generated
void setNumMax()
{
    switch (drawType) {
        case SQUARE_SPIRAL:
            numMax = ScreenWidth * ScreenHeight;
            break;
        case CIRCLE_SPIRAL:
            numMax = ScreenWidth / 2 / .0002;
            break;
    }
}

//Prime generation with sieve using bits in a char array for generation
void GeneratePrimes(ll maxNumber)
{
    numbers.clear();
    char * sieve;
    sieve = new (nothrow) char[maxNumber/8+1];
    memset(sieve, 0xFF, (maxNumber/8+1) * sizeof(char));
    for(ll i = 2; i <= maxNumber; i++)
    {
        //get bit at position i in array of chars
        if(sieve[i/8] & (0x01 << (i % 8)))
        {
            numbers.push_back(i);

            for(ll j = 0; j <= maxNumber; j += i)
            {
                //set false for all positions j in char array
                sieve[j/8] &= ~(0x01 << (j % 8));
            }
        }
    }
    //free up memory
    delete [] sieve;
}

//Generates list a primes that are X appart nums amount of times
//example GenerateXPrimes(maxNumber, 1, 1) = all primes
//        GenerateXPrimes(maxNumber, 2, 2) = twin primes
//        GenerateXPrimes(maxNumber, 2, 3) = triplet primes
void GenerateXPrimes(ll maxNumber, ll x, ll nums)
{
    numbers.clear();
    char * sieve;
    sieve = new (nothrow) char[maxNumber/8+1];
    memset(sieve, 0xFF, (maxNumber/8+1) * sizeof(char));
    ll lp;
    bool good;
    for(ll i = 2; i <= maxNumber; i++)
    {
        //get bit at position i in array of chars
        if(sieve[i/8] & (0x01 << (i % 8)))
        {
            if(i >  pow(x,nums))
            {
                good = true;
                lp = i;
                for(ll j = nums-1; j > 0; j--)
                {
                    lp = lp - pow(x, j);
                    if(!(sieve[lp/8] & (0x01 << (lp % 8))) )
                    {
                        good = false;
                        break;
                    }
                }
                if(good)
                {
                    numbers.push_back(i);
                    lp = i;
                    for(ll j = nums-1; j > 0; j--)
                    {
                        lp = lp - pow(x, j);
                        numbers.push_back(lp);
                    }
                }
            }


            for(ll j = i + i; j <= maxNumber; j += i)
            {
                //set false for all positions j in char array
                sieve[j/8] &= ~(0x01 << (j % 8));
            }
        }
    }
    //free up memory
    delete [] sieve;
    sort(numbers.begin(),numbers.end());
    auto it = unique(numbers.begin(),numbers.end());
    numbers.resize(distance(numbers.begin(),it));


}

void GenerateFibonacci(ll maxNumber)
{
    numbers.clear();
    numbers.push_back(1);
    ll first = 1;
    ll second = 1;
    while(second <= maxNumber)
    {
        numbers.push_back(first+second);
        second = first + second;
        first = second - first;
    }

}

void PureRandomPercent(ll maxNumber, double percent)
{
    numbers.clear();
    for(ll i = 1; i < maxNumber; i++)
    {
        if((rand()%1000) / 1000.0 < percent)
        {
            numbers.push_back(i);
        }
    }
}

void OddRandomPercent(ll maxNumber)
{
    numbers.clear();
    ll i = 1;
    ll t;
    while( i <= maxNumber)
    {
        t = (rand() % 10) * 2;
        i += t;
        if(i % 5 != 0)
        {
            numbers.push_back(i);
        }
    }
    //remove duplicates
    auto it = unique(numbers.begin(),numbers.end());
    numbers.resize(distance(numbers.begin(),it));
}

void GenerateSquares(ll maxNumber)
{
    numbers.clear();
    ll count = 0;
    ll num = 1;
    while(num < maxNumber)
    {
        numbers.push_back(num);
        count++;
        num = pow(2,count);
    }

}

void GenerateEveryKth(ll maxNumber)
{
    numbers.clear();
    ll num = 1;
    while(num < maxNumber)
    {
        numbers.push_back(num);
        num += kVal;
    }
}


void GenerateNums(ll maxNumber)
{
    switch (currentGen)
    {
        //Primes
        case PRIMES:
            GenerateXPrimes(maxNumber, 1,1);
            break;
        case TWIN_PRIMES:
            GenerateXPrimes(maxNumber, 2,2);
            break;
        case TRIPLET_PRIMES:
            GenerateXPrimes(maxNumber, 2,3);
            break;
        case SEPARATED_BY_FOUR:
            GenerateXPrimes(maxNumber, 4,2);
            break;
        case SEPARATED_BY_SIX:
            GenerateXPrimes(maxNumber, 6,2);
            break;
        case SEPARATED_BY_TWELVE:
            GenerateXPrimes(maxNumber, 12,2);
            break;


        //random
        case FIVE_PERCENT:
            PureRandomPercent(maxNumber, .05);
            break;

        case TEN_PERCENT:
            PureRandomPercent(maxNumber, .1);
            break;

        case FIFTEEN_PERCENT:
            PureRandomPercent(maxNumber, .15);
            break;

        case TWENTY_PERCENT:
            PureRandomPercent(maxNumber, .2);
            break;

        case THIRTY_PERCENT:
            PureRandomPercent(maxNumber, .3);
            break;

        case FOURTY_PERCENT:
            PureRandomPercent(maxNumber, .4);
            break;

        case FIFTY_PERCENT:
            PureRandomPercent(maxNumber, .5);
            break;

        case RANDOM_ODDS:
            OddRandomPercent(maxNumber);
            break;

        //Other
        case FIBONACCI:
            GenerateFibonacci(maxNumber);
            break;

        case SQUARES:
            GenerateSquares(maxNumber);
            break;

        case KTH_VALUE:
            GenerateEveryKth(maxNumber);
            break;


        default:
            break;
    }
}
