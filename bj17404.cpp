#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, ans = 1000000000;
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> cost;

    std::cin>>N;

    dp.assign(N + 1, std::vector<int>(3,0));
    cost.assign(N + 1, std::vector<int>(3,0));

    for(int i = 1; i <= N; i++)
    {
        std::cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == i)
            {
                dp[1][i] = cost[1][i];
            }
            else
            {
                dp[1][j] = 1000000000;
            }
        }

        for(int k = 2; k <= N; k++)
        {
            dp[k][0] = std::min(dp[k - 1][1], dp[k - 1][2]) + cost[k][0];
            dp[k][1] = std::min(dp[k - 1][0], dp[k - 1][2]) + cost[k][1];
            dp[k][2] = std::min(dp[k - 1][0], dp[k - 1][1]) + cost[k][2];
        }

        for(int k = 0; k < 3; k++)
        {
            if(i == k)
            {
                continue;
            }
            else
            {
                ans = std::min(ans,dp[N][k]);
            }
        }
    }

    std::cout<<ans;

    return 0;
}