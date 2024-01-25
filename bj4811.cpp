#include <iostream>

int main()
{
    long long dp[31][31];
    int par;

    for(int i = 0; i < 31; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i < 31; i++)
    {
        for(int j = 0; j < 31; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i - 1][1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
            }
        }
    }

    std::cin>>par;

    while (par != 0)
    {
        std::cout<<dp[par][0]<<'\n';
        std::cin>>par;    
    }
    
    return 0;
}