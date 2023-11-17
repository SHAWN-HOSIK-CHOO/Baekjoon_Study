/*
    https://tooo1.tistory.com/151
    코드 참고했습니다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, max = 0, ans = 0;
    int index = 0;
    std::vector<int> v;
    std::vector<int> dp;
    std::vector<int> s;

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

        for(int j = 0; j < i; j++)
        {
            if(v[i] > v[j])
            {
                max = std::max(max,dp[j]);
            }
        }

        dp[i] = max + 1;

        ans = std::max(dp[i], ans);
    }

    for(int i = 0; i < N; i++)
    {
        if(dp[i] == ans)
        {
            index = i;
        }
    }

    s.push_back(v[index]);
    ans--;

    for(int i = index - 1; i >= 0; i--)
    {
        if(dp[i] == ans)
        {
            s.push_back(v[i]);
            ans--;
        }
    }

    std::cout<<s.size()<<'\n';

    std::reverse(s.begin(),s.end());

    for(int i = 0; i < s.size(); i++)
    {
        std::cout<<s[i]<<" ";
    }

    return 0;
}