#include <iostream>
#include <stdint.h>
#include <stdlib.h>     /* atoi */
#include <memory.h>

using namespace std;

#define TEST_NUMBER ( 20 )

bool is_factor( uint64_t qwCandidate, uint64_t qwLargeNum )
{
	if ( qwCandidate == 0 ) return false;

	return ( ( qwLargeNum % qwCandidate ) == 0 );
}

int smallest_prime_factor( uint64_t iNum )
{
	uint64_t n = 6;

	if ( is_factor( 2, iNum ) )
		return 2;

	if ( is_factor( 3, iNum ) )
		return 3;

	while ( n-1 <= iNum )
	{
		if ( is_factor( n - 1, iNum ) )
			return n - 1;

		if ( is_factor( n + 1, iNum ) )
			return n + 1;

		n += 6;
	}

	return 0;
}

int main( int argc, char**argv )
{
	int *a;
	int *b;
	int iCandidate;
	int iFactor;
	uint64_t multiple = 1;
	int iInput;
	int iBufLen;

	if ( argc < 2 )
	{
		cout << "Usage: " << argv[0] << " <number>" << endl;
		return 1;
	}

	iInput = atoi( argv[1] );
	iBufLen = iInput + 1;

	a = (int*)malloc( iBufLen * sizeof( int ) );
	b = (int*)malloc( iBufLen * sizeof( int ) );

	if ( NULL == a || NULL == b  )
	{
		return 1;
	}

	// Clear b in preparation
	memset( b, 0, iBufLen * sizeof( int ) );

	while( iInput >= 2 )
	{
		cout << "Testing " << iInput << endl;
		iCandidate = iInput;
		memset( a, 0, iBufLen * sizeof( int ) );

		while( ( iFactor = smallest_prime_factor( iCandidate ) ) )
		{
			iCandidate /= iFactor;
			a[iFactor]++;

			if ( b[iFactor] < a[iFactor] )
			{
				multiple *= iFactor;
				b[iFactor]++;
			}
		}

		iInput--;
	}

	free( a );
	free( b );

	cout << multiple << endl;
}
