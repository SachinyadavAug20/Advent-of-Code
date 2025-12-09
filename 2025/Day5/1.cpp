// --- Day 5: Cafeteria ---
//
// As the forklifts break through the wall, the Elves are delighted to discover
// that there was a cafeteria on the other side after all.
//
// You can hear a commotion coming from the kitchen. "At this rate, we won't
// have any time left to put the wreaths up in the dining hall!" Resolute in
// your quest, you investigate.
//
// "If only we hadn't switched to the new inventory management system right
// before Christmas!" another Elf exclaims. You ask what's going on.
//
// The Elves in the kitchen explain the situation: because of their complicated
// new inventory management system, they can't figure out which of their
// ingredients are fresh and which are spoiled. When you ask how it works, they
// give you a copy of their database (your puzzle input).
//
// The database operates on ingredient IDs. It consists of a list of fresh
// ingredient ID ranges, a blank line, and a list of available ingredient IDs.
// For example:
//
// 3-5
// 10-14
// 16-20
// 12-18
//
// 1
// 5
// 8
// 11
// 17
// 32
//
// The fresh ID ranges are inclusive: the range 3-5 means that ingredient IDs 3,
// 4, and 5 are all fresh. The ranges can also overlap; an ingredient ID is
// fresh if it is in any range.
//
// The Elves are trying to determine which of the available ingredient IDs are
// fresh. In this example, this is done as follows:
//
//     Ingredient ID 1 is spoiled because it does not fall into any range.
//     Ingredient ID 5 is fresh because it falls into range 3-5.
//     Ingredient ID 8 is spoiled.
//     Ingredient ID 11 is fresh because it falls into range 10-14.
//     Ingredient ID 17 is fresh because it falls into range 16-20 as well as
//     range 12-18. Ingredient ID 32 is spoiled.
//
// So, in this example, 3 of the available ingredient IDs are fresh.
//
// Process the database file from the new inventory management system. How many
// of the available ingredient IDs are fresh?
//

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
  // Open the input file
  ifstream inputFile("input.txt");
  // Check if the file was opened successfully
  if (!inputFile) {
    cerr << "Unable to open file input.txt";
    return 1; // Exit with error code
  }
  string ranges[300];
  int no_of_ranges = 0;
  // take ranges here
  while (true) {
    string line;
    getline(inputFile, line);
    if (line.size() == 0) {
      break;
    }
    ranges[no_of_ranges] = line;
    no_of_ranges++;
  }

  for (int i = 0; i < no_of_ranges; i++) {
    cout << ranges[i] << endl;
  }

  long long int test[1100];
  int no_of_test = 0;
  // take samples test here
  while (true) {
    string line;
    getline(inputFile, line);
    if (line.size() == 0) {
      break;
    }
    test[no_of_test] = stoll(line);
    no_of_test++;
  }
  // for (int i = 0; i < no_of_test; i++) {
  //   cout << test[i] << endl;
  // }
  int no_of_fresh = 0;
  for (int i = 0; i < no_of_test; i++) {
    for (int j = 0; j < no_of_ranges; j++) {
      string range = ranges[j];
     long long int min = stoll(range.substr(0, range.find('-')));
     long long int max = stoll(range.substr(range.find('-') + 1));

      if (test[i] > max || test[i] < min) {
        // cout << "spoiled : " << test[i] << endl;
        continue;
      }
      no_of_fresh++;
      cout << "fresh: " << test[i] << endl;
            break;
    }
  }
  cout << "no of fresh :" << no_of_fresh << endl;
}
