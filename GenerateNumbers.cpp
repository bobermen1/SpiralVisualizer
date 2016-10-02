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

void GenerateNums(ll maxNumber)
{
    switch (currentGen) {
        case PRIMES:
            GeneratePrimes(maxNumber);
            break;
        case FIBONACCI:
            GenerateFibonacci(maxNumber);
            break;
    }
}
