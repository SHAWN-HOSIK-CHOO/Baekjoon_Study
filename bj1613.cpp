#include <iostream>
#include <vector>
#include <algorithm>

int n, k, s;
std::vector<std::vector<int>> graph;

void Floyd()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][j] != 0)
                {
                    continue;
                }

                if(graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>k;
    graph.assign(n + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i < k; i++)
    {
        int a, b;
        std::cin>>a>>b;

        graph[a][b] = -1;
        graph[b][a] = 1;
    }

    Floyd();

    std::cin>>s;

    for(int i = 0; i < s; i++)
    {
        int a, b;
        std::cin>>a>>b;

        std::cout<<graph[a][b]<<'\n';
    }

    return 0;
}