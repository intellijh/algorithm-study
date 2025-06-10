#include <bits/stdc++.h>
using namespace std;

int k, n, m, psum_a[2004], psum_b[2004], a[1004], b[1004], ret;

map<int, int> mp_a, mp_b;

void cut(int s, int psum[1004], map<int, int>& mp) {
    for (int interval = 1; interval <= s; interval++) {
        for (int start = interval; start <= s + interval - 1; start++) {
            int sum = psum[start] - psum[start - interval];
            mp[sum]++;
            if (interval == s) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum_a[i] = psum_a[i - 1] + a[i];
    }
    for (int i = n + 1; i <= n * 2; i++) psum_a[i] = psum_a[i - 1] + a[i - n];
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];        
    }
    for (int i = m + 1; i <= m * 2; i++) psum_b[i] = psum_b[i - 1] + b[i - m];

    cut(n, psum_a, mp_a);
    cut(m, psum_b, mp_b);

    ret += mp_a[k] + mp_b[k];
    for (int i = 1; i <= k - 1; i++) {
        ret += mp_a[i] * mp_b[k - i];
    }

    cout << ret << '\n';

    return 0;
}