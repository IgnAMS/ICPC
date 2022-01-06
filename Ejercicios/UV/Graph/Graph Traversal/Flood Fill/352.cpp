
int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

vector<vector<bool>> visited(n, vector<bool>(n, false));
int comp = 0;

void dfs(int a, int b)
{
    if (visited[a][b])
        return; // si ya fue visitado, no sigas xd
    visited[a][b] = true;
    for (int h = 0; h < 8; h++)
    {
        int posi = a + drow[h];
        int psoj = b + dcol[h];
        if (0 <= posi && posi < n && 0 <= posj && posj < n && mat[posi][posj] == 1)
        {
            dfs(posi, posj);
        }
    }
    return;
}

vector<vector<int>> mat(n, vector<int>(n));
for (int i = 0; i < mat.size(); i++)
{
    for (int j = 0; j < mat[i].size(); j++)
    {
        if (mat[i][j] == 1)
        {
            if (!visited[posi][posj])
                comp++;
            dfs(i, j);
        }
    }
}
