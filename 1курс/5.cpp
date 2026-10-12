#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int hand_size = 5;
    int poker_hand[hand_size];
    int card_counts[14] = { 0 };

    cout << "Введите значения карт (2-13): ";
    for (int i = 0; i < hand_size; i++) {
        cin >> poker_hand[i];
        card_counts[poker_hand[i]]++;
    }

    bool has_three_of_a_kind = false;
    bool has_four_of_a_kind = false;
    int pair_count = 0;

    for (int card_value = 1; card_value < 13; card_value++) {
        if (card_counts[card_value] == 5) {
            cout << "1 - Покер (пять одинаковых)" << endl;
            return 0;
        }
        else if (card_counts[card_value] == 4) {
            has_four_of_a_kind = true;
        }
        else if (card_counts[card_value] == 3) {
            has_three_of_a_kind = true;
        }
        else if (card_counts[card_value] == 2) {
            pair_count++;
        }
    }

    if (has_four_of_a_kind) {
        cout << "2 - Каре (четыре одинаковых)" << endl;
    }
    else if (has_three_of_a_kind && pair_count == 1) {
        cout << "3 - Фулл хаус (тройка + пара)" << endl;
    }
    else if (has_three_of_a_kind) {
        cout << "4 - Тройка" << endl;
    }
    else if (pair_count == 2) {
        cout << "5 - Две пары" << endl;
    }
    else if (pair_count == 1) {
        cout << "6 - Одна пара" << endl;
    }
    else {
        cout << "7 - Старшая карта" << endl;
    }

    return 0;
}