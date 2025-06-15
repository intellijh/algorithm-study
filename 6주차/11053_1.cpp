#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int a[1004], cnt[1004], n, ret = 1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(cnt, cnt + 1004, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
            }

            ret = max(ret, cnt[i]);
        }
    }

    cout << ret << '\n';
    return 0;
}