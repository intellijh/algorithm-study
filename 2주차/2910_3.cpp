#include <bits/stdc++.h>
using namespace std;

int n, c, temp;
map<int, int> mp, mp_order;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>&  b) {
    if (a.first == b.first) {
        return mp_order[a.second] < mp_order[b.second];
    }
    
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        if (mp[temp] == 0) {
            mp_order[temp] = i + 1;
        }
        mp[temp]++;
    }

    for (auto it : mp) {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), cmp);
    
    for (auto it : v) {
        for (int i = 0; i < it.first; i++) {
            cout << it.second << " ";
        }
    }

    return 0;
}