#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int n, k, q1, q2, q3, q4, dp[104][100004];
vector<pair<int, int>> v1, v2;

int go(int idx, int time) {
    if (time > k) return INF;
    if (idx == n) return 0;

    int& ret = dp[idx][time];
    if (ret) return ret;

    return ret = max(go(idx + 1, time + v1[idx].first) + v1[idx].second, go(idx + 1, time + v2[idx].first) + v2[idx].second);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> q1 >> q2 >> q3 >> q4;
        v1.push_back({q1, q2});
        v2.push_back({q3, q4});
    }

    cout << go(0, 0) << '\n';

    return 0;
}