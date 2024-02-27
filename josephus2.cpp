#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<int> s;
    
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    auto it = s.begin();

    for (int i = 0; i < n; i++) {
        for (int _ = 0; _ < k%s.size(); _++) {
            it++;
            if (it == s.end()) it = s.begin();
        }
        int remove = *it;
        cout << remove << " ";
        s.erase(remove);
        it = s.upper_bound(remove);
        if (it == s.end()) it = s.begin();
    }
}