#include <stdio.h>		// printf
#include <stdlib.h>		// EXIT_SUCCESS

/**
 * Entry point
 */
int main(void)
{
	unsigned long long i = 123456789;
	char str[50];
	char *cur1, *cur2;
	int total = 0;

	// Brute force approach!
	while(i <= 9876543210)
	{
		//if(i%1000000000 == 0)printf("%llu\n", i);

		// Check whether the decimal number has duplicate digits in it
		// Naive implementation
		sprintf(str, "%010llu", i);

		//printf("%s\n", str);

		int dup = 0;
		cur2 = str;
		while(*cur2)
		{
			cur1 = (cur2 + 1);
			while(*cur1)
			{
				// Check we don't have a duplicate character in here
				if((*cur1 == *cur2) || (*cur1 > '9') || (*cur2 > '9'))
				{
					//printf("%c %c\n", *cur1, *cur2);
					dup = 1;
					goto end;
				}

				cur1++;
			}
			cur2++;
		}

end:
		if(!dup)
		{
			total++;
			printf("%d %s\n", total, str);
			if(total == 1000000) return EXIT_SUCCESS;
		}

		i++;
	}

	return EXIT_FAILURE;
}
