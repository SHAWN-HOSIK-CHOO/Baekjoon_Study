/*
    출처 : https://hagisilecoding.tistory.com/139
*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>

int N, M;
std::vector<int> gDist;
std::vector<std::vector<std::pair<int,int>>> g;

void Dijkstra(int start)
{
    gDist[start] = 0;
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;

    pq.push({start,0});

    while (!pq.empty())
    {
        /* code */
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(gDist[cur] < cost)
        {
            continue;
        }

        for(int i = 0; i < g[cur].size(); i++)
        {
            int next = g[cur][i].first;
            int nextCost = g[cur][i].second;

            if(gDist[next] > nextCost + cost)
            {
                pq.push({next, nextCost + cost});
                gDist[next] = nextCost + cost;
            }
        }
    }
    
}

int main()
{
    int start_node, end_node;

    std::cin>>N>>M;

    gDist.assign(N + 1, std::numeric_limits<int>::max());
    g.assign(N + 1, std::vector<std::pair<int,int>>());

    g[0].push_back({0,0});

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    std::cin>>start_node>>end_node;

    Dijkstra(start_node);

    std::cout<<gDist[end_node];

    return 0;
}