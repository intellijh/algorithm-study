#include <bits/stdc++.h>
using namespace std;

int n, l, r, rr;
string p, s;

void go(int it) {
    l = 0;
    r = p.size() - 1;
    rr = s.size() - 1;

    if (s.size() < p.size() - 1) {
        cout << "NE" << '\n';
        return;
    }
    
    while (l < it) {
        if (s[l] != p[l]) {
            cout << "NE" << '\n';
            return;
        }
        l++;
    }
    
    while (r > it) {
        if (s[rr] != p[r]) {
            cout << "NE" << '\n';
            return;
        }
        r--;
        rr--;
    }
    cout << "DA" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> p;
    auto it = p.find('*');
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        go(it);
    }

    return 0;
}