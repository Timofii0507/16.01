#include <iostream>
#include <Windows.h>

using namespace std;

template <class T>
class Queue {
private:
    T* arr;
    int size;
    int front, rear;
public:
    Queue(int s) {
        size = s;
        arr = new T[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool IsEmpty() {
        return (front == -1);
    }

    bool IsFull() {
        return (rear == size - 1);
    }

    void Enqueue(T x) {
        if (IsFull()) {
            cout << "Черга повна, неможливо додати елемент\n";
        }
        else {
            rear++;
            arr[rear] = x;
            if (front == -1) {
                front = 0;
            }
            cout << "Елемент " << x << " додано в чергу\n";
        }
    }

    T Dequeue() {
        if (IsEmpty()) {
            cout << "Черга порожня, неможливо видалити елемент\n";
            return 0;
        }
        else {
            T x = arr[front];
            front++;
            if (front > rear) {
                front = rear = -1;
            }
            cout << "Елемент " << x << " видалено з черги\n";
            return x;
        }
    }

    void Show() {
        if (IsEmpty()) {
            cout << "Черга порожня, немає елементів для відображення\n";
        }
        else {
            cout << "Елементи черги: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    int element;
    int size;
    cout << "Введіть розмір черги: ";
    cin >> size;
    Queue<int> q(size);
    do {
        cout << "\nВиберіть опцію:\n";
        cout << "1. Перевірити, чи черга порожня\n";
        cout << "2. Перевірити, чи черга повна\n";
        cout << "3. Додати елемент в чергу\n";
        cout << "4. Видалити елемент з черги\n";
        cout << "5. Відобразити всі елементи черги\n";
        cout << "6. Вийти\n";
        cin >> choice;
        switch (choice) {
        case 1:
            if (q.IsEmpty()) {
                cout << "Черга порожня\n";
            }
            else {
                cout << "Черга не порожня\n";
            }
            break;
        case 2:
            if (q.IsFull()) {
                cout << "Черга повна\n";
            }
            else {
                cout << "Черга не повна\n";
            }
            break;
        case 3:
            cout << "Введіть елемент, який хочете додати: ";
            cin >> element;
            q.Enqueue(element);
            break;
        case 4:
            element = q.Dequeue();
            break;
        case 5:
            q.Show();
            break;
        case 6:
            cout << "До зустірчі\n";
            break;
        default:
            cout << "Неправильний вибір, спробуйте ще раз\n";
            break;
        }
    } while (choice != 6);
    return 0;
}