/* Name: <Cole Hunter>
Date: <10/24/16>
Title: Health Statistics Calculator
File: Lab6
Description:
This program allows a user to enter data about health
into an array for storage and will also perform a few
calulations on the data, like life expectancy comparisons.
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()

//global arrays
float healthData[7][2][2] = 
{
	{ {66.5,59.1},{72.2,62.9} },
	{ { 67.4,61.1},{74.1,66.3} },
	{ {68.0,60.0},{75.6,68.3} },
	{ {70.7,63.8},{78.1,72.5} },
	{ {72.7,64.5},{79.4,73.6} },
	{ {74.9,68.3},{80.1,75.2} },
	{ {76.5,71.8},{81.3,78.0} }
};// so you dont have to use scanf
	
float raceDifference[7][2][1]; //decade, race, difference
float genderDifference[7][2][1]; //decade sex, difference
float percentChange[6][2][2];

//function prototypes
void enterData(void);
void raceDifferenceF(void);
void genderDifferenceF(void);
void percentChangeF(void);
void tabularPrint(void);
void percentDprint(void);
void differencePrint(void);

int main()
{
	printf("Welcome.\n");
	//going through all functions sequentially
	//enterData(); only needed this function originally, was taken
	//out of lab. i kept the function for reference.
	raceDifferenceF();
	genderDifferenceF();
	percentChangeF();
	//these print everything out in a nice format
	tabularPrint();
	differencePrint();
	percentDprint();
	return 0;
}

void enterData(void) {
	//declaring variables for ease of user input
	int decade = 1950;
	char sex;
	char race;
	int i, j, k;
	float userInput;

	//entering data into global array healthData
	for (i = 0; i < 7; i++)
	{
		printf("Please Enter data for %d.\n", decade);
		for (j = 0; j < 2; j++)
		{
			//helps user kow what to enter
			if (j == 0)
				sex = 'M';
			else
				sex = 'F';
			for (k = 0; k < 2; k++)
			{
				//helps user know what to enter
				if (k == 0)
					race = 'W';
				else
					race = 'B';
				printf("Please proceed by inputting data for sex: %c and race: %c.\n", sex, race);
				scanf_s("%f", &userInput);
				healthData[i][j][k] = userInput;

			}
		}
		decade += 10;
	}
}

void raceDifferenceF(void)
{
	//iterating through
	int decade = 1950;
	char race;
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 2; j++)
		{
			//holding the sums, and counter
			int count = 0;
			float difference = 0;
			float d1, d2;
			if (j == 0)
				race = 'W';
			else
				race = 'B';
			d1 = healthData[i][j][count];
			count++; // this will make race a constant
			d2 = healthData[i][j][count];//putting array values into d2
			difference = d1 - d2;
			raceDifference[i][j][0] = difference;
		}
		decade += 10;
	}
}

void genderDifferenceF(void)
{
	//iterating the same way as enterData
	int decade = 1950;
	char sex;
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 2; j++)
		{
			//holding sums
			int count = 0;
			float difference = 0;
			float d1, d2;
			if (j == 0)
				sex = 'M';
			else
				sex = 'F';
			d1 = healthData[i][count][j];
			count++; // this will make sex a constant
			d2 = healthData[i][count][j];
			difference = d2 - d1;
			genderDifference[i][j][0] = difference;
		}
		decade += 10;
	}
}

void percentChangeF(void)
{
	//counters
	int i, j, k, count;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				count = 0;
				count = i;
				float PercentD, d1, d2;
				d1 = healthData[i][j][k];
				count++;
				d2 = healthData[count][j][k];
				PercentD = (d2 - d1) / d1 * 100; //percent change calculation
				percentChange[i][j][k] = PercentD;
			}
		}
	}
}

void tabularPrint(void)
{
	int i;
	int decade = 1950;
	printf("\nThe data entered was:\n");
	printf("Decade\tM White\t\tF White\t\tM Black\t\tF Black\n");
	for (i = 0; i < 7; i++)
	{
		printf("%d\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\n", decade, healthData[i][0][0], healthData[i][0][1], healthData[i][1][0], healthData[i][1][1]);
		decade += 10;
	}


}

void differencePrint(void)
{
	printf("\nFor the entered data:\n");
	printf("Decade\tWhite\tBlack\tMale\tFemale \n");
	printf("\tM vs F\tM vs F\tW vs B\tW vs B\n");
	int decade = 1950;
	int i, j;
	for (i = 0; i < 7; i++) {
		printf_s("%d", decade);
		for (int j = 0; j < 2; j++) //same race loop 
		{
			float one;
			one = genderDifference[i][j][0];
			printf("\t%.2f", one);
		}
		for (j = 0; j < 2; j++) { //same sex loop
			float two;
			two = raceDifference[i][j][0];
			printf("\t%.2f", two);
		}
		printf("\n");
		decade += 10;
	}
}

void percentDprint(void)
{
	printf_s("\nThe percent difference is:\n");
	printf_s("\t\tWhite\t\tBlack\n");
	printf_s("Decade\t\tMale\tFemale\tMale\tFemale");
	int decade = 1950;
	int i, j, k;
	for (i = 0; i < 6; i++) {
		printf("\n%d-", decade);
		decade += 10;
		printf("%d\t", decade);//decade difference
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				float printer;
				printer = percentChange[i][j][k];//printing out values
				printf("%.2f\t", printer);
			}
		}
	}
}