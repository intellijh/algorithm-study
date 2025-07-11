#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, a, b;

struct Cacher {
    int id, max_time, cacher_id;
    
    bool operator< (const Cacher& other) const {
        if (max_time == other.max_time) {
            return cacher_id > other.cacher_id;
        }
        return max_time > other.max_time;
    }
};
vector<Cacher> v;

bool cmp(const Cacher& a, const Cacher& b) {
    if (a.max_time == b.max_time) {
        return a.cacher_id > b.cacher_id;
    }
    return a.max_time < b.max_time;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    priority_queue<Cacher> pq;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (i < k) {
            pq.push({a, b, i});
            continue;
        }
        
        Cacher c = pq.top();
        v.push_back(c);
        pq.push({a, c.max_time + b, c.cacher_id});
        pq.pop();
    }
    while (pq.size()) {
        v.push_back(pq.top()); pq.pop();
    }

    sort(v.begin(), v.end(), cmp);
    ll ret = 0;
    for (int i = 1; i <= v.size(); i++) {
        ret += 1LL * i * v[i - 1].id;
    }
    cout << ret << '\n';

    return 0;
}