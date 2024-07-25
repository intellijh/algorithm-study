#include <bits/stdc++.h>
using namespace std;

int N, M, temp, cnt;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    //갑옷의 최대가 100,000
    //둘의 최대합이 200,000
    if (M > 200000) {
        cout << 0;
        exit(0);
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i] + v[j] == M) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}