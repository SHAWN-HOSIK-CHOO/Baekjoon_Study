/*
    출처 : https://yabmoons.tistory.com/441
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define inf 987654321

int N, M;
std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> route;
std::vector<int> v;

void Floyd_warshall()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(i == j)
                {
                    continue;
                }

                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
}

void Route(int start, int end)
{
    if(route[start][end] == 0)
    {
        v.push_back(start);
        v.push_back(end);
        return;
    }

    Route(start, route[start][end]);
    v.pop_back();
    Route(route[start][end], end);
}

int main()
{
    std::cin>>N>>M;

    dp.assign(N + 1, std::vector<int>(N + 1, inf));
    route.assign(N + 1, std::vector<int>(N + 1, 0));

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        dp[a][b] = std::min(dp[a][b],c);
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
                v.clear();
                Route(i, j);
                std::cout<<v.size()<<" ";

                for(int k = 0; k < v.size(); k++)
                {
                    std::cout<<v[k]<<" ";
                }
            }
            std::cout<<'\n';
        }
    }

    return 0;
}