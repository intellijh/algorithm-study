#include <bits/stdc++.h>
using namespace std;

int n, x, num;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    string bufferFlush;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s != "all" && s != "empty") {
            cin >> x;
        }

        if (s == "add") num |= 1 << x;
        else if (s == "remove") num &= ~(1 << x);
        else if (s == "check") {
            bool chk = num & (1 << x);
            cout << chk << '\n';
        }
        else if (s == "toggle") num ^= 1 << x;
        else if (s == "all") num = (1 << 21) - 1;
        else if (s == "empty") num = 0;
    }

    return 0;
}