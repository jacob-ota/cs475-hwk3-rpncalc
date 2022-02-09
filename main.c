/*
 ============================================================================
 Name        : PolishSol.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	char eqn[MAX_EQ_LEN];	 // string to store the input RPN expression
	char resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"
	bool cont = true;
	bool check = true;
	/* TODO */
	//first time asking for user input
	printf("Enter and equation (in RPN): \n");
	fgets(eqn, MAX_EQ_LEN, stdin);
	//call the evaluate function to do all the work
	evaluate(eqn);
	
	printf("\n");
	//while loop for next input(s)
	while (cont) {
		check = true;
		while (check) {
			//ask for another evaluation
			printf("Evaluate another? (y/n): ");
			fgets(resp, MAX_EQ_LEN, stdin);
			//what to do with user input
			if (*resp == 'y') {
				check = false;
			}
			else if (*resp == 'n') {
				break;
			}
			else {
				printf("Invalid input! Try again!\n");
			}

		}
		//break out of everything if the user puts in n
		if(*resp == 'n') {
			break;
		}
		//ask for another equation
		printf("Enter and equation (in RPN): \n");
		fgets(eqn, MAX_EQ_LEN, stdin);
		//call the evaluate function to do all the work
		evaluate(eqn);

		printf("\n");
	}
	printf("Exiting...\n");
	return 0;
}
