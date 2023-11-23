#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<std::vector<int>> dp;

    std::cin>>N;

    dp.assign(N + 1, std::vector<int>(3,0));

    if(N == 1)
    {
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;
    }
    else
    {
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;

        for(int i = 2; i <= N; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
        }
    }

    std::cout<<(dp[N][0] + dp[N][1] + dp[N][2]) % 9901;

    return 0;
}