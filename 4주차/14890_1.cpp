#include <bits/stdc++.h>
using namespace std;

int n, l, a[104][104], ret, cnt, b[104][104];

void solve(int a[104][104]) {
    for (int i = 0; i < n; i++) {
        cnt = 1;

        int j;
        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++;
            else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if (j == n - 1 && cnt >= 0) ret++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];

        }
    }
    
    solve(a);
    solve(b);

    cout << ret << '\n';
    
    return 0;
}