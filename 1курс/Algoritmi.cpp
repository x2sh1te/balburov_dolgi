#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void SortMethodA(int* data, int count) {
    auto begin_time = high_resolution_clock::now();
    for (int idx = 1; idx < count; idx++) {
        int temp_value = data[idx];
        int pos = idx - 1;
        while (pos >= 0 && data[pos] > temp_value) {
            data[pos + 1] = data[pos];
            pos--;
        }
        data[pos + 1] = temp_value;
    }
    auto finish_time = high_resolution_clock::now();
    duration<double> elapsed = finish_time - begin_time;
    cout << "Время выполнения: " << elapsed.count() << " секунд\n";
}

void SortMethodB(int* data, int count) {
    auto begin_time = high_resolution_clock::now();

    for (int idx = count / 2 - 1; idx >= 0; idx--) {
        int current = idx;
        while (2 * current + 1 < count) {
            int next = 2 * current + 1;
            if (next + 1 < count && data[next] < data[next + 1])
                next++;
            if (data[current] < data[next]) {
                int swap_temp = data[current];
                data[current] = data[next];
                data[next] = swap_temp;
                current = next;
            }
            else break;
        }
    }

    for (int idx = count - 1; idx > 0; idx--) {
        int swap_temp = data[0];
        data[0] = data[idx];
        data[idx] = swap_temp;

        int current = 0;
        while (2 * current + 1 < idx) {
            int next = 2 * current + 1;
            if (next + 1 < idx && data[next] < data[next + 1])
                next++;
            if (data[current] < data[next]) {
                int temp = data[current];
                data[current] = data[next];
                data[next] = temp;
                current = next;
            }
            else break;
        }
    }

    auto finish_time = high_resolution_clock::now();
    duration<double> elapsed = finish_time - begin_time;
    cout << "Время выполнения: " << elapsed.count() << " секунд\n";
}

void RecursiveSort(int* data, int left, int right) {
    int l = left, r = right;
    int middle_value = data[(left + right) / 2];

    while (l <= r) {
        while (data[l] < middle_value) l++;
        while (data[r] > middle_value) r--;
        if (l <= r) {
            int temp_val = data[l];
            data[l] = data[r];
            data[r] = temp_val;
            l++;
            r--;
        }
    }

    if (left < r) RecursiveSort(data, left, r);
    if (l < right) RecursiveSort(data, l, right);
}

void SortMethodC(int* data, int count) {
    auto begin_time = high_resolution_clock::now();
    RecursiveSort(data, 0, count - 1);
    auto finish_time = high_resolution_clock::now();
    duration<double> elapsed = finish_time - begin_time;
    cout << "Время выполнения: " << elapsed.count() << " секунд\n";
}

void SortMethodD(int* data, int n) {
    auto begin_time = high_resolution_clock::now();

    int** containers = new int* [n];
    int* sizes = new int[n];

    for (int i = 0; i < n; i++) {
        containers[i] = new int[n];
        sizes[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int container_idx = data[i] / 10;
        containers[container_idx][sizes[container_idx]++] = data[i];
    }

    int position = 0;
    for (int i = 0; i < n; i++) {
        SortMethodA(containers[i], sizes[i]);
        for (int j = 0; j < sizes[i]; j++)
            data[position++] = containers[i][j];
    }

    for (int i = 0; i < n; i++)
        delete[] containers[i];
    delete[] containers;
    delete[] sizes;

    auto finish_time = high_resolution_clock::now();
    duration<double> elapsed = finish_time - begin_time;
    cout << "Время выполнения: " << elapsed.count() << " секунд\n";
}

void SortMethodE(int data[], int count) {
    auto begin_time = high_resolution_clock::now();

    for (int segment = 1; segment < count; segment *= 2) {
        for (int j = 0; j < count - segment; j += 2 * segment) {
            int left_bound = j;
            int middle_bound = j + segment;
            int right_bound = (j + 2 * segment < count) ? j + 2 * segment : count;

            int i = left_bound, k = middle_bound, pos = 0;
            int* buffer = new int[right_bound - left_bound];

            while (i < middle_bound && k < right_bound)
                buffer[pos++] = (data[i] < data[k]) ? data[i++] : data[k++];
            while (i < middle_bound) buffer[pos++] = data[i++];
            while (k < right_bound) buffer[pos++] = data[k++];

            for (int t = 0; t < pos; t++)
                data[left_bound + t] = buffer[t];

            delete[] buffer;
        }
    }

    auto finish_time = high_resolution_clock::now();
    duration<double> elapsed = finish_time - begin_time;
    cout << "Время выполнения: " << elapsed.count() << " секунд\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int array_size;
    cout << "Укажите размер набора данных: ";
    cin >> array_size;

    int* numbers = new int[array_size];

    cout << "Исходные данные:\n";
    for (int i = 0; i < array_size; i++) {
        numbers[i] = rand() % 100;
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    cout << "1 - Метод A\n"
        << "2 - Метод B\n"
        << "3 - Метод C\n"
        << "4 - Метод D\n"
        << "5 - Метод E\n"
        << "Выберите вариант: ";

    int choice;
    cin >> choice;
    cout << "\n";

    switch (choice) {
    case 1: SortMethodA(numbers, array_size); break;
    case 2: SortMethodB(numbers, array_size); break;
    case 3: SortMethodC(numbers, array_size); break;
    case 4: SortMethodD(numbers, array_size); break;
    case 5: SortMethodE(numbers, array_size); break;
    default: cout << "Некорректный выбор\n";
    }

    cout << "\nРезультат обработки:\n";
    for (int i = 0; i < array_size; i++)
        cout << numbers[i] << " ";

    delete[] numbers;
    return 0;
}