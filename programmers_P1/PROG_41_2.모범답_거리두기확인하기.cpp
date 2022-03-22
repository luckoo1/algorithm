#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
이코드는 p주변에 한칸씩만 탐색한다
마냑 첫번째 p를 한칸씩 탐색하다가 O를 보면 true처리 

그러다가 두번째 p에서 한칸 이동하여 탐색했는데 o임에도 불구하고
true처리 되어있으면 이건 거리두기를 지키지 않은 경우가 되는거다.

그럼 X는 그냥 무시하면된다.
O를 통해서만 거리두기를 판별하는 거니깐 O의 true만 신경쓰면 된다.
*/
bool is_valid_place(const vector<string> &place)
{
    vector<vector<int>> check(5, vector<int>(5, false));

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    for (int i = 0; i != 5; ++i)
    {
        for (int j = 0; j != 5; ++j)
        {
            if (place[i][j] == 'P')
            {
                for (int k = 0; k != 4; ++k)
                {
                    int moved_i = i + di[k];
                    int moved_j = j + dj[k];

                    if (moved_i >= 5 || moved_j >= 5 || moved_i < 0 || moved_j < 0)
                        continue;

                    if (place[moved_i][moved_j] == 'P')
                    {
                        return false;
                    }
                    else if (place[moved_i][moved_j] == 'O')
                    {
                        if (check[moved_i][moved_j] == true)
                            return false;
                        check[moved_i][moved_j] = true;
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer(5);
    for (int i = 0; i != 5; ++i)
        answer[i] = is_valid_place(places[i]);
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