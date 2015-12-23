#include <iostream>
#include <stdint.h>
#include <memory.h>

using namespace std;

#define TEST_NUMBER ( 10 )

bool is_factor( uint64_t qwCandidate, uint64_t qwLargeNum )
{
	if ( qwCandidate == 0 ) return false;

	return ( ( qwLargeNum % qwCandidate ) == 0 );
}

int smallest_prime_factor( uint64_t iNum )
{
	uint64_t n = 6;

	if ( is_factor( 2, iNum ) )
	{
		return 2;
	}

	if ( is_factor( 3, iNum ) )
	{
		return 3;
	}

	while ( n-1 <= iNum )
	{
		if ( is_factor( n - 1, iNum ) )
		{
			return n - 1;
		}

		if ( is_factor( n + 1, iNum ) )
		{
			return n + 1;
		}

		n += 6;
	}

	return 0;
}

int main( void )
{
	uint64_t n;
	uint64_t f;
	uint64_t a[TEST_NUMBER + 1];
	uint64_t b[TEST_NUMBER + 1];
	uint64_t num;
	uint64_t index;
	uint64_t multiple = 1;

	memset( b, 0, sizeof(a) );

	for( num = 2; num <= TEST_NUMBER; num ++ )
	{
		cout << "Testing " << num << endl;
		n = num;
		memset( a, 0, sizeof(a) );

		while( ( f = smallest_prime_factor( n ) ) )
		{
			n /= f;
			a[f]++;
		}

		for( index = 0; index < sizeof(a) / sizeof(a[0]); index++ )
		{
			if (b[index] < a[index])
			{
				b[index] = a[index];
			}
		}
	}

	for( index = 0; index < sizeof(b) / sizeof(b[0]); index++ )
	{
		cout << "[" << index << "]x" << b[index] << endl;

		while ( 0 != b[index] )
		{
			multiple *= index;
			b[index] --;
		}
	}

	cout << multiple << endl;
}
