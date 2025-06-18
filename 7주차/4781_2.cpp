#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, m, c, dp[10004], m1, m2, p;

int main() {

    while (true) {
        scanf("%d %d.%d", &n, &m1, &m2);
        m = m1 * 100 + m2;
        if (n == 0 && m == 0) break;
        fill(dp, dp + 10004, 0);
        
        int ret = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            p = m1 * 100 + m2;

            for (int j = p; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - p] + c);
                ret = max(ret, dp[j]);
            }
        }
        
        printf("%d\n", ret);
    }

    return 0;
}