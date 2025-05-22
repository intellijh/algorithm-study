#include <bits/stdc++.h>
using namespace std;

int n, k, a[54];
string s;
vector<string> v;

int check(int num) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & num) == a[i]) cnt++;
    }
    return cnt;
}

int go(int idx, int cnt, int num) {
    if (cnt < 0) return 0;
    if (idx == 26) return check(num);
    
    int ret = go(idx + 1, cnt - 1, num | (1 << idx));
    if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a') {
        ret = max(ret, go(idx + 1, cnt, num));
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char j : s) {
            a[i] |= 1 << (j - 'a');
        }
    }

    cout << go(0, k, 0) << '\n';

    return 0;
}