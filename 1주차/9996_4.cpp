#include <bits/stdc++.h>
using namespace std;

int n;
string s, p, pre, suf;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> p;
    int pos = p.find('*');
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (pre.size() + suf.size() > s.size()) {
            cout << "NE" << '\n';
        } else {
            if (s.substr(0, pos) == pre && s.substr(s.size() - suf.size()) == suf) {
                cout << "DA" << '\n';
            } else {
                cout << "NE" << '\n';
            }
        }
    }

    return 0;
}