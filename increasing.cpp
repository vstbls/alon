#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    long total = 0;
    for (int i = 1; i < n; i++) {
        int diff = t[i-1] - t[i];
        if (diff > 0) {
            total += diff;
            t[i] = t[i-1];
        }
    }

    cout << total;
}