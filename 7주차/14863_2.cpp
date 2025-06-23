#include <bits/stdc++.h>
using namespace std;

int n, k, q1, q2, q3, q4, dp[100004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> q1 >> q2 >> q3 >> q4;
        
        for (int j = k; j >= 0; j--) {
            if (dp[j]) {
                if (j + q1 <= k) dp[j + q1] = max(dp[j + q1], dp[j] + q2);
                if (j + q3 <= k) dp[j + q3] = max(dp[j + q3], dp[j] + q4);
            }
            
            dp[j] = 0;
        }
    }

    cout << *max_element(dp, dp + 100004) - 1 << '\n';
    return 0;
}