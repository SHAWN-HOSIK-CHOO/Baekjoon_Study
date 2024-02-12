#include <iostream>
#include <vector>

#define MOD 1000000009

long long n, m, t;
std::vector<std::vector<long long>> dp;

int main()
{
    std::cin>>t;
    dp.assign(1001, std::vector<long long>(1001, 0));

    dp[1][1] = 1; dp[2][1] = 1; dp[3][1] = 1;

    for(int i = 2; i <= 1000; i++)
    {
        for(int j = 1; j <= 1000; j++)
        {
            for(int k = 1; k <= 3; k++)
            {
                if(j - k > 0)
                {
                    dp[j][i] += dp[j - k][i - 1];
                    dp[j][i] %= MOD;
                }
            }
        }
    }

    for(int i = 0; i < t; i++)
    {
        std::cin>>n>>m;
        long long ans = 0;

        for(int i = 1; i <= m; i++)
        {
            ans += dp[n][i];
            ans %= MOD;
        }

        std::cout<<ans<<'\n';
    }

    return 0;
}