#include <bits/stdc++.h>
using namespace std;

int t, temp, ret, n, m;
vector<int> v;

int binary_search(int target) {
    int l = 0, r = v.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> temp;
            if (binary_search(temp) == -1) cout << "큰돌이는 까먹었어!\n";
            else cout << "큰돌이는 기억해!\n";
        }
    }


    return 0;
}