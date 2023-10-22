#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

void DFS(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& visited, int x, int y, int width, int height)
{
    std::stack<std::pair<int,int>> stack;
    stack.push({x,y});
    visited[x][y] = 1;

    std::vector<int> deltaX{-1,-1,-1,0, 0,1,1, 1};
    std::vector<int> deltaY{ 1, 0,-1,1,-1,1,0,-1};

    while (!stack.empty())
    {
        int xx = stack.top().first;
        int yy = stack.top().second;
        stack.pop();

        for(int i = 0; i < 8; i++)
        {
            int dx = xx + deltaX[i];
            int dy = yy + deltaY[i];

            if(dx >= 0 && dy >= 0 && dx < height && dy < width && visited[dx][dy] == 0 && graph[dx][dy] == 1)
            {
                stack.push({dx,dy});
                visited[dx][dy] = 1;
            }
        }
    }
    
}

int main()
{
    std::vector<int> ans;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> visited;
    int width = 0, height = 0;
    int cnt = 0;

    while (true)
    {
        std::cin>>width>>height;
        if(!width && !height)
        {
            break;
        }

        graph.assign(height,std::vector<int>(width,0));
        visited.assign(height,std::vector<int>(width,0));

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                std::cin>>graph[i][j];
            }
        }

    /*
        std::cout<<"DEBUG GRAPH"<<'\n';
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                std::cout<<graph[i][j];
            }
            std::cout<<'\n';
        }

        std::cout<<"DEBUG VISITED"<<'\n';
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                std::cout<<visited[i][j];
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';

    */

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(graph[i][j] == 1 && visited[i][j] == 0)
                {
                    DFS(graph,visited,i,j,width,height);
                    cnt++;
                }
            }
        }
        

        ans.push_back(cnt);

        // Clear Everything
        for(auto g : graph)
        {
            g.clear();
        }
        graph.clear();

        for(auto v : visited)
        {
            v.clear();
        }
        visited.clear();
        cnt = 0;
    }

    for(auto a : ans)
    {
        std::cout<<a<<'\n';
    }
    
    return 0;
}