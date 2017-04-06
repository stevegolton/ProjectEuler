#include <stdio.h>
#include <string.h>

#define NUM_DIGITS (1000)

/** Adds big integers dest and src together assuming they both have size "digits", storing the result in dest.
 *
 *
 */
void add_big_ints(unsigned int *dest, unsigned int *src, size_t digits)
{
	for(int i=1; i<NUM_DIGITS; i++)
	{
		unsigned int res = dest[i] + src[i];
		dest[i] = res % 10;
		dest[i-1] += res / 10;
	}
}

int main(int argc, char *argv[])
{
	// Settings
	int verbose = 1;
	
	unsigned int bignum[NUM_DIGITS] = {0, };
	bignum[NUM_DIGITS - 1] = 1;
	unsigned int buf[NUM_DIGITS] = {0, };
	
	unsigned int multiplier = atoi(argv[1]);
	int i;
	int latch = 0;
	unsigned int total = 0;
	
	while(multiplier > 1)
	{
		// Make a copy of the bug number
		memcpy(buf, bignum, sizeof(bignum));
		for(i=0; i<multiplier-1; i++)
		{
			add_big_ints(bignum, buf);
		}
		multiplier --;
	}

	if (verbose)
	{
		printf("%d! = ", atoi(argv[1]));
		for(i=0; i<NUM_DIGITS; i++)
		{
			if(bignum[i] !=0) latch = 1;
			if(latch)
				printf("%u", bignum[i]);
			
			total += bignum[i];
		}
		printf("\n");
	}
	
	printf("Sum of digits = %u\n", total);
	
	return 0;
}
