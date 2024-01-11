#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> ans;

int main()
{
    int sum = 0;
    std::cin>>N;

    graph.assign(N + 1, std::vector<int>(N + 1, 0));
    ans.assign(N + 1, std::vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            std::cin>>graph[i][j];
            ans[i][j] = graph[i][j];
        }
    }

    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(k == i || k == j)
                {
                    continue;
                }

                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    std::cout<<-1;
                    return 0;
                }

                if(graph[i][j] == graph[i][k] + graph[k][j])
                {
                    ans[i][j] = 0;

                }
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            sum += ans[i][j];
        }
    }

    std::cout<<sum / 2;

    return 0;
}