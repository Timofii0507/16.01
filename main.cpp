#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SinglyLinkedList() {
        DeleteAll();
    }

    void AddToHead(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (!head) {
            cout << "Список порожній. Немає елементів для видалення з початку." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
    }

    void DeleteFromTail() {
        if (!head) {
            cout << "Список порожній. Немає елементів для видалення з кінця." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void DeleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() const {
        if (!head) {
            cout << "Список порожній." << endl;
            return;
        }
        Node* current = head;
        cout << "Список: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SinglyLinkedList<int> myList;

    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    cout << "Введіть елементи: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        myList.AddToTail(value);
    }

    myList.Show();

    myList.DeleteFromHead();
    cout << "Після видалення з початку: ";
    myList.Show();

    myList.DeleteFromTail();
    cout << "Після видалення з кінця: ";
    myList.Show();

    myList.DeleteAll();
    cout << "Після видалення всіх: ";
    myList.Show();

    return 0;
}