#include <iostream>
#include <vector>

int main()
{
    int T, n;
    std::vector<long long> dp;

    std::cin>>T;

    for(int i = 0; i < T; i++)
    {
        std::cin>>n;

        dp.assign(n+1,0);

        if(n == 1)
        {
            dp[1] = 1;
        }
        else if(n == 2)
        {
            dp[1] = 1;
            dp[2] = 2;
        }
        else 
        {
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            for(int j = 4; j <= n; j++)
            {
                dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;
            }
        }

        std::cout<<dp[n]<<'\n';
    }

    return 0;
}