// --- Part Two ---
//
// The escalator doesn't move. The Elf explains that it probably needs more
// joltage to overcome the static friction of the system and hits the big red
// "joltage limit safety override" button. You lose count of the number of times
// she needs to confirm "yes, I'm sure" and decorate the lobby a bit while you
// wait.
//
// Now, you need to make the largest joltage by turning on exactly twelve
// batteries within each bank.
//
// The joltage output for the bank is still the number formed by the digits of
// the batteries you've turned on; the only difference is that now there will be
// 12 digits in each bank's joltage output instead of two.
//
// Consider again the example from before:
//
// 987654321111111
// 811111111111119
// 234234234234278
// 818181911112111
//
// Now, the joltages are much larger:
//
//     In 987654321111111, the largest joltage can be found by turning on
//     everything except some 1s at the end to produce 987654321111. In the
//     digit sequence 811111111111119, the largest joltage can be found by
//     turning on everything except some 1s, producing 811111111119. In
//     234234234234278, the largest joltage can be found by turning on
//     everything except a 2 battery, a 3 battery, and another 2 battery near
//     the start to produce 434234234278. In 818181911112111, the joltage
//     888911112111 is produced by turning on everything except some 1s near the
//     front.
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {

  // Open the input file
  ifstream inputFile("input.txt");

  // Check if the file was opened successfully
  if (!inputFile) {
    cerr << "Unable to open file input.txt";
    return 1; // Exit with error code
  }

  long long int sum_max = 0;
  while (true) {
    string bank_J;
    getline(inputFile, bank_J);
    // cin >> bank_J;
    if (bank_J.size() == 0) {
      break;
    }
    // cout<<bank_J<<endl;
    string num;
    long long int max = 0;
    for (int i = 0; i < bank_J.size(); ++i) {
      for (int j = 0; j < bank_J.size(); ++j) {
        if (i >= j) {
          continue;
        }

        for (int a = 0; a < bank_J.size(); ++a) {
          if (j >= a) {
            continue;
          }

          for (int b = 0; b < bank_J.size(); ++b) {
            if (a >= b) {
              continue;
            }

            for (int c = 0; c < bank_J.size(); ++c) {
              if (b >= c) {
                continue;
              }

              for (int d = 0; d < bank_J.size(); ++d) {
                if (c >= d) {
                  continue;
                }

                for (int e = 0; e < bank_J.size(); ++e) {
                  if (d >= e) {
                    continue;
                  }

                  for (int f = 0; f < bank_J.size(); ++f) {
                    if (e >= f) {
                      continue;
                    }

                    for (int g = 0; g < bank_J.size(); ++g) {
                      if (f >= g) {
                        continue;
                      }

                      for (int h = 0; h < bank_J.size(); ++h) {
                        if (g >= h) {
                          continue;
                        }

                        for (int k = 0; k < bank_J.size(); ++k) {
                          if (h >= k) {
                            continue;
                          }

                          for (int l = 0; l < bank_J.size(); ++l) {
                            if (k >= l) {
                              continue;
                            }
                            num = "";
                            num.push_back(bank_J[i]);
                            num.push_back(bank_J[j]);
                            num.push_back(bank_J[a]);
                            num.push_back(bank_J[b]);
                            num.push_back(bank_J[c]);
                            num.push_back(bank_J[d]);
                            num.push_back(bank_J[e]);
                            num.push_back(bank_J[f]);
                            num.push_back(bank_J[g]);
                            num.push_back(bank_J[h]);
                            num.push_back(bank_J[k]);
                            num.push_back(bank_J[l]);
                            cout<<num<<endl;
                            if (max < stoll(num)) {
                              max = stoll(num);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        // num="";
        //   num.push_back(bank_J[i]);
        //   num.push_back(bank_J[j]);
        //   // cout<<num<<endl;
        //   if(max<stoi(num)){
        //     max=stoi(num);
        //   }
      }
    }
    cout << max << endl;
    sum_max += max;
  }
  cout << "sum of max : " << sum_max;
}
