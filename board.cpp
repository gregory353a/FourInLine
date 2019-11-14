#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>

namespace {

void showColumnsNumbers() {
    std::cout.put(' ');
    for(auto i = 0U; i < Board::BoardWidth; ++i) {
        std::cout << i + 1 << ' ';
    }
    std::cout.put('\n');
}

void showRowsSeparator() {
    std::fill_n(std::ostream_iterator<char>(std::cout, "-"), Board::BoardWidth, '+');
    std::cout << "+\n";
}

void showRow(const Board::fields_t::value_type& row) {
    for(const auto& field: row) {
        std::cout << '|' << (field ? field->getRepr(): ' ');
    }
    std::cout << "|\n";
}

bool columnNotFull(const Board::fields_t& fields, unsigned col) {
    return ! fields[Board::BoardHeight - 1][col].has_value();
}

void tokenGravity(Board::fields_t& fields, unsigned col) {
    auto row = Board::BoardHeight;
    while(row--) {
        if (fields[row - 1][col]) {
            break;
        }
        fields[row - 1][col].emplace(fields[row][col]->getColor());
        fields[row][col].reset();
    }
}

} // anonymous namespace

Board::Board()
    : fields{} {
        // simple example
        //fields[3][3].emplace(TokenColor::Red);
}

void Board::show() const {
    showColumnsNumbers();
    auto row = BoardHeight;
    while(row--) {
        showRowsSeparator();
        showRow(fields[row]);
    }
    showRowsSeparator();
    showColumnsNumbers();
}

bool Board::dropToken(const Token& token, unsigned col) {
    assert((col > 0) && (col <= BoardWidth));
    bool result = true;
    // Normalize col to index
    --col;
    if (columnNotFull(fields, col)) {
        fields[BoardHeight - 1][col].emplace(token.getColor());
        tokenGravity(fields, col);
    } else {
        result = false;
    }
    return result;
}

bool Board::isFull() const {
    const auto& row = fields[BoardWidth - 1];
    return ! std::any_of(row.cbegin(), row.cend(),
        [](const auto& field) { return !field.has_value(); });
}
