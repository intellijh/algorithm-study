#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321, a, sum;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum += a;
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
    }

    cout << ret << '\n';

    return 0;
}