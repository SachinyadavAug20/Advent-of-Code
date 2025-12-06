// The ranges are separated by commas (,); each range gives its first ID and
// last ID separated by a dash (-).
//
// Since the young Elf was just doing silly patterns, you can find the invalid
// IDs by looking for any ID which is made only of some sequence of digits
// repeated twice. So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice)
// would all be invalid IDs.
//
// None of the numbers have leading zeroes; 0101 isn't an ID at all. (101 is a
// valid ID that you would ignore.)
//
// Your job is to find all of the invalid IDs that appear in the given ranges.
// In the above example:
//
//     11-22 has two invalid IDs, 11 and 22.
//     95-115 has one invalid ID, 99.
//     998-1012 has one invalid ID, 1010.
//     1188511880-1188511890 has one invalid ID, 1188511885.
//     222220-222224 has one invalid ID, 222222.
//     1698522-1698528 contains no invalid IDs.
//     446443-446449 has one invalid ID, 446446.
//     38593856-38593862 has one invalid ID, 38593859.
//     The rest of the ranges contain no invalid IDs.
//
// Adding up all the invalid IDs in this example produces 1227775554.
//
// What do you get if you add up all of the invalid IDs?
//
//

#include <bits/stdc++.h>
using namespace std;
int product_of_invalid_numbers = 1, no_of_digits = 0;

long long int check_for_invalid_numbers(long long int from, long long int to) {

  long int sum = 0, f = 0;

  for (long long int i = from; i <= to; ++i) {
    f = 0;
    string num = to_string(i);
    if (num.size() % 2 != 0) {
      continue;
    }
    no_of_digits = num.size();
    for (int i = 0; i < no_of_digits / 2; ++i) {
      if (num[i] != num[(no_of_digits / 2) + i]) {
        // cout<<"valid "<<endl;
        f = 1;
      }
    }
    // cout << "Invalid number" << endl;
    if (f == 0) {
      sum += i;
    }
  }

  return sum;
}

int main() {
  string str, to, from;
  long long int sum = 0;
  cin >> str;
  // cout<<str;
  int i = 0;

  while (str.size() - i) {
    from = "";
    to = "";
    for (i; str[i] != '-'; ++i) {
      from.push_back(str[i]);
    }
    i++;
    for (i; str[i] != ',' && str[i] != '\n'; ++i) {
      to.push_back(str[i]);
    }
    i++;
    long long int n1 = stoll(from);
    long long int n2 = stoll(to);
    sum += check_for_invalid_numbers(n1, n2);
    cout << n1 << "-" << n2 << endl;
  }
  cout << sum << endl;
}
// for real big input it takes too long to process output
// so i did get Time excidded error for it
//  i solved this by breaking input into 4 parts run them individual got answers
//  and then add it
// like this add ==> 29929 + 3192950894 + 9489409201 + 134938837 + 32902870 =
// 12850231731 and this is how i got correct answer
