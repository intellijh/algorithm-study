#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 0, 1, 1};
const int dx[] = {0, 1, 0, 1};
int N;
string a[64][64], s;

string quad(int y, int x, int size) {
    if (size == 1) {
        return a[y][x];
    }

    string ret = "";
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * size / 2;
        int nx = x + dx[i] * size / 2;
        ret += quad(ny, nx, size / 2);        
    }
    
    if (ret == "0000") return "0";
    else if (ret == "1111") return "1";
    else return "(" + ret + ")";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            a[i][j] = s[j];
        }
    }

    cout << quad(0, 0, N);
    return 0;
}