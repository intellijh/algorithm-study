#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int n, k, w, v, dp[100004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(dp, dp + 100004, INF);
    dp[0] = 0;
    cin >> n >> k;

    int ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;

        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
            ret = max(ret, dp[j]);
        }
    }

    cout << ret << '\n';

    return 0;
}