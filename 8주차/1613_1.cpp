#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, k, s, dist[404][404], a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        dist[a][b] = -1;
        dist[b][a] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
                else if (dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
            }
        }
    }

    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }

    return 0;
}