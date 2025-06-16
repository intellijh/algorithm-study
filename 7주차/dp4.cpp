#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, dp[10004];

int main() {

    cin >> t;
    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (j - i >= 0) dp[j] += dp[j - i];
        }
    }
    cout << dp[t] << '\n';

    return 0;
}