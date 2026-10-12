#include "Board.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>

Board::Board(int rows, int columns) : n(rows), m(columns) {
    if (n < 2 || m < 2)
        throw std::invalid_argument("The board needs at least 2 by 2 points.");
    h_edges.assign(n, std::vector<bool>(m - 1, false));
    v_edges.assign(n - 1, std::vector<bool>(m, false));
    boxes.assign(n - 1, std::vector<int>(m - 1, 0));
}

void Board::draw() const {
    std::cout << "\n y\\x";
    for (int col = 1; col <= m; ++col)
        std::cout << std::setw(4) << col;
    std::cout << '\n';
    for (int row = 0; row < n; ++row) {
        std::cout << std::setw(4) << row + 1 << "   ";
        for (int col = 0; col < m; ++col) {
            std::cout << '+';
            if (col < m - 1)
                std::cout << (h_edges[row][col] ? "---" : "   ");
        }
        std::cout << '\n';
        if (row < n - 1) {
            std::cout << "       ";
            for (int col = 0; col < m; ++col) {
                std::cout << (v_edges[row][col] ? '|' : ' ');
                if (col < m - 1) {
                    const int owner = boxes[row][col];
                    std::cout << ' ' << (owner == 1 ? 'A' : owner == 2 ? 'B' : ' ') << ' ';
                }
            }
            std::cout << '\n';
        }
    }
}

bool Board::captureBox(int row, int col, int player) {
    if (row < 0 || row >= n - 1 || col < 0 || col >= m - 1)
        return false;
    if (boxes[row][col] == 0 && h_edges[row][col] && h_edges[row + 1][col]
        && v_edges[row][col] && v_edges[row][col + 1]) {
        boxes[row][col] = player;
        return true;
    }
    return false;
}

bool Board::placeEdge(int x1, int y1, int x2, int y2, int p, int& s) {
    s = 0;
    if (p < 1 || p > 2 || x1 < 1 || x1 > m || x2 < 1 || x2 > m
        || y1 < 1 || y1 > n || y2 < 1 || y2 > n)
        return false;
    if (std::abs(x1 - x2) + std::abs(y1 - y2) != 1)
        return false;

    const int row = (y1 < y2 ? y1 : y2) - 1;
    const int col = (x1 < x2 ? x1 : x2) - 1;
    if (y1 == y2) {
        if (h_edges[row][col]) return false;
        h_edges[row][col] = true;
        s += captureBox(row - 1, col, p);
        s += captureBox(row, col, p);
    } else {
        if (v_edges[row][col]) return false;
        v_edges[row][col] = true;
        s += captureBox(row, col - 1, p);
        s += captureBox(row, col, p);
    }
    return true;
}

bool Board::allBoxesFilled() const {
    for (const auto& row : boxes)
        for (int owner : row)
            if (owner == 0) return false;
    return true;
}

int Board::getBoxOwner(int i, int j) const {
    if (i < 0 || i >= n - 1 || j < 0 || j >= m - 1)
        throw std::out_of_range("Box coordinates are outside the board.");
    return boxes[i][j];
}

int Board::nBoxes() const {
    return (n - 1) * (m - 1);
}
