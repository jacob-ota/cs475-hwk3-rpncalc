// TODO implementation of stack goes here
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int size() {
    return 0;
}

void push(double data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->nextNodePointer = NULL;
    
}

double pop() {
    return 0.0;
}