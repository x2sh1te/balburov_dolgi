#include <iostream> 
#include<windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows_count;
    int columns_count;

    cout << "Введите количество строк: ";
    cin >> rows_count;
    cout << "Введите количество столбцов: ";
    cin >> columns_count;

    int data_matrix[30][30];

    cout << "Введите значения элементов построчно: ";
    for (int row = 0; row < rows_count; row++) {
        for (int col = 0; col < columns_count; col++) {
            cin >> data_matrix[row][col];
        }
    }

    for (int row = 0; row < rows_count; row++) {
        if (row % 2 == 0) {
            for (int col = 0; col < columns_count; col++) {
                cout << data_matrix[row][col] << " ";
            }
        }
        else {
            for (int col = columns_count - 1; col >= 0; col--) {
                cout << data_matrix[row][col] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}