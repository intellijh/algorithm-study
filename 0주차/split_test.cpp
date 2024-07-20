#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, string delimiter) {
	vector<string> ret;
	string token = "";
	long long pos;
	while((pos = str.find(delimiter)) != string.npos) {
		token = str.substr(0, num);
		ret.push_back(token);
		str.erase(0, num + delimiter.length());		
	}
	ret.push_back(str);
	return ret;
}
	
int main() {
	string temp = "ad:bc:kk";
	vector<string> v =split(temp, ":");
	for (string i : v) cout << i << '\n';
	return 0;	
}
