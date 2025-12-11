#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream input("input.txt");
    if (!input) {
        cerr << "Unable to open file input.txt\n";
        return 1;
    }

    vector<string> grid;
    string line;
    while (getline(input, line)) {
        if (line.size() == 0) break; // stop on blank line (as your puzzle input does)
        grid.push_back(line);
    }

    if (grid.empty()) {
        cerr << "No data\n";
        return 1;
    }

    // Last row is operators line
    if (grid.size() < 2) {
        cerr << "Not enough rows (need at least one data row + operator row)\n";
        return 1;
    }

    int rows = (int)grid.size() - 1;
    // pad all lines to same width (max length)
    size_t cols = 0;
    for (auto &s : grid) cols = max(cols, s.size());
    for (auto &s : grid) if (s.size() < cols) s.append(cols - s.size(), ' ');

    string ops = grid.back(); // operator row
    vector<vector<long long>> problems;
    vector<char> opList;

    auto columnHasDigit = [&](size_t c) {
        for (int r = 0; r < rows; ++r) {
            if (isdigit((unsigned char)grid[r][c])) return true;
        }
        return false;
    };

    size_t c = 0;
    while (c < cols) {
        // skip columns that don't contain any digit in the number rows
        if (!columnHasDigit(c)) { ++c; continue; }

        // find contiguous block of columns that belong to this problem
        size_t d = c;
        while (d < cols && columnHasDigit(d)) ++d; // block is [c, d-1]

        // extract numbers for this block by reading each row across columns [c..d-1]
        vector<long long> nums;
        for (int r = 0; r < rows; ++r) {
            string token;
            for (size_t k = c; k < d; ++k) {
                char ch = grid[r][k];
                if (isdigit((unsigned char)ch)) token.push_back(ch);
            }
            if (!token.empty()) {
                // safe stoi for reasonable AoC ints; use stoll to be safe
                nums.push_back(stoll(token));
            }
        }

        // find operator in ops row within block [c..d-1]
        char op = '?';
        for (size_t k = c; k < d; ++k) {
            if (ops[k] == '+' || ops[k] == '*') { op = ops[k]; break; }
        }
        // If operator not found inside block, scan rightwards a bit (just in case of spacing)
        if (op == '?') {
            size_t k = d;
            while (k < cols && ops[k] == ' ') ++k;
            if (k < cols && (ops[k] == '+' || ops[k] == '*')) op = ops[k];
        }

        if (!nums.empty() && (op == '+' || op == '*')) {
            problems.push_back(nums);
            opList.push_back(op);
        } else {
            // If we didn't find valid numbers+op, you might want to debug the block:
            // Uncomment the following to print debug info:
            // cerr << "Skipped block ["<<c<<","<<d-1<<"] op="<<op<<" nums="<<nums.size()<<"\n";
        }

        c = d; // continue after this block
    }

    // compute grand total
    long long grand = 0;
    for (size_t i = 0; i < problems.size(); ++i) {
        long long val = (opList[i] == '+') ? 0LL : 1LL;
        if (opList[i] == '+') {
            for (auto x : problems[i]) val += x;
        } else {
            for (auto x : problems[i]) val *= x;
        }
        grand += val;
    }

    cout << "grand total : " << grand << "\n";
    return 0;
}
//This soln i got logic from reddit and it overcomes all problems of parsing the input k

