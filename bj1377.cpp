/*
    출처 : https://tose33.tistory.com/1017
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, ans = -1;
std::vector<std::pair<int,int>> v;

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        int tmp1;
        std::cin>>tmp1;

        v.push_back({tmp1, i});
    }

    std::sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        ans = std::max(ans, v[i].second - i);
    }

    std::cout<<ans + 1;

    return 0;
}