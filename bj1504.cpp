#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define inf 987654321

int N, E, res = inf;
std::vector<std::vector<std::pair<int,int>>> graph;
std::vector<int> dist;

void Dijkstra(int start)
{
    dist.assign(N + 1, inf);
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;

            if(dist[next] > cur_cost + next_cost)
            {
                dist[next] = cur_cost + next_cost;
                pq.push({dist[next], next});
            }
        }
    }
    
}

int main()
{
    std::cin>>N>>E;
    graph.assign(N + 1, std::vector<std::pair<int,int>>());

    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    std::cin>>v1>>v2;

    Dijkstra(1);
    int one2v1 = dist[v1];
    int one2v2 = dist[v2];

    Dijkstra(v1);
    int v1_2_v2 = dist[v2];
    int v1_2_N  = dist[N];

    Dijkstra(v2);
    int v2_2_N = dist[N];

    res = std::min((one2v1 + v1_2_v2 + v2_2_N), (one2v2 + v1_2_v2 + v1_2_N));

    if(res >= inf || res <= 0)
    {
        res = -1;
    }

    std::cout<<res;

    return 0;
}