#include <bits/stdc++.h>
using namespace std;

struct Num {
    int a, b, c;
};

int N, C, temp;
vector<Num> ret;
map<int, int> mp, order;

bool cmp(Num a, Num b) {
    if (a.b == b.b) {
        return a.c < b.c;
    }
    return a.b > b.b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        
        if (mp[temp] == 0) order[temp] = i;
        mp[temp]++;
    }


    for (auto it : mp) {
        Num num = {it.first, it.second, order[it.first]};
        ret.push_back(num);
    }

    sort(ret.begin(), ret.end(), cmp);
    for (Num num : ret) {
        for (int i = 0; i < num.b; i++) {
            cout << num.a << " ";
        }
    }

    return 0;
}