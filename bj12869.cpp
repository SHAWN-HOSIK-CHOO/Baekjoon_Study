#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N;
std::vector<std::vector<int>> graph =
{
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};  
int dp[61][61][61];
int input[3];

struct element
{
    int x;
    int y;
    int z;
};


int bfs(int x, int y, int z)
{
    std::queue<element> q;
    q.push({x, y, z});
    dp[x][y][z] = 1;

    while (!q.empty())
    {
        element cur = q.front();
        q.pop();

        int cur_x = cur.x;
        int cur_y = cur.y;
        int cur_z = cur.z;

        if(dp[0][0][0] != -1) break;

        for(int i = 0; i < 6; i++)
        {
            int xx = std::max(0, cur_x - graph[i][0]);
            int yy = std::max(0, cur_y - graph[i][1]);
            int zz = std::max(0, cur_z - graph[i][2]);

            if(dp[xx][yy][zz] != -1) continue;

            dp[xx][yy][zz] = dp[cur_x][cur_y][cur_z] + 1;

            q.push({xx, yy, zz});
        }
    }

    return dp[0][0][0] - 1;
}

int main()
{
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        std::cin>>input[i];
    }

    memset(dp, -1, sizeof(dp));

    std::cout<<bfs(input[0], input[1], input[2]);

    return 0;
}