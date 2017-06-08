#include <stdio.h>		// printf, fprintf, fscanf, FILE
#include <stdlib.h>		// malloc, realloc, free, EXIT_FAILURE, EXIT_SUCCESS
#include <string.h>		// strlen, strcpy
#include <ctype.h>		// toupper

/**
 * Calculates the alphabetical value of a string.
 */
int calc_value(char *name)
{
	int value = 0;

	while(*name)
	{
		value += (toupper(*name) - 'A') + 1;
		name++;
	}

	return value;
}

/**
 * Compares two strings (where a and b are pointers to char pointers) returning
 * a positive number if b is of higher alphabetical order and a negative number
 * if a is of higher alphabetical order. Returns 0 if the names are identical.
 */
int compare(const void *a, const void *b)
{
	char *name_a = *(char**)a;
	char *name_b = *(char**)b;

	// Walk through both strings until at least one of them ends
	while(*name_a && *name_b)
	{
		// If the characters differ, return the difference between them
		if(*name_a != *name_b)
			return *name_a - *name_b;

		// Move the pointer on through the strings
		name_a++;
		name_b++;
	}

	// If we have ended one string, see which one still has characters remaining
	if(*name_a) return +1;
	if(*name_b) return -1;

	// If we have got here the strings are exactly identical
	return 0;
}

/**
 * Entry point
 */
int main(void)
{
	FILE *f;						// File pointer to use for reading the names file
	char name[100] = {'\0', };		// Temporary buffer for holding names
	char **names = NULL;			// List of names
	int size = 0;					// Number of elements in the list of names
	int total = 0;					// Total problem count

	// Try to open the file
	f=fopen("names.txt", "r");

	// Did it work?
	if(NULL != f)
	{
		// Scan and read in all the names in the .csv file
		while(0 < fscanf(f, "\"%[A-Z]\",", &name[0]))
		{
			// Resize the array of names, as we have another to add
			void *ptr = realloc((void*)names, sizeof(char*) * (size + 1));
			if(NULL != ptr)
			{
				// Malloc worked, store our new pointer
				names = (char**)ptr;

				// Allocate enough room for this name
				names[size] = (char*)malloc(strlen(name));
				if(NULL != names[size])
				{
					// Copy it in and officially increment the number of
					// elements in this array
					strcpy(names[size], name);
					size++;
				}
				else
				{
					// Error while trying to allocate memory for the name
					fprintf(stderr, "Memory allocation error\n");

					// Free the pre-existing names
					for(int i = 0; i < size; i++) free(names[i]);

					// Free the list of names
					free(names);

					// Set list of names to NULL so we don't try and access it
					// later
					names = NULL;
					size = 0;
					break;
				}
			}
			else
			{
				// Error while trying to allocate memory for a new pointer
				fprintf(stderr, "Memory allocation error\n");

				// Free the pre-existing names
				for(int i = 0; i < size; i++) free(names[i]);

				// Free the list of names (if we have one yet)
				if(NULL != names) free(names);

				// Set list of names to NULL so we don't try and access it later
				names = NULL;
				size = 0;
				break;
			}
		}

		// Check we got at least some names from the file with no errors
		if (NULL != names)
		{
			// Sort the list using our compare function up above
			qsort(names, size, sizeof(char*), compare);

			// Run through the list, printing, working out values, and freeing
			// pointers
			for(int i = 0; i < size; i++)
			{
				// Calculate concrete values, positions and increment the total
				int value = calc_value(names[i]);
				int position = i+1;
				total += position*value;

				printf("%s: %d * %d = %d\n", names[i], position, value, position*value);

				// Free this name, we are done with it
				free(names[i]);
			}

			printf("Total value = %d\n", total);

			// Free the list of names
			free(names);
		}
		else
		{
			// No names read from file
			fprintf(stderr, "Unable to read any names from the file!\n");
		}

		fclose(f);
	}
	else
	{
		// fopen failed
		fprintf(stderr, "Unable to open file\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
