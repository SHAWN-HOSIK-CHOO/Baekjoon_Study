#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321

int V, E;
std::vector<std::vector<int>> graph;

int main()
{
    int ans = inf;

    std::cin>>V>>E;
    graph.assign(V + 1, std::vector<int>(V + 1, inf));

    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        graph[a][b] = c;
    }

    for(int k = 1; k <= V; k++)
    {
        for(int i = 1; i <= V; i++)
        {
            for(int j = 1; j <= V; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        ans = std::min(ans, graph[i][i]);
    }

    if(ans >= inf)
    {
        std::cout<<-1;
    }
    else
    {
        std::cout<<ans;
    }

    return 0;
}