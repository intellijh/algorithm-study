#include <bits/stdc++.h>
using namespace std;

int n, x;
string s;
map<int, int> mp;

void add(int x) {
    mp[x] = 1;
}

void remove(int x) {
    mp[x] = 0;
}

void check(int x) {
    if (mp[x] == 1) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void toggle(int x) {
    if (mp[x] == 1) mp[x] = 0;
    else mp[x] = 1;
}

void all() {
    for (int i = 1 ; i <= 20; i++) {
        mp[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    string bufferFlush;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s != "all" && s != "empty") {
            cin >> x;
        }

        if (s == "add") add(x);
        else if (s == "remove") remove(x);
        else if (s == "check") check(x);
        else if (s == "toggle") toggle(x);
        else if (s == "all") all();
        else if (s == "empty") mp.clear();
    }

    return 0;
}