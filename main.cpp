#include "lab.h"
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    LinkedList<int> myList;

    int choice, value;

    do 
    {
        cout << "1. ������ �� �������\n";
        cout << "2. ������ �� ����\n";
        cout << "3. �������� � �������\n";
        cout << "4. �������� � ����\n";
        cout << "5. �������� ��\n";
        cout << "6. ��������\n";
        cout << "0. �����\n";
        cout << "������ ��� ����: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "������ �������� ��� ��������� �� �������: ";
            cin >> value;
            myList.AddToHead(value);
            break;
        case 2:
            cout << "������ �������� ��� ��������� �� ����: ";
            cin >> value;
            myList.AddToTail(value);
            break;
        case 3:
            myList.DeleteFromHead();
            break;
        case 4:
            myList.DeleteFromTail();
            break;
        case 5:
            myList.DeleteAll();
            break;
        case 6:
            cout << "������: ";
            myList.Show();
            break;
        case 0:
            cout << "����� � ��������.\n";
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 0);
    return 0;
}
