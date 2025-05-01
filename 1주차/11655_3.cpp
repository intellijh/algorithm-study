#include <bits/stdc++.h>
using namespace std;

string s, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ret += s[i] + 13 > 'Z' ? s[i] + 13 - 26 : s[i] + 13;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            ret += s[i] + 13 > 'z' ? s[i] + 13 - 26 : s[i] + 13;
        } else {
            ret += s[i];
        }
    }

    cout << ret << '\n';

    return 0;
}