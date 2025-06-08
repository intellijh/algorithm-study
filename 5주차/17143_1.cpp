#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int n, m, k, ret, shark[104][104], temp[104][104];

struct S {
    int y, x, s, dir, z, death;
} a[104 * 104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y--; a[i].x--; a[i].dir--;

        if (a[i].dir <= 1) a[i].s %= (2 * (n - 1));
        else a[i].s %= (2 * (m - 1));

        shark[a[i].y][a[i].x] = i;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (shark[j][i]) {
                a[shark[j][i]].death = 1;
                ret += a[shark[j][i]].z;
                shark[j][i] = 0;
                break;
            }
        }
        
        for (int j = 1; j <= k; j++) {
            if (a[j].death) continue;
            
            int y = a[j].y;
            int x = a[j].x;
            int s = a[j].s;
            int d = a[j].dir;
            int ny, nx;
            
            while (1) {
                ny = y + s * dy[d];
                nx = x + s * dx[d];
                
                if (ny >= 0 && nx >= 0 && ny < n && nx < m) break;
                
                if (d <= 1) {
                    if (ny < 0) {
                        s -= y;
                        y = 0;
                    } else {
                        s -= n - 1 - y;
                        y = n - 1;
                    }
                } else {
                    if (nx < 0) {
                        s -= x;
                        x = 0;
                    } else {
                        s -= m - 1 - x;
                        x = m - 1;
                    }
                }
                
                d ^= 1;
            }
            
            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].z < a[j].z) {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = j;
                } else {
                    a[j].death = 1;
                }
            } else temp[ny][nx] = j;
            
            a[j].y = ny;
            a[j].x = nx;
            a[j].dir = d;
        }
        
        memcpy(shark, temp, sizeof(temp));
        memset(temp, 0, sizeof(temp));
    }
    
    cout << ret << '\n';
    return 0;
}