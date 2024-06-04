#include <iostream>
#include <vector>

int N, M, start = 0, end = 0, number = 0;
std::vector<int> g_Bracket;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>M;
    g_Bracket.assign(N + 1, 0);

    for(int cnt = 1; cnt <= M; cnt++)
    {
        std::cin>>start>>end>>number;

        for(int i = start; i <= end; i++)
        {
            g_Bracket[i] = number;
        }
    }
    g_Bracket.erase(g_Bracket.begin());

    for(auto v : g_Bracket)
    {
        std::cout<<v<<' ';
    }

    return 0;
}