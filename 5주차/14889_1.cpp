#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, a[24][24], r1, r2 = 2, ret = INF;
bool visited[24][24];

vector<int> b;

int combi2(int start, vector<int>& b, vector<int>& bb) {
    int r = 0;
    if (bb.size() == r2) {
        for (int i = 0; i < n; i++) {
            visited[b[bb[0]]][i] = 1;
            visited[i][b[bb[0]]] = 1;            
            visited[b[bb[1]]][i] = 1;
            visited[i][b[bb[1]]] = 1;
        }

        return a[b[bb[0]]][b[bb[1]]] + a[b[bb[1]]][b[bb[0]]];
    }

    for (int i = start + 1; i < n / 2; i++) {
        bb.push_back(i);
        r += combi2(i, b, bb);
        bb.pop_back();
    }
    return r;
}

void combi1(int start, vector<int>& b) {
    if (b.size() == r1) {
        vector<int> bb;
        fill(&visited[0][0], &visited[0][0] + 24 * 24, 0);
        int temp = combi2(-1, b, bb);
        int temp2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) temp2 += a[i][j];
            }
        }
        ret = min(ret, abs(temp - temp2));
        return;
    }
    
    for (int i = start + 1; i < n; i++) {
        b.push_back(i);
        combi1(i, b);
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    r1 = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    combi1(-1, b);

    cout << ret << '\n';
    return 0;
}