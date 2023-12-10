/*
    출처 : https://gamedoridori.tistory.com/73
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

int N,M, gCount = 0;
bool flag = false;
std::vector<std::vector<int>> maze;
std::vector<std::vector<bool>> visited;
std::vector<int> dx{-1,1,0,0};
std::vector<int> dy{0,0,-1,1};

void BFS()
{
    std::queue<std::pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;

    while (!q.empty())
    {
        /* code */
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == N - 1 && y == M - 1)
        {
            std::cout<<gCount<<'\n';
            flag = true;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx >= 0 && yy >= 0 && xx < N && yy < M )
            {
                if(!visited[xx][yy])
                {
                    visited[xx][yy] = true;
                    
                    if(maze[xx][yy] == 0)
                    {
                        q.push({xx,yy});
                    }
                    else
                    {
                        maze[xx][yy] = 0;
                    }
                }
            }

        }
    }
    gCount++;
}

int main()
{
    std::cin>>M>>N;

    maze.assign(N, std::vector<int>(M,0));
    std::string s;

    for(int i = 0; i < N; i++)
    {
        std::cin>>s;
        for(int j = 0; j < M; j++)
        {
            maze[i][j] = s[j] - 48;
        }
    }

    while (true)
    {
        /* code */
        visited.assign(N, std::vector<bool>(M,false));
        BFS();

        if(flag)
        {
            break;
        }
    }
    

    return 0;
}