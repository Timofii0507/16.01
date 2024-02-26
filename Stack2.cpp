#include "Stack2.h" 
#include <iostream>

using namespace std;

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

List* Stack::clone() {
    List* newList = new List(); 
    Node* temp = head; 
    while (temp != nullptr) { 
        newList->addLast(temp->data); 
        temp = temp->next; 
    }
    return newList; 
}

List* Stack::operator+(List* other) {
    List* newList = this->clone(); 
    Node* temp = other->head; 
    while (temp != nullptr) { 
        newList->addLast(temp->data); 
        temp = temp->next; 
    }
    return newList; 
}

List* Stack::operator*(List* other) {
    List* newList = new List();
    Node* temp1 = this->head;
    while (temp1 != nullptr) {
        Node* temp2 = other->head;
        while (temp2 != nullptr) {
            if (temp1->data == temp2->data) {
                newList->addLast(temp1->data);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return newList;
}