#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    long sum = 0;
    for (int i = 1; i <= n; i++) sum += i;

    if (sum % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> v1;
    vector<int> v2;
    long v1_sum = 0;

    for (int i = n; i > 0; i--) {
        if (v1_sum + i <= sum/2) {
            v1.push_back(i);
            v1_sum += i;
        } else {
            v2.push_back(i);
        }
    }

    cout << v1.size() << "\n";
    for (int i: v1) cout << i << " ";
    cout << "\n" << v2.size() << "\n";
    for (int i: v2) cout << i << " ";
}