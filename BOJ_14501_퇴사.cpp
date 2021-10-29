#include <iostream>
using namespace std;

int work_day[16];
int money[16];

int total_day;
int ans = 0;
int end_day = 0;

void dfs(int day, int get_money) {

	if (day > total_day + 1) {
		return;
	}

	if (day == total_day + 1) {
		if (get_money > ans) {
			ans = get_money;
		}
		return;
	}

	dfs(day + 1, get_money);
	dfs(day + work_day[day], get_money + money[day]);

}

int main() {
	cin >> total_day;

	for (int i = 1; i <= total_day; i++) {
		cin >> work_day[i] >> money[i];
	}

	dfs(1, 0);

	cout << ans;

}