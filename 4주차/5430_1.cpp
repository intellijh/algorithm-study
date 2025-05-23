#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        deque<int> dq;
        int n;
        string p, arr, num;
        char temp;
        bool r = 0, flag = 0;

        cin >> p >> n >> arr;
        arr = arr.substr(1, arr.size() - 2);
        stringstream ss(arr);

        while (getline(ss, num, ',')) {
            if (!num.empty()) {
                dq.push_back(stoi(num));
            }
        }
        
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