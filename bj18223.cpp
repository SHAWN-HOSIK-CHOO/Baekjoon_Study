/*
    최단경로는 여러개일 수 있다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii std::pair<int,int>
#define INF 987654321

int V, E, P;
bool g_CanSaveHim = false;
std::vector<std::vector<pii>> g_Graph;  // { vertex, weight }
std::vector<int> g_Dist;

int RunDijkstra(int start_node, int end_node)
{
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; // { current cost, vertex }
    g_Dist.assign(V + 1, INF);

    pq.push({0, start_node});
    g_Dist[start_node] = 0;

    while (!pq.empty())
    {
        int cur_vert = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if(cur_vert == end_node)
            return g_Dist[end_node];

        for(int i = 0; i < g_Graph[cur_vert].size(); i++)
        {
            int next_vert = g_Graph[cur_vert][i].first;
            int next_cost = cur_cost + g_Graph[cur_vert][i].second;

            if(g_Dist[next_vert] > next_cost)
            {
                g_Dist[next_vert] = next_cost;
                pq.push({next_cost, next_vert});
            }
        }
    }

    return g_Dist[end_node];
}

int main()
{
    std::cin>>V>>E>>P;
    g_Graph.assign(V + 1, std::vector<pii>());
    g_Dist.assign(V + 1, INF);

    int start, end, weight;

    for(int i = 0; i < E; i++)
    {
        std::cin>>start>>end>>weight;
        g_Graph[start].push_back({end, weight});
        g_Graph[end].push_back({start, weight});
    }

    g_CanSaveHim = (RunDijkstra(1, P) + RunDijkstra(P, V)) <= RunDijkstra(1, V);

    if(g_CanSaveHim)
        std::cout<<"SAVE HIM"<<'\n';
    else
        std::cout<<"GOOD BYE"<<'\n';

    return 0;
}