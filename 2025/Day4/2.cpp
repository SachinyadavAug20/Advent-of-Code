// --- Part Two ---
//
// Now, the Elves just need help accessing as much of the paper as they can.
//
// Once a roll of paper can be accessed by a forklift, it can be removed. Once a
// roll of paper is removed, the forklifts might be able to access more rolls of
// paper, which they might also be able to remove. How many total rolls of paper
// could the Elves remove if they keep repeating this process?
//
// Starting with the same example as above, here is one way you could remove as
// many rolls of paper as possible, using highlighted @ to indicate that a roll
// of paper is about to be removed, and using x to indicate that a roll of paper
// was just removed:
//

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void prit_grid(vector<char> a[], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

int main() {
  // Open the input file
  ifstream inputFile("input.txt");
  // Check if the file was opened successfully
  if (!inputFile) {
    cerr << "Unable to open file input.txt";
    return 1; // Exit with error code
  }

  vector<char> grid[150];
  int row = 0, col = 0;

  for (int i = 0; true; i++) {
    string line;
    getline(inputFile, line);
    if (!line.length()) {
      break;
    }
    for (int i = 0; i < line.size(); i++) {
      grid[i].push_back(line[i]);
    }
    col = line.size();
    row++;
  }

  // now have a grid
  int no_of_accessibe = 0, no_of_nebigours = 0, no_of_removed;
  while (true) {
        no_of_removed=0;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {

        no_of_nebigours = 0;
        if (grid[i][j] == '@') {

          if (j + 1 < col && grid[i][j + 1] == '@') {
            no_of_nebigours++;
          }
          if (j - 1 >= 0 && grid[i][j - 1] == '@') {
            no_of_nebigours++;
          }
          if (j + 1 < col && i + 1 < row && grid[i + 1][j + 1] == '@') {
            no_of_nebigours++;
          }
          if (j + 1 < col && i - 1 >= 0 && grid[i - 1][j + 1] == '@') {
            no_of_nebigours++;
          }
          if (i + 1 < row && j - 1 >= 0 && grid[i + 1][j - 1] == '@') {
            no_of_nebigours++;
          }
          if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '@') {
            no_of_nebigours++;
          }
          if (i - 1 >= 0 && grid[i - 1][j] == '@') {
            no_of_nebigours++;
          }
          if (i + 1 < row && grid[i + 1][j] == '@') {
            no_of_nebigours++;
          }

          if (no_of_nebigours < 4) {
            // cout << "pos :" << "(" << i << "," << j << ")" << endl;
            no_of_accessibe++;
            grid[i][j] = '.';
                        no_of_removed++;
            prit_grid(grid, row, col);
            cout << endl;
          }
        }
        // cout << grid[i][j];
      }
    }
        if(no_of_removed==0){
            break;
        }
  }
  cout << "no of accessible : " << no_of_accessibe;
}



//THIS is also visulaizer of state of the grid after removal of each set of rolls
