#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, m, k, t, a, b, cnt[304], dp[304][304];
vector<pair<int, int>> v;

int go(int idx, int cnt, int prev) {
    if (idx == v.size()) return 0;

    int& ret = dp[idx][cnt];
    if (ret) return ret;

    int cost = max(0, t - v[idx].second);
    int real_cost = (prev >= cost) ? 0 : cost - prev;

    if (cost == 0) prev = 0;
    if (cnt - real_cost >= 0) {
        return ret = max(go(idx + 1, cnt - real_cost, cost) + v[idx].first, go(idx + 1, cnt, prev));
    } else {
        return ret = go(idx + 1, cnt, prev);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> t;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) {
            cnt[j] = min(t, ++cnt[j]);
        }
    }

    int temp = cnt[1];
    int count = 1;
    for (int i = 2; i <= n; i++) {
        if (temp != cnt[i]) {
            v.push_back({count, temp});
            count = 0;
            temp = cnt[i];
        }
        count++;
    }
    v.push_back({count, temp});
    cout << go(0, k, 0) << '\n';

    return 0;
}