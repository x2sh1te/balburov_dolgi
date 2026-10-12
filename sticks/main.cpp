#include "Board.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

struct Edge {
    int x1, y1, x2, y2;
};

bool readNumbers(const std::string& prompt, int count, std::vector<int>& values) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line) || line == "q" || line == "Q")
            return false;
        std::istringstream input(line);
        values.clear();
        int value;
        while (static_cast<int>(values.size()) < count && input >> value)
            values.push_back(value);
        if (static_cast<int>(values.size()) == count) {
            input >> std::ws;
            if (input.eof()) return true;
        }
        std::cout << "Введите ровно " << count << " целых чисел или q для выхода.\n";
    }
}

std::vector<Edge> makeEdges(int rows, int columns) {
    std::vector<Edge> edges;
    for (int y = 1; y <= rows; ++y)
        for (int x = 1; x < columns; ++x)
            edges.push_back({x, y, x + 1, y});
    for (int y = 1; y < rows; ++y)
        for (int x = 1; x <= columns; ++x)
            edges.push_back({x, y, x, y + 1});
    return edges;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::cout << "ПАЛОЧКИ (Dots and Boxes)\n"
        << "Соединяйте соседние точки. Замкнутая клетка приносит очко\n"
        << "и обязательный повторный ход. Побеждает игрок с большим счётом.\n"
        << "Границы поля тоже нужно рисовать. Игроки: A и B.\n"
        << "Вместо ввода чисел можно ввести q для выхода.\n\n";
    std::vector<int> input;
    int mode;
    while (true) {
        if (!readNumbers("1 — два игрока, 2 — демонстрация, 0 — выход: ", 1, input))
            return 0;
        mode = input[0];
        if (mode == 0) return 0;
        if (mode == 1 || mode == 2) break;
        std::cout << "Выберите 0, 1 или 2.\n";
    }

    int height, width;
    while (true) {
        if (!readNumbers("Размер в КЛЕТКАХ: высота ширина (1–10, например 6 6): ", 2, input))
            return 0;
        height = input[0];
        width = input[1];
        if (height >= 1 && height <= 10 && width >= 1 && width <= 10) break;
        std::cout << "Каждый размер должен быть от 1 до 10 клеток.\n";
    }
    int delay = 0;
    if (mode == 2) {
        while (true) {
            if (!readNumbers("Пауза между ходами в миллисекундах (0–2000): ", 1, input))
                return 0;
            delay = input[0];
            if (delay >= 0 && delay <= 2000) break;
            std::cout << "Введите число от 0 до 2000.\n";
        }
    }

    Board board(height + 1, width + 1);
    int player = 1;
    int score[3] = {0, 0, 0};
    auto edges = makeEdges(height + 1, width + 1);
    std::mt19937 random(std::random_device{}());
    std::shuffle(edges.begin(), edges.end(), random);
    board.draw();

    while (!board.allBoxesFilled()) {
        std::cout << "\nСчёт: A = " << score[1] << ", B = " << score[2]
            << ". Ход игрока " << (player == 1 ? 'A' : 'B') << ".\n";
        Edge edge{};
        if (mode == 2) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            // Prefer a scoring move; otherwise take a random unused edge.
            std::size_t chosen = edges.size() - 1;
            for (std::size_t i = 0; i < edges.size(); ++i) {
                Board trial = board;
                int captured = 0;
                const Edge& candidate = edges[i];
                trial.placeEdge(candidate.x1, candidate.y1, candidate.x2, candidate.y2, player, captured);
                if (captured > 0) {
                    chosen = i;
                    break;
                }
            }
            edge = edges[chosen];
            edges.erase(edges.begin() + static_cast<std::ptrdiff_t>(chosen));
            std::cout << "Компьютер: " << edge.x1 << ' ' << edge.y1 << ' '
                << edge.x2 << ' ' << edge.y2 << '\n';
        } else {
            if (!readNumbers("Введите x1 y1 x2 y2 (x — столбец, y — строка): ", 4, input)) {
                std::cout << "Партия прервана.\n";
                return 0;
            }
            edge = {input[0], input[1], input[2], input[3]};
        }

        int captured = 0;
        if (!board.placeEdge(edge.x1, edge.y1, edge.x2, edge.y2, player, captured)) {
            std::cout << "Недопустимый ход: нужны соседние точки внутри поля\n"
                << "и ещё не проведённая линия. Попробуйте снова.\n";
            continue;
        }
        score[player] += captured;
        board.draw();
        if (captured > 0) {
            std::cout << "Игрок " << (player == 1 ? 'A' : 'B') << " захватил клеток: " << captured << ".\n";
            if (!board.allBoxesFilled()) std::cout << "Дополнительный ход!\n";
        } else {
            player = 3 - player;
        }
    }

    std::cout << "\nИгра окончена! Всего клеток: " << board.nBoxes()
        << ". Итоговый счёт: A = " << score[1] << ", B = " << score[2] << ".\n";
    if (score[1] == score[2]) std::cout << "Ничья!\n";
    else std::cout << "Победил игрок " << (score[1] > score[2] ? 'A' : 'B') << "!\n";
    return 0;
}
