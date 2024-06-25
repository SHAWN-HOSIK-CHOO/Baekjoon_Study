#include <iostream>
#include <algorithm>

#define MAX 301

int N;
int stairs[MAX] = {0};
int dp[MAX] = {0};

int main()
{
    std::cin>>N;

    for(int i = 1; i <= N; i++)
    {
        std::cin>>stairs[i];
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = std::max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    for(int i = 4; i <= N; i++)
    {
        dp[i] = std::max(stairs[i] + dp[i - 2] , stairs[i] + stairs[i - 1] + dp[i -  3]);
    }

    std::cout<<dp[N]<<'\n';

    return 0;
}

