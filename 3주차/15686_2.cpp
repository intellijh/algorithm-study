#include <bits/stdc++.h>
using namespace std;

int n, m, a[54][54], ret = 987654321;
vector<pair<int, int>> h, c;
vector<int> b;

void solve() {
    int temp = 0;
    
    for (auto it : h) {
        int mn = 987654321;
        for (int i : b) {
            mn = min(mn, abs(c[i].first - it.first) + abs(c[i].second - it.second));
        }
        temp += mn;
    }
    ret = min(ret, temp);
}

void combi(int start, vector<int>& b) {
    if (b.size() == m) {
        solve();
        return;
    }

    for (int i = start + 1; i < c.size(); i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) h.push_back({i, j});
            else if (a[i][j] == 2) c.push_back({i, j});
        }
    }
    
    combi(-1, b);
    cout << ret << '\n';
    return 0;
}