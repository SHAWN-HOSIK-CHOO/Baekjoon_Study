#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii std::pair<int,int>
#define INF 987654321

int n, m, r, curMax = 0;
std::vector<std::vector<pii>> g_Graph;
std::priority_queue<pii, std::vector<pii>,std::greater<pii>> pq;
std::vector<int> g_Dist;
std::vector<int> g_ItemCount;

int Dijkstra(int startNode)
{
    g_Dist[startNode] = 0;
    int retVal = 0;
    pq.push({0, startNode});

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        for(int i = 0; i < g_Graph[curNode].size(); i++)
        {
            int nextNode = g_Graph[curNode][i].first;
            int nextCost = g_Graph[curNode][i].second;

            if(g_Dist[nextNode] > curCost + nextCost)
            {
                g_Dist[nextNode] = curCost + nextCost;
                pq.push({g_Dist[nextNode], nextNode});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(g_Dist[i] <= m)
        {
            retVal += g_ItemCount[i];
        }
    }

    return retVal;
}

int main()
{
    std::cin>>n>>m>>r;

    g_Graph.assign(n + 1, std::vector<pii>());
    g_Dist.assign(n + 1, INF);
    g_ItemCount.assign(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        int tmp;
        std::cin>>tmp;

        g_ItemCount[i] = tmp;
    }

    for(int i = 0; i < r; i++)
    {
        int tmp1, tmp2, w;
        std::cin>>tmp1>>tmp2>>w;

        g_Graph[tmp1].push_back({tmp2, w});
        g_Graph[tmp2].push_back({tmp1, w});
    }

    for(int i = 0; i < n; i++)
    {
        g_Dist.assign(n + 1, INF);
        curMax = std::max(curMax, Dijkstra(i));
    }

    std::cout<<curMax<<'\n';

    return 0;
}