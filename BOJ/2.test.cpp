#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int y, x;
	int dir;
	bool alive;
}fish;

int result = 0;
int y_ar[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int x_ar[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
bool ended = false;


void dfs(fish a[17], fish b, int c[4][4],int cnt) {
	
	result = max(result, cnt);

	fish fishes[17];
	fish shark;
	int arr[4][4];

	for (int i = 1; i <= 16; i++)
		fishes[i] = a[i];
	shark = b;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			arr[i][j] = c[i][j];




	// fish
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].alive== false)
			continue;
		int y = fishes[i].y;
		int x = fishes[i].x;
		int dir = fishes[i].dir;

		int ny = y + y_ar[dir];
		int nx = x + x_ar[dir];
		bool jud = false;

		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
			if (arr[ny][nx] == 0) { //없으면

				jud = true;
				fishes[i].y = ny;
				fishes[i].x = nx;
				arr[ny][nx] = i;
				arr[y][x] = 0;
				
			}
			else if (arr[ny][nx] != -1) {// 물고기가 있으면
				jud = true;
			
				fish temp = fishes[i];
				fishes[i].y = fishes[arr[ny][nx]].y;	
				fishes[i].x = fishes[arr[ny][nx]].x;
				fishes[arr[ny][nx]].y = temp.y;
				fishes[arr[ny][nx]].x = temp.x;

				int temp2;
				temp2 = arr[y][x];
				arr[y][x] = arr[ny][nx];
				arr[ny][nx] = temp2;

			}


		}
		if (jud == true) continue;
		else {
			int ndir = dir + 1;
			if (ndir == 9) ndir = 1;
			int ny = y + y_ar[ndir];
			int nx = x + x_ar[ndir];


			while (ndir != dir) {
				if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
					if (arr[ny][nx] == 0) { //없으면

						
						fishes[i].y = ny;
						fishes[i].x = nx;
						fishes[i].dir = ndir;
						arr[ny][nx] = i;
						arr[y][x] = 0;

						break;
					}
					else if (arr[ny][nx] != -1) {// 물고기가 있으면
						
						fish temp = fishes[i];
						fishes[i].y = fishes[arr[ny][nx]].y;
						fishes[i].x = fishes[arr[ny][nx]].x;
						fishes[arr[ny][nx]].y = temp.y;
						fishes[arr[ny][nx]].x = temp.x;
						

						int temp2;
						temp2 = arr[y][x];
						arr[y][x] = arr[ny][nx];
						arr[ny][nx] = temp2;

						fishes[i].dir = ndir;
						break;

					}

				}
				ndir++;
				if (ndir == 9) ndir = 1;
				ny = y + y_ar[ndir];
				nx = x + x_ar[ndir];

			}
		}



	}



	// 상어의 이동
	//1. 해당 방향으로 이동 (가능한 경우 모두)	
	
	int nx = shark.x;
	int ny = shark.y;

	while (1) {

		ny += y_ar[shark.dir];
		nx += x_ar[shark.dir];

		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {


			//1. 상어의 위치 바꾸기 2. 그 위치에 물고기
			if (arr[ny][nx] == 0) continue;


			int fishnum = arr[ny][nx];
			int ndir = fishes[fishnum].dir;

			arr[shark.y][shark.x] = 0;
			arr[ny][nx] = -1;
			shark = fishes[fishnum];
			fishes[fishnum].alive = false;


			dfs(fishes, shark, arr, cnt + fishnum);

			fishes[fishnum].alive = true;
			arr[ny][nx] = fishnum;
			shark = b;
			arr[shark.y][shark.x] = -1;


		}
		else
			break;

	}



}

int main() {
	int a, b;

	fish fishes[17];
	fish shark;
	int arr[4][4];
	int fishnum;

	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			if (i == 0 && j == 0) {
				shark = { i,j,b,1 };
				fishes[a] = { 0,0,0,0 };
				arr[0][0] = -1;
				fishnum = a;
				continue;
			}
			else{
				fishes[a] = { i,j,b,1 };
				arr[i][j] = a;
				}
		}



	dfs(fishes, shark, arr, fishnum);

	cout << result << endl;

}