#include <iostream>
#include <algorithm>
#include <vector>

int M, N, K;
std::vector<std::vector<int>> g_Graph;
std::vector<std::vector<bool>> g_Visited;
std::vector<int> ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int DFS(int x, int y)
{
    if(g_Visited[x][y]) 
        return 0;

    g_Visited[x][y] = true;

    int ret = 1;

    for(int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
            continue;
        if(g_Visited[nextX][nextY] || g_Graph[nextX][nextY])
            continue;

        ret += DFS(nextX, nextY);
    }

    return ret;
}

int main()
{
    std::cin>>M>>N>>K;
    g_Graph.assign(M + 1, std::vector<int>(N + 1, 0));
    g_Visited.assign(M + 1, std::vector<bool>(N + 1, false));
    for(int i = 0; i < K; i++)
    {
        int x1, x2, y1, y2;
        std::cin>>x1>>y1>>x2>>y2;

        for(int y = y1; y < y2; y++)
        {
            for(int x = x1; x < x2; x++)
            {
                g_Graph[y][x] = true;
            }
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(g_Graph[i][j] || g_Visited[i][j])
                continue;

            ans.push_back(DFS(i, j));
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout<<ans.size()<<'\n';
    for(auto a : ans)
    {
        std::cout<<a<<" ";
    }

    return 0;
}
