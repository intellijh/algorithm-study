#include <bits/stdc++.h>
using namespace std;

int n, k, a[10004], temp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    a[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = temp; j <= k; j++) {
            a[j] += a[j - temp];
        }
    }

    cout << a[k] << '\n';

    return 0;
}