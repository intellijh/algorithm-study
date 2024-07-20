#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
	cin >> n;
	cin >> m;
	int temp = 0;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
//			v[i].push_back(temp);
			v[i][j] = temp;
		}
	}
	
	for (auto it : v) {
		for (int i : it) cout << i << " ";
		cout << '\n';
	}
	return 0;
}
