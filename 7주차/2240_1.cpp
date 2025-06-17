#include <bits/stdc++.h>
using namespace std;

int n, m, a[1004], dp[1001][2][31];

int go(int idx, int pos, int cnt) {
    if (cnt < 0) return -1e9;
    if (idx == n) return 0;

    int& ret = dp[idx][pos][cnt];
    if (ret) return ret;
    
    return ret = max(go(idx + 1, pos, cnt), go(idx + 1, pos ^ 1, cnt - 1)) + (a[idx] == pos);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    cout << max(go(0, 0, m), go(0, 1, m - 1)) << '\n';

    return 0;
}