#include <iostream>
#include <vector>

int V, E, cnt = 0;
std::vector<std::vector<int>> graph;
std::vector<int> visited;

void DFS(int n)
{
    visited[n] = true;

    for(int i = 0; i < graph[n].size(); i++)
    {
        int nxt = graph[n][i];

        if(visited[nxt] == false)
        {
            DFS(nxt);
            cnt++;
        }
    }
}

int main()
{
    std::cin>>V>>E;
    graph.assign(V + 1, std::vector<int>());
    visited.assign(V + 1, false);

    int tmp1, tmp2;

    for(int i = 0; i < E; i++)
    {
        std::cin>>tmp1>>tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    DFS(1);

    std::cout<<cnt;

    return 0;
}