#include <iostream>
#include <stdint.h>
#include <stdlib.h>     /* atoi */
#include <memory.h>

using namespace std;

/**
 * Entry point.
 */
int main( int argc, char**argv )
{
	int iInput;
	int iTest;
	uint64_t qwSumOfSquares = 0;
	uint64_t qwSquareOfSum = 0;

	// Check args
	if ( argc < 2 )
	{
		cout << "Usage: " << argv[0] << " <number>" << endl;
		return 1;
	}

	// Get test number from input arg[1]
	iInput = atoi( argv[1] );

	// Work out the sum of the squares
	iTest = iInput;
	while( iTest  > 0 )
	{
		qwSumOfSquares += iTest * iTest;
		iTest--;
	}

	// Work out the square of the sum
	iTest = iInput;
	while( iTest  > 0 )
	{
		qwSquareOfSum += iTest;
		iTest--;
	}
	qwSquareOfSum *= qwSquareOfSum;

	// Print result
	cout << "Sum of squares (a) = " << qwSumOfSquares << endl;
	cout << "Square of sums (b) = " << qwSquareOfSum << endl;

	cout << "b-a = " << qwSquareOfSum - qwSumOfSquares << endl;
}
