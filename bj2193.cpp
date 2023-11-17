#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<std::vector<long long>> dp;

    std::cin>>N;
    dp.assign(N+1,std::vector<long long>(2,0));
    
    dp[1][0] = 0;
    dp[1][1] = 1;

    if(N >= 2)
    {
        dp[2][0] = 1;
        dp[2][1] = 0;
    }

    if(N >= 3)
    {
        dp[3][0] = 1;
        dp[3][1] = 1;
    }

    if(N >= 4)
    {
        for(int i = 4; i <= N; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
    }

    std::cout<<dp[N][0] + dp[N][1]<<'\n';

    return 0;
}