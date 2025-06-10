#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    a = v[0].first, b = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first <= b) b = max(b, v[i].second);
        else {
            ret += abs(b - a);
            a = v[i].first;
            b = v[i].second;
        }
    }
    ret += abs(b - a);

    cout << ret << '\n';
    return 0;
}