#include <bits/stdc++.h>
using namespace std;

int N, M, r = 2, cnt, a[15001];
vector<int> v;

void combi(int start, vector<int> &b) {
    if (b.size() == 2) {
        if (b[0] + b[1] == M) cnt++;
        return;
    }

    for (int i = start + 1; i < N; i++) {
        b.push_back(a[i]);
        combi(i, b);
        b.pop_back();
    }
    return;
}

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
        cin >> a[i];
    }

    combi(-1, v);
    cout << cnt << '\n';
    return 0;
}