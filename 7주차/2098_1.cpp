#include <bits/stdc++.h>
using namespace std;
#define MAX_N 16

const int INF = 1e9;
int n, a[MAX_N][MAX_N], dp[MAX_N][1 << MAX_N];

int go(int here, int visited) {
    if (visited == (1 << n) - 1) {
        return a[here][0] ? a[here][0] : INF;
    }

    int& ret = dp[here][visited];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        if (a[here][i] == 0) continue;

        ret = min(ret, go(i, visited | (1 << i)) + a[here][i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << '\n';

    return 0;
}