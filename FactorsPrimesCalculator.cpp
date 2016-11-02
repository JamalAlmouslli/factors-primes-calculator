#include <cstdlib>
#include <iostream>
#include <map>

using Factors = std::map<long long int, long long int>;
using Primes = std::map<int, int>;

Factors calculateFactors(long long int integer, int& numberOfFactors)
{
	Factors factors;
	
	// these avoids a call to std::sqrt()
    // doing so also avoids casting
	long long int incr = 0;
	long long int incrSum = 1;
	
	// start loop based on even or odd integer
	long long int i = (integer % 2 == 0) ? 2 : 3;
	
	for (; incrSum <= integer; i++)
    {
    	// get remainder and quotient at once
    	std::lldiv_t result = std::lldiv(integer, i);
    	
        if (result.rem == 0)
        {
			factors[i] = result.quot;
			numberOfFactors += (i == factors[i]) ? 1 : 2;
        }

        // addition is usually faster
		incr += 2;
		incrSum += incr;
    }
	
	return factors;
}

Primes calculatePrimes(long long int integer)
{
	Primes primes;
	int divisor = 2;

	while (integer % divisor == 0)
	{
		integer /= divisor;
		primes[divisor]++;
	}

	for (divisor = 3; integer > 1; divisor += 2)
    {
		while (integer % divisor == 0)
		{
			integer /= divisor;
			primes[divisor]++;
		}
    }
	
	return primes;
}

std::ostream& operator<<(std::ostream& out, Factors const& factors)
{
	for (auto& iter : factors)
	{
		out << iter.first << " x " << iter.second << "\n";
	}

	return out;
}

std::ostream& operator<<(std::ostream& out, Primes const& primes)
{
	const auto firstPrime = primes.cbegin();
	
	for (auto& iter : primes)
	{
		// don't print 'x' before first prime
		if (&iter != &*firstPrime)
		{
			out << " x ";
		}

		out << iter.first;

        // don't print exponent if 1
		if (iter.second > 1)
		{
			out << '^' << iter.second;
		}
	}

	return out;
}

int main()
{
	long long int integer;
	std::cin >> integer;

    // includes 1 and itself
    // such calculation not needed
	int numberOfFactors = 2;
	
	std::cout << "Factors of " << integer << ":\n\n";
	Factors factors = calculateFactors(integer, numberOfFactors);
	std::cout << "1 x " << integer << "\n" << factors;
	std::cout << "\n(" << numberOfFactors << " unique factors)\n\n";
	
	std::cout << "Prime Factorization of " << integer << ":\n\n";
	Primes primes = calculatePrimes(integer);
	std::cout << primes;
}