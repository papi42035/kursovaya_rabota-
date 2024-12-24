// ИДЗ
#include <iostream>
void Bits(int &num) {
    bool isNegative = num < 0;
    for (int z = 0; z < sizeof(num) * 8; z += 2) {
        if (isNegative) {
            num &= ~(1 << z);
        } else {
            num |= (1 << (z + 1));
        }
    }

    }

// Задание номер 1
int main() {
    setlocale(0, "");
    std::cout << "Задание 1\n";
    std::cout << "int: " << sizeof(int) << " байт" << std::endl;
    std::cout << "short int: " << sizeof(short int) << " байт" << std::endl;
    std::cout << "long int: " << sizeof(long int) << " байт" << std::endl;
    std::cout << "float: " << sizeof(float) << " байт " << std::endl;
    std::cout << "double: " << sizeof(double) << " байт " << std::endl;
    std::cout << "long double: " << sizeof(long double) << " байт" << std::endl;
    std::cout << "char: " << sizeof(char) << " байт" << std::endl;
    std::cout << "bool: " << sizeof(bool) << " байт" << std::endl;
    std::cout << "\n";
    // Задание номер два
    std::cout << "Задание 2\n";
    using namespace std;
    int i;
    cout << "Введите целое число: ";
    cin >> i;
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    cout << "Двоичная запись числа: ";
    for (int x = 0; x < sizeof(int) * 8; x++, mask >>= 1) {
        if (i & mask) {
            cout << '1';
        } else {
            cout << '0';
        }
        if (x % 8 == 0 && x != 0) {
            cout << " ";
        }
    }

    cout << "\n";
    cout << endl;
    // Задание номер 3
    std::cout << "Задание 3\n";
    cout << "Введите значение float: ";
    union {
        float a;
        int v;
    };
    cin >> a;
    mask = 1 << (sizeof(float) * 8 - 1);
    cout << "Двоичная запись числа float:\n ";
    for (int x = 0; x < sizeof(float) * 8; x++, mask >>= 1) {
        if (v & mask) {
            cout << '1';
        } else {
            cout << '0';
        }
        if (x % 8 == 0 && x != 0) {
            cout << " ";
        }
    }
    std::cout << "\n";
    std::cout << "Задание ИДЗ номер 13\n";
    cout << endl;
    int z;
    cout << "Введите число для изменения:";
    cin >> z;
    
    std::cout << "Исходное число: " << z << std::endl;
    Bits(z);
    
    std::cout << "Измененное число: " << z << std::endl << "\n";
    
    return 0;
}
