#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define INF 987654321

int N, M, K, X;
std::vector<std::vector<int>> graph;
std::vector<int> visited;                   // Save distances here
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq; // first == length, second == vertex
std::set<int> ans_list;

void Dijkstra()
{
    pq.push({0, X});
    visited[X] = 0;

    while (!pq.empty())
    {
        int cur_length = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[cur_vertex].size(); i++)
        {
            int next_vertex = graph[cur_vertex][i];
            
            if(visited[next_vertex] > visited[cur_vertex] + 1)
            {
                visited[next_vertex] = visited[cur_vertex] + 1;
                pq.push({visited[next_vertex], next_vertex});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>M>>K>>X;
    graph.assign(N + 1, std::vector<int>());
    visited.assign(N + 1, INF);

    int tmp1, tmp2;

    for(int i = 0; i < M; i++)
    {
        std::cin>>tmp1>>tmp2;
        graph[tmp1].push_back(tmp2); // single-directed graph
    }

    Dijkstra();

    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == K)
            ans_list.insert(i);
    }

    if(ans_list.empty())
        std::cout<<-1<<'\n';
    else
    {
        for(auto ans : ans_list)
        {
            std::cout<<ans<<'\n';
        }
    }

    return 0;
}