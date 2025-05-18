#include <bits/stdc++.h>
using namespace std;

int x, y, m, k, n, ret = 4;
int a[34][34];

bool check() {
    for (int i = 1; i <= m; i++) {
        int start = i;
        for (int j = 1; j <= n; j++) {
            if (a[j][start]) start++;
            else if (a[j][start - 1]) start--;
        }
        if (start != i) return false;
    }
    return true;
}

void go(int here, int count) {
    if (count > 3) return;
    if (check()) {
        ret = min(ret, count);
        return;
    }

    for (int i = here; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] || a[i][j - 1] || a[i][j + 1]) continue;
            a[i][j] = 1;
            go(i, count + 1);
            a[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> y >> x;
        a[y][x] = 1;
    }

    go(1, 0);


    if (ret > 3) cout << -1 <<'\n';
    else cout << ret << '\n';

    return 0;
}