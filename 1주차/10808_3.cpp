#include <bits/stdc++.h>
using namespace std;

int ret[26];
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        ret[s[i] -'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << ret[i] << " ";
    }
    return 0;
}