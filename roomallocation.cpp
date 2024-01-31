#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<pair<int,int>> times;
    for (int _ = 0; _ < n; _++) {
        int a,b;
        cin >> a >> b;
        times.push_back({a,b});
    }

    sort(times.begin(), times.end());

    priority_queue<pair<int,int>> q;
    int max = 1;
    vector<int> rooms;
    for (auto t: times) {
        auto [a, b] = t;
        if (q.empty()) {
            q.push({-b,1});
            rooms.push_back(1);
            continue;
        }
        if (a <= -q.top().first) {
            q.push({-b,q.size()+1});
            rooms.push_back(q.size());
            if (q.size() > max) max = q.size();
        } else {
            int room = q.top().second;
            q.pop();
            q.push({-b, room});
            rooms.push_back(room);
        }
    }
    cout << max << "\n";
    for (auto r: rooms) cout << r << " ";
}