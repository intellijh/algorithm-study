#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, c, a[31];
vector<int> v1, v2;
ll ret;

void go(int s, int e, vector<int>& v, int sum) {
    if (sum > c) return;
    if (s == e + 1) {
        v.push_back(sum);
        return;
    }

    go(s + 1, e, v, sum + a[s]);
    go(s + 1, e, v, sum);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    go(0, n / 2 - 1, v1, 0);
    go(n / 2, n - 1, v2, 0);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int b : v2) {
        if (c - b >= 0) {
            ret += upper_bound(v1.begin(), v1.end(), c - b) - v1.begin();
        }
    }
    cout << ret << '\n';

    return 0;
}