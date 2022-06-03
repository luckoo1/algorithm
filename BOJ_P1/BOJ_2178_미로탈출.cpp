#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int row, col;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int map[101][101];
int distan[101][101];
bool check[101][101];

queue <pair<int, int>> q;

struct point {
	int r;
	int c;
};

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	struct point p1;

	p1.r = 0;
	p1.c = 0;
	check[0][0] = true;
	distan[0][0] = 1;

	q.push(make_pair(p1.r, p1.c));

	while (!q.empty()) {
		int now_r = q.front().first;
		int now_c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {

			int move_r = now_r + dr[k];
			int move_c = now_c + dc[k];

			if (move_r < 0 || move_c < 0 || move_r >= row || move_c >= col) {
				continue;
			}
			if (check[move_r][move_c] == true || map[move_r][move_c] == 0) {
				continue;
			}

			q.push(make_pair(move_r, move_c));
			check[move_r][move_c] = true;
			distan[move_r][move_c] = distan[now_r][now_c] + 1;
		}
	}

	cout << distan[row - 1][col - 1];
}
