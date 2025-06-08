#include <bits/stdc++.h>
using namespace std;

const int INF = 1987654321;

int n, l, ret, a, b, idx, temp;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (v[i].second <= idx) continue;

        if (idx <= v[i].first) {
            temp = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
            idx = v[i].first + temp * l;
        } else {
            temp = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0);
            idx = idx + temp * l;
        }
        ret += temp;
    }

    cout << ret << '\n';
    return 0;
}