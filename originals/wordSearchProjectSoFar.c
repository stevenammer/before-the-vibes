#define _CRT_SECURE_NO_WARNINGS

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Definitions
#define pause system("pause")
#define cls system("cls")
#define flush fflush(stdin)
#define DIRECTIONLB 1
#define DIRECTIONUB 8
#define SPOTINGRIDILB 0
#define SPOTINGRIDIUB 30
#define SPOTINGRIDJLB 0
#define SPOTINGRIDJUB 60

//Prototypes
void doIntro(int*);
void getWords(char[][20], int);
void enterUserWord(char[][20], char[], int);
void enterWordsIntoGrid(char[][20], char[][60], int);
void chooseDirection(int*);
void chooseSpotinGrid(int*, int*);
void enterWordRight(char[][20], char[][60], char*, int, int, int);
void enterWordLeft(char[][20], char[][60], char*, int, int);
void enterWordUp(char[][20], char[][60], char*, int, int);
void enterWordDown(char[][20], char[][60], char*, int, int);
void enterWordUpRight(char[][20], char[][60], char*, int, int);
void enterWordUpLeft(char[][20], char[][60], char*, int, int);
void enterWordDownLeft(char[][20], char[][60], char*, int, int);
void enterWordDownRight(char[][20], char[][60], char*, int, int);

int main() {
	int numberOfWords = 0;
	char words [16][20];
	char grid [30][60];
	doIntro(&numberOfWords);
	getWords(words, numberOfWords);
	enterWordsIntoGrid(words,grid, numberOfWords);
} //End main.

//Functions:
void doIntro(int *numberOfWords) {
	printf("You are going to create a word search. \n");
	printf("You can enter up to 16 words into the word search. \n");
	do {
		printf("How many words would you like to be in the word search? \n");
		scanf("%i", numberOfWords);
		if (*numberOfWords < 1 || *numberOfWords > 16) {
			printf("You must pick a number 1-16. \n");
			pause;
		} //End if.
	} while (*numberOfWords < 1 || *numberOfWords > 16); //End do while.
	printf("You have chosen to enter %i words \n", *numberOfWords);
	pause;
	return;
} //End doIntro function.

void getWords(char words[][20], int numberOfWords) {
	int count = 0;
	char userWord [20];
	do {
		cls;
		printf("Enter word %i:", count + 1);
		scanf("%s", userWord);
		flush;
		printf("You entered %s. \n", userWord);
		enterUserWord(words, userWord, count);
		count++;
	} while (count < numberOfWords); //End do while.
	return;
} //End getWords function.

void enterUserWord(char words[][20], char userWord[], int count) {
	int i = count, j = 0, letters = 0;
	for (j = 0; j < strlen(userWord); j++) {
		words[i][j] = userWord[letters];
		letters++;
	} //End for.
	return;
} //End enterUserWord function.

void enterWordsIntoGrid(char words[][20], char grid[][60], int numberOfWords) {
	int direction = 0, spotInGridI = 0, spotInGridJ = 0, count = 0;
	char doesItFit = 'N';
	do {
		do {
			chooseDirection(&direction);
			chooseSpotinGrid(&spotInGridI, &spotInGridJ);
			if (direction = 1) {
				enterWordRight(words, grid, &doesItFit, spotInGridI, spotInGridJ, count);
			} //End if.
			if (direction = 2) {
				enterWordLeft(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
			if (direction = 3) {
				enterWordDown(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
			if (direction = 4) {
				enterWordUp(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
			if (direction = 5) {
				enterWordUpRight(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
			if (direction = 6) {
				enterWordUpLeft(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
			if (direction = 7) {
				enterWordDownLeft(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
			if (direction = 8) {
				enterWordDownRight(words, grid, &doesItFit, spotInGridI, spotInGridJ);
			} //End if.
		} while (doesItFit = 'N'); //End inner do while.
		count++;
	} while (count < numberOfWords); //End outer do while.
	return;
} //End enterWordsIntroGrid function.

void chooseDirection(int *direction) {
	srand((unsigned) time(NULL));
	*direction = DIRECTIONLB + rand() % (DIRECTIONUB - DIRECTIONLB + 1);
	return;
} //End chooseDirection function.

void chooseSpotinGrid(int *spotInGridI, int *spotInGridJ) {
	srand((unsigned) time(NULL));
	*spotInGridI = SPOTINGRIDILB + rand() % (SPOTINGRIDIUB - SPOTINGRIDILB + 1);
	*spotInGridJ = SPOTINGRIDJLB + rand() % (SPOTINGRIDJUB - SPOTINGRIDJLB + 1);
	return;
} //End chooseSpotInGrid function.

void enterWordRight(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ, int count) {
	int wordsI = 0, wordsJ = 0;
	wordsI = count;
	for(wordsJ = 0; words[wordsI][wordsJ] == '\0'; wordsJ++) { //Does this work?
		grid[spotInGridI][spotInGridJ] = words[wordsI][wordsJ];
	} //End for.
} //End enterWordRight function.

void enterWordLeft(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordLeft function.

void enterWordDown(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordDown function.

void enterWordUp(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordUp function.

void enterWordUpRight(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordUpRight function.

void enterWordUpLeft(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordUpLeft function.

void enterWordDownLeft(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordDownLeft function.

void enterWordDownRight(char words[][20], char grid[][60], char *doesItFit, int spotInGridI, int spotInGridJ) {

} //End enterWordDownRight function.