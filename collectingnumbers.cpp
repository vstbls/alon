#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n+1, 0);
    v[0] = 1;

    int counter = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x] = 1;
        if (!v[x-1]) counter++;
    }

    cout << ++counter;
}