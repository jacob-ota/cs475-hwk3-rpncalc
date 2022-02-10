// TODO implementation of stack goes here
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stack_size = 0;
Node* head = NULL;
Node* current = NULL;

int size() {
    return stack_size;
}

void push(double data) {
    //allocate memory for a new Node struct and store data
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    //make the new Node the head if head is NULL
    if(head == NULL) {
        head = newNode;
        current = head;
        stack_size++;
    }
    //else push it to the top of the stack
    else {
        //new nodes pointer points at the element next on stack and becomes new current
        newNode->nextNodePointer = current;
        current = newNode;
        stack_size++;
    } 
}

double pop() {
    Node* poppedNode;
    double poppedVal;
    //get value to be returned
    poppedVal = current->value;
    poppedNode = current;
    //change current to the next node on stack
    if (stack_size > 1) {
        current = current->nextNodePointer;
    }
    //deallocate the old node
    free(poppedNode);
    stack_size--;
    return poppedVal;
}