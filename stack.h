/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */

#ifndef STACK_H_
#define STACK_H_

// TODO: declaration of stack struct and its functions go here
struct Stack
{
    double value;
    struct Stack* nextNodePointer;
};

//function declarations
int size();
void push(double dataVal);
double pop();

#endif /* STACK_H_ */
