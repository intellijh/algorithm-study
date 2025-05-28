#include <bits/stdc++.h>
using namespace std;

int n, ret, temp;
bool che[4000004];
deque<int> dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (che[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            che[j] = 1;
        }
    }

    for (int i = n; i >= 2; i--) {
        if (che[i]) continue;
        temp = 0;
        dq.push_back(i);
        for (int i = 0; i < dq.size(); i++) {
            temp += dq[i];
        }
        
        if (temp == n) ret++, dq.pop_front();
        else if (temp > n) dq.pop_front();
    }

    cout << ret << '\n';

    return 0;
}