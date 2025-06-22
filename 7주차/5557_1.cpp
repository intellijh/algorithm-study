#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[104], dp[104][21];

ll go(ll idx, ll sum) {
    if (sum < 0 || sum > 20) return 0;
    if (idx == n - 1) {
        if (sum == a[n - 1]) return 1;
        else return 0;
    }

    ll& ret = dp[idx][sum];
    if (ret != -1) return ret;

    ret = 0;
    return ret = go(idx + 1, sum + a[idx]) + go(idx + 1, sum - a[idx]); 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << go(1, a[0]) << '\n';

    return 0;
}