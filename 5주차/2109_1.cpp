#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, ret, mx, visited[10004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        mx = max(mx, v[i].second);
    }
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < n; i++) {
        for (int j = v[i].second; j >= 1; j--) {
            if (visited[j]) continue;
            else {visited[j] = v[i].first; break;}
        }
    }

    for (int i = 1; i <= mx; i++) {
        ret += visited[i];
    }

    cout << ret << '\n';
    return 0;
}