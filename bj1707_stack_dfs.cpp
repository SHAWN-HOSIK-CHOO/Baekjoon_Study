#include <iostream>
#include <vector>
#include <set>
#include <stack>

bool flag = true;

void Coloring_DFS(std::vector<std::vector<int>>& graph, std::vector<int>& visitedNColor, int start)
{
    std::stack<int> stack;
    stack.push(start);

    visitedNColor[start] = 1;

    while (!stack.empty())
    {
        int idx = stack.top();
        stack.pop();
        for(auto next : graph[idx])
        {
            if(visitedNColor[next] == 0)
            {   
                //stack.push(idx);
                stack.push(next);
                visitedNColor[next] = visitedNColor[idx] * -1;
            }
            else if(visitedNColor[next] + visitedNColor[idx] != 0)
            {
                flag = false;
                return;
            }
        }
    }
}

int main()
{
    int K, V, E;
    std::vector<std::vector<int>> graph;
    std::vector<int> visited_color;
 

    std::cin>>K;

    while (K--)
    {
        std::cin>>V>>E;

        for(int i = 0; i <= V; i++)
        {
            graph.push_back(std::vector<int>());
        }

        visited_color.assign(V+1,0);

        flag = true;

        for(int i = 0; i < E; i++)
        {
            int temp1, temp2;
            std::cin>>temp1>>temp2;
            graph[temp1].push_back(temp2);
            graph[temp2].push_back(temp1);
        }

        for(int i = 1; i <= V; i++)
        {
            if(flag == false) break;
            if(visited_color[i] == 0)
            {
                Coloring_DFS(graph,visited_color,i);
            }
        }

        if(!flag)
        {
            std::cout<<"NO"<<'\n';
        }
        else
        {
            std::cout<<"YES"<<'\n';
        }

        // Clearing everything for the next loop
        // Clear Graph
        for(int i = 0; i <= V; i++)
        {
            graph[i].clear();
        }
        graph.clear();

        //Clear visited 
        visited_color.clear();
    }
    return 0;
}