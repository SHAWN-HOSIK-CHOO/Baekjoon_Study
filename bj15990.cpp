/*
    https://jdselectron.tistory.com/71
    블로그 참고했습니다. 감사합니다.
*/
#include <iostream>
#include <vector>

int main()
{
    int T;
    long long n;
    std::vector<std::vector<long long>> dp;

    std::cin>>T;

    dp.assign(100001, std::vector<long long>(4,0));

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for(int i = 4; i <= 100000; i++)
    {
        dp[i][1] = (dp[i - 1][3] + dp[i - 1][2]) % 1000000009;
        dp[i][2] = (dp[i - 2][3] + dp[i - 2][1]) % 1000000009;
        dp[i][3] = (dp[i - 3][2] + dp[i - 3][1]) % 1000000009;
    }

    for(int i = 1; i <= T; i ++)
    {
        std::cin>>n;

        std::cout<<(dp[n][1] + dp[n][2] + dp[n][3])%1000000009<<'\n';
    }

    return 0;
}