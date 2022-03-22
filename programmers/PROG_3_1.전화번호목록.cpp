#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    map<string, int> hash_map;
    sort(phone_book.begin(), phone_book.end());
    hash_map[phone_book[0]]+=1;

    for (int i = 1; i < phone_book.size(); i++)
    {
        string temp_str = "";
        for (int j = 0; j < phone_book[i - 1].size(); j++) // for (int j = 0; j < phone_book[i].size(); j++)
        {
            temp_str.push_back(phone_book[i][j]);
        }
        if(hash_map[temp_str]==1)
            return false;
        else
            hash_map[phone_book[i]] += 1; // hash_map[temp_str]
    }
    return true;
}

int main()
{
    vector<string> a{"119", "97674223", "1195524421"};
    vector<string> b{"123", "456", "789"};
    vector<string> c{"12", "123","1235","567", "88"};
    bool ans = solution(c);
    cout << ans << endl;
}