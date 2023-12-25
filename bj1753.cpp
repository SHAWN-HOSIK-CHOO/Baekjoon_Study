#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

int V,E;
std::vector<int> gDist;
std::vector<std::vector<std::pair<int,int>>> gMap;

void Dijkstra(int start)
{
    gDist[start] = 0;
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;

    pq.push({0,start});

    while (!pq.empty())
    {
        /* code */
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(int i = 0; i < gMap[cur].size(); i++)
        {
            int next = gMap[cur][i].first;
            int nxtCost = gMap[cur][i].second;

            if(gDist[next] > nxtCost + cost)
            {
                pq.push({nxtCost + cost, next});
                gDist[next] = nxtCost + cost;
            }
        }
    }
    
}

int main()
{
    int start;

    std::cin>>V>>E>>start;

    gDist.assign(V + 1, std::numeric_limits<int>::max());
    gMap.assign(V + 1, std::vector<std::pair<int,int>>());

    for(int i = 0; i < E; i++)
    {
        int u, v, w;

        std::cin>>u>>v>>w;

        gMap[u].push_back({v,w});
    }

    Dijkstra(start);

    for(int i = 1; i <= V; i++)
    {
        if(gDist[i] == std::numeric_limits<int>::max())
        {
            std::cout<<"INF"<<'\n';
        }
        else
        {
            std::cout<<gDist[i]<<'\n';
        }
    }

    return 0;
}