#include <bits/stdc++.h>
using namespace std;

int n, k, a[104], dp[10004];

int go(int sum) {
    if (sum > k) return 1e9;
    if (sum == k) return 0;

    int& ret = dp[sum];
    if (ret) return ret;

    ret = 1e9;
    for (int i = 0; i < n; i++) {
        ret = min(ret, go(sum + a[i]) + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ret = go(0);
    if (ret == 1e9) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}