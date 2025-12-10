// --- Day 6: Trash Compactor ---
//
// After helping the Elves in the kitchen, you were taking a break and helping
// them re-enact a movie scene when you over-enthusiastically jumped into the
// garbage chute!
//
// A brief fall later, you find yourself in a garbage smasher. Unfortunately,
// the door's been magnetically sealed.
//
// As you try to find a way out, you are approached by a family of cephalopods!
// They're pretty sure they can get the door open, but it will take some time.
// While you wait, they're curious if you can help the youngest cephalopod with
// her math homework.
//
// Cephalopod math doesn't look that different from normal math. The math
// worksheet (your puzzle input) consists of a list of problems; each problem
// has a group of numbers that need to be either added (+) or multiplied (*)
// together.
//
// However, the problems are arranged a little strangely; they seem to be
// presented next to each other in a very long horizontal list. For example:
//
// 123 328  51 64
//  45 64  387 23
//   6 98  215 314
// *   +   *   +
//
// Each problem's numbers are arranged vertically; at the bottom of the problem
// is the symbol for the operation that needs to be performed. Problems are
// separated by a full column of only spaces. The left/right alignment of
// numbers within each problem can be ignored.
//
// So, this worksheet contains four problems:
//
//     123 * 45 * 6 = 33210
//     328 + 64 + 98 = 490
//     51 * 387 * 215 = 4243455
//     64 + 23 + 314 = 401
//
// To check their work, cephalopod students are given the grand total of adding
// together all of the answers to the individual problems. In this worksheet,
// the grand total is 33210 + 490 + 4243455 + 401 = 4277556.
//
// Of course, the actual worksheet is much wider. You'll need to make sure to
// unroll it completely so that you can read the problems clearly.
//
// Solve the problems on the math worksheet. What is the grand total found by
// adding together all of the answers to the individual problems?

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Unable to open file input.txt";
        return 1; // Exit with error code
    }
    string nums[300];
    int no_of_nums = 0;
    // take ranges here
    do {
        string line;
        getline(inputFile, line);
        if (line.empty()) {
            break;
        }
        nums[no_of_nums] = line;
        no_of_nums++;
    } while (true);

    vector<int> arr[1000];
    string line, num = "";
    for (int i = 0; i < no_of_nums - 1; i++) {
        line = nums[i];
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == ' ') {
                if (num.size() != 0) {
                    arr[i].push_back(stoi(num));
                    num = "";
                }
                continue;
            } else if (line[j] == '\n') {
                break;
            }
            num.push_back(line[j]);
        }
        if (num.size() != 0) {
            arr[i].push_back(stoi(num));
        }
    }

    vector<char> ope;
    for (int i = 0; i < nums[no_of_nums - 1].size(); i++) {

        if (nums[no_of_nums - 1][i] == ' ' || nums[no_of_nums - 1][i] == '\n') {

            continue;
        }
        ope.push_back(nums[no_of_nums - 1][i]);
    }
    for (int i = 0; i < no_of_nums - 1; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    long long int Tsum = 0, sum = 0, Tpro = 0, pro = 1;

    for (int i = 0; i < ope.size(); i++) {
        if (ope[i] == '+') {
            sum = 0;
            for (int j = 0; j < no_of_nums - 1; j++) {
                sum += arr[j][i];
            }
            Tsum += sum;

        } else if (ope[i] == '*') {
            pro = 1;
            for (int j = 0; j < no_of_nums - 1; j++) {
                pro *= arr[j][i];
            }
            Tpro += pro;
        }
    }
    cout << endl;
    cout << "grand total : " << Tsum << " + " << Tpro << " = " << Tsum + Tpro
        << endl;
}
//this code works for sample input but fails and gives wrong answer in realinput buz real input has special characters like \r \t and trailling spaces etc so leads to wrong garbage value but i got rddit soln which works 

