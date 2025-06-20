#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool che[20];
double a, b, dp[20][20][20];

double go(int t1, int t2, int cnt) {
    if (cnt == 18) {
        if (che[t1] || che[t2]) return 1.0;
        return 0.0;
    }

    double& ret = dp[t1][t2][cnt];
    if (ret > -0.5) return ret;

    ret = 0.0;
    ret += go(t1 + 1, t2, cnt + 1) * a * (1 - b);
    ret += go(t1, t2 + 1, cnt + 1) * (1 - a) * b;
    ret += go(t1 + 1, t2 + 1, cnt + 1) * a * b;
    ret += go(t1, t2, cnt + 1) * (1 - a) * (1 - b);
    return ret;
}

void era() {
    fill(che, che + 20, 1);
    che[0] = 0; che[1] = 0;
    for (int i = 2; i <= 19; i++) {
        if (che[i]) continue;
        for (int j = i + i; j <= 19; j += i) {
            che[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);

    cin >> a >> b;
    a /= 100; b /= 100;

    era();
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0) << '\n';

    return 0;
}