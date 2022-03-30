#include <iostream>
#include <string>

#include "Notebook.hpp"

using namespace std;
using namespace ariel;

Notebook::Notebook() {

}

void inputCheck(int page, int row, int column, int length, Direction dir) {

    if (dir == Direction::Horizontal) {
        if ((length + column - 1) >= ROWMAX || column < ROWMIN || page < ROWMIN ||
            row < ROWMIN || length < ROWMIN) {
            throw invalid_argument("page/row/column negative, column+strlen above 100");
        }
    } else {
        if (column + 1 > ROWMAX || column < ROWMIN || page < ROWMIN || row < ROWMIN || length < ROWMIN) {
            throw invalid_argument("page/row/column/length negative column above 100");
        }
    }
}

void Notebook::write(int page, int row, int column, Direction dir, const string &str) {

    inputCheck(page, row, column, str.length(), dir);
    const char *temp = str.c_str();
    if (dir == Direction::Horizontal) {
        for (int  i = column, j = 0; j < str.length(); ++i, ++j) {
            if ((notebook[page][row].count(i) == 0 || notebook[page][row][i] == '_') && isprint(temp[j]) != 0 && temp[j] != '~' ) {
                notebook[page][row][i] = temp[j];
            }
            else {
                throw invalid_argument("can't write on erased places/non printable");
            }
        }
    } else {
        for (int  i = row, j = 0; j < str.length(); ++i, ++j) { 
            if ((notebook[page][i].count(column) == 0 || notebook[page][i][column] == '_') && isprint(temp[j]) != 0&& temp[j] != '~') {
                notebook[page][i][column] = temp[j];
            }
            else {
                throw invalid_argument("can't write on erased places/non printable");
            }
        }
    }
}


string Notebook::read(int page, int row, int column, Direction dir, int length) {

    inputCheck(page, row, column, length, dir);

    string ans;

    if (dir == Direction::Horizontal) {
        for (int i = column; i < column + length; ++i) {
            if (notebook[page][row].count(i) == 0) {
                ans += '_';
            }
            else {
                ans += notebook[page][row][i];
            }
        }
    } else {
        for (int i = row; i < row + length; ++i) {
            if ((notebook[page][i]).count(column) == 0) {
                ans += '_';
            }
            else {
                ans += notebook[page][i][column];
            }
        }
    }
    return ans;
}

void Notebook::erase(int page, int row, int column, Direction dir, int length) {

    inputCheck(page, row, column, length, dir);
    
    if (dir == Direction::Horizontal) {
        for (int i = column; i < column + length; ++i) {
            notebook[page][row][i] = '~';
        }
    } else {
        for(int i = row; i < row + length; ++i) {
            notebook[page][i][column] = '~';
        }
    }
}

void Notebook::show(int page) {

    if (page < 0){
        throw invalid_argument("page cant be negative");
    }

    cout << notebook[page][0][0] << endl;
}