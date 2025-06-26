#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int a, b, n, w, dp[1004][1004], px[1004], py[1004];

int dist(int a, int b) {
    return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int go(int a, int b) {
    if (a == w + 1 || b == w + 1) return 0;

    int& ret = dp[a][b];
    if (ret != INF) return ret;
    
    int next = max(a, b) + 1;
    return ret = min(go(a, next) + dist(b, next), go(next, b) + dist(a, next));
}

void trace() {
    int a = 0, b = 1;
    
    for (int i = 2; i < w + 2; i++) {
        if (dp[i][b] + dist(a, i) < dp[a][i] + dist(b, i)) {
            cout << 1 << '\n';
            a = i;
        } else {
            cout << 2 << '\n';
            b = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> w;
    for (int i = 2; i < w + 2; i++) {
        cin >> a >> b;
        px[i] = a; py[i] = b;
    }
    px[0] = 1; py[0] = 1;
    px[1] = n; py[1] = n;

    fill(&dp[0][0], &dp[0][0] + 1004 * 1004, INF);

    cout << go(0, 1) << '\n';
    trace();
    
    return 0;
}