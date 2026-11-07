//Drinking Game Project
//Written By: Team C - [classmate], Steven Ammer, [classmate]
//Written On: 4/4/14

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
#define SIZE 1000
#define LB 1
#define UB 10

typedef struct {
	int month, day, year;
} DATE;

typedef struct {
	char name[100], gender;
	DATE dateOfBirth;
	int shots;
	double bloodAlcoholLevel, weight;
} PLAYERS;

//Prototypes
void displayMenu();
int getChoice();
PLAYERS *newPlayer();
void addPlayer(PLAYERS*);
void deleteAPassedOutPlayer(PLAYERS**, int*);
void displayPlayers(PLAYERS**, int);
void searchForPlayer(PLAYERS**, int, char*, int*, char[]);
void sortPlayersByBAL(PLAYERS**, int);
void doTheSwitch(PLAYERS**, char*, int);
void displayRules();
void playTheGame(PLAYERS**, int, time_t);
int pickGame();
void displayChallenge(int game);
void whoWon(PLAYERS **playerPointers, int numberOfPlayers);
void recalculateBloodAlcoholLevel(PLAYERS**, int, time_t);
//void clearMemory(PLAYERS**, int);

int main() {
	PLAYERS *playerPointers[SIZE]; //Array of pointers to PLAYER structs.
	int numberOfPlayers = 0, choice = 0, i = 0;
	time_t start = 0;
	start = time(NULL);
	do {
		choice = getChoice();
		switch (choice) {
			case 1:
				playerPointers[numberOfPlayers] = newPlayer();
				addPlayer(playerPointers[numberOfPlayers]);
				numberOfPlayers++;
				break;
			case 2:
				deleteAPassedOutPlayer(playerPointers, &numberOfPlayers);
				break;
			case 3:
				sortPlayersByBAL(playerPointers, numberOfPlayers);
				displayPlayers(playerPointers, numberOfPlayers);
				break;
			case 4:
				displayRules();
				playTheGame(playerPointers, numberOfPlayers, start);
				break;
		} //End switch.
	} while (choice != 5); //End do while.
	//clearMemory(playerPointers, numberOfPlayers);
	free(*playerPointers);
	return 0;
} //End main.

//Functions:
int getChoice() {
	int result;
	do {
		displayMenu();
		scanf_s("%i", &result);
		flush;
		if (result < 1 || result > 5) {
			printf("Error you must enter 1-5 only! \n");
			pause;
		} //End if.
	} while (result < 1 || result > 5);
	return result;
} //End getANumber function.

void displayMenu() {
	cls;
	printf("Main Menu \n");
	printf("1. Add a players. \n");
	printf("2. Delete a passed (pussed) out player. \n");
	printf("3. Display all players: drunkest last. \n");
	printf("4. Start next round. \n");
	printf("5. Quit. \n\n");
	printf("Enter selection:");
	return;
} //End displayMenu function.

PLAYERS* newPlayer() {
	PLAYERS* playerPointers;
	playerPointers = malloc(sizeof(PLAYERS));
	return playerPointers;
} //End newPlayer function.

void addPlayer(PLAYERS *playerPointers) {
	printf("Enter first name: ");
	scanf("%[^\n]s", playerPointers->name); 
	flush;
	printf("Enter last name: ");
	do {
		printf("Enter the month you were born (For example, if you were born in April, enter 4.): ");
		scanf("%i", &playerPointers->dateOfBirth.month);
		flush;
		if (playerPointers->dateOfBirth.month < 1 || playerPointers->dateOfBirth.month > 12) {
			printf("You must enter a number 1-12. \n");
			pause;
		} //End if.
	} while (playerPointers->dateOfBirth.month < 1 || playerPointers->dateOfBirth.month > 12); //End do while.
	do {
		printf("Enter the day you were born (For example, if you were born on the 20th, enter 20.): ");
		scanf("%i", &playerPointers->dateOfBirth.day);
		flush;
		if (playerPointers->dateOfBirth.day < 1 || playerPointers->dateOfBirth.day > 31) {
			printf("You must enter a number 1-31. \n");
			pause;
		} //End if.
	} while (playerPointers->dateOfBirth.day < 1 || playerPointers->dateOfBirth.day > 31); //End do while.
	do {
		printf("Enter the year you were born (For example, if you were born in 1993, enter 1993.): ");
		scanf("%i", &playerPointers->dateOfBirth.year);
		flush;
		if (playerPointers->dateOfBirth.year < 1900 || playerPointers->dateOfBirth.year > 2015) {
			printf("You're a liar. Try again. \n");
			pause;
		} //End if.
	} while (playerPointers->dateOfBirth.year < 1900 || playerPointers->dateOfBirth.year > 2015); //End do while.
	do {
		printf("Enter weight: ");
		scanf("%lf", &playerPointers->weight);
		flush;
		if (playerPointers->weight < 1 || playerPointers->weight > 500) {
			printf("You must enter a number 1-500. (For example, if you weight 195 lbs, enter 195.) \n");
			pause;
		} //End if.
	} while (playerPointers->weight < 1 || playerPointers->weight > 500); //End do while.
	do {
		printf("Enter sex M or F:");
		scanf("%c", &playerPointers->gender);
		flush;
		if (playerPointers->gender != 'F' && playerPointers->gender != 'M') {
			printf("You must enter a M or a F. Make sure you are using capital letters. \n");
			pause;
		} //End if.
	} while (playerPointers->gender != 'F' && playerPointers->gender != 'M'); //End do while.
	playerPointers->shots = 0;
	playerPointers->bloodAlcoholLevel = 0;
	return;
} //End addPlayer function.

void displayPlayers(PLAYERS **playerPointers, int numberOfPlayers) {
	int i;
	printf("Name:\tDate of Birth:\tGender:\tWeight:\tShots:\tBlood Alcohol Level:\n");
	for (i = 0; i < numberOfPlayers; i++) {
		printf("%s\t%i/%i/%i\t%c\t%.2lf lbs\t%i\t%.2lf \n", playerPointers[i]->name,
			playerPointers[i]->dateOfBirth.month, playerPointers[i]->dateOfBirth.day, playerPointers[i]->dateOfBirth.year, 
			playerPointers[i]->gender, playerPointers[i]->weight, playerPointers[i]->shots, playerPointers[i]->bloodAlcoholLevel);
	} //End for.
	pause;
	return;
} //End displayPlayers function.

void deleteAPassedOutPlayer(PLAYERS **playerPointers, int *numberOfPlayers) {
	char player[100], doesItExist = 'N';
	int location = 0, i = 0;
	do {
		printf("Who Passed out:");
		scanf("%[^\n]s", &player);
		flush;
		searchForPlayer(playerPointers, *numberOfPlayers, &doesItExist, &location, player);
		if (doesItExist == 'N') {
			printf("You must enter a player's name. If you want to quit, type: Cancel \n");
			pause;
		} //End if.
	} while (doesItExist == 'N' && strcmp(player, "Cancel") != 0); //End do while.
	if (doesItExist == 'Y') {
		for (i = location; i < *numberOfPlayers; i++) {
			playerPointers[i] = playerPointers[i + 1];
		} //End for.
		//free memory of playerpointers[numberOfPlayers]
		*numberOfPlayers = *numberOfPlayers - 1;
	} //End if.
	return;
} //End deleteAPassedOutPlayer function.

void searchForPlayer(PLAYERS **playerPointers, int numberOfPlayers, char *doesItExist, int *location, char player[]) {
	int i = 0;
	for (i = 0; i < numberOfPlayers; i++) {
		if (strcmp(playerPointers[i]->name, player) == 0) {
			*doesItExist = 'Y';
			*location = i;
		} //End if.
	} //End for.
	return;
} //End searchForPlayer function.

void sortPlayersByBAL(PLAYERS **playerPointers, int numberOfPlayers) {
	int i = 0, bottom = numberOfPlayers - 1;
	char switchMade = 'N';
	do {
		switchMade = 'N';
		for(i = 0; i < bottom; i++) {
			if(playerPointers[i]->bloodAlcoholLevel > playerPointers[i + 1]->bloodAlcoholLevel) {
				doTheSwitch(playerPointers, &switchMade, i);
			} //End if.
		} //End for.
		bottom--;
	} while(switchMade == 'Y');
	return;
} //End sortPlayersByBAL function.

void doTheSwitch(PLAYERS **playerPointers, char *switchMade, int i) {
	PLAYERS *temp;
	temp = playerPointers[i];
	playerPointers[i] = playerPointers[i + 1];
	playerPointers[i + 1] = temp;
	*switchMade = 'Y';
	return;
} //End doTheSwitch function.

void displayRules() {
	printf("[student-era drinking joke redacted] \n\n");
	printf("RULES ARE:\n");
	printf("1. You lose a challenge, you take a shot or chug a beer\n");
	printf("2. Get drunk\n\n");
	pause;
	return;
} //End displayRules function.

void playTheGame(PLAYERS **playerPointers, int numberOfPlayers, time_t start) {
	int game = 0;
	game = pickGame();
	displayChallenge(game);
	pause;
	whoWon(playerPointers, numberOfPlayers);
	recalculateBloodAlcoholLevel(playerPointers, numberOfPlayers, start);
	return;
} //End playTheGame function.

int pickGame() {
	int result;
	srand((unsigned) time(NULL));
	result = LB + rand() % (UB - LB + 1);
	return result;
} //End pickGame function.

void displayChallenge(int game) {
	switch (game){
			case 1:
				cls;
				printf("Flip cup, use 3 cups\n");
				break;
			case 2:
				cls;
				printf("3 cup beer pong\n");
				break;
			case 3:
				cls;
				printf("Quarters, first one to make 5 wins\n");
				break;
			case 4:
				cls;
				printf("Stand on your head, last one standing wins\n");
				break;
			case 5:
				cls;
				printf("Stack 10 cups into a triangle\n");
				break;
			case 6:
				cls;
				printf("Stack 6 dice on the end of a popsicle while other end is being held in mouth\n");
				break;
			case 7:
				cls;
				printf("Roll ping pong ball into glass laying down at the end of a table. Whoever finishes first wins\n");
				break;
			case 8:
				cls;
				printf("Balance 7 books on top of head. Whoever drops them first loses\n");
				break;
			case 9:
				cls;
				printf("Jenga- whoever makes it fall loses\n");
				break;
			case 10:
				cls;
				printf("Stack 3 golf balls on top of each other. It must stay for 3 seconds. Whoever finishes first wins\n");
				break;
	} //end switch.
	return;
} //End displayChallenge function

void whoWon(PLAYERS **playerPointers, int numberOfPlayers) {
	char player[100], doesItExist = 'N';
	int location = 0, i = 0;
	do {
		printf("Who won:");
		scanf("%[^\n]s", &player);
		flush;
		searchForPlayer(playerPointers, numberOfPlayers, &doesItExist, &location, player);
		if (doesItExist == 'N') {
			printf("You must enter a player's name. If you want to quit, type: Cancel \n");
			pause;
		} //End if.
	} while (doesItExist == 'N' && strcmp(player, "Cancel") != 0); //End do while.
	if (doesItExist == 'Y') {
		for (i = 0; i < numberOfPlayers; i++) {
			if (location != i) {
			playerPointers[i]->shots = playerPointers[i]->shots + 1;
			} //End if.
		} //End for.
	} //End if.
	return;
} //End whoLost function.

void recalculateBloodAlcoholLevel(PLAYERS **playerPointers, int numberOfPlayers, time_t start) {
	double newBloodAlcoholLevel = 0, alcoholDistributionRatio = 0;
	time_t end = 0;
	int elapsed = 0, i = 0;
	end = time(NULL);
	elapsed = end - start;
	for (i = 0; i < numberOfPlayers; i++) {
		if (playerPointers[i]->gender == 'M') {
			alcoholDistributionRatio = 0.73;
		}
		if (playerPointers[i]->gender == 'F') {
			alcoholDistributionRatio = 0.66;
		}
		newBloodAlcoholLevel = (((5.14 * 0.60 * playerPointers[i]->shots) / (playerPointers[i]->weight * alcoholDistributionRatio)) - (0.015 * (elapsed/36000))) * 10;
		playerPointers[i]->bloodAlcoholLevel = newBloodAlcoholLevel;
	} //End for.
	return;
} //End recalculateBloodAlcoholLevel function.

/* void clearMemory(PLAYERS **playerPointers, int numberOfPlayers) {
	int i = 0;
	 for(i=0; i < numberOfPlayers; i++) {
        free(playerPointers[i]);
	 } //End for.
    free(playerPointers);
} //End clearMemory function.
*/