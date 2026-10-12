#include <iostream>
#include<windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int coeff_a, coeff_b, coeff_c;
	cout << "Введите коэффициенты a,b,c: ";
	cin >> coeff_a >> coeff_b >> coeff_c;

	int vertex_x, vertex_y;
	vertex_x = (coeff_b * (-1)) / 2 * coeff_a;
	vertex_y = ((4 * coeff_a * coeff_c) - (coeff_b * coeff_b)) / 4 * coeff_a;

	cout << "Абсцисса вершины: " << vertex_x << endl;
	cout << "Ордината вершины: " << vertex_y << endl;

	return 0;
}