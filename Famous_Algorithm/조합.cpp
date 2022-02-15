//////////////////////////////////////////////////////////////////////////////////
// N과M
#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool check[9] = {false};
vector<int> ans;

void dfs(int dep)
{
    if (dep == m)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
        {
            ans.push_back(i + 1);
            check[i] = true;
            dfs(dep + 1);
            ans.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    dfs(0);
}
//////////////////////////////////////////////////////////////////////////////////
// N과M
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a[10];
int d[10];
bool check[10];

void dfs(int dep)
{
    if (dep == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", d[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
        {
            d[dep] = a[i];
            check[i] = true;
            dfs(dep + 1);
            check[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    dfs(0);
    return 0;
}

// 0 01 012 0123 013 02 023 03 1 12 123 13 2 23 3

#include <iostream>
#include <vector>
vector<string> temp_ans;
void dfs()
{
}

int main()
{
    dfs(0, 4);
}