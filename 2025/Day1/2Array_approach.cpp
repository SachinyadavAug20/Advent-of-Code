#include <bits/stdc++.h>
using namespace std;
int arr[101] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
                45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
                60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
                75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
                90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
int current_state = arr[50], no_of_zeros = 0;

void rotate(char p, int r) {
  if (p == 'L') {
    for (int i = 0; i < r; i++) {
      if (current_state == 0) {
        no_of_zeros++;
      }
      current_state = arr[abs(((current_state - 1)<0?current_state-1+100:current_state-1) % 100)];
    }
  }
  if (p == 'R') {
    for (int i = 0; i < r; i++) {
      if (current_state == 0) {
        no_of_zeros++;
      }
      current_state = arr[abs((current_state + 1) % 100)];
    }
  }
}
int main() {
  string input;
  char p;
  int r;
  while (true) {
    cin >> input;
    p = input[0];
    r = stoi(input.erase(0, 1));

    if (p != 'L' && p != 'R') {
      break;
    }
    rotate(p, r);  }

    cout<<no_of_zeros;
}
