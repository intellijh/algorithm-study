#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, dp[34][34];

ll go(int w, int nw) {
    if (w == 0 && nw == 0) return 1;

    ll& ret = dp[w][nw];
    if (ret) return ret; 
    
    if (w > 0) ret += go(w - 1, nw + 1);
    if (nw > 0) ret += go(w, nw - 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (cin >> n) {
        if (n == 0) break;

        memset(dp, 0, sizeof(dp));
        cout << go(n, 0) << '\n';
    }

    return 0;
}