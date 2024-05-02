#include <iostream>
#include <vector>
#define MOD 10007

int N, K;
std::vector<std::vector<int>> dp;

int main()
{
    std::cin>>N>>K;

    dp.assign(N + 1, std::vector<int>(K + 1, 0));

    for(int n = 1; n <= N; n++)
    {
        for(int k = 0; k <= K; k++)
        {
            if(n == k || k == 0) dp[n][k] = 1;
            else
            {
                dp[n][k] = (dp[n - 1][k] + dp[n - 1][k - 1]) % MOD;
            }

        }
    }

    std::cout<<dp[N][K]<<'\n';

    return 0;
}