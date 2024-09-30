#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ��������� Student, �� ����������� ��������
struct Student {
    string name;
    int number;
    int birthYear;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int numStudents = 2; 
    Student* students = new Student[numStudents];

    // �������� ����� ��� ��������
    for (int i = 0; i < numStudents; i++) {
        cout << "������ ��� ��� �������� " << i + 1 << ":" << endl;
        cout << "ϲ�: ";
        cin.ignore(); 
        getline(cin, students[i].name);
        cout << "����� �����: ";
        cin >> students[i].number;
        cout << "г� ����������: ";
        cin >> students[i].birthYear;
    }

    // ������������� ������ � ����� �� ���������� ������ ����� ������� �����
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].number > students[j].number) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // �������� ���� ���������� ��� ������ ��������
    int year;
    cout << "***********************************************";
    cout << "\n������ �� ���������� ��� ������ ��������: ";
    cin >> year;

    // ��������� ϲ� � ������ ���� �������� ������ ���� ����������
    cout << "\n";
    cout << "��������, �� ���������� � " << year << " ����:" << endl;
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].birthYear == year) {
            cout << "ϲ�: " << students[i].name << ", ����� �����: " << students[i].number << endl;
            found = true;
        }
    }

    // ���� �� �������� �������� ������ ���� ����������
    if (!found) {
        cout << "���� ��������, �� ���������� � " << year << " ����." << endl;
    }

    return 0;
}