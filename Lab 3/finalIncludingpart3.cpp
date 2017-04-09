/* Name: <Cole Hunter>
Date: <10/3/16>
Title: Carbon dioxide fee calculation
File: Lab3
Description:
This program will calculate the number of gallons burned by your car and
use that info to calculate the number of kilos of CO2 released and a fee
based on that amount. It will also use these figures to make an estimate of
those same fees for the entire state of california driving population.
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()

int main()
{
	//variable declaration
	const double FEE = 0.25;
	const double GRAMSCO2 = 6453.00;
	double milage = 0.0;
	double mpg = 0.0;
	double gallons = 0.0;
	double kgCO2 = 0.0;
	double payment = 0.0;
	double totalPayment = 0.0;
	double totalCO2 = 0.0;
	int numDrivers = 24487807;

	//User values
	printf("Welcome to the Carbon Calculation Program \n");
	printf("Enter how many miles you drive per year: ");
	scanf_s("%lf", &milage);
	printf("\nEnter the fule efficiency of your car in miles per gallon: ");
	scanf_s("%lf", &mpg);

	//calculation section
	gallons = milage/mpg; // calculating gallons of fuel burned
	kgCO2 = (gallons * GRAMSCO2) / 1000.00; //calculating kilos of CO2 released
	payment = kgCO2*FEE; // calculating users fee
	totalCO2 = kgCO2*numDrivers; //CAlculating total CO2 released
	totalPayment = totalCO2*FEE; //Calculating total fee for California

								 //print statements based on calculations
	printf("\n You burned %lf gallons of gas last year\n", gallons);
	printf("You released %lf kilograms of CO2 last year\n", kgCO2);
	printf("Your fee comes to %lf dollars.\n", payment);
	printf("Assuming all cars are like yours, \n");
	printf("Total Carbon Dioxide released is: %lf \n", totalCO2);
	printf("Total Carbon Fee is: %lf \n", totalPayment);
	printf("Thank you for using this program. \n");



	return 0;
}
