#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> kids(n,1);

    int removed = 0;
    int pos = 0;
    int skipped = 0;
    while (removed < n) {
        pos++;
        pos %= n;
        if (kids[pos]) {
            if (skipped < k) {
                skipped++;
                continue;
            }
            if (pos == 0) cout << n << " ";
            else cout << pos << " ";
            kids[pos] = 0;
            removed++;
            skipped = 0;
        }
    }
}