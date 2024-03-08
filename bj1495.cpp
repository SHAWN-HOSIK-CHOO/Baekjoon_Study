/*
    출처 :  https://yabmoons.tistory.com/547
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, S, M;
std::vector<int> V;
std::vector<std::vector<bool>> dp;

int main()
{
    std::cin>>N>>S>>M;
    V.assign(N + 1, 0);
    dp.assign(N + 1, std::vector<bool>(M + 1, false));

    for(int i = 1; i <= N; i++)
    {
        std::cin>>V[i];
    }

    if(S + V[1] <= M)
    {
        dp[1][S + V[1]] = true;
    }

    if(S - V[1] >= 0)
    {
        dp[1][S - V[1]] = true;
    }

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            if(dp[i - 1][j])
            {
                if(j + V[i] <= M)
                {
                    dp[i][j + V[i]] = true; 
                }

                if(j - V[i] >= 0)
                {
                    dp[i][j - V[i]] = true;
                }
            }
        }
    }

    for(int i = M; i >= 0; i--)
    {
        if(dp[N][i])
        {
            std::cout<<i;
            return 0;
        }
    }

    std::cout<<-1;

    return 0;
}