#include <bits/stdc++.h>
using namespace std;
#define y1 yyy

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, y1, x1, y2, x2, y, x;
char a[304][304];
string s;
int visited[304][304];
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    int cnt = 0;
    q.push({y1, x1});
    while (a[y2][x2] != '0') {
        queue<pair<int, int>> temp;
        cnt++;

        while (q.size()) {
            tie(y, x) = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;
                if (a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                } else {
                    q.push({ny, nx});
                }
                
                visited[ny][nx] = cnt;
            }
        }

        q = temp;
    }

    cout << visited[y2][x2] << '\n';

    return 0;
}