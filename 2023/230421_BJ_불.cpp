#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define DEBUG (0)
int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int f_dist[1003][1003] = {0};
int j_dist[1003][1003] = {0};
bool check[1003][1003] = {false};
struct DATA
{
	int r;
	int c;
	DATA(int r, int c)
	{
		this->r = r;
		this->c = c;
	}
};

int main()
{
	#if DEBUG
	freopen("Input.txt", "r", stdin);
	#endif
	int N, M;
	cin >> N >> M;
	vector<string> graph;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		graph.push_back(temp);
	}
	queue<DATA> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 'F')
			{
				q.push(DATA(i, j));
				f_dist[i][j] = 1;
				check[i][j]=true;
			}
		}
	}

	while (!q.empty())
	{
		int now_r = q.front().r;
		int now_c = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int move_r = now_r + DR[i];
			int move_c = now_c + DC[i];
			if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= M)
				continue;
			if (graph[move_r][move_c] == '#' || check[move_r][move_c]==true)
				continue;

			q.push(DATA(move_r, move_c));
			f_dist[move_r][move_c] = f_dist[now_r][now_c] + 1;
			check[move_r][move_c]=true;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 'J')
			{
				q.push(DATA(i, j));
				j_dist[i][j] = 1;
			}
		}
	}
	int flag = 0;
	while (!q.empty())
	{
		if(flag == 1)
			break;
		int now_r = q.front().r;
		int now_c = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int move_r = now_r + DR[i];
			int move_c = now_c + DC[i];
			if (move_r == -1 || move_c == -1|| move_r == N || move_c == M)
			{
				flag = 1;
				cout<<j_dist[now_r][now_c];
				break;
			}
			if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= M)
				continue;
			if (graph[move_r][move_c] == '#' || j_dist[move_r][move_c] != 0)
				continue;
			if(check[move_r][move_c] == true){
				if ((j_dist[now_r][now_c] + 1) - f_dist[move_r][move_c] >= 0)
					continue;
			}
			q.push(DATA(move_r, move_c));
			j_dist[move_r][move_c] = j_dist[now_r][now_c] + 1;
		}
	}
	#if DEBUG
	cout<<endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << f_dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << j_dist[i][j] << " ";
		}
		cout << endl;
	}
	#endif
	if(flag ==0)
		cout<<"IMPOSSIBLE";
}
