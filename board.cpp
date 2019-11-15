#include "board.hpp"
#include "displayer.hpp"
#include <algorithm>
#include <cassert>

namespace {

inline bool columnNotFull(const Board::fields_t& fields, unsigned col) {
    return ! fields[BoardHeight - 1][col].has_value();
}

void tokenGravity(Board::fields_t& fields, unsigned col) {
    auto row = BoardHeight - 1;
    while(row--) {
        auto& prevField = fields[row + 1][col];
        auto& currField = fields[row][col];
        if (currField) {
            break;
        }
        prevField.swap(currField);
    }
}

void transformFieldsToInt(const Board::fields_t& fields, int tab[BoardHeight][BoardWidth]) {
    for(auto row = 0U; row < BoardHeight; ++row) {
        for(auto col = 0U; col < BoardWidth; ++col) {
            tab[row][col] = (fields[row][col].has_value() ? static_cast<int>(fields[row][col]->getColor()) + 1: 0);
        }
    }
}

} // anonymous namespace

Board::Board()
    : fields{} {
}

bool Board::dropToken(Token&& token, unsigned col) {
    assert((col > 0) && (col <= BoardWidth));
    bool result = true;
    // Normalize col to index
    --col;
    if (columnNotFull(fields, col)) {
        fields[BoardHeight - 1][col] = std::move(token);
        tokenGravity(fields, col);
    } else {
        result = false;
    }
    return result;
}

bool Board::isFull() const {
    const auto& row = fields[BoardHeight - 1];
    return ! std::any_of(row.cbegin(), row.cend(), [](const auto& field) {
        return !field.has_value();
    });
}

void Board::accept(Displayer& displayer) const {
    int tab[BoardHeight][BoardWidth];
    transformFieldsToInt(fields, tab);
    displayer.visit(tab);
}
