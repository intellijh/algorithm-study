#include <bits/stdc++.h>
using namespace std;

int n, ret = 1, from, to;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());

    from = v[0].second; to = v[0].first;
    for (int i = 1; i < n; i++) {
        if (to > v[i].second) continue;
        
        from = v[i].second; to = v[i].first; ret++;
    }
    cout << ret << '\n';
    return 0;
}