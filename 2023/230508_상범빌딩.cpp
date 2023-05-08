#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define DEBUG (0)

int K, N, M;

int DR[6] = {1, -1, 0, 0, 0, 0};
int DC[6] = {0, 0, 1, -1, 0, 0};
int DD[6] = {0, 0, 0, 0, 1, -1};
struct DATA
{
    int d;
    int r;
    int c;
    DATA(int d, int r, int c)
    {
        this->d = d;
        this->r = r;
        this->c = c;
    }
};

void print_cnt(vector<vector<vector<int>>> &cnt_graph)
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cout << cnt_graph[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
#if DEBUG == 1
    freopen("Input.txt", "r", stdin);
#endif

    string temp;
    while (1)
    {
        cin >> K >> N >> M;
        int LK, LN, LM;
        if (K == 0 && N == 0 && M == 0)
            break;
        queue<DATA> q;
        vector<vector<string>> graph(K, vector<string>(N));
        vector<vector<vector<int>>> cnt_graph(K, vector<vector<int>>(N, vector<int>(M, -1)));
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> temp;
                graph[i][j] = temp;
                for (int k = 0; k < M; k++)
                {
                    if (graph[i][j][k] == 'S')
                    {
                        q.push(DATA(i, j, k));
                        cnt_graph[i][j][k] = 0;
                    }
                    if (graph[i][j][k] == 'E')
                    {
                        LK = i;
                        LN = j;
                        LM = k;
                    }
                }
            }
        }

        while (!q.empty())
        {
            int now_d = q.front().d;
            int now_r = q.front().r;
            int now_c = q.front().c;
            q.pop();
            for (int k = 0; k < 6; k++)
            {
                int move_r = now_r + DR[k];
                int move_c = now_c + DC[k];
                int move_d = now_d + DD[k];

                if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= M||move_d<0||move_d>=K)
                    continue;

                if (graph[move_d][move_r][move_c] == '#' || cnt_graph[move_d][move_r][move_c] != -1)
                    continue;

                cnt_graph[move_d][move_r][move_c] = cnt_graph[now_d][now_r][now_c] + 1;
                q.push(DATA(move_d, move_r, move_c));
            }
        }
        // print_cnt(cnt_graph);
        if (cnt_graph[LK][LN][LM] == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << cnt_graph[LK][LN][LM] << " minute(s).\n";
    }
}

#if 0
/*
틀렸던 코드
int DR[6] = {1, -1, 0, 0, 0, 0};
int DC[6] = {0, 0, 1, -1, 0, 0};
int DD[6] = {0, 0, 0, 0, 1, -1};
이게 핵심이었다.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define DEBUG (0)

int K, N, M;

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

int DD[2] = {1,-1};
struct DATA
{
	int d;
	int r;
	int c;
	DATA(int d, int r, int c)
	{
		this->d = d;
		this->r = r;
		this->c = c;
	}
};


int main()
{

	string temp;
	while (1)
	{
		cin >> K >> N >> M;
		int LK, LN, LM;
		queue<DATA> q;
		if (K == 0 && N == 0 && M == 0)
			break;
		vector<vector<string>> graph(K, vector<string>(N));
		vector<vector<vector<int>>> cnt_graph(K, vector<vector<int>>(N, vector<int>(M, -1)));
		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				graph[i][j] = temp;
				for (int k = 0; k < M; k++)
				{
					if (graph[i][j][k] == 'S')
					{
						q.push(DATA(i, j, k));
                        cnt_graph[i][j][k] = 0;
					}
					if (graph[i][j][k] == 'E')
					{
						LK = i;
						LN = j;
						LM = k;
					}
				}
			}
		}

		while (!q.empty())
		{
			int now_d = q.front().d;
			int now_r = q.front().r;
			int now_c = q.front().c;
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int move_r = now_r + DR[k];
				int move_c = now_c + DC[k];
				if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= M)
					continue;

				if (graph[now_d][move_r][move_c] == '#' || cnt_graph[now_d][move_r][move_c] != -1)
					continue;
				
				cnt_graph[now_d][move_r][move_c] = cnt_graph[now_d][now_r][now_c]+1;
				q.push(DATA(now_d,move_r,move_c));

                for(int l=0;l<2;l++){
				    int move_d = now_d+DD[l];
				    if(move_d>=K||move_d<0)
					    continue;
				    if (graph[move_d][move_r][move_c] == '#' || cnt_graph[move_d][move_r][move_c] != -1)
					    continue;
				    cnt_graph[move_d][now_r][now_c] = cnt_graph[now_d][now_r][now_c]+1;
				    q.push(DATA(move_d,now_r,now_c));
	
                }
			}
		}
		if(cnt_graph[LK][LN][LM]==-1)
			cout<<"Trapped!"<<endl;
        else
            cout << "Escaped in " << cnt_graph[LK][LN][LM]<< " minute(s).\n";

	}
}
#endif