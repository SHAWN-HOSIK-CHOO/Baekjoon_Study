#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> card;

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

        card.push_back(tmp);
    }

    std::sort(card.begin(), card.end());

    std::cin>>M;

    for(int i = 0; i < M; i++)
    {
        int tmp;
        std::cin>>tmp;

        std::cout<<std::upper_bound(card.begin(), card.end(), tmp) - std::lower_bound(card.begin(), card.end(), tmp)<<" ";
    }

    return 0;
}