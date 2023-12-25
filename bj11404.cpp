#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define inf 987654321

int N, M;
std::vector<std::vector<int>> dp;

void Floyd_warshall()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                dp[i][j] = std::min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main()
{
    std::cin>>N>>M;

    dp.assign(N + 1, std::vector<int>(N + 1, inf));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < M; i++)
    {
        int a,b,c;
        std::cin>>a>>b>>c;

        dp[a][b] = std::min(dp[a][b], c);
    }

    Floyd_warshall();

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(dp[i][j] == inf)
            {
                std::cout<<0<<" ";
            }
            else
            {
                std::cout<<dp[i][j]<<" ";
            }
        }

        std::cout<<'\n';
    }

    return 0;
}