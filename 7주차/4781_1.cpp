#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, c, dp[10004];
double m, p;
vector<pair<int, int>> v;

int go(int money, int prev) {
    if (money < 0) return -prev;
    if (money == 0) return 0;

    int& ret = dp[money];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < v.size(); i++) {
        ret = max(ret, go(money - v[i].second, v[i].first) + v[i].first);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        fill(dp, dp + 10004, -1);
        v.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> c >> p;
            v.push_back({c, (int) (p * 100 + 0.5)});
        }
        
        cout << go((int) (m * 100 + 0.5), 0) << '\n';
    }

    return 0;
}