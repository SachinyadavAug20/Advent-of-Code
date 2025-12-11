// --- Part Two ---
//
// The big cephalopods come back to check on how things are going. When they see
// that your grand total doesn't match the one expected by the worksheet, they
// realize they forgot to explain how to read cephalopod math.
//
// Cephalopod math is written right-to-left in columns. Each number is given in
// its own column, with the most significant digit at the top and the least
// significant digit at the bottom. (Problems are still separated with a column
// consisting only of spaces, and the symbol at the bottom of the problem is
// still the operator to use.)
//
// Here's the example worksheet again:
//
// 123 328  51 64
//  45 64  387 23
//   6 98  215 314
// *   +   *   +
//
// Reading the problems right-to-left one column at a time, the problems are now
// quite different:
//
//     The rightmost problem is 4 + 431 + 623 = 1058
//     The second problem from the right is 175 * 581 * 32 = 3253600
//     The third problem from the right is 8 + 248 + 369 = 625
//     Finally, the leftmost problem is 356 * 24 * 1 = 8544
//
// Now, the grand total is 1058 + 3253600 + 625 + 8544 = 3263827.
//
// Solve the problems on the math worksheet again. What is the grand total found
// by adding together all of the answers to the individual problems?

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    if (line.size() == 0) {
      break;
    }
    grid.push_back(line);
  }
  // got full input in grid
  for (int i = 0; i < grid.size(); i++) {
    cout << grid[i] << endl;
  }

  int rows = (int)grid.size() - 1; // no of rows with numberical data
  // cout << rows << endl;
    
  size_t cols = 0;
  for (auto &s : grid)
    cols = max(cols, s.size());
  for (auto &s : grid)
    if (s.size() < cols)
      s.append(cols - s.size(), ' ');

  string ops = grid.back(); // operator row
  vector<vector<long long>> problems;
  vector<char> opList;

  auto columnHasDigit = [&](size_t c) {
    for (int r = 0; r < rows; ++r) {
      if (isdigit((unsigned char)grid[r][c]))
        return true;
    }
    return false;
  };

  size_t c = 0;
  while (c < cols) {
    // skip columns that don't contain any digit in the number rows
    if (!columnHasDigit(c)) {
      ++c;
      continue;
    }

    // find contiguous block of columns that belong to this problem
    size_t d = c;
    while (d < cols && columnHasDigit(d))
      ++d; // block is [c, d-1]

    // extract numbers for this block by reading each row across columns
    // [c..d-1]
    vector<long long> nums;
    for (int r = 0; r < rows; ++r) {
      string token;
      for (size_t k = c; k < d; ++k) {
        char ch = grid[r][k];
        if (isdigit((unsigned char)ch))
          token.push_back(ch);
      }
      if (!token.empty()) {
        // safe stoi for reasonable AoC ints; use stoll to be safe
        nums.push_back(stoll(token));
      }
    }

    // find operator in ops row within block [c..d-1]
    char op = '?';
    for (size_t k = c; k < d; ++k) {
      if (ops[k] == '+' || ops[k] == '*') {
        op = ops[k];
        break;
      }
    }
    // If operator not found inside block, scan rightwards a bit (just in case
    // of spacing)
    if (op == '?') {
      size_t k = d;
      while (k < cols && ops[k] == ' ')
        ++k;
      if (k < cols && (ops[k] == '+' || ops[k] == '*'))
        op = ops[k];
    }

    if (!nums.empty() && (op == '+' || op == '*')) {
      problems.push_back(nums);
      opList.push_back(op);
    } else {
      // If we didn't find valid numbers+op, you might want to debug the block:
      // Uncomment the following to print debug info:
      // cerr << "Skipped block ["<<c<<","<<d-1<<"] op="<<op<<"
      // nums="<<nums.size()<<"\n";
    }

    c = d; // continue after this block
  }

  // compute grand total
  long long grand = 0;
  for (size_t i = 0; i < problems.size(); ++i) {
    long long val = (opList[i] == '+') ? 0LL : 1LL;
    if (opList[i] == '+') {
      for (auto x : problems[i])
        val += x;
    } else {
      for (auto x : problems[i])
        val *= x;
    }
    grand += val;
  }

  cout << "grand total : " << grand << "\n";
  return 0;
}
// This soln i got logic from reddit and it overcomes all problems of parsing
// the input k Stuck
