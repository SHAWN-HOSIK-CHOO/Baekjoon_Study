#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, max = 0;
    std::vector<std::vector<int>> dp;

    std::cin>>n;

    dp.assign(n+1,std::vector<int>(n+1,0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            std::cin>>dp[i][j];
        }
    }

    max = dp[1][1];

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 1)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j];
            }
            else if(j == i)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j] + std::max(dp[i - 1][j - 1],dp[i - 1][j]);
            }

            max = std::max(max,dp[i][j]);
        }
    }

    std::cout<<max;

    return 0;
}