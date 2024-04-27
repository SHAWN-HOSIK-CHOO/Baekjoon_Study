/*
    출처 : https://velog.io/@soosungp33/BOJ-2170%EB%B2%88-%EC%84%A0-%EA%B8%8B%EA%B8%B0C
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int,int>> v;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tmp1, tmp2;
    int ans = 0; 

    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>tmp1>>tmp2;
        v.push_back({tmp1, tmp2});
    }

    std::sort(v.begin(), v.end());
    int left = v[0].first; 
    int right = v[0].second;

    for(int i = 1; i < N; i++)
    {
        if(v[i].first <= right)
        {
            right = std::max(right, v[i].second);
        }
        else
        {
            ans += right - left;
            right = v[i].second;
            left = v[i].first;
        }
    }

    ans += right - left;

    std::cout<<ans<<'\n';

    return 0;
}