vector<vector<int>> reset_map(vector<vector<int>> MAP, vector<vector<int>> CLOUD)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] >= 2&&CLOUD[i][j]==0)
            {
                MAP[i][j]-=2;
            }
        }
    }
}
vector<vector<int>> reset_cloud(vector<vector<int>> MAP, vector<vector<int>> CLOUD)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] >= 2)
            {
                CLOUD[i][j] = 1;
            }
            else
            {
                CLOUD[i][j] = 0;
            }
        }
    }
    return CLOUD;
}
