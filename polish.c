// TODO implementation of evaluate() goes here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

double evaluate(char* equation) {
    double checkDub;
    int checkPunct;
    equation = strtok(equation, "  \n \t");
    while(equation != NULL) {
        checkDub = atof(equation);
        checkPunct = ispunct(*equation);

        //check what operator it is and do calculations
        if(checkPunct && *equation == '+') {
            printf("This is a plus");
        }
        else if(checkPunct && *equation == '-') {
            printf("This is a minus");
        }
        else if(checkPunct && *equation == '*') {
            printf("This is a multi");
        }
        else if(checkPunct && *equation == '/') {
            printf("This is a div");
        }
        //if it isn't a operator then show error and break
        else if (checkPunct) {
            char symbol = *equation;
            printf("Error: operator %c unrecognized.\n", symbol);
            break;
        }

        //if 0 is entered then return 0
        if(*equation == '0') {
            checkDub = 0.0;
        }
        //else if not a punct or a number then print error and break
        else if(checkDub == 0.0 && checkPunct == 0) {
            printf("Not a valid input! Only numbers and operators!\n");
            break;
        }
        else {
            printf("push this onto stack");
        }
        equation = strtok (NULL, "  \n \t");
    }
    return 0.0;
}