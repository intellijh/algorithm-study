#include <bits/stdc++.h>
using namespace std;

int n, m, temp, dp[42];
bool a[42];

int go(int idx) {
    if (idx >= n) return 1;
    if (a[idx]) return go(idx + 1);

    int& ret = dp[idx];
    if (ret != -1) return ret;

    ret = 0;
    if (a[idx] == idx) {
        return ret += go(idx + 1);
    }

    if (!a[idx + 1]) ret += go(idx + 1) + go(idx + 2);
    else ret += go(idx + 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        a[temp] = 1;
    }

    memset(dp, -1, sizeof(dp));
    cout << go(1) << '\n';

    return 0;
}