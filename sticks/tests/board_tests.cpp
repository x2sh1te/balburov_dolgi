#include "../Board.h"
#include <cassert>
#include <stdexcept>

int main() {
    bool threw = false;
    try { Board invalid(1, 2); } catch (const std::invalid_argument&) { threw = true; }
    assert(threw);
    Board board(2, 3);
    assert(board.nBoxes() == 2 && !board.allBoxesFilled());
    int s = 99;
    assert(!board.placeEdge(0, 1, 1, 1, 1, s) && s == 0);
    assert(!board.placeEdge(1, 1, 2, 2, 1, s));
    assert(!board.placeEdge(1, 1, 3, 1, 1, s));
    assert(!board.placeEdge(1, 1, 1, 1, 1, s));
    assert(!board.placeEdge(1, 1, 2, 1, 3, s));
    assert(board.placeEdge(2, 1, 1, 1, 1, s) && s == 0);
    assert(!board.placeEdge(1, 1, 2, 1, 2, s));
    assert(board.placeEdge(2, 1, 3, 1, 1, s) && s == 0);
    assert(board.placeEdge(1, 2, 2, 2, 1, s) && s == 0);
    assert(board.placeEdge(2, 2, 3, 2, 1, s) && s == 0);
    assert(board.placeEdge(1, 2, 1, 1, 1, s) && s == 0);
    assert(board.placeEdge(3, 1, 3, 2, 1, s) && s == 0);
    assert(board.placeEdge(2, 1, 2, 2, 2, s) && s == 2);
    assert(board.allBoxesFilled());
    assert(board.getBoxOwner(0, 0) == 2 && board.getBoxOwner(0, 1) == 2);
    assert(!board.placeEdge(2, 2, 2, 1, 1, s) && s == 0);
    threw = false;
    try { board.getBoxOwner(1, 0); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);

    Board vertical(3, 2);
    for (int y = 1; y <= 2; ++y) {
        assert(vertical.placeEdge(1, y, 1, y + 1, 1, s));
        assert(vertical.placeEdge(2, y, 2, y + 1, 1, s));
    }
    assert(vertical.placeEdge(1, 1, 2, 1, 1, s) && s == 0);
    assert(vertical.placeEdge(1, 3, 2, 3, 1, s) && s == 0);
    assert(vertical.placeEdge(2, 2, 1, 2, 1, s) && s == 2);
    assert(vertical.allBoxesFilled());
}
