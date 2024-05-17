#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

int T, M, N, K, ans = 0; // M이 가로 N이 세로임
int map[51][51] = {0};
bool visited[51][51] = {false};
std::queue<std::pair<int,int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y)
{
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if(map[nx][ny] == 0)
                continue;
            if(visited[nx][ny] == true)
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
}

int main()
{
    std::cin>>T;

    while(T > 0)
    {
        std::cin>>M>>N>>K;

        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        ans = 0;

        for(int i = 0; i < K; i++)
        {
            int tmpX, tmpY;
            std::cin>>tmpX>>tmpY;

            map[tmpY][tmpX] = 1;
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if((map[i][j] == 1) && (visited[i][j] == false))
                {
                    ans++;
                    BFS(i, j);
                }
            }
        }

        std::cout<<ans<<'\n';
        T--;
    }
    return 0;
}