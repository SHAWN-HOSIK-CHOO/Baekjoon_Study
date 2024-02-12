/*
    출처 : https://woongtech.tistory.com/entry/C-python-BOJ-%EB%B0%B1%EC%A4%80-15992-1-2-3-%EB%8D%94%ED%95%98%EA%B8%B0-7
*/
#include <iostream>
#include <vector>

#define MOD 1000000009

long long T, N, M;
std::vector<std::vector<long long>> dp;

int main()
{
    std::cin>>T;

    dp.assign(1001, std::vector<long long>(1001,0));
    dp[1][1] = dp[2][1] = dp[3][1] = 1;

    for(int i = 2; i < 1001; i++)
    {
        for(int j = 1; j < 1001; j++)
        {
            for(int k = 1; k < 4; k++)
            {
                if(j - k > 0)
                {
                    dp[j][i] += dp[j - k][i - 1];
                    dp[j][i] %= MOD;
                }
            }
        }
    }

    for(int i = 0; i < T; i++)
    {
        std::cin>>N>>M;
        std::cout<<dp[N][M]<<'\n';
    }

    return 0;
}