#include <bits/stdc++.h>
using namespace std;

int n, ret, l, r, a[4000004], p, sum;
bool che[4000004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (che[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            che[j] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (che[i]) continue;
        a[p++] = i;
    }

    while (1) {
        if (sum >= n) sum -= a[l++];
        else if (p == r) break;
        else sum += a[r++];
        if (sum == n) ret++;
    }

    cout << ret << '\n';
    return 0;
}