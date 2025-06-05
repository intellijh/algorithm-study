#include <bits/stdc++.h>
using namespace std;

int n, ret, a[24][24];
bool visited[24][24];

void count(int b[24][24]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, b[i][j]);
        }
    }
}

void slide(int a[24][24]) {
    int temp[24][24];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) continue;
            if (temp[i][cnt] == 0) temp[i][cnt] = a[i][j];
            else if (temp[i][cnt] == a[i][j]) temp[i][cnt] *= 2, cnt++;
            else cnt++, temp[i][cnt] = a[i][j]; 
        }
    }
    memcpy(a, temp, sizeof(temp));
}

void rotate(int a[24][24]) {
    int temp[24][24];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = a[n - j - 1][i];
        }
    }
    memcpy(a, temp, sizeof(temp));
}

void go(int cnt, int b[24][24]) {
    if (cnt == 5) {
        count(b);
        return;
    }

    for (int i = 0 ; i < 4; i++) {
        int a[24][24];
        memcpy(a, b, sizeof(a));
        slide(a);
        go(cnt + 1, a);
        rotate(b);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0, a);

    cout << ret << '\n';

    return 0;
}