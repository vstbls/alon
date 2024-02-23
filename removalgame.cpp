#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pick(n, vector<int>(n, 0));
    vector<vector<int>> wait = pick;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pick[0][i] = x;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            int left = pick[0][j] + wait[i-1][j+1];
            int right = pick[0][j+i] + wait[i-1][j];
            pick[i][j] = max(left, right);
            wait[i][j] = left > right ? pick[i-1][j+1] : pick[i-1][j];
        }
    }

    cout << pick[n-1][0];
}
