/*
    도저히 안되겠어서 코드 참고했습니다
    https://m42-orion.tistory.com/61
    감사합니다 
*/
#include <iostream>
#include <vector>
#include <set>
#include <stack>

void Coloring_DFS(std::vector<std::vector<int>>& graph,std::vector<int>& color_vector,int start)
{
    if(!color_vector[start])
    {
        color_vector[start] = 1;
    }

    for(int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];

        if(!color_vector[next])
        {
            if(color_vector[start] == 1) color_vector[next] = 2;
            else if(color_vector[start] == 2) color_vector[next] = 1;
            Coloring_DFS(graph,color_vector,next);
        }
    }
    
}

bool isBipartiteGraph(std::vector<std::vector<int>>& graph, std::vector<int>& color_vector, int V)
{
    for(int i = 1; i < V; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(color_vector[i] == color_vector[graph[i][j]])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int K, V, E;
    std::vector<std::vector<int>> graph;
    std::vector<int> color_vector;

    std::cin>>K;

    while (K--)
    {
        std::cin>>V>>E;
        
        graph.assign(V+1, std::vector<int>(0,0));
        color_vector.assign(V + 1, 0);

        for(int i = 0; i < E; i++)
        {
            int temp1, temp2;
            std::cin>>temp1>>temp2;
            graph[temp1].push_back(temp2);
            graph[temp2].push_back(temp1);
        }

        for(int i = 1; i <= V; i++)
        {
            if(!color_vector[i])
            {
                Coloring_DFS(graph,color_vector,i);
            }
        }

        if(isBipartiteGraph(graph,color_vector,V))
        {
            std::cout<<"YES"<<'\n';
        }
        else
        {
            std::cout<<"NO"<<'\n';
        }
        
    }
    return 0;
}