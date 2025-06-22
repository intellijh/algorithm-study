#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
string s;
int n, dp2[2504];
char a[2504];
bool dp[2504][2504];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        a[i] = s[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
    }
    
    for (int size = 2; size <= n; size++) {
        for (int j = 0; j < n - size; j++) {
            if (a[j] == a[j + size] && dp[j + 1][j + size -1] == 1) dp[j][j + size] = 1;
        }
    }

    fill(dp2, dp2 + 2504, INF);
    dp2[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[j - 1][i - 1]) {
                dp2[i] = min(dp2[i], dp2[j - 1] + 1);
            }
        }
    }


    cout << dp2[n] << '\n';

    return 0;
}