#include <iostream>
#include <stdint.h>
#include <stdlib.h>     /* atoi */
#include <memory.h>

using namespace std;

bool is_prime( unsigned int uiCandidate )
{
	int i = 2;

	if ( 2 > uiCandidate )
		return false;

	if ( 2 == uiCandidate )
		return true;

	while ( ( i * i ) <= uiCandidate )
	{
		if ( ( uiCandidate % i ) == 0 )
			return false;
		i++;
	}

	return true;
}

unsigned int get_nth_prime( unsigned int uiNthPrime )
{
	unsigned int n = 6;

	if ( 1 == uiNthPrime )
		return 2;
	else
		uiNthPrime--;

	if ( 2 == uiNthPrime )
		return 3;
	else
		uiNthPrime--;

	// Test all numbers in the sequence 6n +- 1
	while ( uiNthPrime > 0 )
	{
		if ( is_prime( n - 1 ) )
		{
			if ( 0 == --uiNthPrime )
				return n - 1;
		}

		if ( is_prime( n + 1 ) )
		{
			if ( 0 == --uiNthPrime )
				return n + 1;
		}

		n += 6;
	}

	return 0;
}

/**
 * Entry point.
 */
int main( int argc, char**argv )
{
	int iInput;

	// Check args
	if ( argc < 2 )
	{
		cout << "Usage: " << argv[0] << " <number>" << endl;
		return 1;
	}

	// Get test number from input arg[1]
	iInput = atoi( argv[1] );

	cout << "The " << iInput <<  "th prime is " << get_nth_prime(iInput) << endl;
}
