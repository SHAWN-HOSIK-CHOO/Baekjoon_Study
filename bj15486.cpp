#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int N, ans = 0;
std::vector<int> dp;
std::vector<std::pair<int,int>> schedule; // T | P

int main()
{
    std::cin>>N;
    schedule.assign(N + 2, std::pair<int,int>());
    dp.assign(N + 2, 0);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>schedule[i].first>>schedule[i].second;
    }

    for(int i = 1; i <= N + 1; i++)
    {
        ans = std::max(ans, dp[i]);

        if(i + schedule[i].first > N + 1)
        {
            continue;
        }

        dp[i + schedule[i].first] = std::max(dp[i + schedule[i].first], ans + schedule[i].second);
    }

    std::cout<<ans;

    return 0;
}