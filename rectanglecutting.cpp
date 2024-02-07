#include <iostream>
#include <vector>

using namespace std;

int main () {
    int a,b;
    cin >> a >> b;
    if (a>b) swap(a,b);

    vector<vector<int>> cuts(a+1,vector<int>(b+1,0));

    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= b; j++) {
            if (i == j) {
                cuts[i][j] = 1;
                continue;
            }
            int least = i*j;
            for (int k = 1; k < i; k++) {
                int cut_sum = cuts[k][j] + cuts[i-k][j];
                if (cut_sum < least) least = cut_sum;
            }
            for (int k = 1; k < j; k++) {
                int cut_sum = cuts[i][k] + cuts[i][j-k];
                if (cut_sum < least) least = cut_sum;
            }
            cuts[i][j] = least;
            if (j <= a) cuts[j][i] = least;
        }
    }
    cout << cuts[a][b]-1;
}