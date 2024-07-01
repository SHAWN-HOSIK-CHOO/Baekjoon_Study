#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define INF 10000000001
#define pii std::pair<ll,ll>

int N, M;
std::vector<std::vector<pii>> graph;
std::vector<ll> dist;
std::vector<int> visibility_vector;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; // { weight, node }

void Dijkstra(ll start)
{
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        ll cur_node = pq.top().second;
        ll cur_weight = pq.top().first;
        pq.pop();

        if(dist[cur_node] < cur_weight)
        {
            continue;
        }

        for(pii next_list : graph[cur_node])
        {
            ll next_node = next_list.first;
            ll next_cost = cur_weight + next_list.second;

            if(dist[next_node] > next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>M;
    graph.assign(N + 1, std::vector<pii>());
    dist.assign(N + 1, INF);
    visibility_vector.assign(N + 1, 0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>visibility_vector[i];
    }

    int from, to, weight;
    for(int i = 0; i < M; i++)
    {
        std::cin>>from>>to>>weight;

        if(visibility_vector[from] || visibility_vector[to])
        {
            if((from != N - 1) && (to != N - 1))
                continue;
        }

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    Dijkstra(0);

    if(dist[N - 1] == INF)
    {
        std::cout<<-1;
    }
    else
    {
        std::cout<<dist[N - 1];
    }

    return 0;
}