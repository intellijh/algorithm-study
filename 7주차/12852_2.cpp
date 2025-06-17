#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001
#define prev ppp

const int INF = 1e9;
int n, dp[MAX_N];

void go(int here) {
    if (here == 0) return;
    cout << here << " ";

    if (here % 3 == 0 && dp[here] == dp[here / 3] + 1) go(here / 3);
    else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1) go(here / 2);
    else go(here - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    fill(dp, dp + MAX_N, INF);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    cout << dp[n] << '\n';
    go(n);

    return 0;
}