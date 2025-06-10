#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321, psum[100004], temp, idx = 1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }

    for (int i = 1; i <= n; i++) {
        temp = psum[i] - psum[i - idx];
        ret = max(ret, temp);
        if (temp >= 0) idx++;
        else idx = 1;
    }

    cout << ret << '\n';

    return 0;
}