/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */

#ifndef STACK_H_
#define STACK_H_

// TODO: declaration of stack struct and its functions go here
typedef struct Node_struct
{
    double value;
    struct Node_struct* nextNodePointer;
}Node;

//function declarations
int size();
void push(double dataVal);
double pop();

#endif /* STACK_H_ */
