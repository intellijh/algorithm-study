#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int h[24], joy[24], n, dp[104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> joy[i];

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 100; j > h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + joy[i]);
        }
    }

    cout << dp[100] << '\n';

    return 0;
}