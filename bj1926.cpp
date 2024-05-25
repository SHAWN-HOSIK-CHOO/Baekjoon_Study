#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n, m, Area = 0, cnt = 0;
std::vector<std::vector<int>> g_Canvas;
std::vector<std::vector<bool>> g_Visited;
std::queue<std::pair<int,int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(int x, int y)
{
    int ret = 0;
    q.push({x, y});
    g_Visited[x][y] = true;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        ret++;

        for(int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue;

            if(g_Visited[nextX][nextY] == true || g_Canvas[nextX][nextY] == 0)
                continue;

            g_Visited[nextX][nextY] = true;
            q.push({nextX, nextY});
        }
    }
    
    return ret;
}

int main()
{
    std::cin>>n>>m;
    g_Canvas.assign(n + 1, std::vector<int>(m + 1, 0));
    g_Visited.assign(n + 1, std::vector<bool>(m + 1, false));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin>>g_Canvas[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g_Canvas[i][j] == 1 && g_Visited[i][j] == false)
            {
                cnt++;
                Area = std::max(Area, BFS(i, j));
            }
        }
    }

    std::cout<<cnt<<'\n';
    std::cout<<Area<<'\n';

    return 0;
}