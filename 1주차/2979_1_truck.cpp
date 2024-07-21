#include <bits/stdc++.h>
using namespace std;

int a, b, c, sum;
int temp1, temp2;
vector<pair<int, int>> v;

int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }

    int minNum = 101, maxNum = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++) {
        minNum = min(v[i].first, minNum);
        maxNum = max(v[i].second, maxNum);
    }
    for (int i = 0; i < 3; i++) {
        v[i].first -= minNum;
        v[i].second -= minNum;
    }
    maxNum -= minNum;
    int cnt[maxNum];
    fill(cnt, cnt + maxNum, 0);

    for (int i = 0; i < 3; i++) {
        for (int j = v[i].first; j < v[i].second; j++) {
            cnt[j]++;
        }
    }

    for (int i = 0; i < maxNum; i++) {
        switch (cnt[i]) {
            case 1: {
                sum += a;
                break;
            }
            case 2: {
                sum += 2 * b;
                break;
            }
            case 3: {
                sum += 3 * c;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}