#include <stdio.h>		// printf
#include <stdlib.h>		// EXIT_SUCCESS

/**
 * Checks a string to see if it contains duplicate characters.
 * Returns !0 if all characters are unique, 0 otherwise.
 */
int is_unique(const char *str)
{
	const char *c1, *c2;

	// Arrange two cursors c1 & c2 to scan through the string and find
	// duplicate characters, starting from the beginning of course!
	c1 = str;
	while(*c1)
	{
		// Put the second cursor just after the first one, no need to scan
		// behind the first cursor...
		c2 = (c1 + 1);
		while(*c2)
		{
			// Check we don't have a duplicate character in here
			if(*c2 == *c1)
			{
				return 0;
			}

			c2++;
		}
		c1++;
	}

	return 1;
}

/**
 * Entry point
 */
int main(void)
{
	unsigned long long i = 123456789;
	char str[50];
	char *c2, *c1;
	int total = 0;
	const int target = 1000000;

	// Brute force approach!
	while(i <= 9876543210)
	{
		// Print our number to a string
		sprintf(str, "%010llu", i);

		if(is_unique(str))
		{
			total++;
			printf("%d %s\n", total, str);
			if(total == target) return EXIT_SUCCESS;
		}

		i++;
	}

	return EXIT_FAILURE;
}
