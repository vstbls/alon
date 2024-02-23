#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
    int n,k;
    cin >> n >> k;

    vector<int> x;
    for (int _ = 0; _ < n; _++) {
        int i;
        cin >> i;
        x.push_back(i);
    }

    long count = 0;
    map<int, int> m;
    int sub_a = 0;
    for (int sub_b = 0; sub_b < x.size(); sub_b++) {
        int i = x[sub_b];
        if (!m[i]) m[i] = 0;
        m[i]++;
        while (m.size() > k) {
            int j = x[sub_a];
            m[j]--;
            if (!m[j]) m.erase(j);
            sub_a++;
        }
        count += sub_b-sub_a+1;
    }
    cout << count;
}