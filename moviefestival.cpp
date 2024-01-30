#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a,b});
    }

    sort(movies.begin(), movies.end());
    int offset = 0;
    int count = 0;
    
    while (1) {
        int end = movies[offset].second;
        for (int i = offset; i < movies.size(); i++) {
            if (movies[i].first >= end) break;
            if (movies[i].second < end) end = movies[i].second;
        }

        vector<pair<int,int>> earliest;
        for (int i = offset; i < movies.size(); i++) {
            auto m = movies[i];
            if (m.first < end) {
                int overlaps = 0;
                overlaps += i-offset;
                for (int j = i; j < movies.size(); j++) {
                    auto m2 = movies[j];
                    if (m2.first < m.second <= m2.second) overlaps++;
                    else break;
                }
                earliest.push_back({overlaps,i});
            }
            else break;
        }
        
        sort(earliest.begin(), earliest.end());
        
        offset = earliest[0].second;// fix offset, it doesn't point to the next movies rn
        end = movies[offset].second;
        for (int i = offset; i < movies.size(); i++) {
            offset = i;
            if (movies[i].first >= end) break;
        }
        count++;
        if (movies[movies.size()-1].first < end) break;
    }

    cout << count;
}