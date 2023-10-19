#include <iostream>
#include <stack>
#include <vector>

void DFS(std::vector<std::vector<int>>& g, std::vector<int>& c, int start)
{

}

int main()
{
    int K, V, E, temp1, temp2;
    std::vector<std::vector<int>> graph;
    std::vector<int> offset;
    // color == 0 means unvisited vertex
    std::vector<int> color;

    offset.push_back(1);
    // At index 0 -> not using it
    graph.push_back(std::vector<int>());

    std::cin>>K;

    for(int i = 1; i <= K; i++)
    {
        std::cin>>V>>E;
        offset.push_back(V + offset[i - 1]);

        for(int j = 0; j < V; j++ )
        {
            graph.push_back(std::vector<int>());
        }

        for(int k = 0; k < E; k++)
        {   
            std::cin>>temp1>>temp2;
            graph[temp1].push_back(temp2);
            graph[temp2].push_back(temp1);
        }
    }

    
    
    return 0;
}