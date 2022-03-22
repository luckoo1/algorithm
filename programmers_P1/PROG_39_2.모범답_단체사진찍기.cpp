#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

inline int normalize_alphabet(char c)
{
    assert(c >= 'A' && c <= 'Z');
    return c - 'A';
}

inline int normalize_digit(char c)
{
    assert(c >= '0' && c <= '9');
    return c - '0';
}

inline int abs(int n)
{
    return n < 0 ? -n : n;
}

inline void get_indexes(int (*index)[26], const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        (*index)[normalize_alphabet(str[i])] = i;
    }
}

int solution(int n, vector<string> data)
{
    char str[] = "ACFJMNRT";
    int index[26] = {
        0,
    };
    get_indexes(&index, str);

    int perm[] = {0, 1, 2, 3, 4, 5, 6, 7};

    int answer = 0;
    do
    {
        bool flag = true;

        for (string &cond : data)
        {
            const int name1 = normalize_alphabet(cond[0]);
            const int name2 = normalize_alphabet(cond[2]);
            const int num = normalize_digit(cond[4]);
            const char op = cond[3];

            const int dist = abs(perm[index[name1]] - perm[index[name2]]) - 1;

            if (op == '>' && !(dist > num))
                flag = false;
            if (op == '=' && !(dist == num))
                flag = false;
            if (op == '<' && !(dist < num))
                flag = false;

            if (flag == false)
            {
                break;
            }
        }
        if (flag)
        {
            answer++;
        }
    } while (next_permutation(perm, perm + 8));

    return answer;
}