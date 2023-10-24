#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

void BFS(std::vector<std::string>& graph, std::vector<std::vector<int>>& distance, int x, int y)
{
    std::queue<std::pair<int,int>> queue;
    queue.push({x,y});

    std::vector<int> dx{-1,1,0,0};
    std::vector<int> dy{0,0,1,-1};

    distance[x][y] = 1;

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

            if(d_x >= 0 && d_y >= 0 && d_x < graph.size() && d_y < graph[i].size() && distance[d_x][d_y] == 0 && graph[d_x][d_y] == '1')
            {
                queue.push({d_x,d_y});
                distance[d_x][d_y] = distance[xx][yy] + 1;
            }
        }
    }
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,M;
    std::vector<std::string> graph;
    std::vector<std::vector<int>> visitedNDistance;

    std::cin>>N>>M;

    graph.assign(N,"");
    visitedNDistance.assign(N,std::vector<int>(M,0));

    for(int i = 0; i < N; i++)
    {
        std::cin>>graph[i];
    }

    BFS(graph,visitedNDistance,0,0);

    std::cout<<visitedNDistance[N-1][M-1];

    return 0;
}