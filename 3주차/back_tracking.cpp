#include <bits/stdc++.h>
using namespace std;

int N, a[104], ret, cnt;
const int mod = 11;

void go(int idx, int sum) {
    if (ret == 10) return;
    if (idx == N) {
        ret = max(ret, sum % mod);
        cnt++;
        return;
    }
    go(idx + 1, sum + a[idx]);
    go(idx + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    go(0, 0);
    cout << ret << '\n';
    cout << cnt << '\n';
    return 0;
}