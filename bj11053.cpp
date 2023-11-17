/*
    출처 : https://hwan-shell.tistory.com/299
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, lengt, max, ans = 0;
    std::vector<int> v;
    std::vector<int> dp;

    std::cin>>N;

    v.assign(N,0);
    dp.assign(N,0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>v[i];
    }

    for(int i = 0; i < N; i++)
    {
        max = 0;

        for(int j = 0; j < i + 1; j++)
        {
            if(v[i] > v[j])
            {
                if(max < dp[j])
                {
                    max = dp[j];
                }
            }
        }

        dp[i] = max + 1;
        ans = std::max(ans,dp[i]);
    }

    std::cout<<ans;

    return 0;
}