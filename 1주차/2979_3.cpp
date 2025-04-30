#include <bits/stdc++.h>
using namespace std;

int a, b, c, ret;
int cnt[104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        for (int j = t1; j < t2; j++) {
            cnt[j]++;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == 0) continue;
        else if (cnt[i] == 1) ret += a;
        else if (cnt[i] == 2) ret += b * 2;
        else if (cnt[i] == 3) ret += c * 3;
    }

    cout << ret << '\n';
    return 0;
}