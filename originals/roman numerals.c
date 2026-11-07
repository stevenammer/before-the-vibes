//Written By: Steven Ammer
//Written On: 3/13/14
//Purpose: Converting numbers to Roman Numerals

#define _CRT_SECURE_NO_WARNINGS

//Includes:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Definitions:
#define pause system("pause")
#define cls system("cls")
#define flush fflush(stdin)

//Prototypes:
void getNumber(int*);

int main () {
	int num = 0, numberOfIs = 0, numberOfXs = 0, numberOfCs = 0, temp = 0, count = 0;
	while (num != -1) {
		getNumber(&num);
		if (num == 1000) {
			printf("M");
		} //End if.
		if (num > 899 && num < 1000) {
			printf("CM");
			num = num % 100;
		} //End if.
		if (num > 499 && num < 900) {
			printf("D");
			numberOfCs = (num - 500) / 100;
			for (count = 0; count < numberOfCs; count++) { 
				printf("C");
			} //End for.
			num = num % 100;
		} //End if.
		if (num > 99 && num < 400) {
			numberOfCs = num / 100;
			for (count = 0; count < numberOfCs; count++) { 
				printf("C");
			} //End for.
			num = num % 100;
		} //End if.
		if (num > 399 && num < 500) {
			printf("CD");
			num = num % 100;
		} //End if.
		if (num > 9 && num < 40) {
			numberOfXs = num / 10;
			for (count = 0; count < numberOfXs; count++) { 
				printf("X");
			} //End for.
		} //end if.
		if (num > 39 && num < 50) {
			printf("XL");
		} //End if.
		if (num > 49 && num < 90) {
			printf("L");
		} //End if.
		if (num > 59 && num < 90) {
			temp = num - 50;
			numberOfXs = temp / 10;
			for (count = 0; count < numberOfXs; count++) { 
				printf("X");
			} //End for.
		} //End if.
		if (num > 89 && num < 100) {
			printf("XC");
		} //End if.
		if (num % 10 < 4) {
			numberOfIs = num % 10;
			for (count = 0; count < numberOfIs; count++) {
				printf("I");
			} //End for.
			printf("\n");
		} //End if
		if (num % 10 == 4) {
			printf("IV \n");
		} //End if.
		if (num % 10 > 4 && num % 10 < 9) {
			printf("V");
			numberOfIs = num % 10 - 5;
			for (count = 0; count < numberOfIs; count++) {
				printf("I");
			} //End for.
			printf("\n");
		} //End if.
		if (num % 10 == 9) {
			printf("IX");
			printf("\n");
		} //End if
		if (num == -1) {
			printf("Thank you for learning about a pointless way of numbering things. \n");
		} //End if.
		pause;
		cls;
	} //End while
} //End main.

//Functions:
void getNumber(int *num) {
	do {
		printf("Enter a number 1-1000 or enter -1 to quit:");
		scanf("%i", num);
		flush;
		printf("You entered %i. \n", *num);
		if (*num < -1 || *num > 1000) {
			printf("You must enter a number 1-1000 or enter -1 to quit. \n");
		} //End if.
	} while (*num < -1 || *num > 1000); //End do while.
	return;
} //End getNumber function.5