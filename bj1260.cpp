#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

void BFS(std::vector<std::vector<int>>& g, std::vector<bool>& v,int start)
{
    std::queue<int> queue;
    queue.push(start);

    while (!queue.empty())
    {
        int n_idx = queue.front();
        queue.pop();

        if(v[n_idx])
        {
            continue;
        }
        std::cout<<n_idx<<" ";
        v[n_idx] = true;

        for(int i = 0; i < g[n_idx].size(); i++)
        {
            if(g[n_idx][i] && !v[g[n_idx][i]])
            {
                queue.push(g[n_idx][i]);
            }
        }
    }
    
}

void DFS(std::vector<std::vector<int>>& g, std::vector<bool>& v,int start)
{
    std::stack<int> stack;
    stack.push(start);

    while(!stack.empty())
    {
        int n_idx = stack.top();
        stack.pop();

        if(v[n_idx])
        {
            continue;
        }

        std::cout<<n_idx<<" ";
        v[n_idx] = true;

        for(int i = g[n_idx].size() - 1; i >= 0; i--)
        {
            if(g[n_idx][i] && !v[g[n_idx][i]])
            {
                stack.push(g[n_idx][i]);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int Vertex, Edge, start, temp1, temp2;
    std::vector<std::vector<int>> graph;
    std::vector<bool> visited;

    std::cin>>Vertex>>Edge>>start;
    for(int i = 0; i <= Vertex; i++)
    {
        graph.push_back(std::vector<int>());
    }
    visited.resize(Vertex + 1, false);

    for(int i = 0; i < Edge; i++)
    {
        std::cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    for(auto& v : graph)
    {
        std::sort(v.begin(),v.end());
    }

    DFS(graph,visited,start);
    std::cout<<'\n';
    visited.clear();
    visited.resize(Vertex + 1, false);
    BFS(graph,visited,start);

    return 0;
}