#include <bits/stdc++.h>
using namespace std;

int N, pIndex, rpIndex;
string p, str[104], r, rp;

void solve(int index) {
    r = str[index];
    reverse(r.begin(), r.end());

    if (p.size() -1 > str[index].size()) {
        cout << "NE" << '\n';
        return;
    }

    if (p.substr(0, pIndex) == str[index].substr(0, pIndex)) {
        if (rp.substr(0, rpIndex) == r.substr(0, rpIndex)) {
            cout << "DA" << '\n';
            return;
        }
    }

    cout << "NE" << '\n';
}

int main() {
    cin >> N;
    cin >> p;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    rp = p;
    reverse(rp.begin(), rp.end());

    pIndex = p.find("*");
    rpIndex = rp.find("*");

    for (int i = 0; i < N; i++) {
        solve(i);
    }

    return 0;
}