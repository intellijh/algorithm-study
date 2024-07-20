#include <bits/stdc++.h>
using namespace std;

vector<int> v = {3, 10, 4, 11};

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	sort(v.begin(), v.end(), cmp);
	for (int i : v) cout << i << ' ';
}
