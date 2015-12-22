#include <iostream>
#include <stdint.h>

using namespace std;

#define LARGE_NUMBER ( 600851475143 )
//#define LARGE_NUMBER ( 21 )

bool is_factor( uint64_t qwCandidate, uint64_t qwLargeNum )
{
	if ( qwCandidate == 0 ) return false;

	return ( ( qwLargeNum % qwCandidate ) == 0 );
}

bool is_prime( uint64_t qwCandidate )
{
	uint64_t i = 2;
	bool prime = true; // Assume prime

	if ( qwCandidate < 2 )
	{
		return false;
	}

	while ( ( i * i ) <= qwCandidate )
	{
		if ( ( qwCandidate % i ) == 0 )
		{
			prime = false;
			break;
		}

		i++;
	}

	return prime;
}

int main( void )
{
	uint64_t i = 2;

	// Only bother testing up to the sqrt of the number
	while( ( i * i ) < LARGE_NUMBER )
	{
		if ( is_factor( i, LARGE_NUMBER ) )
		{
			// Is factor - check this factor...
			if ( is_prime( i ) )
				cout << i << endl;

			// ... and check the other factor
			if ( is_prime( LARGE_NUMBER / i ) )
				cout << LARGE_NUMBER / i << endl;
		}
		i++;
	}
}
