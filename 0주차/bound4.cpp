#include <bits/stdc++.h>
using namespace std;

vector<int> a = {1, 2, 3, 3, 3, 3, 4, 100};

int main() {
	cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3) << '\n';
	return 0;
}
