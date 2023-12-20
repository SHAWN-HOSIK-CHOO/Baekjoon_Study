#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int N, M, W;
std::vector<long long> Dist;
std::vector<std::pair<int,std::pair<int,int>>> E;

bool Bellman_Ford()
{
    Dist[1] = 0;

    for(int i = 1; i <= N - 1; i++)
    {
        for(int j = 0; j < E.size(); j++)
        {
            int From = E[j].second.first;
            int To = E[j].second.second;
            int Cost = E[j].first;

            if(Dist[To] > Dist[From] + Cost)
            {
                Dist[To] = Dist[From] + Cost;
            }
        }
    }

    for(int i = 0; i < E.size(); i++)
    {
        int From = E[i].second.first;
        int To = E[i].second.second;
        int Cost = E[i].first;

        if(Dist[To] > Dist[From] + Cost)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int TC;
    std::cin>>TC;

    for(int i = 0; i < TC; i++)
    {
        std::cin>>N>>M>>W;

        Dist.assign(N + 1, 30000000);
        E.clear();

        for(int j = 0; j < M; j++)
        {
            int s, e, t;

            std::cin>>s>>e>>t;

            E.push_back({t,{s,e}});
            E.push_back({t,{e,s}});
        }

        for(int j = 0; j < W; j++)
        {
            int s, e, t;

            std::cin>>s>>e>>t;

            E.push_back({-t,{s,e}});
        }

        if(Bellman_Ford())
        {
            std::cout<<"YES"<<'\n';
        }
        else
        {
            std::cout<<"NO"<<'\n';
        }
    }

    return 0;
}