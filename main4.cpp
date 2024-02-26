#include "Stack2.h" 
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int capacity;
    cout << "������ ���������� ����� �����: ";
    cin >> capacity;

    Stack myStack(capacity);

    int choice;
    int data;

    while (true) {
        cout << "1. ������ �������\n2. �������� �������\n3. ����������� �������\n4. ���� �������?\n5. ���� ������?\n6. ������� ����\n7. �����\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ �������� ��� ������� ��������: ";
            cin >> data;
            myStack.push(data);
            break;
        case 2:
            data = myStack.pop();
            if (data != -1) {
                cout << "��������: " << data << endl;
            }
            break;
        case 3:
            data = myStack.peek();
            if (data != -1) {
                cout << "������ �������: " << data << endl;
            }
            break;
        case 4:
            cout << "���� " << (myStack.isEmpty() ? "�������" : "�� �������") << endl;
            break;
        case 5:
            cout << "���� " << (myStack.isFull() ? "������" : "�� ������") << endl;
            break;
        case 6:
            myStack.printStack();
            break;
        case 7:
            exit(0);
        default:
            cout << "������ �������!" << endl;
        }
    }

    return 0;
}
