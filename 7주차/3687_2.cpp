#include <bits/stdc++.h>
using namespace std;

string INF;
string mx;
int t, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[104];

string str_min(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return min(s1, s2);
    } else {
        return s1.size() > s2.size() ? s2 : s1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for (int i = 0; i <= 50; i++) INF += "9";
    cin >> t;
    while (t--) {
        cin >> n;
        mx = "";

        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) mx += "1";
        } else {
            mx = "7";
            for (int i = 0; i < (n - 3) / 2; i++) mx += "1";
        }

        fill(dp, dp + 104, INF);
        dp[0] = "";
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                if (i - a[j] < 0) continue;
                if (dp[i - a[j]] == "" && j == 0) continue;
                dp[i] = str_min(dp[i], dp[i - a[j]] + to_string(j));
            }
        }


        cout << dp[n] << " ";
        cout << mx << '\n';
    }

    return 0;
}