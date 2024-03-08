/*
    출처 : https://nanyoungkim.tistory.com/182
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
std::vector<std::vector<int>> dp;
std::vector<int> w;
std::vector<int> v;

int main()
{
    std::cin>>N>>K;
    dp.assign(N + 1, std::vector<int>(K + 1, 0));
    w.assign(N + 1, 0);
    v.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>w[i]>>v[i];
    }

    for(int max_w = 1; max_w <= K; max_w++)
    {
        for(int i = 1; i <= N; i++)
        {
            if(w[i] > max_w) 
                dp[i][max_w] = dp[i - 1][max_w];
            else
                dp[i][max_w] = std::max(dp[i - 1][max_w], dp[i - 1][max_w - w[i]] + v[i]); 
        }
    }

    std::cout<<dp[N][K];

    return 0;
}