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

//Generates list a primes that are X appart nums amount of times
//Primes are generated using sieve method with char array
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

void GenerateHappyNumbers(ll maxNumber)
{
    numbers.clear();
    bool good;
    ll number;
    //for faster generation later
    static map<ll, bool> cache;


    for(ll i = 1; i < maxNumber; i++)
    {
        number = i;
        set<ll> cycle;
        while(number != 1 && !cycle.count(number))
        {
            if(cache.count(number))
            {
                number = cache[number] ? 1 : 0;
                break;
            }
            cycle.insert(number);
            ll newNumber = 0;
            while(number > 0)
            {
                ll digit = number % 10;
                newNumber += digit * digit;
                number /= 10;
            }
            number = newNumber;
        }
        good  = number == 1;
        for(auto it = cycle.begin(); it != cycle.end(); it++)
        {
            cache[*it] = good;
        }
        if(good)
        {
            numbers.push_back(i);
        }
    }
}

void GenerateAbundantDeficient(ll maxNumber, classification cl)
{
    numbers.clear();
    vector<ll> sums;
    sums.resize(maxNumber,0);
    for(ll n = 1; n < maxNumber; n++)
    {
        for(int i = n * 2; i < maxNumber; i += n)
        {
            sums[i] += n;
        }

        if(sums[n] < n && cl == DEFICIENT)
        {
            numbers.push_back(n);
        }
        else if(sums[n] > n && cl == ABUNDANT)
        {
            numbers.push_back(n);
        }
    }
}

ll next(vector<bool> & nums, ll i)
{
    for(ll l = i + 1; l < (ll)nums.size();l++)
    {
        if(nums[l] == false)
        {
            return l;
        }
    }
    return nums.size() + 1;
}

ll which(vector<bool> & nums, ll i)
{
    ll k = 0,l;
    for(l = 0; l < i; l++)
    {
        k = next(nums,k);
    }
    return k;
}

void GenerateLucky(ll maxNumber)
{
    numbers.clear();

    vector<bool> nums;
    nums.resize(maxNumber,false);
    for(ll i = 2; i < maxNumber; i += 2)
    {
        nums[i] = true;
    }
    ll k = 2;
    ll j = 0;
    ll l = 0;
    ll p = 0;
    for(ll i = 2; (k+k) < maxNumber; i++)
    {
        k = which(nums,i);
        l = 0;
        p = 0;
        ll sw = 0;
        bool untrue=false;
        for(j = 1; l < maxNumber; j++)
        {
            if((p==k) && sw == 1)
            {
                nums[l]=true;
                untrue = true;
                p = 0;
            }
            l = next(nums,l);
            p++;
            sw = 1;
        }
        if(!untrue)
        {
            break;
        }
    }
    for(ll i = 0; i < (ll)nums.size();i++)
    {
        if(!nums[i])
        {
            numbers.push_back(i);
        }
    }

}

void GenerateNums(ll maxNumber)
{
    switch (currentGen)
    {
        //Primes
        case PRIMES:
            glutSetWindowTitle(string(PROGRAM_NAME + " - All Primes").c_str());
            GenerateXPrimes(maxNumber, 1,1);
            break;
        case TWIN_PRIMES:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Twin Primes").c_str());
            GenerateXPrimes(maxNumber, 2,2);
            break;
        case TRIPLET_PRIMES:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Triplet Primes").c_str());
            GenerateXPrimes(maxNumber, 2,3);
            break;
        case SEPARATED_BY_FOUR:
            glutSetWindowTitle(string(PROGRAM_NAME + " - All Primes Separated by Four").c_str());
            GenerateXPrimes(maxNumber, 4,2);
            break;
        case SEPARATED_BY_SIX:
            glutSetWindowTitle(string(PROGRAM_NAME + " - All Primes Separated by Six").c_str());
            GenerateXPrimes(maxNumber, 6,2);
            break;
        case SEPARATED_BY_TWELVE:
            glutSetWindowTitle(string(PROGRAM_NAME + " - All Primes Separated by Twelve").c_str());
            GenerateXPrimes(maxNumber, 12,2);
            break;


        //random
        case FIVE_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 5% fill").c_str());
            PureRandomPercent(maxNumber, .05);
            break;

        case TEN_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 10% fill").c_str());
            PureRandomPercent(maxNumber, .1);
            break;

        case FIFTEEN_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 15% fill").c_str());
            PureRandomPercent(maxNumber, .15);
            break;

        case TWENTY_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 20% fill").c_str());
            PureRandomPercent(maxNumber, .2);
            break;

        case THIRTY_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 30% fill").c_str());
            PureRandomPercent(maxNumber, .3);
            break;

        case FOURTY_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 40% fill").c_str());
            PureRandomPercent(maxNumber, .4);
            break;

        case FIFTY_PERCENT:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random 50% fill").c_str());
            PureRandomPercent(maxNumber, .5);
            break;

        case RANDOM_ODDS:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Random Odd Numbers").c_str());
            OddRandomPercent(maxNumber);
            break;

        //Other
        case FIBONACCI:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Fibonacci").c_str());
            GenerateFibonacci(maxNumber);
            break;

        case SQUARES:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Squares of Two").c_str());
            GenerateSquares(maxNumber);
            break;

        case KTH_VALUE:
            if(kVal > 3)
            {
                glutSetWindowTitle(string(PROGRAM_NAME + " - Every " + to_string(kVal) + "th Number").c_str());
            }
            else if(kVal == 3)
            {
                glutSetWindowTitle(string(PROGRAM_NAME + " - Every 3rd Number").c_str());
            }
            else if(kVal == 2)
            {
                glutSetWindowTitle(string(PROGRAM_NAME + " - Every 2nd Number").c_str());
            }
            else if(kVal == 1)
            {
                glutSetWindowTitle(string(PROGRAM_NAME + " - Every Number").c_str());
            }
            GenerateEveryKth(maxNumber);
            break;

        case HAPPY:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Happy Numbers").c_str());
            GenerateHappyNumbers(maxNumber);
            break;

        case ABUNDANTS:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Abundant Numbers").c_str());
            GenerateAbundantDeficient(maxNumber, ABUNDANT);
            break;

        case DEFICIENTS:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Deficient Numbers").c_str());
            GenerateAbundantDeficient(maxNumber, DEFICIENT);
            break;

        case LUCKY:
            glutSetWindowTitle(string(PROGRAM_NAME + " - Lucky Numbers (Warning Slow!)").c_str());
            GenerateLucky(maxNumber);
            break;

        default:
            break;
    }
}
