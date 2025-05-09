#include <bits/stdc++.h>
using namespace std;

int n;
int a[66][66];
string s, ret;

string go(int y, int x, int size) {
    if (size == 1) {
        return to_string(a[y][x]);
    }

    string temp;
    char b = a[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (b != a[i][j]) {
                temp += "(";
                temp += go(y, x, size / 2);
                temp += go(y, x + size / 2, size / 2);
                temp += go(y + size / 2, x, size / 2);
                temp += go(y + size / 2, x + size / 2, size / 2);
                temp += ")";
                return temp;
            }

        }
    }
    return to_string(a[y][x]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    ret = go(0, 0, n);
    cout << ret << '\n';
    
    return 0;
}