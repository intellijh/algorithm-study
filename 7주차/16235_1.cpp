#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, k, a[14][14], b[14][14], ret;
vector<int> v[14][14];

void springSummer() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int die_tree = 0;
            vector<int> temp;
            sort(v[i][j].begin(), v[i][j].end());
            for (int z = 0; z < v[i][j].size(); z++) {
                int age = v[i][j][z];

                if (age > a[i][j]) {
                    die_tree += age / 2;
                } else {
                    a[i][j] -= age;
                    temp.push_back(age + 1);
                }
            }

            a[i][j] += die_tree;
            v[i][j] = temp;
        }
    }
}

void fall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int z = 0; z < v[i][j].size(); z++) {
                int& age = v[i][j][z];

                if (age % 5 == 0) {
                    for (int c = 0; c < 8; c++) {
                        int y = i + dy[c];
                        int x = j + dx[c];

                        if (y < 1 || x < 1 || y > n || x > n) continue;
                        v[y][x].push_back(1);
                    }
                }
            }
        }
    }  
}

void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += b[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }

    fill(&a[0][0], &a[0][0] + (14 * 14), 5);
    for (int i = 0; i < m; i++) {
        int y, x, z;
        cin >> y >> x >> z;
        v[y][x].push_back(z);
    }

    for (int i = 0; i < k; i++) {
        springSummer();
        fall();
        winter();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ret += v[i][j].size();
        }
    } 

    cout << ret << '\n';

    return 0;
}