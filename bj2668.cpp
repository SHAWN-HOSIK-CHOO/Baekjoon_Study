#include <iostream>
#include <vector>
#include <set>

int N;
std::vector<int> graph;
std::set<int> ans;
std::set<int> visited;

void DFS(int start, int node)
{
    if(visited.find(node) != visited.end())
    {
        ans.insert(node);
        return;
    }

    visited.insert(node);
    DFS(start, graph[node]);
    visited.erase(node);
}

int main()
{
    std::cin>>N;
    graph.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>graph[i];
    }

    for(int i = 1; i <= N; i++)
    {
        DFS(i, i);
    }

    std::cout<<ans.size()<<'\n';
    for(auto a : ans)
    {
        std::cout<<a<<'\n';
    }

    return 0;
}