#include "Stack2.h" 
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int capacity;
    cout << "Введіть початковий розмір стеку: ";
    cin >> capacity;

    Stack myStack(capacity);

    int choice;
    int data;

    while (true) {
        cout << "1. Додати елемент\n2. Видалити елемент\n3. Переглянути вершину\n4. Стек порожній?\n5. Стек повний?\n6. Вивести стек\n7. Вихід\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть значення для додання елемента: ";
            cin >> data;
            myStack.push(data);
            break;
        case 2:
            data = myStack.pop();
            if (data != -1) {
                cout << "Видалено: " << data << endl;
            }
            break;
        case 3:
            data = myStack.peek();
            if (data != -1) {
                cout << "Верхній елемент: " << data << endl;
            }
            break;
        case 4:
            cout << "Стек " << (myStack.isEmpty() ? "порожній" : "не порожній") << endl;
            break;
        case 5:
            cout << "Стек " << (myStack.isFull() ? "повний" : "не повний") << endl;
            break;
        case 6:
            myStack.printStack();
            break;
        case 7:
            exit(0);
        default:
            cout << "Невірна команда!" << endl;
        }
    }

    return 0;
}
