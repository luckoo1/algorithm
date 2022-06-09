#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M, K;
int row, col, age;
vector<vector<int>> ENERGY(11, vector<int>(11, 5));
vector<vector<int>> PLUS_ENERGY(11, vector<int>(11, 0));
vector<vector<int>> dead_tree_map(11, vector<int>(11, 0));

int DR[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int DC[8] = {0, 0, 1, -1, 1, -1, 1, -1};

map<string, vector<int>> hash_map;
int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> PLUS_ENERGY[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> row >> col >> age;
        string str_row = to_string(row);
        string str_col = to_string(col);
        string hash_key = str_row + str_col;
        hash_map[hash_key].push_back(age);
    }
    //----------------------------------------------------------------------------------
    for (int X = 0; X < K; X++)
    {
        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            sort(iter->second.begin(), iter->second.end());
        }

        vector<int> new_age;
        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            row = (iter->first)[0] - 48;
            col = (iter->first)[1] - 48;
            int dead_tree_energy = 0;
            for (int i = 0; i < iter->second.size(); i++)
            {
                age = iter->second[i];
                int namuji_energy = ENERGY[row][col] - age;
                
                if (namuji_energy >= 0)
                {
                    new_age.push_back(age + 1);
                    ENERGY[row][col] = namuji_energy;
                }
                else
                {
                    dead_tree_energy += age / 2; //땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
                    break;
                }
            }
            ENERGY[row][col] += dead_tree_energy;

            iter->second = new_age;
            new_age.clear();
        }
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

        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            for (int i = 0; i < iter->second.size(); i++)
            {
                if ((iter->second[i]) % 5 == 0)
                {
                    row = (iter->first)[0] - 48;
                    col = (iter->first)[1] - 48;
                    for (int k = 0; k < 8; k++)
                    {
                        int move_row = row + DR[k];
                        int move_col = col + DC[k];
                        if (move_row < 0 || move_col < 0 || move_row >= N || move_col >= N)
                        {
                            continue;
                        }
                        string str_row = to_string(move_row);
                        string str_col = to_string(move_col);
                        string hash_key = str_row + str_col;
                        hash_map[hash_key].push_back(1);
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ENERGY[i][j] += PLUS_ENERGY[i][j];
            }
        }
    }

    int ANS = 0;
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        cout << "RESULT" << endl;
        ANS += iter->second.size();
        cout << "TREE : " << iter->first << endl;
        for (int i = 0; i < iter->second.size(); i++)
        {
            cout << iter->second[i] << " ";
        }
        cout << endl;
    }

    cout << ANS;
}