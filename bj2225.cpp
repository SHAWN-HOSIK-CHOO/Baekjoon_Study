/*
    https://dontdiethere.tistory.com/84
    참고했습니다.
*/
#include <iostream>
#include <vector>

int main()
{
    int N, K;
    std::vector<std::vector<int>> dp;

    std::cin>>N>>K;

    dp.assign(N+1,std::vector<int>(K+1,0));

    for(int i = 1; i <= K; i++)
    {
        dp[1][i] = i;
    }

    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
        }
    }

    std::cout<<dp[N][K];

    return 0;
}