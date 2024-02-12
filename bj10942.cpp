/*
    출처 :  https://cocoon1787.tistory.com/326
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, S, E, M;
std::vector<std::vector<int>> dp;
std::vector<int> seq;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;
    seq.assign(N + 1, 0);
    dp.assign(N + 1, std::vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++)
    {
        std::cin>>seq[i];
    }

    for(int i = 1; i <= N; i++)
    {
        dp[i][i] = 1;
    }

    for(int i = 1; i <= N - 1; i++)
    {
        if(seq[i] == seq[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }

    for(int j = 2; j <= N - 1; j++)
    {
        for(int i = 1; i + j <= N; i++)
        {
            if(seq[i] == seq[i + j] && dp[i + 1][i + j - 1])
            {
                dp[i][i + j] = 1;
            }
        }
    }

    std::cin>>M;

    for(int i = 0; i < M; i++)
    {
        std::cin>>S>>E;

        std::cout<<dp[S][E]<<'\n';
    }

    return 0;
}