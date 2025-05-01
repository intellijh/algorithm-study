#include <bits/stdc++.h>
using namespace std;

string s;
int m, l, r;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    m = s.size() / 2;
    if (s.size() % 2 == 0) {
        l = m - 1;
        r = m;
    } else {
        l = m - 1;
        r = m + 1;
    }

    while (l >= 0 && r < s.size()) {
        if (s[l] != s[r]) {
            cout << 0 << '\n';
            exit(0);
        }
        l--;
        r++;
    }
    cout << 1 << '\n';
    return 0;
}