#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int ret = v[0].first + v[0].second;
    for (int i = 1; i < n; i++) {
        ret = max(ret, v[i].first);
        ret += v[i].second;   
    }

    cout << ret << '\n';

    return 0;
}