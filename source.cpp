#include <iostream>
#include <stack>
#include <windows.h>

#include "Stack.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Stack<int> s;

    std::cout << "Пушим элементы...\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Размер стека: " << s.size() << "\n"; // Ожидаем: 3
    std::cout << "Верхний элемент: " << s.top() << "\n"; // Ожидаем: 30

    std::cout << "Выталкиваем верхний элемент...\n";
    s.pop();

    std::cout << "Новый верхний элемент: " << s.top() << "\n"; // Ожидаем: 20
    std::cout << "Размер стека: " << s.size() << "\n"; // Ожидаем: 2

    std::cout << "Emplace новый элемент (42)...\n";
    s.emplace(42);
    std::cout << "Верхний элемент теперь: " << s.top() << "\n"; // Ожидаем: 42

    std::cout << "Проверка swap:\n";
    Stack<int> s2;
    s2.push(100);
    s2.push(200);

    std::cout << "s.top() до swap: " << s.top() << "\n";
    std::cout << "s2.top() до swap: " << s2.top() << "\n";

    swap(s, s2);

    std::cout << "s.top() после swap: " << s.top() << "\n"; // Ожидаем: 200
    std::cout << "s2.top() после swap: " << s2.top() << "\n"; // Ожидаем: 42

    std::cout << "Проверка исключения при pop на пустом:\n";
    try 
    {
        Stack<int> empty;
        empty.pop(); // Должно бросить исключение
    }
    catch (const std::exception& e) 
    {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    return 0;
}