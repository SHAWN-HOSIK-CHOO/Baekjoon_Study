#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int N, M;
std::vector<std::pair<int,std::pair<int,int>>> E;
std::vector<long long> Dist;
bool isCycle = false;

void Bellman_Ford()
{
    Dist[1] = 0;
    for(int i = 1; i <= N - 1; i++)
    {
        for(int j = 0; j < E.size(); j++)
        {
            int From = E[j].second.first;
            int To = E[j].second.second;
            int Cost = E[j].first;

            if(Dist[From] == std::numeric_limits<long long>::max())
            {
                continue;
            }

            if(Dist[To] > Dist[From] + Cost)
            {
                Dist[To] = Dist[From] + Cost;
            }
        }
    }

    for(int j = 0; j < E.size(); j++)
    {
        int From = E[j].second.first;
        int To = E[j].second.second;
        int Cost = E[j].first;

        if(Dist[From] == std::numeric_limits<long long>::max())
        {
            continue;
        }

        if(Dist[To] > Dist[From] + Cost)
        {
            isCycle = true;
            return;
        }
    }
}

int main()
{
    std::cin>>N>>M;

    Dist.assign(N + 1, std::numeric_limits<long long>::max());
    E.assign(M + 1, std::pair<int,std::pair<int,int>>());

    for(int i = 0; i < M; i++)
    {
        int a,b,c;
        std::cin>>a>>b>>c;

        E.push_back({c,{a,b}});
    }

    Bellman_Ford();

    if(isCycle)
    {
        std::cout<<-1;
    }
    else
    {
        for(int i = 2; i <= N; i++)
        {
            if(Dist[i] == std::numeric_limits<long long>::max())
            {
                std::cout<<-1<<'\n';
            }
            else
            {
                std::cout<<Dist[i]<<'\n';
            }
        }
    }

    return 0;
}