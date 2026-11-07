#define _CRT_SECURE_NO_WARNINGS

//Includes:
#include <stdio.h>
#include <stdlib.h>

//Definitions:
#define flush fflush(stdin)
#define pause system("pause")

//Datatypes:
typedef struct {
	int month;
	int day;
	int year;
} DATE;

typedef struct {
	char fName[100], lName[100], gender;
	DATE dateOfBirth;
	float income;
} PERSON;

//Prototypes:
void printDate(DATE);
void getBirthday(DATE*);
void printEmployeeInfo(PERSON);

int main() {
	/* 
	DATE birthday;
	birthday.month = 12; 
	birthday.day = 25;
	birthday.year = 2014; //Initializes birthday struct.
	getBirthday(&birthday); //Make sure you pass by reference.
	printDate(birthday);
	*/
	PERSON employee;
	printf("Enter first name: ");
	scanf("%s", &employee.fName);
	flush;
	printf("Enter last name: ");
	scanf("%s", &employee.lName);
	flush;
	printf("Enter birth month: ");
	scanf("%i", &employee.dateOfBirth.month);
	flush;
	printf("Enter day of birth: ");
	scanf("%i", &employee.dateOfBirth.day);
	flush;
	printf("Enter birth year: ");
	scanf("%i", &employee.dateOfBirth.year);
	flush;
	printf("Enter gender of employee M or F: ");
	scanf("%c", &employee.gender);
	flush;
	printf("Enter employee income: ");
	scanf("%f", &employee.income);
	printEmployeeInfo(employee);
	flush; 
	return 0;
} 

//Functions:
void printDate(DATE birthday) {
	printf("%2i/%2i/%4i \n", birthday.month, birthday.day, birthday.year);
	pause;
	return;
} //End printDate function.

void getBirthday(DATE *birthday) {
	printf("Enter month of birth:");
	scanf("%i", &birthday->month);
	flush;
	printf("Enter day of month:");
	scanf("%i", &birthday->day);
	flush;
	printf("Enter birth year:");
	scanf("%i", &birthday->year);
	flush;
	return;
} //End getBirthday function.

void printEmployeeInfo(PERSON employee) {
	printf("Employee Name: %s \n", employee.fName);
	printf("Employee Name: %s \n", employee.lName);
	printf("Employee date of birth: %2i/%2i/%4i \n", employee.dateOfBirth.month, employee.dateOfBirth.day, employee.dateOfBirth.year);
	printf("Employee Name: %c \n", employee.gender);
	printf("Employee Name: %.2f \n", employee.income);
	pause;
	return;
} //endPrintEmployeeInfo function.