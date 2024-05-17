#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

int n, m, s, t;
std::vector<std::vector<std::pair<int,int>>> graph;
std::vector<int> dist;

void Dijkstra()
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    pq.push({0,s});
    dist[s] = 0;

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curVert = pq.top().second;
        pq.pop();

        if(curVert == t)
        {
            std::cout<<curCost<<'\n';
            return;
        }

        for(int i = 0; i < graph[curVert].size(); i++)
        {
            int nextVert = graph[curVert][i].first;
            int nextCost = curCost + graph[curVert][i].second;

            if(nextCost < dist[nextVert])
            {
                dist[nextVert] = nextCost;
                pq.push({nextCost, nextVert});
            }
        }
    }
    
}

int main()
{
    std::cin>>n>>m;

    graph.assign(n + 1, std::vector<std::pair<int,int>>());
    dist.assign(n + 1, INF);

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    std::cin>>s>>t;

    Dijkstra();

    return 0;
}