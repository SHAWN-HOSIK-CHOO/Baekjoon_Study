#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::vector<int> wine;
    std::vector<int> dp;

    std::cin>>n;

    wine.assign(n + 1,0);
    dp.assign(n + 1,0);

    for(int i = 1; i <= n; i++)
    {
        std::cin>>wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for(int i = 3; i <= n; i++)
    {
        dp[i] = std::max(dp[i - 3] + wine[i - 1] + wine[i], std::max(dp[i - 2] + wine[i], dp[i - 1]));
    }

    std::cout<<dp[n];

    return 0;
}