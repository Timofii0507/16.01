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
        cout << "1. Додати до початку\n";
        cout << "2. Додати до кінця\n";
        cout << "3. Видалити з початку\n";
        cout << "4. Видалити з кінця\n";
        cout << "5. Видалити всі\n";
        cout << "6. Показати\n";
        cout << "0. Вихід\n";
        cout << "Введіть ваш вибір: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Введіть значення для додавання до початку: ";
            cin >> value;
            myList.AddToHead(value);
            break;
        case 2:
            cout << "Введіть значення для додавання до кінця: ";
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
            cout << "Список: ";
            myList.Show();
            break;
        case 0:
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
    return 0;
}
