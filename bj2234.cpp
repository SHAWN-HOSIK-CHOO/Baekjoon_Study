#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

int N, M, room_cnt = 0, big_room = 0;
int room[50][50];
bool visited[50][50] = {false, };

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int a, int b)
{
    int size = 0;
    std::queue<std::pair<int,int>> q;
    q.push({a, b});
    visited[a][b] = true;
    size++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int w = 1;

        for(int i = 0; i < 4; i++)
        {
            if((room[x][y] & w) != w)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if(xx < 0 || xx >= N || yy < 0 || yy >= M || visited[xx][yy]) 
                {
                    w = w << 1;
                    continue;
                }

                size++;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }

            w = w << 1;
        }
    }
    
    return size;
}

int main()
{
    std::cin>>M>>N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin>>room[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!visited[i][j])
            {
                big_room = std::max(big_room, bfs(i, j));
                room_cnt++;
            }
        }
    }

    std::cout<<room_cnt<<'\n';
    std::cout<<big_room<<'\n';

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int w = 1; w <= 8; w <<= 1)
            {
                if((room[i][j] & w) == w)
                {
                    memset(visited, false, sizeof(visited));
                    room[i][j] = room[i][j] - w;
                    big_room = std::max(big_room, bfs(i, j));
                    room[i][j] = room[i][j] + w;
                }
            }
        }
    }

    std::cout<<big_room<<'\n';

    return 0;
}