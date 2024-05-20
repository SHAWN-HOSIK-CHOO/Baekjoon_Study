#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> v;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    std::cin>>M;

    for(int i = 0 ; i < M; i++)
    {
        int tmp;
        std::cin>>tmp;

        if(std::binary_search(v.begin(), v.end(), tmp))
        {
            std::cout<<1<<'\n';
        }
        else
        {
            std::cout<<0<<'\n';
        }
    }

    return 0;
}