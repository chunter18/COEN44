/* Name: <Cole Hunter>
Date: <10/31/16>
Title: Vector Calculator using Arrays
File: Lab7
Description:
This program allows a user to enter the components of two
vectors and will perform calculations on them and return
the values of those calculations.
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()

//function prototypes
float vectorSum(float a[], float b[], float c[], int n);
float vectorDiff(float a[], float b[], float c[], int n);
float vectorMinMax(float a[], float b[], float *c, float *d);


int main()
{
	//variable declaration
	int i, j; //counter variables
	 //arrays
	float vector1[3];
	float vector2[3];
	float diffAns[3];
	float sumAns[3];
	//min and max pointers
	float min;
	float max;

	//entering the vectors
	printf("\nEnter the components of the first vector: \n");
	for (i = 0; i < 3; i++)
		scanf_s("%f", &vector1[i]);
	printf("\nEnter the components of the second vector: \n");
	for (j = 0; j < 3; j++)
		scanf_s("%f", &vector2[j]);

	//functionc alls
	vectorSum(vector1, vector2, sumAns, 3);
	vectorDiff(vector1, vector2, diffAns, 3);
	vectorMinMax(vector1, vector2, &min, &max);

	//printing statements
	printf("\nThe componenets of the vectors you entered are: \n");
	printf("Vector 1: %fi %fj %fk\n", vector1[0], vector1[1], vector1[2]);
	printf("Vector 2: %fi %fj %fk\n", vector2[0], vector2[1], vector2[2]);
	printf("\nThe sum of the two vectors is: \n");
	printf("%fi %fj %fk\n", sumAns[0], sumAns[1], sumAns[2]);
	printf("\nThe difference of the two vectors are: \n");
	printf("%fi %fj %fk\n", diffAns[0], diffAns[1], diffAns[2]);
	printf("\nThe minimum component value is: %f \n", min);
	printf("\nThe maximum component value is: %f \n", max);

	return 0;
}

float vectorSum(float a[], float b[], float c[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i]; //summing up the ith components
	}

	return(0);
}

float vectorDiff(float a[], float b[], float c[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		c[i] = a[i] - b[i]; // taking the difference of the ith components
	}

	return(0);
}

float vectorMinMax(float a[], float b[], float *c, float *d)
{
	int i, j, k, l;
	*c = a[0];
	*d = a[0];

	//finding max values
	for (i = 0; i < 3; i++)
	{
		if (a[i] > *d)
			*d = a[i];
	}

	for (j = 0; j < 3; j++)
	{
		if (b[j] > *d)
			*d = b[j];
	}

	//finding min values
	for (k = 0; k < 3; k++)
	{
		if (a[k] < *c)
			*c = a[k];
	}

	for (l = 0; l < 3; l++)
	{
		if (a[l] < *c)
			*c = a[l];
	}

	return(0);
}


