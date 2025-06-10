#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, m, t, x, d, k, tmp, ret;
vector<int> v[54];
vector<pair<int, int>> temp;

void avg() {
    int sum = 0, cnt = 0;
    double average = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j]) cnt++;
            sum += v[i][j];
        }
    }

    average = (double) sum / cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (!v[i][j]) continue;

            if (v[i][j] > average) v[i][j] -= 1;
            else if (v[i][j] < average) v[i][j] += 1;
        }
    }
}

void rmv() {
    for (auto it : temp) {
        v[it.first][it.second] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    for (int i = 0; i < t; i++) {
        cin >> x >> d >> k;

        for (int j = 1; j <= n; j++) {
            if (j % x != 0) continue;

            if (d == 0) {
                rotate(v[j].rbegin(), v[j].rbegin() + k, v[j].rend());
            } else {
                rotate(v[j].begin(), v[j].begin() + k, v[j].end());
            }
        }

        for (int y = 1; y <= n; y++) {
            for (int x = 0; x < m; x++) {
                if (v[y][x] == 0) continue;
                
                if (v[y][x] == v[y][(x + 1) % m]) {
                    temp.push_back({y, x});
                    temp.push_back({y, (x + 1) % m});
                }

                if (y < n && v[y][x] == v[y + 1][x]) {
                    temp.push_back({y, x});
                    temp.push_back({y + 1, x});
                }
            }
        }
        
        if (temp.size()) rmv();
        else avg();
        temp.clear();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            ret += v[i][j];
        }
    }

    cout << ret << '\n';

    return 0;
}