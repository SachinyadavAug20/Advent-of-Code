// With your analysis of the manifold complete, you begin fixing the teleporter.
// However, as you open the side of the teleporter to replace the broken
// manifold, you are surprised to discover that it isn't a classical tachyon
// manifold - it's a quantum tachyon manifold.
//
// With a quantum tachyon manifold, only a single tachyon particle is sent
// through the manifold. A tachyon particle takes both the left and right path
// of each splitter encountered.
//
// Since this is impossible, the manual recommends the many-worlds
// interpretation of quantum tachyon splitting: each time a particle reaches a
// splitter, it's actually time itself which splits. In one timeline, the
// particle went left, and in the other timeline, the particle went right.
//
// To fix the manifold, what you really need to know is the number of timelines
// active after a single particle completes all of its possible journeys through
// the manifold.
//
// In the above example, there are many timelines. For instance, there's the
// timeline where the particle always went left:

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>
using namespace std;
bool checkifDone(vector<char> a[], int nRow) {
  for (int i = 0; i < a[nRow - 1].size(); i++) {
    if (a[nRow - 1][i] == '|') {
      return true;
    }
  }
  return false;
}

void printBoard(vector<char> a[], int nRow) {
  int lines_number = 0;
    int no_of_splitets=0;
  for (int i = 0; i < nRow; i++) {
        lines_number=0;
        no_of_splitets=0;
    for (int j = 0; j < a[0].size(); j++) {
      if (a[i][j] == '|' && ) {
        lines_number++;
      }
            if (a[i][j]==) {
            
            }
      cout << a[i][j];
    }
    cout << endl;
  }
  cout << "no of lines : " << lines_number << endl;
}

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

  vector<char> board[150];
  int no_of_rows = 0;
  for (int i = 0; i < grid.size(); i++) {
    string current_line = grid[i];
    for (int j = 0; j < grid[i].size(); j++) {
      board[i].push_back(current_line[j]);
    }
    no_of_rows++;
  }
  printBoard(board, no_of_rows);
  // while (checkifDone(board, no_of_rows)) {
  //
  // }
  // find index of S
  int iS;
  for (int i = 0; i < board[0].size(); i++) {
    if (board[0][i] == 'S') {
      iS = i;
    }
  }
  vector<int> iTarget;
  iTarget.push_back(iS);

  vector<int> nextTargets;
  nextTargets.push_back(iS);
  int no_of_split = 0;
  int no_of_timelines = 0;
  for (int i = 1; i < no_of_rows; i++) {

    for (int k = 0; k < iTarget.size(); k++) {
      if (board[i][iTarget[k]] == '.') {
        board[i][iTarget[k]] = '|';
      }
      if (board[i][iTarget[k]] == '^') {
        auto newEnd =
            remove(nextTargets.begin(), nextTargets.end(), iTarget[k]);

        nextTargets.erase(newEnd, nextTargets.end());
        nextTargets.push_back(iTarget[k] + 1);
        nextTargets.push_back(iTarget[k] - 1);
        no_of_split++;
        // erase dupliate if 2 split cause only 3 beams
        sort(nextTargets.begin(), nextTargets.end());

        newEnd = std::unique(nextTargets.begin(), nextTargets.end());

        nextTargets.erase(newEnd, nextTargets.end());
        no_of_timelines += nextTargets.size();
      }
    }
    iTarget = nextTargets;
    printBoard(board, no_of_rows);
  }
  cout << no_of_split << " " << no_of_timelines << " " << nextTargets.size()
       << endl;
}
