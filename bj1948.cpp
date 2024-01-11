/*
    출처 : https://yabmoons.tistory.com/443
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n, m, cnt = 0, start, end;
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<std::vector<std::pair<int, int>>> reverse_graph;
std::vector<int> cost;
std::vector<int> inDegree;
std::vector<bool> visited;

void TopologySort()
{
    std::queue<std::pair<int, int>> q;

    q.push({start, 0});

    while(!q.empty())
    {
        int cur = q.front().first;
        int cur_cost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nxt_cost = graph[cur][i].second;

            inDegree[next]--;

            if(cost[next] < cost[cur] + nxt_cost)
            {
                cost[next] = cost[cur] + nxt_cost;
            }

            if(inDegree[next] == 0)
            {
                q.push({next, cost[next]});
            }
        }
    }
}

void Longest()
{
    std::queue<int> q;
    q.push(end);
    visited[end] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < reverse_graph[cur].size(); i++)
        {
            int prev = reverse_graph[cur][i].first;
            int prev_cost = reverse_graph[cur][i].second;

            if(cost[cur] - prev_cost == cost[prev])
            {
                cnt++;
                if(!visited[prev])
                {
                    visited[prev] = true;
                    q.push(prev);
                }
            }
        }
    }
    
}

int main()
{
    std::cin>>n>>m;
    graph.assign(n + 1, std::vector<std::pair<int,int>>());
    reverse_graph.assign(n + 1, std::vector<std::pair<int, int>>());
    cost.assign(n + 1, 0);
    inDegree.assign(n + 1, 0);
    visited.assign(n + 1, false);

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        graph[a].push_back({b, c});
        reverse_graph[b].push_back({a, c});
        inDegree[b]++;
    }

    std::cin>>start>>end;

    TopologySort();
    Longest();

    std::cout<<cost[end]<<'\n';
    std::cout<<cnt<<'\n';

    return 0;
}