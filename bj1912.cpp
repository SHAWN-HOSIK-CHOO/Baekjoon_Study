#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, max;
    std::vector<int> v;
    std::vector<int> dp;

    std::cin>>n;

    v.assign(n,0);
    dp.assign(n,0);

    for(int i = 0; i < n; i++)
    {
        std::cin>>v[i];
    }

    max = v[0];
    dp[0] = max;
    
    for(int i = 1; i < n; i++)
    {
        dp[i] = std::max(dp[i - 1] + v[i], v[i]);
        max = std::max(dp[i],max);
    }

    std::cout<<max;

    return 0;
}