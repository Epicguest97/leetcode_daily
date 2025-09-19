#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;
    int rows;

    pair<int,int> parseCell(const string& cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }

    bool isNumber(const string& s) {
        if (s.empty()) return false;
        for (char c : s) if (!isdigit(c)) return false;
        return true;
    }

    int evaluate(const string& token) {
        if (isNumber(token)) return stoi(token);
        auto [r, c] = parseCell(token);
        return grid[r][c];
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        if (formula[0] == '=') formula = formula.substr(1);
        int pos = formula.find('+');
        string X = formula.substr(0, pos);
        string Y = formula.substr(pos+1);
        return evaluate(X) + evaluate(Y);
    }
};
