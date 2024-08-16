#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0, 0};
const int dx[] = {0, 1, 0, - 1, 0};
int n, a[14][14], visited[14][14], ret = 20000;

int check(int y, int x) {
    for (int i = 0 ; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (visited[ny][nx] == 1) return true;
    }

    for (int i = 0 ; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
    }
    return false;
}

void nono(int y, int x) {
    for (int i = 0 ; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

int calc() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) sum += a[i][j];
        }
    }
    return sum;
}

void go(int here,int cnt) {
    if (cnt == 3) {
        ret = min(ret, calc());
        return;
    }

    for (int i = here; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (check(i, j)) continue;
            go(i, cnt + 1);
            nono(i, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(1, 0);
    cout << ret;
    return 0;
}