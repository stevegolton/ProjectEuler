#include <iostream>
#include <stdint.h>
#include <stdlib.h>     /* atoi */
#include <memory.h>

using namespace std;

/**
 * Tests whether a number is a factor of another number.
 *
 * @param[in]	uiCandiate	Potential factor.
 * @param[in]	uiLargeNum	Number to test against.
 *
 * @returns		true if factor, false otherwise
 */
bool is_factor( unsigned int uiCandidate, unsigned int uiLargeNum )
{
	// Don't divide by 0
	if ( uiCandidate == 0 )
		return false;

	// Check remainder from divide
	return ( ( uiLargeNum % uiCandidate ) == 0 );
}

/**
 * Primality test.
 *
 * @param[in]	iCandidate	Potential prime.
 *
 * @returns		true if iCandidate is prime, false otherwise.
 */
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

/**
 * Gets the smallest prime factor of a given integer.
 *
 * @param[in]	uiNum	The number to factorise.
 *
 * @returns		Smallest prime factor of uiNum.
 */
unsigned int smallest_prime_factor( unsigned int uiNum )
{
	int n = 6;

	// First test 2 and 3 as we know they are prime
	if ( is_factor( 2, uiNum ) )
		return 2;

	if ( is_factor( 3, uiNum ) )
		return 3;

	// Test all numbers in the sequence 6n +- 1
	while ( n-1 <= uiNum )
	{
		if ( is_factor( n - 1, uiNum ) )
			if ( is_prime (  n - 1 ) )
				return n - 1;

		if ( is_factor( n + 1, uiNum ) )
			if ( is_prime (  n + 1 ) )
				return n + 1;

		n += 6;
	}

	return 0;
}

/**
 * Entry point.
 */
int main( int argc, char**argv )
{
	int *aiLocal;
	int *aiMaster;
	int iCandidate;
	int iFactor;
	uint64_t qwResult = 1;
	int iInput;
	int iBufLen;
	bool bFirst = true;

	// Check args
	if ( argc < 2 )
	{
		cout << "Usage: " << argv[0] << " <number>" << endl;
		return 1;
	}

	// Get test number from input arg[1]
	iInput = atoi( argv[1] );
	iBufLen = iInput + 1;

	// Allocate memory for
	aiMaster = new int[iBufLen];
	aiLocal = new int[iBufLen];

	if ( NULL == aiMaster || NULL == aiLocal  )
	{
		cout << "Memory allocation error" << endl;
		return 1;
	}

	// Clear b in preparation
	memset( aiMaster, 0, iBufLen * sizeof( int ) );

	// Run through all the numbers from iInput down to 2
	while( iInput >= 2 )
	{
		// Copy iInput and keep factorising until we reach 1.
		iCandidate = iInput;

		memset( aiLocal, 0, iBufLen * sizeof( int ) );

		while( ( iFactor = smallest_prime_factor( iCandidate ) ) )
		{
			iCandidate /= iFactor;
			aiLocal[iFactor]++;

			// Increment our master array b
			if ( aiMaster[iFactor] < aiLocal[iFactor] )
			{
				// Work out the final result here
				qwResult *= iFactor;
				aiMaster[iFactor]++;

				// Print the factors as we multiply them
				if ( bFirst )
				{
					bFirst = false;
					cout << iFactor;
				}
				else
				{
					cout << " * " << iFactor;
				}
			}
		}

		iInput--;
	}

	// Mr clean
	delete( aiMaster );
	delete( aiLocal );

	// Print result
	cout << " = " << qwResult << endl;
}
