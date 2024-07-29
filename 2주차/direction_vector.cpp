#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ny, nx;

int main() {
    int y = 0, x = 0;

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        cout << "(" << ny << ", " << nx << ")" << '\n';
    }
    return 0;
}