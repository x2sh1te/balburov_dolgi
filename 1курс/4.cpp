#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int price_per_pair = 105;
    int price_per_bundle = 1025;
    int price_per_box = 11400;

    int total_pairs_needed;
    cout << "Введите необходимое количество пар носков: ";
    cin >> total_pairs_needed;

    int boxes_count = total_pairs_needed / (12 * 12);
    total_pairs_needed = total_pairs_needed - boxes_count * (12 * 12);

    int bundles_count = total_pairs_needed / 12;
    total_pairs_needed = total_pairs_needed - bundles_count * 12;

    int pairs_count = total_pairs_needed / 2;

    cout << "Необходимо приобрести:" << endl;
    cout << "Коробок (по 144 пары): " << boxes_count << endl;
    cout << "Связок (по 12 пар): " << bundles_count << endl;
    cout << "Пар носков: " << pairs_count << endl;

    return 0;
}