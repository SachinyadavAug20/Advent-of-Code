#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) return 1;

    vector<pair<long long, long long>> ranges;
    string line;

    // read ranges until blank line
    while (getline(inputFile, line) && !line.empty()) {
        long long l = stoll(line.substr(0, line.find('-')));
        long long r = stoll(line.substr(line.find('-') + 1));
        ranges.push_back({l, r});
    }

    // sort by starting point
    sort(ranges.begin(), ranges.end());

    long long total = 0;
    long long curL = ranges[0].first;
    long long curR = ranges[0].second;

    for (int i = 1; i < ranges.size(); i++) {
        long long L = ranges[i].first;
        long long R = ranges[i].second;

        if (L <= curR + 1) {
            // overlaps or touches: merge
            curR = max(curR, R);
        } else {
            // finish previous segment
            total += (curR - curL + 1);
            curL = L;
            curR = R;
        }
    }

    // add last merged range
    total += (curR - curL + 1);

    cout << "fresh IDs = " << total << "\n";
}

