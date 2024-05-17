#include <iostream>
#include <queue>
#include <algorithm>

struct Room
{
    Room(int z_, int x_, int y_) 
        : x(x_), y(y_), z(z_) {}
    int x;
    int y;
    int z;
};

int M, N, H, ans = 0;
int tomato[101][101][101] = {0};
int dist[101][101][101] = {0};
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

std::queue<Room> q;

void BFS()
{
    while (!q.empty())
    {
        Room cur = q.front();
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            int nz = cur.z + dz[i];
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if(dist[nz][nx][ny] >= 0)
                continue;

            dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
            q.push({nz, nx, ny});
        }
    }
    
}

int main()
{
    std::cin>>M>>N>>H;

    for(int k = 0; k < H; k++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int i = 0; i < M; i++)
            {
                std::cin>>tomato[k][j][i];
                if(tomato[k][j][i] == 1)
                    q.push({k, j, i}); // z, x, y
                if(tomato[k][j][i] == 0)
                    dist[k][j][i] = -1;
            }
        }
    }

    BFS();

    for(int k = 0; k < H; k++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int i = 0; i < M; i++)
            {
                if(dist[k][j][i] == -1)
                {
                    std::cout<<-1;
                    return 0;
                }
                ans = std::max(ans, dist[k][j][i]);
            }
        }
    }

    std::cout<<ans;

    return 0;
}