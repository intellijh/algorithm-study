#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, k, a[10004], temp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(a, a + 10004, INF);
    a[0] = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = temp; j <= k; j++) {
            a[j] = min(a[j], a[j - temp] + 1);
        }
    }

    if (a[k] == INF) cout << -1 << '\n';
    else cout << a[k] << '\n';

    return 0;
}