// --- Part Two ---
//
// The clerk quickly discovers that there are still invalid IDs in the ranges in
// your list. Maybe the young Elf was doing other silly patterns as well?
//
// Now, an ID is invalid if it is made only of some sequence of digits repeated
// at least twice. So, 12341234 (1234 two times), 123123123 (123 three times),
// 1212121212 (12 five times), and 1111111 (1 seven times) are all invalid IDs.
//
// From the same example as before:
//
//     11-22 still has two invalid IDs, 11 and 22.
//     95-115 now has two invalid IDs, 99 and 111.
//     998-1012 now has two invalid IDs, 999 and 1010.
//     1188511880-1188511890 still has one invalid ID, 1188511885.
//     222220-222224 still has one invalid ID, 222222.
//     1698522-1698528 still contains no invalid IDs.
//     446443-446449 still has one invalid ID, 446446.
//     38593856-38593862 still has one invalid ID, 38593859.
//     565653-565659 now has one invalid ID, 565656.
//     824824821-824824827 now has one invalid ID, 824824824.
//     2121212118-2121212124 now has one invalid ID, 2121212121.

#include <bits/stdc++.h>
using namespace std;
int product_of_invalid_numbers = 1, no_of_digits = 0;

long long int check_for_invalid_numbers(long long int from, long long int to) {

  long int sum = 0;

  for (long long int i = from; i <= to; ++i) {

    string num = to_string(i);
    no_of_digits = num.size();

      int repeating =1;
    while(repeating<=(no_of_digits/2)){
       if (no_of_digits % repeating != 0) {
        repeating++;
        continue;
    }
      //divide it in no_of_digits/repeating parts and see if are equal

      vector<string> parts(no_of_digits / repeating);
      for (int j = 0; j < no_of_digits/repeating; ++j){
        parts[j]=num.substr(j*repeating,repeating);
      }
      //check
      int fl=1;
      for (int k = 0; k < (no_of_digits/repeating)-1; ++k){
        if (parts[k]!=parts[k+1])
        {
            fl=0;
        }
      }

      if(fl){
        cout<<"Invalid :"<<num<<endl;
        sum+=i;
        cout<<"range :"<<sum<<endl;
        break;
      }
    repeating++; 

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
    cout<<sum<<endl;
    // cout<<n1<<"-"<<n2 << endl;
  }
  cout<<endl<<endl << "sum : " << sum << endl;
}

// solved this took a very long time 
