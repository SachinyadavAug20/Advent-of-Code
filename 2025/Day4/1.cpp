// --- Day 4: Printing Department ---
//
// You ride the escalator down to the printing department. They're clearly
// getting ready for Christmas; they have lots of large rolls of paper
// everywhere, and there's even a massive printer in the corner (to handle the
// really big print jobs).
//
// Decorating here will be easy: they can make their own decorations. What you
// really need is a way to get further into the North Pole base while the
// elevators are offline.
//
// "Actually, maybe we can help with that," one of the Elves replies when you
// ask for help. "We're pretty sure there's a cafeteria on the other side of the
// back wall. If we could break through the wall, you'd be able to keep moving.
// It's too bad all of our forklifts are so busy moving those big rolls of paper
// around."
//
// If you can optimize the work the forklifts are doing, maybe they would have
// time to spare to break through the wall.
//
// The rolls of paper (@) are arranged on a large grid; the Elves even have a
// helpful diagram (your puzzle input) indicating where everything is located.
//
// For example:
//
// ..@@.@@@@.
// @@@.@.@.@@
// @@@@@.@.@@
// @.@@@@..@.
// @@.@@@@.@@
// .@@@@@@@.@
// .@.@.@.@@@
// @.@@@.@@@@
// .@@@@@@@@.
// @.@.@@@.@.
//
// The forklifts can only access a roll of paper if there are fewer than four
// rolls of paper in the eight adjacent positions. If you can figure out which
// rolls of paper the forklifts can access, they'll spend less time looking and
// more time breaking down the wall to the cafeteria.
//
// In this example, there are 13 rolls of paper that can be accessed by a
// forklift (marked with x):
//
// ..xx.xx@x.
// x@@.@.@.@@
// @@@@@.x.@@
// @.@@@@..@.
// x@.@@@@.@x
// .@@@@@@@.@
// .@.@.@.@@@
// x.@@@.@@@@
// .@@@@@@@@.
// x.x.@@@.x.
//
// Consider your complete diagram of the paper roll locations. How many rolls of
// paper can be accessed by a forklift?
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

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
  int no_of_accessibe = 0, no_of_nebigours = 0;
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
          cout << "pos :" << "(" << i << "," << j << ")" << endl;
          no_of_accessibe++;
        }
      }
      cout << grid[i][j];
    }
    cout << endl;
  }
  cout << "no of accessible : " << no_of_accessibe;
}
