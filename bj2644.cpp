#include <iostream>
#include <vector>
#include <algorithm>

int n, m, dist = -1, start, end;
std::vector<std::vector<int>> g_Family;
std::vector<bool> g_Visited;

void DFS(int node, int distance)
{
    if(g_Visited[node] == true)
        return;

    g_Visited[node] = true;

    if(node == end)
    {
        dist = distance;
        return;
    }

    for(int i = 0; i < g_Family[node].size(); i++)
    {
        int nextNode = g_Family[node][i];

        if(g_Visited[nextNode] == true)
            continue;
        
        DFS(nextNode, distance + 1);
    }
}

int main()
{
    std::cin>>n;
    g_Family.assign(n + 1, std::vector<int>());
    g_Visited.assign(n + 1, false);

    std::cin>>start>>end;

    std::cin>>m;
    int tmp1, tmp2;
    for(int i = 0; i < m; i++)
    {
        std::cin>>tmp1>>tmp2;
        g_Family[tmp1].push_back(tmp2);
        g_Family[tmp2].push_back(tmp1);
    }

    DFS(start, 0);

    std::cout<<dist;

    return 0;
}