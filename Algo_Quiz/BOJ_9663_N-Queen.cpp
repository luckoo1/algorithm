#include <cstdio>

int n;
bool map[16][16];
bool check_col[16];
int ans = 0;

bool check(int row, int col) {

	int r = row - 1;
	int c = col - 1;

	while (r >= 0 && c >= 0) {
		if (map[r][c] == true) {
			return false;
		}
		r -= 1;
		c -= 1;
	}

	r = row - 1;
	c = col + 1;

	while (r >= 0 && c < n) {
		if (map[r][c] == true) {
			return false;
		}
		r -= 1;
		c += 1;
	}
	return true;
}

void calc(int row) {

	if (row == n) {
		ans += 1;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check(row, i) == true) {
			if (check_col[i] == false) {
				map[row][i] = true;
				check_col[i] = true;
				calc(row + 1);
				map[row][i] = false;
				check_col[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	calc(0);

	printf("%d", ans);
}
