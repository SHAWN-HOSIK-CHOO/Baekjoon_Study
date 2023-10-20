#include <iostream>
#include <vector>
#include <set>
#include <stack>

enum class Color
{
    NONE,RED,BLACK
};

void Coloring_DFS(std::vector<std::vector<int>>& graph, std::set<int>& visited, std::vector<Color>& color, int start)
{
    std::stack<int> stack;
    stack.push(start);

    Color cur_color = Color::RED;
    color[start] = cur_color;

    while (!stack.empty())
    {
        int idx = stack.top();
        stack.pop();
       
        if(visited.find(idx) == visited.end())
        {
            visited.insert(idx);

            if(cur_color == Color::RED)
            {
                cur_color = Color::BLACK;
            }
            else if(cur_color == Color::BLACK)
            {
                cur_color = Color::RED;
            }            

            for(int i = 0; i < graph[idx].size(); i++)
            {
                if(visited.find(graph[idx][i]) == visited.end())
                {
                    stack.push(graph[idx][i]);

                    color[graph[idx][i]] = cur_color;                    
                }
            }
        }
    }
    
}

// void Coloring_DFS(std::vector<std::vector<int>>& graph, std::set<int>& visited, std::vector<Color>& color, int start)
// {
//     if(visited.find(start) == visited.end())
//     {
//         visited.insert(start);
//         color[start] = Color::RED;
//     }

//     for(int i = 0; i < graph[start].size(); i++)
//     {
//         int next = graph[start][i];

//         if(visited.find(next) == visited.end())
//         {
//             if(color[start] == Color::RED) color[next] = Color::BLACK;
//             else if(color[start] == Color::BLACK) color[next] = Color::RED;
//             Coloring_DFS(graph,visited,color,next);
//         }
//     }
// }

bool isBipartiteGraph(std::vector<std::vector<int>>& graph, std::vector<Color>& color)
{
    for(int i = 1; i <= graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(color[i] == color[graph[i][j]])
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
    std::set<int> visited_set;
    std::vector<Color> color_vector;

    std::cin>>K;

    while (K--)
    {
        std::cin>>V>>E;

        color_vector.resize(V+1,Color::NONE);

        for(int i = 0; i <= V; i++)
        {
            graph.push_back(std::vector<int>());
        }

        for(int i = 0; i < E; i++)
        {
            int temp1, temp2;
            std::cin>>temp1>>temp2;
            graph[temp1].push_back(temp2);
            graph[temp2].push_back(temp1);
        }

        for(int i = 1; i <= V; i++)
        {
            if(visited_set.find(i) == visited_set.end())
            {
                Coloring_DFS(graph,visited_set,color_vector,i);
            }
        }

        if(isBipartiteGraph(graph,color_vector))
        {
            std::cout<<"YES"<<'\n';
        }
        else
        {
            std::cout<<"NO"<<'\n';
        }


        //Debug
        /*
        for(auto v : color_vector)
        {
            if(v == Color::RED)
            {
                std::cout<<"RED"<<" ";
            }
            else if(v == Color::BLACK)
            {
                std::cout<<"BLACK"<<" ";
            }
            else
            {
                std::cout<<"NONE"<<" ";
            }
        }

        */
        // Clearing everything for the next loop
        // Clear Graph
        for(int i = 0; i <= V; i++)
        {
            graph[i].clear();
        }
        graph.clear();

        //Clear visited set
        visited_set.clear();
    }
    return 0;
}