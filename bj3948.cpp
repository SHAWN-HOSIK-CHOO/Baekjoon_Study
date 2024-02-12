/*
    출처 : https://nicotina04.tistory.com/76
*/
#include <iostream>
#include <vector>

int T, N;
std::vector<std::vector<long long>> dp;

long long zigzag(int n, int k)
{
    if(k == 0)
    {
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    long long& ret = dp[n][k];

    if(ret != - 1)
    {
        return ret;
    }

    return ret = zigzag(n, k - 1) + zigzag(n - 1, n - k);
}

int main()
{
    std::cin>>T;
    dp.assign(21, std::vector<long long>(21, -1));

    dp[0][0] = 1;

    for(int i = 0; i < T; i++)
    {
        std::cin>>N;

        if(N == 1)
        {
            std::cout<<1<<'\n';
        }
        else
        {
            std::cout<<zigzag(N, N) * 2<<'\n';
        }
    }

    return 0;
}