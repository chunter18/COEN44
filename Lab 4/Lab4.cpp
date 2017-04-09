/* Name: <Cole Hunter>
Date: <10/10/16>
Title: Carbon dioxide fee calculation
File: Lab4
Description:
This program will calculate the number of gallons burned by your car and
use that info to calculate the number of kilos of CO2 released and a fee
based on that amount. It will also adjust that fee based on your families
income.
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()

//function prototypes

double adjustedFee(double taxBracket);
int i;

int main()
{
	for (i = 0; i <= 5; i++)
	{
		//variable declaration
		const double FEE = 1.00;
		const double GRAMSCO2 = 8887.00;
		double milage = 0.0;
		double mpg = 0.0;
		double gallons = 0.0;
		double kgCO2 = 0.0;
		double payment = 0.0;
		double totalFee = 0.00;
		double multiplier = 0;
		double familyIncome = 0.0;


		//entering values
		printf("Welcome to the Carbon Calculation Program \n");
		printf("Enter how many miles you drive per year: ");
		scanf_s("%lf", &milage);
		printf("\nEnter the fule efficiency of your car in miles per gallon: ");
		scanf_s("%lf", &mpg);
		printf("\nPlease enter your yearly family income (family of four): ");
		scanf_s("%lf", &familyIncome);
		//getting fee multiplier
		multiplier = adjustedFee(familyIncome);
		//printf("%lf",&multiplier);

		//calculation section
		gallons = milage / mpg; // calculating gallons of fuel burned
		kgCO2 = (gallons * GRAMSCO2) / 1000.00; //calculating kilos of CO2 released
		payment = kgCO2*FEE; // calculating users fee
		totalFee = payment*multiplier;

		//final print statements
		printf("\nThank you. ");
		printf("\nYour total carbon produced is: %lf Kilograms. ", kgCO2);
		//printf("\nThe total fee is: %lf", payment);
		printf("\nYour income adjusted fee is: %lf", totalFee);
		printf("\n");

	}
	return 0;
}

double adjustedFee(double taxBracket)
{
	//variable declaraton
	double mult = 0.0;
	double poverty = 23850.00;
	double median = 71015;

	//conditionals to determine multipler to payment
	if (taxBracket <= poverty)
		mult = 0.0;
	if (taxBracket>poverty && taxBracket <= (2 * poverty))
		mult = 0.5;
	if (taxBracket>(2 * poverty) && taxBracket <= (2 * median))
		mult = 1.0;
	if (taxBracket>(2 * median) && taxBracket <= (3 * median))
		mult = 2.0;
	if (taxBracket>(3 * median) && taxBracket <= (4 * median))
		mult = 4.5;
	if (taxBracket >= (4 * median))
		mult = 10.0;
	return(mult);
}