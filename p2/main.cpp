#include <iostream>

using namespace std;

bool is_even( int i )
{
	return ( i % 2 == 0 );
}

int main( void )
{
	int fib1 = 1;
	int fib2 = 2;
	int fib3 = 0;
	int sum = 2;

	while( fib3 < 4000000 )
	{
		// Calulate next fib number
		fib3 = fib1 + fib2;

		if( is_even( fib3 ) )
		{
			sum += fib3;
		}
	
		// Move on down the chain
		fib1 = fib2;
		fib2 = fib3;
	}

	cout << "Sum = " << sum << endl;
}	
