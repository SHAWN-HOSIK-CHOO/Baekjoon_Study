#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

bool flag = false;

void BFS(std::vector<std::vector<int>>& chessboard, std::vector<std::vector<int>>& visited, std::pair<int,int> cur, std::pair<int,int> target)
{
    std::vector<int> dx{-2,-2,-1,-1,1,1,2,2};
    std::vector<int> dy{1,-1,2,-2,2,-2,1,-1};

    std::queue<std::pair<int,int>> queue;
    queue.push(cur);
    visited[cur.first][cur.second] = 1;

    while (!queue.empty())
    {
        /* code */
        int xx = queue.front().first;
        int yy = queue.front().second;

        queue.pop();

        if(std::make_pair(xx,yy) == target)
        {
            flag = true;
            return;
        }

        for(int i = 0; i < 8; i++)
        {
            int d_x = xx + dx[i];
            int d_y = yy + dy[i];

            if(d_x >= 0 && d_y >= 0 && d_x < chessboard.size() && d_y < chessboard.size() && visited[d_x][d_y] == 0)
            {
                queue.push({d_x,d_y});
                visited[d_x][d_y] = visited[xx][yy] + 1;
            }
        }
    }
    
}

int main()
{
    int T, M, cnt =0;
    int cur_X, cur_Y;
    int target_X, target_Y;
    std::vector<std::vector<int>> chessboard;
    std::vector<std::vector<int>> visited;

    std::cin>>T;

    for(int i = 0; i < T; i++)
    {
        std::cin>>M;

        chessboard.assign(M,std::vector<int>(M,0));
        visited.assign(M,std::vector<int>(M,0));
        cnt = 0;
        flag = false;

        std::cin>>cur_X>>cur_Y;
        std::cin>>target_X>>target_Y;

        BFS(chessboard,visited,{cur_X,cur_Y},{target_X,target_Y});

        if(flag)
        {
            cnt = visited[target_X][target_Y];
        }

        std::cout<<cnt - 1<<'\n';
    }

    return 0;
}