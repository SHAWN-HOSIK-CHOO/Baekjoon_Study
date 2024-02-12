/*
    출처 : https://yabmoons.tistory.com/340
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int M, N, ans = 0;
std::vector<std::vector<int>> map;
std::vector<std::vector<int>> dp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y)
{
    if(x == M - 1 && y == N - 1)
    {
        return 1;
    }

    if(dp[x][y] != -1)
    {
        return dp[x][y];
    }

    dp[x][y] = 0;

    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 && xx < M && yy >= 0 && y < N)
        {
            if(map[x][y] > map[xx][yy])
            {
                dp[x][y] = dp[x][y] + dfs(xx, yy);
            }
        }
    }

    return dp[x][y];
}

int main()
{
    std::cin>>M>>N;
    map.assign(M + 1, std::vector<int>(N + 1, 0));
    dp.assign(M + 1, std::vector<int>(N + 1, 0));

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin>>map[i][j];
            dp[i][j] = -1;
        }
    }

    ans = dfs(0, 0);

    std::cout<<ans<<'\n';

    return 0;
}