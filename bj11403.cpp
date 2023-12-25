#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> g;

void Floyd_warshall()
{
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(g[i][k] && g[k][j])
                {
                    g[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    std::cin>>N;

    g.assign(N + 1, std::vector<int>(N + 1, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin>>g[i][j];
        }
    }

    Floyd_warshall();

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout<<g[i][j]<<" ";
        }
        std::cout<<'\n';
    }

    return 0;
}