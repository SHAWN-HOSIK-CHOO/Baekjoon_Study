#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int T, n;
    std::vector<std::vector<int>> sticker;
    //dp[0][i] 0행으로 끝나는 최대값 dp[1][i] 1행으로 끝나는 최댓값
    std::vector<std::vector<int>> dp;

    std::cin>>T;

    for(int i = 0; i < T; i++)
    {
        std::cin>>n;

        sticker.assign(2,std::vector<int>(n,0));
        dp.assign(2,std::vector<int>(n,0));

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cin>>sticker[i][j];
            }
        }

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];

        dp[0][1] = std::max(dp[1][0] + sticker[0][1], dp[0][0]);
        dp[1][1] = std::max(dp[0][0] + sticker[1][1], dp[1][0]);

        for(int i = 2; i < n; i++)
        {
            dp[0][i] = std::max(std::max(dp[1][i - 2] + sticker[0][i],dp[0][i - 2] + sticker[0][i]),dp[1][i - 1] + sticker[0][i]);
            dp[1][i] = std::max(std::max(dp[1][i - 2] + sticker[1][i],dp[0][i - 2] + sticker[1][i]),dp[0][i - 1] + sticker[1][i]);
        }

        std::cout<<std::max(dp[0][n - 1], dp[1][n - 1])<<'\n';
    }

    return 0;
}