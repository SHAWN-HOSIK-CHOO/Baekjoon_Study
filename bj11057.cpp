#include <iostream>
#include <vector>

int main()
{
    int N, ans = 0;
    std::vector<std::vector<int>> dp;

    std::cin>>N;

    dp.assign(N + 1, std::vector<int>(10,0));

    for(int i = 0; i <= 9; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            int temp = 0;
            for(int k = 0; k <= j; k++)
            {
                temp += (dp[i - 1][k]) % 10007;
            }
            dp[i][j] = temp % 10007;
        }
    }

    for(int i = 0; i <= 9; i++)
    {
        ans += (dp[N][i]) % 10007;
    }
    
    std::cout<<ans % 10007;

    return 0;
}