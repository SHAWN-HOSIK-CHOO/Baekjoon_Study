/*
    출처 : https://96glory.tistory.com/47
*/
#include <iostream>
#include <vector>

int T, n;
std::vector<std::vector<int>> dp;

int main()
{
    std::cin>>T;
    dp.assign(10001, std::vector<int>(4, 0));

    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    dp[2][2] = dp[3][2] = 1;
    dp[3][3] = 1;

    // 중복을 피하기 위해 오름차순만 고려함
    for(int i = 4; i <= 10000; i++)
    {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    for(int i = 0; i < T; i++)
    {
        std::cin>>n;

        std::cout<<dp[n][1] + dp[n][2] + dp[n][3]<<'\n';
    }

    return 0;
}
