//[classmate], [classmate], Steven Ammer, & [classmate]
//Group Project
//[course details removed]
//[course details removed]

//Includes:
#include <stdio.h>
#include <stdlib.h>

//Definitions:
#define pause system("pause")
#define cls system("cls")
#define flush fflush(stdin)
#define SIZE 200

//Prototypes:
void displayMenu();
int getUserChoice();
void displayHistory(char[], int[], int, int);
void getSingleChar(char[], int[], int*, int*);
void searchForChar(char, char*, char[], int, int*);
void sortArrays(char[], int[], int, int);
void doTheSwitch(char[], int[], char*, int);
void getACharacterAndItsQuantity(char[], int[], int*, int*);
void userCharacterSearch(char[], int[], int);

//Main:
int main() {
	char userInput[SIZE];
	int runningTally[SIZE] = {0}, choice = 0, i = 0, count = 0;

	do {
		choice = getUserChoice();
		switch(choice) {
			case 1:
				getSingleChar(userInput, runningTally, &i, &count);
				break;
			case 2:
				getACharacterAndItsQuantity(userInput, runningTally, &i, &count);
				break;
			case 3:
				displayHistory(userInput, runningTally, i, count);
				break;
			case 4:
				userCharacterSearch(userInput, runningTally, count);
				break;
		} //End switch.
	} while(choice != 5); //End do while.
	printf("Thank you. Come again. \n");
	pause;
	return 0;
} //End Main

//Functions:
int getUserChoice() {
	int result;
	do {
		displayMenu();
		scanf_s("%i", &result);
		flush;
		if (result < 1 || result > 5) {
			printf("You must enter a number 1-5. \n");
			pause;
		} //End if.
	} while(result < 1 || result > 5); //End do while.
	return result;
} //End getUserChoice function.

void displayMenu() {
	cls;
	printf("MAIN MENU \n\n");
	printf("1. Enter a single character. \n");
	printf("2. Enter a character and its quantity. \n");
	printf("3. History. \n");
	printf("4. Search for a char. \n");
	printf("5. Quit. \n\n");
	printf("Enter choice: \n");
	return;
} //End displayMenu function.

void displayHistory(char userInput[], int runningTally[], int i, int count) {
	if (count > 0) {
		printf("What you've entered so far: \n\n");
		for(i = 0; i < count; i++) {
			printf("%c : %i time(s) \n", userInput[i], runningTally[i]);
		} //End for.
	} //End if.
	else {
		printf("You have to enter some data before you can get a history. \n");
	} //End else.
	pause;
	return;
} //End displayHistory function.

void getSingleChar(char userInput[], int runningTally[], int *i, int *count) {
	char temp, alreadyEntered = 'N';
	int location = 0; 
	
	printf("Enter any character on your keyboard. \n");
	scanf_s("%c", &temp);
	flush;
	searchForChar(temp, &alreadyEntered, userInput, *count, &location);
	if (alreadyEntered == 'Y') {
		runningTally[location] = runningTally[location] + 1;
		printf("You have now entered %c %i times. \n", temp, runningTally[location]);
	} //End if.
	else {
		userInput[*i] = temp;
		runningTally[*i] = 1;
		*i = *i + 1;
		*count = *count + 1;
		printf("You have now entered %c 1 time. \n", temp);
		sortArrays(userInput, runningTally, *i, *count);
	} //End else.
	pause;
	return;
} //End getSingleChar function.

void searchForChar(char temp, char *alreadyEntered, char userInput[], int count, int *location) {
	int first = 0, last = 0, middle = 0;
	char stop = 'N';
	last = count;
	middle = (first + last) / 2;
	while(first <= last && stop == 'N') {
		if (userInput[middle] < temp) {
			first = middle + 1;
		} //End if.
		else {
			if (userInput[middle] == temp) {
				*location = middle;
				stop = 'Y';
				*alreadyEntered = 'Y';
			} //End if.
			else {
				last = middle - 1;
			} //End else.
		} //End else.
		middle = (first + last) / 2;
	} //End while.
	return;
} //End searchForChar function.

void sortArrays(char userInput[], int runningTally[], int i, int count) {
	char switchMade = 'N';
	int bottom = count - 1;
	do {
		switchMade = 'N';
		for (i = 0; i < bottom; i++) {
			if (userInput[i] > userInput[i + 1]) {
				doTheSwitch(userInput, runningTally, &switchMade, i);
			} //End if.
		} //End for.
		bottom--;
	} while(switchMade == 'Y'); //End do while.
	return;
} //End sortArrays function.

void doTheSwitch(char userInput[], int runningTally[], char *switchMade, int i) {
	char temp;
	int temp2;
	temp = userInput[i];
	userInput[i] = userInput[i + 1];
	userInput[i + 1] = temp;
	temp2 = runningTally[i];
	runningTally[i] = runningTally[i + 1];
	runningTally[i + 1] = temp2;
	*switchMade = 'Y';
	return;
} //End doTheSwitch function.

void getACharacterAndItsQuantity(char userInput[], int runningTally[], int *i, int *count) {
	char temp, alreadyEntered = 'N';
	int location = 0, temp2 = 0;
	printf("Enter any character on your keyboard. \n");
	scanf_s("%c", &temp);
	flush;
	do {
		printf("Enter the ammount of times you would like to enter this character. \n");
		scanf_s("%i", &temp2);
		flush;
		if (temp2 < 1) {
			printf("You must enter a number that is greater than zero. \n");
		} //End if.
	} while (temp2 < 1); //End do while.
	searchForChar(temp, &alreadyEntered, userInput, *count, &location);
	if (alreadyEntered == 'Y') {
		runningTally[location] = runningTally[location] + temp2;
		printf("You have now entered %c %i times. \n", temp, runningTally[location]);
	} //End if.
	else {
		userInput[*i] = temp;
		runningTally[*i] = temp2;
		printf("You have now entered %c %i times. \n", temp, runningTally[*i]);
		*i = *i + 1;
		*count = *count + 1;
		sortArrays(userInput, runningTally, *i, *count);
	} //End else. 
	pause;
	return;
} //End GetACharacterAndItsQuantity function.

void userCharacterSearch(char userInput[], int runningTally[], int count) {
	char temp, alreadyEntered = 'N';
	int location = 0;
	if (count < 1) {
		printf("You haven't entered any characters yet. \n");
	} //End if.
	else {
		printf("Enter a character to check if it's been entered before: \n");
		scanf_s("%c", &temp);
		flush;
		searchForChar(temp, &alreadyEntered, userInput, count, &location);
		if (alreadyEntered == 'Y') {
			printf("You have entered %c %i times so far. \n", temp, runningTally[location]);
		} //End if.
		else {
		printf("You have not entered %c yet. \n", temp);
		} //End else.
	} //End else.
	pause;
	return;
} //End userCharacterSearch function.

