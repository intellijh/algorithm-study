#include <bits/stdc++.h>
using namespace std;

int n, m, a[104][104], ret[104][104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(ret, -1, sizeof(ret));
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            
            if (temp == 'c') {
                a[i][j] = 1;
                ret[i][j] = 0;
            } else {
                a[i][j] = 0;   
            }
        }
    }

    for (int k = 1; k <= m - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j > 0; j--) {
                a[i][j] = a[i][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (ret[i][j] == -1 && a[i][j] == 1) {
                    ret[i][j] = k;
                }
            }
        }
    }


    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}