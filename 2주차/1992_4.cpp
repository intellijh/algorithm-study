#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 0, 1, 1};
const int dx[] = {0, 1, 0, 1};
string s, ret;
int n, a[64][64];

string quad(int y, int x, int size) {
    if (size == 1) {
        return to_string(a[y][x]);
    }

    string temp = "";

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * size / 2;
        int nx = x + dx[i] * size / 2;
        temp += quad(ny, nx, size / 2);
    }

    if (temp == "0000") {
        return "0";
    } else if (temp == "1111") {
        return "1";
    } else {
        return "(" + temp + ")";
    }
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

    ret = quad(0, 0, n);
    cout << ret << '\n';

    return 0;
}