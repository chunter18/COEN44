/* Name: <Cole Hunter>
Date: <10/17/16>
Title: Carbon dioxide fee calculation
File: Lab5
Description:
This program allows a user to enter three values and
will perform a variety of caculations like max, min,
and average by some user defined functions
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()
#define EPSILON 0.1

float maxval(float v1, float v2, float v3);
float minval(float v1, float v2, float v3);
char equalval(float v1, float v2, float v3);  // return = if they equal
float averageval(float v1, float v2, float v3);
char nearequal(float v1, float v2);


int main()
{
	//variable declaration
	float num1 = 0.0;
	float num2 = 0.0;
	float num3 = 0.0;
	float max = 0.0;
	float min = 0.0;
	float average = 0.0;
	char allEqual;
	char equalChar;
	char near1;
	char near2;
	char near3;
	char nearTot;
	int anotherOne = 0;
	//loop - do while
	do
	{
		// reading the numbers
		printf("Enter three real numbers : ");
		scanf_s("%f %f %f", &num1, &num2, &num3);

		//function calls and calculations
		max = maxval(num1, num2, num3);
		min = minval(num1, num2, num3);
		allEqual = equalval(num1, num2, num3);
		
		average = averageval(num1, num2, num3);
		equalChar = equalval(num1, num2, num3);
		near1 = nearequal(num1, num2);
		near2 = nearequal(num2, num3);
		near3 = nearequal(num3, num1);
		if (near1 == 'Y' || near2 == 'Y' || near3 == 'Y')
			nearTot = 'Y';
		else
			nearTot = 'N';
		// big ass print statement
		printf("------------------------------------------------------------------------------------------");
		printf("\nNum1\tNum2\tNum3\tMax\tMin\tAvg\tAll-Equal\tNear-Equal\tEpsilon");
		printf("\n------------------------------------------------------------------------------------------");
		printf("\n%.2f \t%.2f \t%.2f \t%.2f \t%.2f \t%.2f \t%c  \t\t%c \t\t%f", num1, num2, num3, max, min, average, allEqual, nearTot, EPSILON);
		printf("\n------------------------------------------------------------------------------------------");
		printf("\nWould you like to enter another data set? type 1 for yes, 0 for no. ");
		scanf_s(" %d", &anotherOne);
	} while (anotherOne == 1);
	return 0;
}

//programmer defined functions
float maxval(float v1, float v2, float v3)
{
	float maximum = 0.0;
	if (v1 == v2 && v2 == v3)
		maximum = v2;
	if (v1>v2 && v1>v3)
		maximum = v1;
	if (v2>v1 && v2>v3)
		maximum = v2;
	if (v3>v2 && v3>v1)
		maximum = v3;
	return(maximum);
}

float minval(float v1, float v2, float v3)
{
	float minimum = 0.0;
	if (v1 == v2 && v2 == v3)
		minimum = v2;
	if (v1<v2 && v1<v3)
		minimum = v1;
	if (v2<v1 && v2<v3)
		minimum = v2;
	if (v3<v2 && v3<v1)
		minimum = v3;
	return(minimum);
}

float averageval(float v1, float v2, float v3)
{
	float avg = 0.0;
	avg = (v1 + v2 + v3) / 3;
	return(avg);
}

char equalval(float v1, float v2, float v3)
{
	char equalOr;
	if (v1 == v2 && v2 == v3)
		equalOr = '=';
	else
		equalOr = '#';
	return(equalOr);
}

char nearequal(float v1, float v2)
{
	char Near;
	double difference = 0.0;
	difference = v1 - v2;
	if (difference <= EPSILON || difference >= (-1 * EPSILON))
	{
		Near = 'Y';
	}
	else
	{
		Near = 'N';
	}
	return(Near);
}
