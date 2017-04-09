/* Names: <Cole Hunter> <Tyler Hack>
Date: <11/7/16>
Title: Room Reservation Tool
File: Lab8
Description:
This program will act as a tool for users to make
and change hotel room reservations. Users can make
requests to book romms and either be placed in a room
or be placed on the waitlist. users can also make changes
to reservations or cancel.
*/

#include "stdafx.h"
#include <stdio.h>// Needed for printf()
#include <stdlib.h>// Needed for system()
#include <string.h> //string stuff
#define SIZE 3 //how many rooms there are

//function prototypes
void reservation(int res[], int WL[], char rnames[][15], char WLnames[][15], int n, int *idp, FILE *inp);
void cancellationRoom(int res[], int WL[], char rnames[][15], char WLnames[][15], int n, int *idp, FILE *inp);
void waitCancelation(int res[], int WL[], char rnames[][15], char WLnames[][15], int n, int *idp, FILE *inp);
void listReservations(int a[], int b[], char rnames[][15], char WLnames[][15], int n, FILE *inp);

int main()
{
	//array declaration
	int rooms[SIZE];
	char reservationNames[SIZE][15];
	int waitlist[SIZE];
	char waitlistNames[SIZE][15];
	//commands for prompt, id for guests
	char command;
	static int id = 0;

	//filling rooms with 0
	//0 meann not occupied, for searching
	//filling strings with null
	for (int i = 0; i < SIZE; i++)
	{
		rooms[i] = 0;
		waitlist[i] = 0;
		reservationNames[i][0] = '\0';
		waitlistNames[i][0] = '\0';
	}
	//declaring and opening input file
	FILE *sampleinput;
	if ((sampleinput = fopen("lab8input.txt", "r")) == NULL)
	{
		printf("There was an error.\a");
		return(255);
	}

	//printing commands for user
	printf("Welcome to the Room Reservation Program!\n");
	printf("The commands are:\n");
	printf("R or r: reserve a room\n");
	printf("C or c: cancel a reservation\n");
	printf("W or w: remove a request from the waiting list\n");
	printf("L or l: list the current reservations for the night\n");
	printf("Q or q: quit the program\n");

	do //infinite loop
	{
		//this code if for use without test file
		printf("\nPlease enter a command: ");
		scanf(" %c", &command);
		
		//command = getc(sampleinput);
		//getc(sampleinput); //jumps to new line, this is needed becuase of way file is formatted
		switch (command) //performs action from input, calls corresponding functions
		{
		case 'R':
			reservation(rooms, waitlist, reservationNames, waitlistNames, SIZE, &id, sampleinput);
			break;
		case 'r':
			reservation(rooms, waitlist, reservationNames, waitlistNames, SIZE, &id, sampleinput);
			break;
		case 'C':
			cancellationRoom(rooms, waitlist, reservationNames, waitlistNames, SIZE, &id, sampleinput);
			break;
		case 'c':
			cancellationRoom(rooms, waitlist, reservationNames, waitlistNames, SIZE, &id, sampleinput);
			break;
		case 'W':
			waitCancelation(rooms, waitlist, reservationNames, waitlistNames, SIZE, &id, sampleinput);
			break;
		case 'w':
			waitCancelation(rooms, waitlist, reservationNames, waitlistNames, SIZE, &id, sampleinput);
			break;
		case 'L':
			listReservations(rooms, waitlist, reservationNames, waitlistNames, SIZE, sampleinput);
			break;
		case 'l':
			listReservations(rooms, waitlist, reservationNames, waitlistNames, SIZE, sampleinput);
			break;
		case 'Q':
			printf("Thank you for using our service!\n");
			break;
		case 'q':
			printf("Thank you for using our service!\n");
			break;
		default:
			printf("Error. Not Valid command. Please enter another.\n");
		}
	} while (command != 'Q' && command != 'q');
	//closingfile
	fclose(sampleinput);
	return 0;
}

void reservation(int res[], int WL[], char rnames[][15], char WLnames[][15], int n, int *idp, FILE *inp) //*idp is pointer for id counter
{
	//variable declaration for reservation
	//counters
	int i = 0, j = 0;
	//for searching arrays
	int foundRoom = 0, foundWL = 0;
	int WhereRoom, WhereWL;
	//for adding guest to waitlist
	char yn;

	//loop to check if there is an empty room
	while (!foundRoom && i < n)
	{
		if (res[i] == 0)
			foundRoom = 1;
		else
			i++;
	}

	//there is an empty room
	if (foundRoom)
	{
		WhereRoom = i;
		(*idp)++;
		res[i] = *idp;
		printf("\nThere is a room available.\n");
		printf("Please enter the name associated with this reservation: ");
		scanf("%s", rnames[i]);// for use without input file
		//fscanf(inp, "%s", rnames[i]); // scans input file for name to add
		//getc(inp); //jumps to new line
		printf("Thank you %s,\n", rnames[i]);
		printf("The room is number %d, your reservation ID is %d\n", (WhereRoom + 1), *idp);
	}
	//no rooms available
	else
	{
		printf("\nThere doesnt seem to be any rooms available.\n");
		printf("Would you like to be placed on the waitlist? Y for yes, N for no.\n");
		scanf(" %c", &yn);
		//yn = getc(inp);
		//getc(inp);
		//putting id in waitlist
		if (yn == 'Y')
		{
			while (!foundWL && j < n)//finding empty waitlist spot
			{
				if (WL[j] == 0)
					foundWL = 1;
				else
					j++;
			}

			if (foundWL == 1)//adding name to waitlist
			{
				WhereWL = j;
				(*idp)++;
				WL[j] = *idp;
				printf("Please enter the name associated with this reservation: ");
				scanf("%s", WLnames[j]);
				//fscanf(inp, "%s", WLnames[j]); // scans input file for name to add
				//getc(inp); //jumps to new line
				printf("Thank you %s,\n", WLnames[j]);
				printf("You have been added to the waitlist.\n");
			}
			else
			{
				printf("\nThe waitlist appears to be full.\n");
				printf("We are quite sorry, but you cannot be added.\n");
				printf("Thank you. Please come again soon.\n");
			}
		}
		else
			printf("\nThank you. Please come again soon.\n");
	}
}
void cancellationRoom(int res[], int WL[], char rnames[][15], char WLnames[][15], int n, int *idp, FILE *inp)
{
	int canceledID = 0;
	int found = 0;
	printf("\nEnter your given ID number.  ");
	scanf_s("%d", &canceledID);
	//fscanf(inp, "%d", &canceledID);
	//getc(inp);
	//checking to see if canceldID matches any of ids given
	for (int j = 0; j <= *idp; j++)
	{
		if (res[j] == canceledID)
		{
			res[j] = 0; //clearing out room reservation
			for (int z = 0; z < 15; z++)//deleting name from room
				rnames[j][z] = 0;
			found = 1;
			printf("Thank you. Your reservation has been removed.\n");
			if (WL[0] > 0)//adding name from waitlist to room 
			{
				res[j] = WL[0];
				strncpy(rnames[j], WLnames[0], 15);
				printf("ID %d on the waiting list has been confirmed into room %d", WL[0], (j + 1));
				for (int k = 1; k < SIZE; k++)
				{
					WL[k - 1] = WL[k]; //shifting evrybody in waitlist up a position
					strncpy(WLnames[k - 1], WLnames[k], 15); //shifting names
				}
				//these fill the very last spot with 0
				WL[(SIZE - 1)] = 0;
				for (int f = 0; f < 15; f++)
				{
					WLnames[(SIZE - 1)][f] = '\0';
				}
			}
			break;
		}
	}
	if (found == 0)
		printf("Sorry, your id is not valid. Please enter another.\n");
}

void waitCancelation(int res[], int WL[], char rnames[][15], char WLnames[][15], int n, int *idp, FILE *inp)
{
	int canceledID = 0;
	int found = 0;
	printf("\nEnter your given ID number.  ");
	scanf_s("%d", &canceledID);
	//fscanf(inp, "%d", &canceledID);
	//getc(inp);
	//checking to see if canceldID matches any of ids given
	for (int j = 0; j <= *idp; j++)
	{
		if (WL[j] == canceledID)
		{
			WL[j] = 0;
			found = 1;
			printf("Thank you. You are no longer on the waitlist.\n");
			//need to find where the in waitlist person was removed
			for (int w = j; w < SIZE; w++)
			{
				WL[w] = WL[w + 1]; // shifting up waitlist
				strncpy(WLnames[w], WLnames[w + 1], 15); //shifting names
			}
			//fill the very last spot with zero
			WL[(SIZE - 1)] = 0;
			for (int f = 0; f < 15; f++)
			{
				WLnames[(SIZE - 1)][f] = '\0';
			}
			break;
		}
	}
	if (found == 0)
		printf("Sorry, your id is not valid. Please enter another.\n");

}

void listReservations(int a[], int b[], char rnames[][15], char WLnames[][15], int n, FILE *inp)
{
	//prints all rooms and waitlist every time
	int j = 0;
	printf("\nRoom\t ID#\t Name\t\t\t\tWaitlist\tID \tName\n");
	for (j = 0; j < SIZE; j++)
	{
		printf("%d\t %d\t %s\t\t\t\t%d\t\t%d\t%s\n", (j + 1), a[j], rnames[j], (j + 1), b[j], WLnames[j]);

	}

}

/*
part 3
changes made to cope with time periods more than 1 day:
need new parallel array that holds length of reservation ie int days[SIZE][1], you would ask the user to enter how long their stay will be, and store that in the second dimension of days.
In the switch statement declare a new case E (for end of day) that enters you into an infinte while loop ie while(cmd!='N') until you enter the character 'N' (for new day), which breaks you out of the loop
then a counter that is representative of the number days, and then put an if statement that checks to see if any for days[SIZE] are equal to your days counter (dayscnt). example below
Case 'E':
for(int z= 0; z<SIZE; z++)
{
if(days[z]=dayscnt)
{
days[z] = 0;
cancellationRoom(parameters go here) // need to edit this function to pass in z value or use a very similar, but different function for this case
}
}
break;

changes made to cope with different priced rooms
to start, youll need another parallel array to rooms[], ie prices[SIZE][1], and you will need to fill each spot with the price information for that room.
print out all of the possible room prices for each room. ask the user if one of these is ok, and ask them which one they want.
once they enter a value, you can check which values in the array match and now you have the correct indicies for rooms[]. now you can run through a loop to
check if they are full. if they arent full, place them in that room, and if it is occupied, place them directly onto the waitlist. once a room becomes vacant,
scan through waitlist until a person is found  who matches that price range, and place that person in the room. if no person matches, do nothing.

*/

