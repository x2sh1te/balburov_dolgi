#include<locale.h>
#include <iostream>
#include <unordered_set>
using namespace std;

bool checkLatinSquare(int** matrix, int size) {
    // Проверка строк
    for (int row = 0; row < size; row++) {
        unordered_set<int> rowValues;
        for (int col = 0; col < size; col++) {
            if (matrix[row][col] < 1 || matrix[row][col] > size || rowValues.count(matrix[row][col])) {
                return false;
            }
            rowValues.insert(matrix[row][col]);
        }
    }

    // Проверка столбцов
    for (int col = 0; col < size; ++col) {
        std::unordered_set<int> colValues;
        for (int row = 0; row < size; ++row) {
            if (matrix[row][col] < 1 || matrix[row][col] > size || colValues.count(matrix[row][col])) {
                return false;
            }
            colValues.insert(matrix[row][col]);
        }
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int dimension;
    cout << "Введите размерность матрицы:";
    cin >> dimension;

    int** matrix = new int* [dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new int[dimension];
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cin >> matrix[i][j];
        }
    }

    if (checkLatinSquare(matrix, dimension)) {
        cout << "Матрица является латинским квадратом";
    }
    else {
        cout << "Матрица не является латинским квадратом";
    }

    // Освобождение памяти
    for (int i = 0; i < dimension; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}