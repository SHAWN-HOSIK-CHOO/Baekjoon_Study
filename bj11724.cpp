#include <iostream>
#include <vector>
#include <stack>

void DFS(std::vector<std::vector<int>>& g, std::vector<bool>& v, int start)
{
    std::stack<int> stack;
    stack.push(start);

    while (!stack.empty())
    {
        int idx = stack.top();
        stack.pop();

        if(v[idx])
        {
            continue;
        }

        v[idx] = true;
        for(int i = 0; i < g[idx].size(); i++)
        {
            if(g[idx][i] && !v[g[idx][i]])
            {
                stack.push(g[idx][i]);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int vert, edge, cnt = 0, temp1, temp2;
    std::vector<std::vector<int>> graph;
    std::vector<bool> visited;

    std::cin>>vert>>edge;
    for(int i = 0; i <= vert; i++)
    {
        graph.push_back(std::vector<int>());
    }

    for(int  i = 0; i < edge; i++)
    {
        std::cin>>temp1>>temp2;

        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    visited.resize(vert + 1,false);
    visited[0] = true;

    for(int i = 1; i <= vert; i++)
    {
        if(!visited[i])
        {
            DFS(graph,visited,i);
            cnt++;
        }
    }

    std::cout<<cnt;

    return 0;
}