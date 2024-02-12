#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> maze;

int main()
{
    std::cin>>N>>M;

    maze.assign(N + 1, std::vector<int>(M + 1, 0));
    dp.assign(N + 1, std::vector<int>(M + 1, 0));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            std::cin>>maze[i][j];
        }
    }

    dp[1][1] = maze[1][1];

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            dp[i][j] = std::max(dp[i - 1][j] + maze[i][j], std::max(dp[i - 1][j - 1] + maze[i][j], dp[i][j - 1] + maze[i][j]));
        }
    }

    std::cout<<dp[N][M];

    return 0;
}