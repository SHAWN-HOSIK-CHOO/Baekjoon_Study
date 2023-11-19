#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::vector<int> dp;

    std::cin>>N;

    dp.assign(N + 1,0);

    for(int i = 1; i <= N; i++)
    {
        dp[i] = i;

        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = std::min(dp[i],dp[i - j * j] + 1);
        }
    }

    std::cout<<dp[N];

    return 0;
}