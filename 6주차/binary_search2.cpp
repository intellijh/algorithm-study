#include <bits/stdc++.h>
using namespace std;

int a[300000], temp, ret = 1987654321, n, m, l = 1, r, mid;

bool check(int target) {
    int ret = 0;

    for (int i = 0; i < m; i++) {
        ret += a[i] / target;
        if (a[i] % target) ret++;
    }

    return ret <= n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    while (l <= r) {
        mid = (l + r) / 2;
        
        if (check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}