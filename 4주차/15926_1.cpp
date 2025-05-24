#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;

    int l = 0, r = 0;
    for (char c : s) {
        if (c == '(') l++;
        else r++;
        if (l == r) ret = max(ret, l + r);
        else if (r > l) l = r = 0;
    }

    l = r = 0;
    reverse(s.begin(), s.end());
    for (char c : s) {
        if (c == ')') r++;
        else l++;
        if (l == r) ret = max(ret, l + r);
        else if (l > r) l = r = 0;
    }

    cout << ret << '\n';
}
