#include <bits/stdc++.h>
using namespace std;

int a[2004], n, m, s, e;
bool dp[2004][2004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
    }

    for (int size = 2; size <= n; size++) {
        for (int i = 0; i < n - size; i++) {
            if (a[i] == a[i + size] && dp[i + 1][i + size - 1]) dp[i][i + size] = 1;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        s--; e--;
        cout << dp[s][e] << '\n';
    }

    return 0;
}