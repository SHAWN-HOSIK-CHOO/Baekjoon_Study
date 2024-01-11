#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int N;
std::vector<std::vector<int>> graph;

int main()
{
    std::cin>>N;
    graph.assign(N, std::vector<int>(N, 0));

    std::string input;

    for(int i = 0; i < N; i++)
    {
        std::cin>>input;

        for(int j = 0; j < N; j++)
        {
            if(input[j] == 'Y')
            {
                graph[i][j] = 1;
            }
            else
            {
                graph[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(graph[i][j] && graph[j][i])
            {
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
    }

    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(graph[i][k] && graph[k][j])
                {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(graph[i][i] == 1)
        {
            std::cout<<"NO";
            return 0;
        }
    }

    std::cout<<"YES";

    return 0;
}
