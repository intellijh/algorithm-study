#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
	if (mp.find(1) == mp.end()) {
		mp[1] = 2;
	}
	for (auto it : mp) cout << it.first << " : " << it.second << '\n';
	
	return 0;
}
