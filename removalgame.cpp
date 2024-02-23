#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long>> pick(n, vector<long>(n, 0));
    vector<vector<long>> wait = pick;

    for (int i = 0; i < n; i++) {
        long x;
        cin >> x;
        pick[0][i] = x;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            long left = pick[0][j] + wait[i-1][j+1];
            long right = pick[0][j+i] + wait[i-1][j];
            pick[i][j] = max(left, right);
            wait[i][j] = min(pick[i-1][j+1], pick[i-1][j]);
        }
    }

    cout << pick[n-1][0];
}
