#include <bits/stdc++.h>
using namespace std;
#define y1 yyy

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret, y1, x1, y, x;
char a[1504][1504];
string s;
bool visitedBird[1504][1504];
int visited[1504][1504];
queue<pair<int, int>> q, bird;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if (s[j] == 'L') {
                y1 = i;
                x1 = j;
            }
            if (s[j] == '.' || s[j] == 'L') {
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 'X') {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }


    bird.push({y1, x1});
    visitedBird[y1][x1] = 1;
    while (true) {
        queue<pair<int, int>> temp2;
        while (bird.size()) {
            tie(y, x) = bird.front(); bird.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visitedBird[ny][nx]) continue;
                if (a[ny][nx] == 'L') {
                    cout << ret << '\n';
                    exit(0);
                } else if (a[ny][nx] == 'X') {
                    temp2.push({ny, nx});
                } else {
                    bird.push({ny, nx});
                }
                visitedBird[ny][nx] = 1;
            }
        }
        bird = temp2;


        queue<pair<int, int>> temp;

        while (q.size()) {
            tie(y, x) = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;
                if (a[ny][nx] == 'X') {
                    a[ny][nx] = '.';
                    temp.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }

        q = temp;
        ret++;
    }
    return 0;
}