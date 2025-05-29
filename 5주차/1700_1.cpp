#include <bits/stdc++.h>
using namespace std;

int n, k, ret, a[104], visited[104], cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        int temp = a[i];
        if (visited[temp]) continue;
        
        if (cnt < n) {
            visited[temp] = 1;
            cnt++;
            continue;
        }

        int mmx = -1, next = -1;
        for (int j = 1; j <= k; j++) {
            if (visited[j]) {
                int mx = -1;
                for (int l = i + 1; l <= k; l++) {
                    if (a[l] == j) {
                        mx = l;
                        break;
                    }
                }

                if (mx == -1) {
                    next = j;
                    break;
                }

                if (mx > mmx) {
                    mmx = mx;
                    next = j;
                }
            }
        }
        visited[next] = 0; visited[temp] = 1; ret++;
    }

    cout << ret << '\n';

    return 0;
}