#include <bits/stdc++.h>
using namespace std;

int n, t, temp, ret, root;
vector<int> adj[50];
bool visited[50];

void post(int here) {
    if (visited[here] == 0) {
        if (adj[here].size() > 0) {
            for (int i = 0; i < adj[here].size(); i++) {
                if (adj[here][i] == t) {
                    if (adj[here].size() == 1) {
                        ret++; 
                    }
                    return;
                }
                post(adj[here][i]);
            }
        }
        
        visited[here] = 1;
    }
}

void postOrder(int here) {
    if (visited[here] == 0) {
        if (adj[here].size() == 0) ret++;
        else {
            for (int i = 0; i < adj[here].size(); i++) {
                postOrder(adj[here][i]);
            }
        }
        
        visited[here] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1) {
            root = i;
            continue;
        }
        adj[temp].push_back(i);
    }
    cin >> t;

    post(root);
    memset(visited, 0, sizeof(visited));

    visited[t] = 1;
    postOrder(root);
    
    cout << ret << '\n';

    return 0;
}