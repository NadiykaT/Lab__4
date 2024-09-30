#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Структура Student, що представляє студента
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

    // Введення даних про студентів
    for (int i = 0; i < numStudents; i++) {
        cout << "Введіть дані для студента " << i + 1 << ":" << endl;
        cout << "ПІБ: ";
        cin.ignore(); 
        getline(cin, students[i].name);
        cout << "Номер групи: ";
        cin >> students[i].number;
        cout << "Рік народження: ";
        cin >> students[i].birthYear;
    }

    // Впорядкування записів у масиві за зростанням номера групи методом обміну
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].number > students[j].number) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Введення року народження для пошуку студентів
    int year;
    cout << "***********************************************";
    cout << "\nВведіть рік народження для пошуку студентів: ";
    cin >> year;

    // Виведення ПІБ і номерів груп студентів одного року народження
    cout << "\n";
    cout << "Студенти, які народилися у " << year << " році:" << endl;
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].birthYear == year) {
            cout << "ПІБ: " << students[i].name << ", Номер групи: " << students[i].number << endl;
            found = true;
        }
    }

    // Якщо не знайдено студентів одного року народження
    if (!found) {
        cout << "Немає студентів, які народилися у " << year << " році." << endl;
    }

    return 0;
}