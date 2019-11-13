#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>

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
        std::cout << "|" << (field ? field->getRepr(): ' ');
    }
    std::cout << "|\n";
}

} // anonymous namespace

Board::Board()
    : fields{} {
        // simple example
        fields[3][3].emplace(TokenColor::Red);
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
