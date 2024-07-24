#include <bits/stdc++.h>
using namespace std;

int N, K, mx = -10000004, temp, sum;
vector<int> t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        t.push_back(temp);
    }

    for (int i = 0; i < N - K + 1; i++) {
        if (i == 0) {
            sum = accumulate(t.begin() + i, t.begin() + i + K, 0);
        } else {
            sum = sum - *(t.begin() + i -1) + *(t.begin() + i + K - 1);
        }
        mx = max(mx, sum);
    }
    cout << mx;
    return 0;
}