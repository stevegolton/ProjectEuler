#include <iostream>

using namespace std;

bool multiple_of_5(int i)
{
	return ( i%5 == 0 );
}

bool multiple_of_3(int i)
{
	return ( i%3 == 0 );
}

int main(void)
{
	int i, total;

	cout << "Hello world!" << endl;

	for ( i = 0; i < 1000; i++ )
	{
		if ( multiple_of_5(i) || multiple_of_3(i) )
		{
			total += i;
			//cout << "Yep" << i << endl;
		}
	}

	cout << "Total = " << total << endl;

	return 0;
}
