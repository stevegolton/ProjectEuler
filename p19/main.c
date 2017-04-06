#include <stdio.h>

const int days_in_months[][2] = {
	{31, 31}, // Jan
	{28, 29}, // Feb
	{31, 31}, // Mar
	{30, 30}, // Apr
	{31, 31}, // May
	{30, 30}, // Jun
	{31, 31}, // Jul
	{31, 31}, // Aug
	{30, 30}, // Sep
	{31, 31}, // Oct
	{30, 30}, // Nov
	{31, 31}  // Dec
};

int is_leap_year(int year)
{
	if(    ((year % 4) == 0)			// Every 4 years ...
	    && (    ((year % 100) != 0)		// ... apart from every century ...
		     || ((year % 400) == 0)))	// ... except every 400 years
	{
		// Found a leap year
		return 1;
	}
	return 0;
}

int main(void)
{
	// Settings
	int verbose = 1;
	
	// Set our known initial conditions
	int day_of_week = 0; // Monday
	int month = 0; // January
	int year = 1900;

	// Initiailize our first_sunday count
	int sunday_count = 0;
	
	// Iterate through all the months from 1900 to present
	while(year <= 2000)
	{		
		// Only count sundays from 1901 onwards
		if((year >= 1901) && (day_of_week == 6))
		{
			sunday_count++;
			
			// Pretty print the date
			if(verbose) printf("01/%02d/%04d\n", month + 1, year);
		}
		
		// Calculate the number of days in this month
		day_of_week += (is_leap_year(year))? days_in_months[month][1] : days_in_months[month][0]; 
		day_of_week %= 7;

		// Increment the month and wrap if we hit 12, incrementing the year too.
		if(++month == 12)
		{
			month = 0;
			year++;
		}
	}

	printf("Total sundays which fell on the 1st of the month in the 20th century = %d\n", sunday_count);

	return 0;
}
