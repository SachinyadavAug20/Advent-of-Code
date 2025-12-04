#include <bits/stdc++.h>
using namespace std;
int current_state = 50,btw_zeros=0;
int rotate(char p, int r) {
  if (p == 'L') {

    if ((current_state - r) % 100 < 0) {
      if(current_state!=0){
      btw_zeros=btw_zeros+(((r - current_state)/100+1));  
      }
      
    current_state = (current_state - r) % 100;
      current_state = current_state + 100;
    }
    else{
      current_state=current_state-r;
    }

  } else if (p == 'R') {
    if(current_state+r>100){

      btw_zeros+=((r + current_state)/100);
    }
    current_state = (current_state + r) % 100;
  }
  return current_state;
}
int main() {
  string input;
  char p;
  int r, no_of_zeros = 0;
  while (true) {
    cin >> input;
    p = input[0];
    r = stoi(input.erase(0, 1));
    // cout<<r<<endl<<p<<endl;

    if (p != 'L' && p != 'R') {
      break;
    }
    rotate(p, r);
    if (current_state == 0) {
      no_of_zeros++;
    }

    cout << current_state<<" ";
      cout<<"no_of_zeros:"<<no_of_zeros<<" || "<<"btw_zeros:"<<btw_zeros<<endl;
  }
  cout << no_of_zeros<<"|"<<btw_zeros << endl;
  return 0;
}
//Doing ARRAAY way is better
//
