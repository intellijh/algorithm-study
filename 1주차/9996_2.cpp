#include <bits/stdc++.h>
using namespace std;

int N, pIndex, rpIndex;
string p, str[104], pre, suf;

int main() {
    cin >> N;
    cin >> p;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }
    int pos = p.find("*");
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);

    for (int i = 0; i < N; i++) {
        if (str[i].size() < pre.size() + suf.size()) {
            cout << "NE" << '\n';
        } else {
            if (pre == str[i].substr(0, pre.size()) && suf == str[i].substr(str[i].size() - suf.size())) cout << "DA" << '\n';
            else cout << "NE" << '\n';
        }
    }

    return 0;
}