#pragma once

#include <vector>

class Board {
private:
    int n, m; 
    std::vector<std::vector<bool>> h_edges;
    std::vector<std::vector<bool>> v_edges;
    std::vector<std::vector<int>> boxes;

    bool captureBox(int row, int col, int player);

public:
    Board(int n, int m);
    void draw() const;
    // Coordinates are (column, row), starting at 1.
    // s receives the number of boxes captured by this move (0, 1 or 2).
    bool placeEdge(int x1, int y1, int x2, int y2, int p, int& s);
    bool allBoxesFilled() const;
    int getBoxOwner(int i, int j) const; // Zero-based box row and column.
    int nBoxes() const;
};
