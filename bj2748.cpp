#include <iostream>

#define ll long long

ll dp[91] = {0};
int n;

int main()
{
    dp[0] = 0; 
    dp[1] = 1;

    for(int i = 2; i <= 90; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cin>>n;
    std::cout<<dp[n];

    return 0;
}