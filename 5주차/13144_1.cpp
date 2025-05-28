#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100004], cnt[100004], e, s, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (e < n) {
        if (!cnt[a[e]]) {
            cnt[a[e]]++;
            e++;
        } else {
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    
    ret += (e - s) * (e - s + 1) / 2;
    cout << ret << '\n';

    return 0;
}