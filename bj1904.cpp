#include <iostream>
#include <vector>

#define MOD 15746
#define ll long long

int N;
std::vector<ll> dp;

int main()
{
    std::cin>>N;
    dp.assign(N + 1, 0);

    if(N >= 2)
    {
        dp[1] = 1;
        dp[2] = 2;
    }
    else
    {
        dp[1] = 1;
    }

    for(int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    std::cout<<dp[N];

    return 0;
}