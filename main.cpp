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
            cout << "����� �����, ��������� ������ �������\n";
        }
        else {
            rear++;
            arr[rear] = x;
            if (front == -1) {
                front = 0;
            }
            cout << "������� " << x << " ������ � �����\n";
        }
    }

    T Dequeue() {
        if (IsEmpty()) {
            cout << "����� �������, ��������� �������� �������\n";
            return 0;
        }
        else {
            T x = arr[front];
            front++;
            if (front > rear) {
                front = rear = -1;
            }
            cout << "������� " << x << " �������� � �����\n";
            return x;
        }
    }

    void Show() {
        if (IsEmpty()) {
            cout << "����� �������, ���� �������� ��� �����������\n";
        }
        else {
            cout << "�������� �����: ";
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
    cout << "������ ����� �����: ";
    cin >> size;
    Queue<int> q(size);
    do {
        cout << "\n������� �����:\n";
        cout << "1. ���������, �� ����� �������\n";
        cout << "2. ���������, �� ����� �����\n";
        cout << "3. ������ ������� � �����\n";
        cout << "4. �������� ������� � �����\n";
        cout << "5. ³��������� �� �������� �����\n";
        cout << "6. �����\n";
        cin >> choice;
        switch (choice) {
        case 1:
            if (q.IsEmpty()) {
                cout << "����� �������\n";
            }
            else {
                cout << "����� �� �������\n";
            }
            break;
        case 2:
            if (q.IsFull()) {
                cout << "����� �����\n";
            }
            else {
                cout << "����� �� �����\n";
            }
            break;
        case 3:
            cout << "������ �������, ���� ������ ������: ";
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
            cout << "�� �������\n";
            break;
        default:
            cout << "������������ ����, ��������� �� ���\n";
            break;
        }
    } while (choice != 6);
    return 0;
}