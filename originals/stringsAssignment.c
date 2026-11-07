#define _CRT_SECURE_NO_WARNINGS

//Written By: Steven Ammer
//Written On: 1/30/14
//First strings assignment.

//Includes:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definitions:
#define pause system("pause");
#define cls system("cls");
#define flush fflush(stdin)

int getChoice();
void displayMenu();
void getNewString(char[]);
void displayTheString(char[]);
void displayStringReversed(char[]);
void displayLengthOfString(char[]);
void displayTheStringVertically(char[]);
void displayTheStringAsATriangle(char[]);

int main() {
	int choice = 0;
	char userString[100] = "Why don't you enter your own string?";
	do {
		choice = getChoice();
		switch (choice) {
			case 1:
				getNewString(userString);
				break;
			case 2:
				displayTheString(userString);
				break;
			case 3:
				displayStringReversed(userString);
				break;
			case 4:
				displayLengthOfString(userString);
				break;
			case 5:
				displayTheStringVertically(userString);
				break;
			case 6:
				displayTheStringAsATriangle(userString);
				break;
		} //End switch.
	} while (choice != 7);
	return 0;
} //End main.

int getChoice() {
	int result;
	do {
		displayMenu();
		scanf_s("%i", &result);
		if (result < 1 || result > 7) {
			printf("Error you must enter 1-7 only! \n");
			pause;
		} //End if.
	} while (result < 1 || result > 7);
	return result;
} //End function get choice.

void displayMenu() {
	cls;
	printf("Main Menu \n");
	printf("1. Enter a new string. \n");
	printf("2. Display the string. \n");
	printf("3. Display the string reversed. \n");
	printf("4. Display the length of the string. \n");
	printf("5. Display the string vertically. \n");
	printf("6. Display the string as a triangle. \n");
	printf("7. Quit. \n\n");
	printf("Enter selection:");
	return;
} //End function displayMenu

void getNewString(char userString[]) {
	printf("Enter your string:");
	scanf(" %99[^\n]", userString);
	flush;
	return;
} //End getNewString function.

void displayTheString(char userString[]) {
	printf("%s \n\n", userString);
	pause;
	return;
} //End displayTheString function.

void displayStringReversed(char userString[]) {
	int i = 0;
	for (i = strlen(userString) - 1; i >= 0; i--) {
		printf("%c", userString[i]);
	} //End for.
	printf("\n");
	pause;
	return;
} //End displayStringReversed function.

void displayLengthOfString(char userString[]) {
	printf("The length of %s is %i. \n", userString, strlen(userString));
	pause;
	return;
} //End displayLengthOfString function.

void displayTheStringVertically(char userString[]) {
	int i = 0;
	for (i = 0; i <= strlen(userString) - 1; i++) {
		printf("%c \n", userString[i]);
	} //End for.
	pause;
	return;
} //End displayTheStringVertically function.

void displayTheStringAsATriangle(char userString[]) {
	int i = 0, length = 1, count = 0;
	while (i <= strlen(userString) - 1) {
		for (count = 0; count < length; count++) {
			printf("%c", userString[i]);
			i++;
		} //End inner while.
		length++;
		printf("\n");
	} //End outter while.
	pause;
	return;
} //End displayTheStringAsATriangle