#include "displayer.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>
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

void showRow(const int row[Board::BoardWidth]) {
    static const char fieldNumberToChar[] = {' ', 'X', 'O' };
    for(auto i = 0U; i < Board::BoardWidth; ++i) {
        auto value = row[i];
        assert((value < 3) && (value >= 0));
        std::cout << '|' << fieldNumberToChar[value];
    }
    std::cout << "|\n";
}

} // anonymous namespace

Displayer::Displayer()
    : fields{} {
    for(auto& row: fields) {
        std::fill_n(std::begin(row), Board::BoardWidth, 0);
    }
}

void Displayer::visit(container_t tab) {
    for(auto row = 0U; row < Board::BoardHeight; ++row) {
        for(auto col = 0U; col < Board::BoardWidth; ++col) {
            fields[row][col] = tab[row][col];
        }
    }
}

void Displayer::show() const {
    showColumnsNumbers();
    auto row = Board::BoardHeight;
    while(row--) {
        showRowsSeparator();
        showRow(fields[row]);
    }
    showRowsSeparator();
    showColumnsNumbers();
}
