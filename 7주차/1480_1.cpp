#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[14], dp[11][21][1 << 13];

int go(int idx, int capa, int jew) {
    if (idx == m) return 0;

    int& ret = dp[idx][capa][jew];
    if (ret) return ret;

    ret = max(ret, go(idx + 1, c, jew));
    for (int i = 0; i < n; i++) {
        bool visited = (1 << i) & jew;
        bool isFull = (capa - a[i]) < 0;
        if (visited || isFull) continue;

        ret = max(ret, go(idx, capa - a[i], jew | (1 << i)) + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << go(0, c, 0) << '\n';

    return 0;
}