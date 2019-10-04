// Project: N-queen problem
// Author: JHSeng
// Date: 09/30/2019

// headers

#include <iostream>
#include <string>
#include <vector>
#include <utility>

// using standard library

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

// global variables

int __chessboardSize;
vector<vector<int>> __map;
vector<pair<int, int>> __queenPos;

// function declaration

bool isNumber           (string __str);
int  convertStringToInt (string _str);
void solve              ();
void printChessboard    ();
bool checkPosition      (int __curr_x, int __curr_y);
void dfs                (int __filled);

// function achieve

// check current string is number or not
bool isNumber(string __str) {
    for (auto __i : __str) {
        if (__i < '0' || __i > '9') return false;
    }
    return true;
}

// translate string into integer
int convertStringToInt(string __str) {
    int __ret = 0;
    for (auto __i : __str) {
        __ret = __ret * 10 + __i - '0';
    }
    return __ret;
}

// solve n-queen problem
void solve() {
    // chessboard init
    __map.resize(__chessboardSize + 1);
    for (auto &__i : __map) {
        for (int __j = 0; __j <= __chessboardSize; __j++) {
            __i.emplace_back(0);
        }
    }

    for (int __i = 1; __i <= __chessboardSize; __i++) {
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            if (checkPosition(__i, __j)) {
                __map[__i][__j] = 1;
                fillVis(__i, __j, 1);
                __queenPos.push_back(make_pair(__i, __j));
                dfs(1);
                fillVis(__i, __j, 0);
                __queenPos.pop_back();
            }
        }
    }
}

// dfs
void dfs(int __filled) {
    if (__filled == __chessboardSize + 1) {
        printChessboard();
        puts("");
        return;
    }
    for (int __i = 1; __i <= __chessboardSize; __i++) {
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            if (checkPosition(__i, __j)) {

            }
        }
    }
}

// print current chessboard
void printChessboard() {
    for (auto &__i : __map) {
        for (auto __j : __i) {
            cout << __j << " ";
        }
        cout << endl;
    }
}

// check current position is useable or not
bool checkPosition(int __curr_x, int __curr_y) {
    for (int i = 1;) {

    }
}

int main() {

    // init chessboard size
    string inputString;
    cout << "Please input the number n, n should be smaller or equal then 10: ";
    cin >> inputString;

    // check whether chessboard size is legal
    while (!isNumber(inputString)) {
        cout << "This input is illegal, please input again";
        cin >> inputString;
    }
    chessboardSize = convertStringToInt(inputString);

    // solve problem
    solve(chessboardSize);

    return 0;
}