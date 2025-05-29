#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, a[24][24], r, ret = INF;
bool visited[24];

vector<int> b;

int go(vector<int>& x, vector<int>& y) {
    pair<int, int> ret;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            ret.first += a[x[i]][x[j]];
            ret.second += a[y[i]][y[j]];
        }
    }
    return abs(ret.first - ret.second);
}

void combi1(int start, vector<int>& b) {
    if (b.size() == r) {
        vector<int> start, link;
        for (int i = 0; i < n; i++) {
            if (visited[i]) start.push_back(i);
            else link.push_back(i);
        }
        ret = min(ret, go(start, link));
        return;
    }
    
    for (int i = start + 1; i < n; i++) {
        visited[i] = 1;
        b.push_back(i);
        combi1(i, b);
        visited[i] = 0;
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    r = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    combi1(-1, b);

    cout << ret << '\n';
    return 0;
}