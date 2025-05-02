#include <bits/stdc++.h>
using namespace std;

int n, k , mx = -987654321;
int a[100004], psum[100004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];

        if (i >= k) {
            mx = max(psum[i] - psum[i - k], mx);
        }
    }

    cout << mx << '\n';

    return 0;
}