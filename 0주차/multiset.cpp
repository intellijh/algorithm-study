#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main() {
	for (int i = 5; i >= 1; i--) {
		s.insert(i);
		s.insert(i);
	}
	
	for (int it : s) cout << it << ' ';
	cout << '\n';
	return 0;
}
