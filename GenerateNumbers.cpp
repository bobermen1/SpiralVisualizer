#include "GenerateNumbers.h"

using namespace std;

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

void GenerateNums(ll maxNumber)
{
    numbers.clear();
    for(ll i = 1; i < maxNumber; i += 4)
    {
        numbers.push_back(i);
    }
}
