#include "Stack.h" 
#include <iostream>

using namespace std;

Node::Node(int data) {
    this->data = data;
    next = nullptr;
}

Stack::Stack(int capacity) {
    this->head = nullptr;
    this->size = 0;
    this->capacity = capacity;
}

void Stack::push(int data) {
    if (isFull()) {
        cout << "Стек переповнений! Розмір буде збільшено." << endl;
        expand();
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    size++;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Стек порожній!" << endl;
        return -1;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;

    return temp->data;
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Стек порожній!" << endl;
        return -1;
    }

    return head->data;
}

bool Stack::isEmpty() {
    return size == 0;
}

bool Stack::isFull() {
    return size == capacity;
}

void Stack::expand() {
    capacity *= 2;
    cout << "Розмір стеку збільшено до " << capacity << endl;
}

void Stack::printStack() {
    if (isEmpty()) {
        cout << "Стек порожній!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
