#ifndef STACK_H 
#define STACK_H

#include "Node.h" 
class Stack {
private:
    Node* head;
    int size;
    int capacity;

public:
    Stack(int capacity);

    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void expand();
    void printStack();
};

#endif
