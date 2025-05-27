#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
        if (pq.size() > 5) {
            pq.pop();
        }
    }

    while (pq.size()) {
        ret.push_back(pq.top()); pq.pop();
    }
    reverse(ret.begin(), ret.end());
    
    for (int i = 0; i < 5; i++) {
        cout << ret[i] << '\n';
    }

    return 0;
}