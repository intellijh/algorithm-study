#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

ll n, m, a, b, d, dist1[4004], dist2[4004][2], ret;
vector<pair<ll, ll>> adj[4004];

struct S {
    ll d, here;
    bool type;

    bool operator > (const S& other) const {
        return d > other.d;
    }
};

void dijkstra1() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
    pq.push({0, 1});

    while (pq.size()) {
        ll here_cost = pq.top().first;
        ll u = pq.top().second; pq.pop();

        if (dist1[u] != here_cost) continue;
        
        for (auto there : adj[u]) {
            ll new_cost = here_cost + there.first;
            ll v = there.second;
            if (dist1[v] > new_cost) {
                dist1[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

void dijkstra2() {
    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, 1, 0});
    
    while (pq.size()) {
        S s = pq.top(); pq.pop();
        ll here_cost = s.d;
        ll u = s.here;
        ll type = s.type;

        if (dist2[u][type] != here_cost) continue;
        
        for (auto there : adj[u]) {
            ll new_cost;
            ll v = there.second;
            if (!type) new_cost = here_cost + there.first / 2;
            else new_cost = here_cost + there.first * 2;
            if (dist2[v][!type] > new_cost) {
                dist2[v][!type] = new_cost;
                pq.push({new_cost, v, !type});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        d *= 2;
        adj[a].push_back({d, b});
        adj[b].push_back({d, a});

    }
    fill(dist1, dist1 + 4004, INF);
    fill(&dist2[0][0], &dist2[0][0] + 4004 * 2, INF);
    dist1[1] = 0;
    dist2[1][0] = 0;

    dijkstra1();
    dijkstra2();

    for (int i = 2; i <= n; i++) {
        ll d = min(dist2[i][0], dist2[i][1]);
        if (dist1[i] < d) ret++;
    }

    cout << ret << '\n';

    return 0;
}