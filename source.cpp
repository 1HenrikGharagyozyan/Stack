#include <iostream>
#include <stack>
#include <windows.h>

#include "Stack.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Stack<int> s;

    std::cout << "����� ��������...\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "������ �����: " << s.size() << "\n"; // �������: 3
    std::cout << "������� �������: " << s.top() << "\n"; // �������: 30

    std::cout << "����������� ������� �������...\n";
    s.pop();

    std::cout << "����� ������� �������: " << s.top() << "\n"; // �������: 20
    std::cout << "������ �����: " << s.size() << "\n"; // �������: 2

    std::cout << "Emplace ����� ������� (42)...\n";
    s.emplace(42);
    std::cout << "������� ������� ������: " << s.top() << "\n"; // �������: 42

    std::cout << "�������� swap:\n";
    Stack<int> s2;
    s2.push(100);
    s2.push(200);

    std::cout << "s.top() �� swap: " << s.top() << "\n";
    std::cout << "s2.top() �� swap: " << s2.top() << "\n";

    swap(s, s2);

    std::cout << "s.top() ����� swap: " << s.top() << "\n"; // �������: 200
    std::cout << "s2.top() ����� swap: " << s2.top() << "\n"; // �������: 42

    std::cout << "�������� ���������� ��� pop �� ������:\n";
    try 
    {
        Stack<int> empty;
        empty.pop(); // ������ ������� ����������
    }
    catch (const std::exception& e) 
    {
        std::cout << "����������: " << e.what() << "\n";
    }

    return 0;
}