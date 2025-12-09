// --- Part Two ---
//
// The Elves start bringing their spoiled inventory to the trash chute at the
// back of the kitchen.
//
// So that they can stop bugging you when they get new inventory, the Elves
// would like to know all of the IDs that the fresh ingredient ID ranges
// consider to be fresh. An ingredient ID is still considered fresh if it is in
// any range.
//
// Now, the second section of the database (the available ingredient IDs) is
// irrelevant. Here are the fresh ingredient ID ranges from the above example:
//
// 3-5
// 10-14
// 16-20
// 12-18
//
// The ingredient IDs that these ranges consider to be fresh are 3, 4, 5, 10,
// 11, 12, 13, 14, 15, 16, 17, 18, 19, and 20. So, in this example, the fresh
// ingredient ID ranges consider a total of 14 ingredient IDs to be fresh.
//
// Process the database file again. How many ingredient IDs are considered to be
// fresh according to the fresh ingredient ID ranges?

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
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

  int no_of_fresh = 0;
  vector<long long int> consider_fresh;
  for (int j = 0; j < no_of_ranges; j++) {
    string range = ranges[j];
    long long int min = stoll(range.substr(0, range.find('-')));
    long long int max = stoll(range.substr(range.find('-') + 1));
    for (long long int i = min; i <= max; i++) {
      consider_fresh.push_back(i);
    }
  }

  set<long long int> uniqueElements(consider_fresh.begin(),
                                    consider_fresh.end());
  vector<long long int> result(uniqueElements.begin(), uniqueElements.end());
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }

  cout << "no of fresh :" << result.size() << endl;
}
//This crashed my pc. Don't run this on actual input but it works for small input like sample input
