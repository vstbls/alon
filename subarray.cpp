#include <iostream>
#include <map>

using namespace std;

int main () {
    int n,k;
    cin >> n >> k;

    map<int, int> m;

    long counter = 1;
    int last = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (last = -1) {
            last = 0;
            m[x] = 0;
            continue;
        }
        if (m.count(x)) {
            counter += i-m[last];
        } else {
            if (m.size() <= k) {
                m[x] = i;
                counter += i-last;
            } else {
            }
        }
    }
}