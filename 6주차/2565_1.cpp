#include <bits/stdc++.h>
using namespace std;

int n, a, b, lis[504], len;
vector<pair<int, int>> p;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        int num = p[i].second;
        auto lower_pos = lower_bound(lis, lis + len, num);
        if (*lower_pos == 0) len++;
        *lower_pos = num;
    }

    cout << n - len << '\n';

    return 0;
}