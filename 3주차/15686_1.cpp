#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[54][54], result[54][54], ret = 1000000000;
vector<pair<int, int>> homeList, originChicList, chicList;


void go() {
    fill(&result[0][0], &result[0][0] + 54 * 54, 10000);
    for (pair<int, int> it : homeList) {
        for (pair<int, int> p : chicList) {
            int temp = abs(it.first - p.first) + abs(it.second - p.second);
            result[it.first][it.second] = min(temp, result[it.first][it.second]);
        }
    }

    int sum = 0;
    for (pair<int, int> it : homeList) {
        sum += result[it.first][it.second];
    }

    ret = min(ret, sum);
}

void combi(int start, vector<int> b) {
    if (b.size() == M) {
        for (int i : b) {
            chicList.push_back(originChicList[i]);
        }

        go();
        chicList.clear();
        return;
    }

    for (int i = start + 1; i < originChicList.size(); i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) homeList.push_back({i, j});
            else if (a[i][j] == 2) originChicList.push_back({i, j});
        }
    }

    vector<int> b;
    combi(-1, b);

    cout << ret;
    return 0;
}