#include <bits/stdc++.h>
using namespace std;

int n, m, temp, cnt;
map<int, int> mp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        mp[temp]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        mp[temp]++;
    }

    for (auto it : mp) {
        if (it.second == 1) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}