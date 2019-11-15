#include "displayer.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <cassert>

namespace {

void showColumnsNumbers() {
    std::cout.put(' ');
    for(auto i = 0U; i < BoardWidth; ++i) {
        std::cout << i + 1 << ' ';
    }
    std::cout.put('\n');
}

void showRowsSeparator() {
    std::fill_n(std::ostream_iterator<char>(std::cout, "-"), BoardWidth, '+');
    std::cout << "+\n";
}

void showRow(const int row[BoardWidth]) {
    constexpr static char fieldNumberToChar[] = {' ', 'X', 'O' };
    for(auto i = 0U; i < BoardWidth; ++i) {
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
        std::fill_n(std::begin(row), BoardWidth, 0);
    }
}

void Displayer::visit(container_t tab) {
    std::memcpy(fields, tab, BoardHeight * BoardWidth * sizeof(int));
}

void Displayer::showBoard() const {
    showColumnsNumbers();
    auto row = BoardHeight;
    while(row--) {
        showRowsSeparator();
        showRow(fields[row]);
    }
    showRowsSeparator();
    showColumnsNumbers();
}

void Displayer::showPlayerInfo(std::string_view name, TokenColor color) const {
    std::cout << "Player: " << name << ", plays: "
      << (color == TokenColor::Red ? "Red": "Yellow") << '\n';
}

void Displayer::showIncorrectMove() const {
    std::cerr << "Incorrect move! Try again!\n";
}

unsigned Displayer::unsignedInput(std::string_view msg, std::string_view err_msg, bool (*check)(unsigned)) {
    unsigned column;
    for(;;) {
        std::cout << msg;
        std::cin >> column;
        if(std::cin && check(column)) {
            break;
        }
        std::cerr << err_msg;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return column;
}

