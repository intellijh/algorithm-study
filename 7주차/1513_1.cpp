#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000007;
int a[54][54], n, m, c, t1, t2, dp[54][54][54][54];
vector<pair<int, int>> v;

int go(int y, int x, int cnt, int prev) {
    if (y > n || x > m) return 0;
    if (y == n && x == m) {
        if (cnt == 0 && a[y][x] == 0) return 1;
        if (cnt == 1 && a[y][x] > prev) return 1;
        return 0;
    }
    
    int& ret = dp[y][x][cnt][prev];
    if (ret != -1) return ret;

    ret = 0;
    if (a[y][x] == 0) {
        ret = (go(y, x + 1, cnt, prev) + go(y + 1, x, cnt, prev)) % mod;
    } else if (a[y][x] > prev) {
        ret = (go(y, x + 1, cnt - 1, a[y][x]) + go(y + 1, x, cnt - 1, a[y][x])) % mod;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        cin >> t1 >> t2;
        a[t1][t2] = i;
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= c; i++) {
        cout << go(1, 1, i, 0) << " ";
    }

    return 0;
}