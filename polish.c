// TODO implementation of evaluate() goes here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

/**
 * Evaluate takes in a char of an equation and evaluates
 * all the elements of the equation based on the RPN algorithm.
 * 
 * @param char* the equation that is entered by user
 * @returns double the solution of the equation
 */
double evaluate(char* equation) {
    stack_size = 0;
    double checkDub;
    int checkPunct;
    equation = strtok(equation, "  \n \t");
    while(equation != NULL) {
        checkDub = atof(equation);
        checkPunct = ispunct(*equation);
        double firstOp;
        double secondOp;
        double solution;

        //check what operator it is and do calculations
        if(checkPunct && *equation == '+') {
            if(size() >= 2) {
                secondOp = pop();
                firstOp = pop();
                solution = firstOp + secondOp;
                push(solution);
            }
            else {
                printf("Error: Insufficient number of operands!\n");
                return 0.0;
            }
        }
        else if(checkPunct && *equation == '-') {
            if(size() >= 2) {
                secondOp = pop();
                firstOp = pop();
                solution = firstOp - secondOp;
                push(solution);
            }
            else {
                printf("Error: Insufficient number of operands!\n");
                return 0.0;
            }
        }
        else if(checkPunct && *equation == '*') {
            if(size() >= 2) {
                secondOp = pop();
                firstOp = pop();
                solution = firstOp * secondOp;
                push(solution);
            }
            else {
                printf("Error: Insufficient number of operands!\n");
                return 0.0;
            }
        }
        else if(checkPunct && *equation == '/') {
            if(size() >= 2) {
                secondOp = pop();
                firstOp = pop();
                if(secondOp == 0) {
                    printf("Error: Divide-by-zero\n");
                    return 0.0;
                }
                else {
                    solution = firstOp / secondOp;
                }
                push(solution);
            }
            else {
                printf("Error: Insufficient number of operands!\n");
                return 0.0;
            }
        }
        //if it isn't a operator then show error and break
        else if (checkPunct) {
            char symbol = *equation;
            printf("Error: operator %c unrecognized.\n", symbol);
            return 0.0;
        }

        //if 0 is entered then return 0
        if(*equation == '0') {
            push(0.0);
        }
        //else if not a punct or a number then print error and break
        else if(checkDub == 0.0 && checkPunct == 0) {
            printf("Not a valid input! Only numbers and operators!\n");
            return 0.0;
        }
        else if (checkDub != 0.0){
            push(checkDub);
        }
        equation = strtok (NULL, "  \n \t");
    }
    if(size() > 1) {
        printf("Error: Too many operands entered \n");
        return 0.0;
    }
    else {
        return pop();
    }
}