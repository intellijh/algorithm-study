#include <bits/stdc++.h>
using namespace std;

int n, a[14], b[4], mx = -1987654321, mn = 1987654321;

int solve(int here, int op, int cnt) {
    if (op == 0) return here + a[cnt];
    else if (op == 1) return here - a[cnt];
    else if (op == 2) return here * a[cnt];
    else return here / a[cnt];
}

void go(int here, int cnt) {
    if (cnt == n) {
        mx = max(mx, here);;
        mn = min(mn, here);;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (b[i] > 0) {
            b[i]--;
            go(solve(here, i, cnt), cnt + 1);
            b[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> b[i];

    go(a[0], 1);
    
    cout << mx << '\n';
    cout << mn << '\n';
    return 0;
}