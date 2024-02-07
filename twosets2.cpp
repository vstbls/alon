#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    long s = 0;
    for (int i = 1; i < n+1; i++) {
        s += i;
    }

    if (s%2 != 0) {
        cout << 0;
        return 0;
    }

    vector<long long> v(s+1,0);
    v[0] = 1;

    for (long i = 1; i < n+1; i++) {
        for (long j = v.size()-1; j > -1; j--) {
            if (v[j]) v[j+i] = (v[j+i]%(1000000007))+(v[j]%(1000000007));
        }
    }

    cout << v[s/2]/2;
}