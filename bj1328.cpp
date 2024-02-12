/*
    출처 : https://everenew.tistory.com/45
*/
#include <iostream>

#define mod 1000000007

int n, l, r;
int dp[101][101][101] = {0, };

int main()
{
    std::cin>>n>>l>>r;

    dp[1][1][1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int l = 1; l <= i; l++)
        {
            for(int r = 1; r <= i; r++)
            {
                dp[i][l][r] = ((long long)dp[i-1][l][r]*(i-2) + dp[i-1][l-1][r] + dp[i-1][l][r-1])%mod;
            }
        }
    }

    std::cout<<dp[n][l][r]<<'\n';

    return 0;
}