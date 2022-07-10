#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int map[21][21];
int visit[21][21];
int n;
bool check(int r, int c, int d1, int d2) {
	if (d1 >= 1 && d2 >= 1) {
		if (r + d1 + d2 <= n) {
			if (1 <= c - d1) {
				if (c + d2 <= n) {
					return true;
				}
			}
		}
	}
	return false;
}

void line(int r, int c, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		visit[r + i][c - i] = 5;
		visit[r + d2 + i][c + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		visit[r + i][c + i] = 5;
		visit[r + d1 + i][c - d1 + i] = 5;
	}


}

void num1(int r, int c, int d1, int d2) {
	for (int i = 1; i < r + d1; i++) {
		for (int j = 1; j <= c; j++) {
			if (visit[i][j] == 5)
				break;
			else {
				visit[i][j] = 1;
			}
		}
	}
}
void num2(int r, int c, int d1, int d2) {
	for (int i = 1; i <= r + d2; i++) {
		for (int j = n; j > c; j--) {
			if (visit[i][j] == 5)
				break;
			else {
				visit[i][j] = 2;
			}
		}
	}
}

void num3(int r, int c, int d1, int d2) {
	for (int i = r+d1; i <= n; i++) {
		for (int j = 1; j < c-d1+d2; j++) {
			if (visit[i][j] == 5)
				break;
			else {
				visit[i][j] = 3;
			}
		}
	}
}

void num4(int r, int c, int d1, int d2) {
	for (int i = r + d2+1; i <= n; i++) {
		for (int j = n; j >= c - d1 + d2; j--) {
			if (visit[i][j] == 5)
				break;
			else {
				visit[i][j] = 4;
			}
		}
	}
}
int sum[6];
int maxv = 0;
int minv = 987654321;
int ans = 987654321;
void cal() {
	maxv = 0;
	minv = 987654321;
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 1) {
				sum[1] += map[i][j];
			}
			else if (visit[i][j] == 2) {
				sum[2] += map[i][j];
			}
			else if (visit[i][j] == 3) {
				sum[3] += map[i][j];
			}
			else if (visit[i][j] == 4) {
				sum[4] += map[i][j];
			}
			else if (visit[i][j] == 5 || visit[i][j]==0) {
				sum[5] += map[i][j];
			}
		}
	}
	for (int i = 1; i <= 5; i++) {
		maxv = max(sum[i], maxv);
		minv = min(sum[i], minv);
	}
	int tempans = maxv - minv;
	ans = min(tempans, ans);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1; d2 < n; d2++) {
					if (check(i, j, d1, d2)) {
						memset(visit, 0, sizeof(visit));
						memset(sum, 0, sizeof(sum));
						line(i, j, d1, d2);
						num1(i, j, d1, d2);
						num2(i, j, d1, d2);
						num3(i, j, d1, d2);
						num4(i, j, d1, d2);
						cal();
					}

				}
			}
		}
	}

	cout << ans << endl;
}