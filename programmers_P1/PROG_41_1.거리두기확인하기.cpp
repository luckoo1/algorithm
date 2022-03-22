#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dr[4]{1, -1, 0, 0};
int dc[4]{0, 0, 1, -1};

struct WHERE
{
    int r;
    int c;
    WHERE(int row, int col)
    {
        this->r = row;
        this->c = col;
    }
};

bool flag = false;
bool check[5][5][5];

void dfs(int dep, vector<vector<string>> &places, int room, int r, int c)
{
    if (flag == true)
        return;
    if (places[room][r][c] == 'X') //칸막이 있으니깐 그냥 리턴해림
    {
        return;
    }
    if (places[room][r][c] == 'P' && dep != 0)
    {
        flag = true;
        return;
    }
    if (dep == 2)
        return;

    for (int i = 0; i < 4; i++)
    {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        if (new_r < 0 || new_c < 0 || new_r >= 5 || new_c >= 5)
            continue;
        if (check[room][new_r][new_c] == true)
            continue;
        check[room][new_r][new_c] = true;
        dfs(dep + 1, places, room, new_r, new_c);
        check[room][new_r][new_c] = false;
    }
}

vector<int> solution(vector<vector<string>> places)
{
    vector<vector<WHERE>> people;
    vector<WHERE> where_room;
    for (int i = 0; i < places.size(); i++)
    {
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].size(); k++)
            {
                if (places[i][j][k] == 'P')
                    where_room.push_back(WHERE(j, k));
            }
        }

        people.push_back(where_room);
        where_room.clear();
    }

    vector<int> answer;

    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people[i].size(); j++)
        {
            check[i][people[i][j].r][people[i][j].c] = true;
            dfs(0, places, i, people[i][j].r, people[i][j].c);
            check[i][people[i][j].r][people[i][j].c] = false;
            if (flag == true)
                break;
        }
        if (flag == false)
            answer.push_back(1);
        else
            answer.push_back(0);
        flag = false;
    }

    return answer;
}

int main()
{
    vector<vector<string>> a{
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> ans = solution(a);
    cout << "ANSWER is" << endl;
    for (auto n : ans)
    {
        cout << n << " ";
    }
}