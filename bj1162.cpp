/*
    출처 : https://ssinee.tistory.com/entry/%EB%B0%B1%EC%A4%80-1162%EB%B2%88-%EB%8F%84%EB%A1%9C%ED%8F%AC%EC%9E%A5-C
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define inf 987654321000

int N, M, K;
std::vector<std::vector<std::pair<int,int>>> graph;
std::vector<std::vector<long long>> dist;

void Dijkstra(int start)
{
    std::priority_queue<std::pair<long long, std::pair<int,int>>> pq;
    dist[start][0] = 0;
    pq.push({0, {start, 0}});

    while(!pq.empty())
    {
        int cur = pq.top().second.first;
        int k = pq.top().second.second;
        long long cost = -pq.top().first;
        pq.pop();

        if(cost > dist[cur][k])
        {
            continue;
        }

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            long long next_cost = graph[cur][i].second + cost;

            if(dist[next][k] > next_cost)
            {
                dist[next][k] = next_cost;
                pq.push({-next_cost,{next, k}});
            }

            if(dist[next][k + 1] > cost && k + 1 <= K)
            {
                dist[next][k + 1] = cost;
                pq.push({-cost, {next, k + 1}});
            }
        }
    }
}

int main()
{
    std::cin>>N>>M>>K;
    graph.assign(N + 1, std::vector<std::pair<int,int>>());
    dist.assign(N + 1, std::vector<long long>(21, inf));

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    Dijkstra(1);
    
    long long ans = inf;

    for(int i = 0; i <= K; i++)
    {
        ans = std::min(ans, dist[N][i]);
    }

    std::cout<<ans;

    return 0;
}