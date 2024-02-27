#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
    int n, k;
    cin >> n >> k;

    indexed_set s;
    
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    int pos = 0;

    for (int i = 0; i < n; i++) {
        pos = (pos+k)%s.size();
        auto it = s.find_by_order(pos);
        int remove = *it;
        cout << remove << " ";
        s.erase(remove);
        it = s.upper_bound(remove);
        if (it == s.end()) it = s.begin();
    }
}