    #include <bits/stdc++.h>
    using namespace std;

    int N, m[4], a[20][5], ret = 987654321;
    vector<vector<int>> retV;

    void check(vector<int> v) {
        vector<int> r(5, 0);
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < 5; j++) {
                r[j] += a[v[i]][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            if (r[i] < m[i]) return;
        }

        if (ret > r[4]) {
            ret = r[4];
            retV.clear();
            retV.push_back(v);
        } else if (ret == r[4]) {
            retV.push_back(v);
        }
    }

    void combi(int start, int k, vector<int> v) {
        if (v.size() == k) {
            check(v);
            return;
        }

        for (int i = start + 1; i < N; i++) {
            v.push_back(i);
            combi(i, k, v);
            v.pop_back();
        }
    }

    int main() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);

        cin >> N;
        for (int i = 0; i < 4; i++) cin >> m[i];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) cin >> a[i][j];
        }

        for (int k = 1; k <= N; k++) {
            vector<int> v;
            combi(-1, k, v);
        }

        if (ret == 987654321) {
            cout << -1;
        } else {
            cout << ret << '\n';
            sort(retV.begin(), retV.end());
            for (int i : retV[0]) {
                cout << i + 1 << " ";
            }
        }
        return 0;
    }