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
        if (last == -1) {
            last = 0;
            m[x] = 0;
            continue;
        }
        if (m.size() == k && !m.count(x)) {
            pair<int,int> lowest = *m.begin();
            for (auto p : m) {
                if (p.second < lowest.first) lowest = p;
            }
            last = lowest.second+1;
            m.erase(lowest.first);
        }
        m[x] = i;
        counter += i-last+1;
    }
    cout << counter;
}