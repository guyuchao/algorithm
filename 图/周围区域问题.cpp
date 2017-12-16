#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
struct point {
	int x;
	int y;
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};
bool operator <(const point a, const point b) {
	if (a.x != b.x) { return a.x < b.x; }
	else {
		return a.y < b.y;
	}
}
int main() {
	char a[10][10];
	int len = 4;
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			cin >> a[i][j];
		}
	}
	queue<point> qu;
	set<point> visited;
	for (int j = 1; j <= len; j++) {
		if (a[1][j] == 'O'){
			qu.push(point(1, j));
			a[1][j] = 'Y';
		}
		if (a[len][j] == 'O') {
			qu.push(point(len, j));
			a[len][j] = 'Y';
		}
		if (a[j][1] == 'O') {
			qu.push(point(j, 1));
			a[j][1] = 'Y';
		}
		if (a[j][len] == 'O') {
			qu.push(point(j, len));
			a[j][len] = 'Y';
		}
	}
	while (!qu.empty()) {
		point tmp_p = qu.front();
		qu.pop();
		if (visited.count(tmp_p) != 0)continue;
		else { visited.insert(tmp_p); }
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (abs(i )== abs(j))continue;
				else {
					point now_tmp(tmp_p.x+i,tmp_p.y+j);
					if (a[now_tmp.x][now_tmp.y]=='O'&&visited.count(now_tmp) == 0) {
						a[now_tmp.x][now_tmp.y] = 'Y';
						qu.push(now_tmp);
					}
				}
			}
		}
	}
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			if (a[i][j] == 'Y')a[i][j] = 'O';
			else if (a[i][j] == 'O')a[i][j] = 'X';
			cout << a[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}