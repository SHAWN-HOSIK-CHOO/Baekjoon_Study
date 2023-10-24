#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

void BFS(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& tomato_count)
{
    std::queue<std::pair<int,int>> queue;
    std::vector<int> dx{-1,1,0,0};
    std::vector<int> dy{0,0,-1,1};
    for(int i = 0; i < graph.size(); i++)
    {   
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] == 1)
            {
                queue.push({i,j});
                tomato_count[i][j] = 1;
            }
        }
    }

    while (!queue.empty())
    {
        /* code */
        int xx = queue.front().first;
        int yy = queue.front().second;

        queue.pop();
        for(int i = 0; i < 4; i++)
        {
            int d_x = xx + dx[i];
            int d_y = yy + dy[i];

            if(d_x >= 0 && d_y >= 0 && d_x < graph.size() && d_y < graph[0].size() && tomato_count[d_x][d_y] == 0 && graph[d_x][d_y] == 0)
            {
                queue.push({d_x,d_y});
                tomato_count[d_x][d_y] = tomato_count[xx][yy] + 1;
            }
        }
    }
    
}

int main()
{
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> tomato_state;

    int M, N, cnt = 0;
    bool flag = false;

    std::cin>>M>>N;

    graph.assign(N,std::vector<int>(M,0));
    tomato_state.assign(N,std::vector<int>(M,0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin>>graph[i][j];
        }   
    }

    BFS(graph,tomato_state);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(graph[i][j] == 0 && tomato_state[i][j] == 0)
            {
                std::cout<<-1;
                flag = true;
                break;
            }

            if(cnt <= tomato_state[i][j])
            {
                cnt = tomato_state[i][j];
            }
        }
        if(flag)
        {
            break;
        }
    }

    if(!flag)
    {
        std::cout<<cnt - 1;
    }

    return 0;
}