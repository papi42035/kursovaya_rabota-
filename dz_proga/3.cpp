#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 1 задание 
void fillMatrixSpiral(int* matrix, int N) {
    int value = 1;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (value <= N * N) {
        for (int i = left; i <= right; ++i)  
            *(matrix + top * N + i) = value++;
        top++;
        for (int i = top; i <= bottom; ++i)  
            *(matrix + i * N + right) = value++;
        right--;
        for (int i = right; i >= left; --i)  
            *(matrix + bottom * N + i) = value++;
        bottom--;
        for (int i = bottom; i >= top; --i)  
            *(matrix + i * N + left) = value++;
        left++;
    }
}


void printMatrix(int* matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << *(matrix + i * N + j) << "\t";
        }
        cout << endl;
    }
}

// 2 задание 
void rearrangeBlocks(int* matrix, int N, int blockSize) {
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            int temp = *(matrix + i * N + j);  
            *(matrix + i * N + j) = *(matrix + i * N + (j + blockSize));  
            *(matrix + i * N + (j + blockSize)) = *(matrix + (i + blockSize) * N + (j + blockSize));  
            *(matrix + (i + blockSize) * N + (j + blockSize)) = *(matrix + (i + blockSize) * N + j);  
            *(matrix + (i + blockSize) * N + j) = temp;  
        }
    }
}

// 3 задание 
void shakerSort(int* matrix, int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        for (int i = left; i < right; ++i) {
            if (*(matrix + i) > *(matrix + i + 1)) {
                swap(*(matrix + i), *(matrix + i + 1));
            }
        }
        right--;
        for (int i = right; i > left; --i) {
            if (*(matrix + i) < *(matrix + i - 1)) {
                swap(*(matrix + i), *(matrix + i - 1));
            }
        }
        left++;
    }
}

// 4 задание 
void scaleMatrix(int* matrix, int N, int factor) {
    for (int i = 0; i < N * N; ++i) {
        *(matrix + i) *= factor;
    }
}

// идз
int calculateDeterminant3x3(int matrix[3][3]) {
    cout << "\nШаги вычисления определителя:\n";
    
    int term1 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    int term2 = -matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    int term3 = matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    cout << "1-й член: " << matrix[0][0] << " * (" << matrix[1][1] << " * " << matrix[2][2] << " - " << matrix[1][2] << " * " << matrix[2][1] << ") = " << term1 << endl;
    cout << "2-й член: -" << matrix[0][1] << " * (" << matrix[1][0] << " * " << matrix[2][2] << " - " << matrix[1][2] << " * " << matrix[2][0] << ") = " << term2 << endl;
    cout << "3-й член: " << matrix[0][2] << " * (" << matrix[1][0] << " * " << matrix[2][1] << " - " << matrix[1][1] << " * " << matrix[2][0] << ") = " << term3 << endl;

    return term1 + term2 + term3;
}


void handle3x3Matrix() {
    int matrix[3][3];
    srand(time(0));
    
    cout << "\nСлучайно сгенерированная матрица 3x3:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = rand() % 61 - 30;  
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int determinant = calculateDeterminant3x3(matrix);
    cout << "\nОпределитель матрицы: " << determinant << endl;
}

int main() {
    srand(time(0));

    int N;
    cout << "Введите размер матрицы (6/8/10): ";
    cin >> N;

    int* matrix = new int[N * N];  
    fillMatrixSpiral(matrix, N);  
    cout << "Матрица, заполненная по спирали:\n";
    printMatrix(matrix, N);

    
    int blockSize = N / 2;  
    rearrangeBlocks(matrix, N, blockSize);
    cout << "\nМатрица после перестановки блоков (по схеме a):\n";
    printMatrix(matrix, N);

    
    shakerSort(matrix, N * N);
    cout << "\nМатрица после сортировки элементов:\n";
    printMatrix(matrix, N);

    
    int factor;
    cout << "\nВведите число для умножения всех элементов матрицы: ";
    cin >> factor;
    scaleMatrix(matrix, N, factor);
    cout << "\nМатрица после умножения на " << factor << ":\n";
    printMatrix(matrix, N);

    
    handle3x3Matrix();

    delete[] matrix;  
    return 0;
}
