#include <bits/stdc++.h>
using namespace std;

struct Q {
    int s, i, p;
} a[54];
int n, dp[1004][1004];
bool visited[54];

int go(int s, int i) {
    int& ret = dp[s][i];
    if (ret != -1) return ret;

    int p = 0;
    vector<int> v;
    ret = 0;
    for (int k = 0; k < n; k++) {
        if (s >= a[k].s || i >= a[k].i) {
            ret++;
            if (!visited[k]) {
                visited[k] = 1;
                p += a[k].p;
                v.push_back(k);
            }
        }
    }

    for (int k = 0; k <= p; k++) {
        int next_s = min(1000, s + p - k);
        int next_i = min(1000, i + k);
        ret = max(ret, go(next_s, next_i));
    }

    for (int here : v) {
        visited[here] = 0;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].i >> a[i].p;
    }

    fill(&dp[0][0], &dp[0][0] + 1004 * 1004, -1);
    cout << go(1, 1) << '\n';

    return 0;
}