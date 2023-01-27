/*
틀린이유 별표 표시
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M, K;
int row, col, age;
vector<vector<int>> ENERGY(12, vector<int>(12, 5));
vector<vector<int>> PLUS_ENERGY(12, vector<int>(12, 0));
vector<vector<int>> dead_tree_map(12, vector<int>(12, 0));

int DR[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int DC[8] = {0, 0, 1, -1, 1, -1, 1, -1};

vector<int> get_row_col(string a)
{
    string row = "";
    string col = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ',')
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                col.push_back(a[j]);
            }
            break;
        }
        row.push_back(a[i]);
    }

    vector<int> return_vec;
    return_vec.push_back(stoi(row));
    return_vec.push_back(stoi(col));
    return return_vec;
}
map<string, vector<int>> hash_map;

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> PLUS_ENERGY[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> row >> col >> age;
        string str_row = to_string(row);
        string str_col = to_string(col);
        string hash_key = str_row + "," + str_col;
        hash_map[hash_key].push_back(age);
    }
    //----------------------------------------------------------------------------------
    for (int X = 0; X < K; X++)
    {
        vector<int> new_age;
        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            vector<int> temp = get_row_col(iter->first);
            int row = temp[0];
            int col = temp[1];

            int dead_tree_energy = 0;
            for (int i = 0; i < iter->second.size(); i++)
            {
                age = iter->second[i];
                int namuji_energy = ENERGY[row][col] - age;

                if (namuji_energy >= 0)
                {
                    ENERGY[row][col] = namuji_energy;
                    new_age.push_back(age + 1);
                }
                else
                {
                    dead_tree_energy += age / 2; 
                    //break; //★★★★★★★★★★★★★★★★★★★ 여기서 틀림
                }
            }
            ENERGY[row][col] += dead_tree_energy;

            iter->second = new_age;
            new_age.clear();
        }

#if 0
        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            cout << "1ST RESULT" << endl;
            cout << "TREE : " << iter->first << endl;
            for (int i = 0; i < iter->second.size(); i++)
            {
                cout << iter->second[i] << " ";
            }
            cout << endl;
        }
#endif

        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            for (int i = 0; i < iter->second.size(); i++)
            {
                if ((iter->second[i]) % 5 == 0)
                {
                    vector<int> temp = get_row_col(iter->first);
                    int row = temp[0];
                    int col = temp[1];
                    for (int k = 0; k < 8; k++)
                    {
                        int move_row = row + DR[k];
                        int move_col = col + DC[k];
                        if (move_row < 1 || move_col < 1 || move_row > N || move_col > N)
                        {
                            continue;
                        }
                        string str_row = to_string(move_row);
                        string str_col = to_string(move_col);
                        string hash_key = str_row + "," + str_col;
                        hash_map[hash_key].insert(hash_map[hash_key].begin(),1);
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                ENERGY[i][j] += PLUS_ENERGY[i][j];
            }
        }
    }

    int ANS = 0;
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        ANS += iter->second.size();
    }

    cout << ANS;
}