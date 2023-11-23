/*
    출처 : https://cryptosalamander.tistory.com/84
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define R 0
#define G 1
#define B 2

int main()
{
    int N;
    std::vector<std::vector<int>> dp;
    std::vector<int> cost;

    std::cin>>N;

    dp.assign(N + 1,std::vector<int>(3,0));
    cost.assign(3,0);

    dp[0][R] = 0; dp[0][G] = 0; dp[0][B] = 0;

    for(int i = 1; i <= N; i++)
    {
        std::cin>>cost[R]>>cost[G]>>cost[B];

        dp[i][R] = std::min(dp[i - 1][G], dp[i - 1][B]) + cost[R];
        dp[i][G] = std::min(dp[i - 1][R], dp[i - 1][B]) + cost[G];
        dp[i][B] = std::min(dp[i - 1][R], dp[i - 1][G]) + cost[B];
    }

    std::cout<<std::min(std::min(dp[N][R], dp[N][G]),dp[N][B]);

    return 0;
}