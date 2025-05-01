#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 == s2) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}