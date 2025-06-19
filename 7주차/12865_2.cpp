#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, k, w, v, dp[100004][104], visited[104];
vector<pair<int, int>> a;

int go(int weight, int idx) {
    if (weight == 0 || idx == n) return 0;

    int& ret = dp[weight][idx];
    if (ret != -1) return ret;

    ret = go(weight, idx + 1);
    if (weight - a[idx].first >= 0) {
        ret = max(ret, go(weight - a[idx].first, idx + 1) + a[idx].second);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        a.push_back({w, v});
    }

    memset(dp, -1, sizeof(dp));
    cout << go(k, 0) << '\n';

    return 0;
}