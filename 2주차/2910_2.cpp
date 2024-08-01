#include <bits/stdc++.h>
using namespace std;

int N, C, temp;
vector<pair<int, int>> ret;
map<int, int> mp, order;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return order[a.second] < order[b.second];
    }
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        
        if (mp[temp] == 0) order[temp] = i;
        mp[temp]++;
    }


    for (auto it : mp) {
        ret.push_back({it.second, it.first});
    }

    sort(ret.begin(), ret.end(), cmp);
    for (auto it : ret) {
        for (int i = 0; i < it.first; i++) {
            cout << it.second << " ";
        }
    }

    return 0;
}