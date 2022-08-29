#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001][2];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct DATA{
	int x;
	int y;
	int z;
	DATA(){};
	DATA(int x, int y, int z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

};

int main(){
    freopen("Input.txt","r",stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
		}
	}

	queue<DATA> q;
	q.push(DATA(0, 0, 0));
	d[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny] == 0 && d[nx][ny][z] == 0) {
				d[nx][ny][z] = d[x][y][z] + 1;
				q.push(DATA(nx, ny, z));
			}
			if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z + 1] == 0) {
				d[nx][ny][z + 1] = d[x][y][z] + 1;
				q.push(DATA(nx, ny, z + 1));
			}
		}
	}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<d[i][j][0]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<d[i][j][1]<<" ";
        }
        cout<<endl;
    }
	if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0) {
		cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
	}
	else if (d[n - 1][m - 1][0] != 0) {
		cout << d[n - 1][m - 1][0];
	}
	else if (d[n - 1][m - 1][1] != 0) {
		cout << d[n - 1][m - 1][1];
	}
	else {
		cout << -1;
	}
	cout << '\n';
	return 0;
}