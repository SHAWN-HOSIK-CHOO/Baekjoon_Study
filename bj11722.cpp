#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, ans = 0;
    std::vector<int> dp;
    std::vector<int> array;

    std::cin>>N;

    dp.assign(N,1);
    array.assign(N,0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>array[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(array[i] < array[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        ans = std::max(ans, dp[i]);
    }

    std::cout<<ans;

    return 0;
}