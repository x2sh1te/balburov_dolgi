#include <iostream>
#include<windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int semi_axis_a, semi_axis_b;
	cout << "Введите полуоси эллипса: ";
	cin >> semi_axis_a >> semi_axis_b;

	for (int coord_x = -semi_axis_a; coord_x <= semi_axis_a; ++coord_x) {
		for (int coord_y = -semi_axis_b; coord_y <= semi_axis_b; ++coord_y) {
			if (((coord_x * coord_x) / (semi_axis_a * semi_axis_a)) +
				((coord_y * coord_y) / (semi_axis_b * semi_axis_b)) <= 1) {
				cout << coord_x << " " << coord_y << endl;
			}
		}
	}

	return 0;
}