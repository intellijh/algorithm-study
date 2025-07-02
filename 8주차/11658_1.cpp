#include <bits/stdc++.h>
using namespace std;
#define max_n 1025

int n, m, a[max_n][max_n], tree[max_n][max_n];

void update(int y, int x, int value) {
    while (y <= n) {
        int i = x;
        while (i <= n) {
            tree[y][i] += value;
            i += i & -i;
        }
        y += y & -y;
    }
}

int sum(int y, int x) {
    int ret = 0;
    while (y > 0) {
        int i = x;
        while (i > 0) {
            ret += tree[y][i];
            i -= i & -i;
        }
        y -= y & -y;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            update(i, j, a[i][j]);
        }
    }

    int w, y1, y2, x1, x2, c;
    for (int i = 0; i < m; i++) {
        cin >> w;
        if (w == 0) {
            cin >> y1 >> x1 >> c;
            int temp = c - a[y1][x1];
            update(y1, x1, temp);
            a[y1][x1] = c;
        } else {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1) << '\n';
        }
    }

    return 0;
}