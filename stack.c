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
        printf("Home: %lf\n", current->value);
        stack_size++;
    }
    //else push it to the top of the stack
    else {
        Node* temp = NULL;
        temp = current->nextNodePointer;
        current->nextNodePointer = newNode;
        newNode->nextNodePointer = temp;
        current = newNode;
        printf("Next: %lf\n", current -> value);
        stack_size++;
    } 
}

double pop() {

    return 0.0;
}