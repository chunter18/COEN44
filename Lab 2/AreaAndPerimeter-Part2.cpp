/*
Date: <9/26/2016>
Name: <Cole Hunter>
Lab #1: Introduction to Visual C
Description: <This program asks the user for some integer values of length and width of a rectangle
and then calculates perimeter and area based on those values.>
*/
/* Library header files */
#include <stdafx.h>
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()
int main(void)
{
	int width, length, perimeter, area; // integer variables
	float ratio; // real (decimal pt) variables
	printf("\nCalculations on a rectangle . . .\n\n");
	printf(" Enter rectangle width> ");
	scanf_s("%d", &width);
	printf(" Enter rectangle length> ");
	scanf_s("%d", &length);
	perimeter = 2 * width + 2 * length;
	area = width * length;
	ratio = area / perimeter;
	printf("\nPerimeter of rectangle = %d\n\n", perimeter);
	printf("Area of rectangle = %d\n\n", area);
	printf("Ratio of Area to Perimeter (A/P) = %8.2f\n\n",
		ratio);
	system("pause");
	return 0;
}