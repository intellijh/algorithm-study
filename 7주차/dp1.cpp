#include <bits/stdc++.h>
using namespace std;

int n, m, a[104], dp[104][2][34];

int go(int idx, int tree, int cnt) {
    if (cnt < 0) return -1e9;
    if (idx == n) return 0;

    int& ret = dp[idx][tree][cnt];
    if (ret != -1) return ret;

    return max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (a[idx] == tree);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    memset(dp, -1, sizeof(dp));
    cout << max(go(0, 0, m), go(0, 1, m - 1)) << '\n';

    return 0;
}