#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> sums;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int size = sums.size();
        for (int i = 0; i < size; i++) sums.push_back(sums[i] + x);
        sums.push_back(x);
    }

    sort(sums.begin(), sums.end());

    long x = 1;
    for (auto s : sums) {
        if (s > x) break;
        x = s+1;
    }

    cout << x;
}