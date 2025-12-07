

#include <fstream>
#include <bits/stdc++.h>
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
    string Tmax = "";
    int max1 = 0, i1 = 0;
    int max2 = 0, i2 = 0;
    int max3 = 0, i3 = 0;

    int max4 = 0, i4 = 0;
    int max5 = 0, i5 = 0;
    int max6 = 0, i6 = 0;

    int max7 = 0, i7 = 0;
    int max8 = 0, i8 = 0;
    int max9 = 0, i9 = 0;

    int max10 = 0, i10 = 0;
    int max11 = 0, i11 = 0;
    int max12 = 0, i12 = 0;

    for (int i = 0; i < bank_J.size() - 11; ++i) {
      if (bank_J[i] > max1) {
        max1 = bank_J[i];
        i1 = i + 1;
      }
    }
    Tmax.push_back(max1);
    for (int i = i1; i < bank_J.size() - 10; ++i) {
      if (bank_J[i] > max2) {
        max2 = bank_J[i];
        i2 = i + 1;
      }
    }
    Tmax.push_back(max2);

    for (int i = i2; i < bank_J.size() - 9; ++i) {
      if (bank_J[i] > max3) {
        max3 = bank_J[i];
        i3 = i + 1;
      }
    }
    Tmax.push_back(max3);

    for (int i = i3; i < bank_J.size() - 8; ++i) {
      if (bank_J[i] > max4) {
        max4 = bank_J[i];
        i4 = i + 1;
      }
    }
    Tmax.push_back(max4); ////////////////////////////////////

    for (int i = i4; i < bank_J.size() - 7; ++i) {
      if (bank_J[i] > max5) {
        max5 = bank_J[i];
        i5 = i + 1;
      }
    }
    Tmax.push_back(max5);

    for (int i = i5; i < bank_J.size() - 6; ++i) {
      if (bank_J[i] > max6) {
        max6 = bank_J[i];
        i6 = i + 1;
      }
    }
    Tmax.push_back(max6);

    for (int i = i6; i < bank_J.size() - 5; ++i) {
      if (bank_J[i] > max7) {
        max7 = bank_J[i];
        i7 = i + 1;
      }
    }
    Tmax.push_back(max7);

    for (int i = i7; i < bank_J.size() - 4; ++i) {
      if (bank_J[i] > max8) {
        max8 = bank_J[i];
        i8 = i + 1;
      }
    }
    Tmax.push_back(max8);

    for (int i = i8; i < bank_J.size() - 3; ++i) {
      if (bank_J[i] > max9) {
        max9 = bank_J[i];
        i9 = i + 1;
      }
    }
    Tmax.push_back(max9);

    for (int i = i9; i < bank_J.size() - 2; ++i) {
      if (bank_J[i] > max10) {
        max10 = bank_J[i];
        i10 = i + 1;
      }
    }
    Tmax.push_back(max10);

    for (int i = i10; i < bank_J.size() - 1; ++i) {
      if (bank_J[i] > max11) {
        max11 = bank_J[i];
        i11 = i + 1;
      }
    }
    Tmax.push_back(max11);

    for (int i = i11; i < bank_J.size() - 0; ++i) {
      if (bank_J[i] > max12) {
        max12 = bank_J[i];
        i12 = i + 1;
      }
    }
    Tmax.push_back(max12);

    cout << Tmax << endl;
    sum_max += stoll(Tmax);
  }
  cout << sum_max;
}
