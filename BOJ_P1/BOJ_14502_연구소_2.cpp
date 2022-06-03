#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row, col;

int ans = 0;

int map[9][9];
int wall[3];

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;

vector<pair<int, int>> zero;

void reset() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 4) {
				map[i][j] = 0;
			}
		}
	}
}

int count_zero() {
	int temp_count_zero = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				temp_count_zero += 1;
			}
		}
	}
	return temp_count_zero;
}

void spread() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int now_row = q.front().first;
		int now_col = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int new_row = now_row + dr[k];
			int new_col = now_col + dc[k];
			if (new_row < 0 || new_row >= row || new_col < 0 || new_col >= col) {
				continue;
			}
			if (map[new_row][new_col] == 0) {
				map[new_row][new_col] = 4;
				q.push(make_pair(new_row, new_col));
			}
		}
	}
}

void dfs(int dep, int x) {
	if (dep == 3) {

		map[zero[wall[0]].first][zero[wall[0]].second] = 1;
		map[zero[wall[1]].first][zero[wall[1]].second] = 1;
		map[zero[wall[2]].first][zero[wall[2]].second] = 1;

		spread();

		int temp_ans = count_zero();

		if (ans < temp_ans) {
			ans = temp_ans;
		}

		map[zero[wall[0]].first][zero[wall[0]].second] = 0;
		map[zero[wall[1]].first][zero[wall[1]].second] = 0;
		map[zero[wall[2]].first][zero[wall[2]].second] = 0;

		reset();

		return;
	}

	for (int i = x; i < zero.size(); i++) {
		wall[dep] = i;
		dfs(dep + 1, i + 1);
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);

	cout << ans;
}