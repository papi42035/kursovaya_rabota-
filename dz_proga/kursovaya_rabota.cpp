#include <iostream>
#include <cstdlib> 

using namespace std;




void lab1() {
    cout << "Лабораторная работа 1" << endl;
    
    system("g++ 1.cpp -o 1.out && 1.out");
}

void lab2() {
    cout << "Лабораторная работа 2" << endl;
    
    system("g++ 2.cpp -o 2.out && 2.out");
}

void lab3() {
    cout << "Лабораторная работа 3" << endl;
    
    system("g++ 3.cpp -o 3.out && 3.out");
}

void lab4() {
    cout << "Лабораторная работа 4" << endl;
    
    system("g++ 4.cpp -o 4.out && 4.out");
}

int main() {
    while (true) {
        cout << "\nВыберите лабораторную работу (1-4) или 0 для выхода: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                lab1();
                break;
            case 2:
                lab2();
                break;
            case 3:
                lab3();
                break;
            case 4:
                lab4();
                break;
            case 0:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }
}
