#include <iostream>
#include <vector>

int main()
{
    int N; 
    long long ans = 0;
    std::vector<std::vector<int>> dp;

    std::cin>>N;
    dp.assign(N+1, std::vector<int>(11,0));

    for(int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 0)
            {
                dp[i][0] = (dp[i - 1][1]) % 1000000000;
            }
            else if(j == 9)
            {
                dp[i][9] = (dp[i - 1][8]) % 1000000000;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
            }
        }
    }

    for(int i = 0; i < 10; i++)
    {
        ans = ans + dp[N][i];
    }

    std::cout<<ans % 1000000000;

    return 0;
}