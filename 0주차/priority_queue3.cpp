#include <bits/stdc++.h>
using namespace std;

struct Point {
	int y, x;
};

struct cmp {
	bool operator()(Point a, Point b) {
		return a.x < b.x;
	}
};

priority_queue<Point, vector<Point>, cmp> pq;

int main() {
	pq.push({1, 1});
	pq.push({2, 2});
	pq.push({3, 3});
	pq.push({4, 4});
	pq.push({5, 5});
	pq.push({6, 6});
	cout << pq.top().x << '\n';
	return 0;
}
