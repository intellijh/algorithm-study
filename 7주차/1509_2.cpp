#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
string s;
int n, dp2[2504];
char a[2504];
bool dp[2504][2504];

int go(int here) {
    if (here == n) return 0;
    
    int& ret = dp2[here];
    if (ret != INF) return ret;

    for (int i = 1; here + i <= n; i++) {
        if (dp[here][i]) ret = min(ret, go(here + i) + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        a[i] = s[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) dp[i][2] = 1;
    }
    
    for (int size = 3; size <= n; size++) {
        for (int j = 0; j + size <= n; j++) {
            if (a[j] == a[j + size - 1] && dp[j + 1][size - 2] == 1) dp[j][size] = 1;
        }
    }

    fill(dp2, dp2 + 2504, INF);

    cout << go(0) << '\n';

    return 0;
}