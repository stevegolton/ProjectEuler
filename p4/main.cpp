#include <iostream>
#include <stdint.h>

using namespace std;


bool is_palendrome( int iCandidate )
{
	uint8_t buf[6];
	int iSize = 0;
	int j = 0;

	if ( iCandidate < 0 )
		return false;

	while( iCandidate > 0 )
	{
		buf[iSize++] = iCandidate % 10;
		iCandidate /= 10;
	}

	bool yes = true;

	while( j < iSize )
	{
		if ( buf[j] != buf[iSize-j-1] )
		{
			yes = false;
			break;
		}
		j++;
	}

	return yes;
}

int main( void )
{
	int i = 100;
	int j = 100;
	int max = 0;
	int candidate;

	while ( i <= 999 )
	{
		j = 100;
		while ( j <= 999 )
		{
			candidate = i * j;
			if ( is_palendrome( candidate ) )
			{
				if ( candidate > max )
				{
					cout << i << "x" << j << "=" << candidate << endl;
					max = candidate;
				}
			}

			j++;
		}

		i++;
	}
}
