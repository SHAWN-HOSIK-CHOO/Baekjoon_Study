/*
    출처 : https://jungahshin.tistory.com/57
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define inf 987654321

int n, m, k;
std::vector<std::vector<std::pair<int,int>>> graph;
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
std::priority_queue<int> dist[1001];

void Dijkstra(int start)
{
    dist[start].push(0);
    pq.push({0, 1});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second + cost;

            if(dist[next].size() < k)
            {
                dist[next].push(next_cost);
                pq.push({next_cost, next});
            }
            else
            {
                if(dist[next].top() > next_cost)
                {
                    dist[next].pop();
                    dist[next].push(next_cost);
                    pq.push({next_cost, next});
                }
            }
        }
    }
    
}

int main()
{
    std::cin>>n>>m>>k;
    graph.assign(n + 1, std::vector<std::pair<int,int>>());
    
    for(int i = 0; i< m; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        graph[a].push_back({b, c});
    }

    Dijkstra(1);

    for(int i = 1; i <= n; i++)
    {
        if(dist[i].size() < k)
        {
            std::cout<<-1<<'\n';
        }
        else
        {
            std::cout<<dist[i].top()<<'\n';
        }
    }

    return 0;
}