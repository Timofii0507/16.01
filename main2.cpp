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
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
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

    void InsertAtPosition(const T& data, int position) {
        if (position <= 0) {
            cout << "Позиція повинна бути більше нуля." << endl;
            return;
        }
        if (position == 1) {
            AddToHead(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        int currentPosition = 1;
        while (current && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        if (!current) {
            cout << "Недопустима позиція." << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) {
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

    void DeleteFromPosition(int position) {
        if (position <= 0 || !head) {
            cout << "Список порожній або недопустима позиція." << endl;
            return;
        }
        if (position == 1) {
            DeleteFromHead();
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        int currentPosition = 1;
        while (current && currentPosition < position) {
            previous = current;
            current = current->next;
            currentPosition++;
        }
        if (!current) {
            cout << "Недопустима позиція." << endl;
            return;
        }
        previous->next = current->next;
        delete current;
        if (previous->next == nullptr) {
            tail = previous;
        }
    }

    int Search(const T& data) const {
        Node* current = head;
        int position = 1;
        while (current) {
            if (current->data == data) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    int Replace(const T& oldData, const T& newData) {
        Node* current = head;
        int count = 0;
        while (current) {
            if (current->data == oldData) {
                current->data = newData;
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void Reverse() {
        if (!head || head == tail) {
            return;
        }
        Node* previous = nullptr;
        Node* current = head;
        Node* nextNode;
        tail = head;
        while (current) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        head = previous;
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

    int searchValue;
    cout << "Введіть значення для пошуку: ";
    cin >> searchValue;
    int searchResult = myList.Search(searchValue);
    if (searchResult != -1) {
        cout << "Елемент знайдено на позиції: " << searchResult << endl;
    }
    else {
        cout << "Елемент не знайдено." << endl;
    }

    int oldData, newData;
    cout << "Введіть значення для заміни: ";
    cin >> oldData;
    cout << "Введіть нове значення: ";
    cin >> newData;
    int replaceResult = myList.Replace(oldData, newData);
    cout << "Кількість замінених елементів: " << replaceResult << endl;

    myList.Reverse();
    cout << "Після реверсу: ";
    myList.Show();

    return 0;
}
