#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimeter) {
	vector<string> ret;
	auto start = 0;
	auto end = input.find(delimeter);
	
	while (end != string::npos) {
		ret.push_back(input.substr(start, end - start));
		start = end + delimeter.size();
		end = input.find(delimeter, start);
	}
	ret.push_back(input.substr(start));
	return ret;
}

int main() {
	string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!", d = " ";
	vector<string> a = split(s, d);
	for (string b : a) cout << b << '\n'; 
}
