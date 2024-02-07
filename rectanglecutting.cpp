#include <iostream>
#include <vector>

using namespace std;

int main () {
    int a,b;
    cin >> a >> b;
    if (a>b) swap(a,b);

    vector<vector<int>> squares(a+1,vector<int>(b+1,0));

    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= b; j++) {
            int least = i*j;
            for (int k = 1; k <= i; k++) {
                int square_sum = squares[k][j-k] + squares[i-k][j] + 1;
                if (square_sum < least) least = square_sum;
            }
            squares[i][j] = least;
            if (j <= a) squares[j][i] = least;
        }
    }
    cout << squares[a][b]-1;
}