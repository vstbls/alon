#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> movies;

    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        movies.push_back({b,a});
    }

    sort(movies.begin(), movies.end());

    int counter = 1;
    int end = movies[0].first;
    for (auto m: movies) {
        if (m.second >= end) {
            counter++;
            end = m.first;
        }
    }

    cout << counter;
}