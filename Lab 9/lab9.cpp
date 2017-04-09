/* Names: <Cole Hunter>
Date: <11/7/16>
Title: Series Approximation program
File: Lab9
Description:
This program will allow a user to choose one of two functions
to approximate using infinite taylor series. The user will then
enter a value for x in that function, and how many decimal
digits to approximate to. the program then uses that information
to do the calculation.
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()
#include <string.h> //string stuff
#include <math.h> //for exponents

//global struct declaration
typedef struct {
	int terms;
	double finalval;
}calculation_t;

//function prototypes
calculation_t ln(double x, double precision, int *count);
calculation_t oneover(double x, double precision, int *count);

int main()
{
	printf("Welcome to the approximation program!\n");
	while (0 != 1) //infinte loop
	{
		//variable declaration
		char ab;
		double x = 0;
		double error = 0;
		int ooCount = 0;
		int lnCount = 0;

		//initial print and user promt/input
		printf("You have two options of functions.\n");
		printf("Please choose one of the following.\n\n");
		while (0 != 1)
		{
			printf("A) 1/(1-x) \t OR \t B) ln( (1+x)/(1-x) )\n");
			printf("Which function would you like? Enter A or B:  ");
			scanf("  %c", &ab);
			if (ab == 'A' || ab == 'B')
				break;
			else
				printf("Error! Character entered is neither A or B. Please try again.");
		}
		while (0 != 1)
		{
			printf("\nPlease remember -1<X<1\n");
			printf("Enter your X value:  ");
			scanf(" %lf", &x);
			if ((x >= -1) && (x <= 1))
				break;
			else
				printf("Error! not within the the accepted limit. Please try again.");
		}
		printf("\nTo what decimal place would you like to aprroximate?\n");
		printf("Please enter a value:  ");
		scanf("%lf", &error);
		if (ab == 'A')//one over calculation
		{
			calculation_t print;
			print = oneover(x, error, &ooCount);
			printf("Value = %f\n", print.finalval); //dereferencing the struct for print
			printf("Number of terms calculated: %d\n\n", print.terms);
		}

		else //ln calculation
		{
			calculation_t print1;
			print1 = ln(x, error, &lnCount);
			printf("Value = %f\n", print1.finalval); //dereferencing the struct for print
			printf("Number of terms calculated: %d\n\n", print1.terms);
		}

	}
	return 0;
}

calculation_t ln(double x, double precision, int *count)
{
	double lntotal = 0;
	double lnabs = 0; //can make this zero, do while always executes once which changes that value
	double lastterm = 0;
	double recent = 0;
	*count = 1;
	do
	{
		lastterm = lntotal; //last value
		lntotal = lntotal + (2 * pow(x, *count)) / (*count); //taylor series calculation
		recent = lntotal; // value just calculated
		(*count) += 2;
		lnabs = recent - lastterm; //for finding where to stop
	} while (lnabs > precision || lnabs < -1 * (precision));
	calculation_t z{ ((*count) / 2) , lntotal };
	return(z);
}
calculation_t oneover(double x, double precision, int *count)
{
	double oototal = 0;
	double ooabs = 0; //can make this zero, do while always executes once which changes that value
	double lastterm = 0;
	double recent = 0;
	do
	{
		lastterm = oototal; //last value
		oototal = oototal + pow(x, *count); //taylor series calculation
		recent = oototal; //value just calculated
		(*count)++;
		ooabs = recent - lastterm; //for finding where to stop
	} while (ooabs > precision || ooabs < -1 * (precision));
	calculation_t z{ *count , oototal };
	return(z);
}
