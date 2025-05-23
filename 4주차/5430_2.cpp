#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        deque<int> dq;
        int n, x = 0;
        string p, temp;
        bool r = 0, flag = 0;

        cin >> p >> n >> temp;
        for (char c : temp) {
            if (c == '[' || c == ']') continue;
            
            if (c >= '0' && c <= '9') x = x * 10 + c - '0';
            else {
                dq.push_back(x);
                x = 0;
            }
        }
        if (x > 0) dq.push_back(x);
        
        for (char c : p) {
            if (c == 'R') r ^= 1;
            else {
                if (dq.size()) {
                    if (r) dq.pop_back();
                    else dq.pop_front();
                } else {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag) cout << "error" << '\n';
        else {
            if (r) {
                reverse(dq.begin(), dq.end());
            }
            cout << '[';
            int dqSize = dq.size();
            for (int i = 0; i < dqSize; i++) {
                if (i == dqSize - 1) cout << dq[i]; 
                else cout << dq[i] << ',';
            } 
            cout << "]\n";
        }
    }
 
    return 0;
}