#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<tuple<int,int,int>> times;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        times.push_back({a,b,i});
    }

    sort(times.begin(), times.end());

    priority_queue<pair<int,int>> q;
    int max = 1;
    vector<pair<int,int>> rooms;
    for (auto t: times) {
        auto [a, b, c] = t;
        if (q.empty()) {
            q.push({-b,1});
            rooms.push_back({c,1});
            continue;
        }
        if (a <= -q.top().first) {
            q.push({-b,q.size()+1});
            rooms.push_back({c,q.size()});
            if (q.size() > max) max = q.size();
        } else {
            int room = q.top().second;
            q.pop();
            q.push({-b, room});
            rooms.push_back({c,room});
        }
    }
    sort(rooms.begin(), rooms.end());
    cout << max << "\n";
    for (auto r: rooms) cout << r.second << " ";
}