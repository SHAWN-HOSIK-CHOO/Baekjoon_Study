#include <iostream>
#include <vector>
#define MAX 10001

int n, k;
int dp[MAX] = {0};
std::vector<int> coin;

int main()
{
    std::cin>>n>>k;

    int tmp;
    for(int i = 0; i < n; i++)
    {
        std::cin>>tmp;
        coin.push_back(tmp);
    }

    dp[0] = 1;

    for(int i : coin)
    {
        for(int j = i; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - i];
        }
    }

    std::cout<<dp[k];

    return 0;
}