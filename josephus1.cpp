#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> kids(n,1);

    int removed = 0;
    int pos = 0;
    bool skipped = false;
    while (removed < n) {
        pos++;
        pos %= n;
        if (kids[pos]) {
            if (!skipped) {
                skipped = true;
                continue;
            }
            if (pos == 0) cout << n << " ";
            else cout << pos << " ";
            kids[pos] = 0;
            removed++;
            skipped = false;
        }
    }
}