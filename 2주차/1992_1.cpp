#include <bits/stdc++.h>
using namespace std;

int N, a[64][64];
string temp;

string quad(int y, int x, int size) {
    if (size == 1) {
        return to_string(a[y][x]);
    }
    int temp = a[y][x];
    string ret = "";
    
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (a[i][j] != temp) {
                ret += "(";
                ret += quad(y, x, size / 2);
                ret += quad(y, x + size / 2, size / 2);
                ret += quad(y + size / 2, x, size / 2);
                ret += quad(y + size / 2 , x + size / 2, size / 2);
                ret += ")";
                return ret;
            }
        }
    }
    return to_string(a[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < N; j++) {
            a[i][j] = temp[j] - '0';
        }
    }
    cout << quad(0, 0, N);
    return 0;
}