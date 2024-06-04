#include <iostream>
#include <vector>

int n;
std::vector<int> dp;

int main()
{
    dp.resize(41);

    dp[0] = 0;
    dp[1] = dp[2] = 1;

    for(int i = 3; i < 41; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cin>>n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin>>tmp;

        if(tmp == 0)
            std::cout<<1<<' '<<0<<'\n';
        else if(tmp == 1)
            std::cout<<0<<' '<<1<<'\n';
        else
            std::cout<<dp[tmp - 1]<<' '<<dp[tmp]<<'\n';
    }

    return 0;
}