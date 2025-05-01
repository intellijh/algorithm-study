#include <bits/stdc++.h>
using namespace std;

string s, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] + 13 > 'Z') {
                ret += (s[i] + 13) - 'Z' + 'A' - 1;
            } else {
                ret += s[i] + 13;
            }
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] + 13 > 'z') {
                ret += (s[i] + 13) - 'z' + 'a' - 1;
            } else {
                ret += s[i] + 13;
            }
        } else {
            ret += s[i];
        }
    }

    cout << ret << '\n';
    return 0;
}