#include <iostream>
#include <algorithm>
#include <vector>

int main()
{   
    int N;
    std::vector<int> p;
    std::vector<int> dp;

    std::cin>>N;

    p.assign(N+1,0);
    dp.assign(N+1,0);

    for(int i = 1; i <= N; i++)
    {
        int temp;
        std::cin>>temp;

        p[i] = temp;
        dp[i] = temp;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i] = std::min(dp[i],dp[i - j] + p[j]);
        }
    }

    std::cout<<dp[N];

    return 0;
}