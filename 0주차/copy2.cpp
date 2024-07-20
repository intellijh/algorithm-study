#include <bits/stdc++.h>
using namespace std;

const int n = 3;

int main() {
	int v[n] = {1, 2, 3};
	int ret[n];
	
	copy(v, v + n, ret);
	cout << ret[1] << '\n';
	
	ret[1] = 100;
	cout << ret[1] << '\n';
	cout << v[1] << '\n';
	return 0;
}
