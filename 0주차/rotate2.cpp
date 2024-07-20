#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6};
	rotate(v.rbegin(), v.rbegin() + 1, v.rend());
	for (int i : v) cout << i << ' ';
	return 0;
}
