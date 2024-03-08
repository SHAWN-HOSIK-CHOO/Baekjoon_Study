/*
    출처 : https://yabmoons.tistory.com/195
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

#define inf 987654321

int N;
char room[50][50] = {'*', };
int visited[50][50][4] = {0, };
std::pair<int, int> start, end;
std::queue<std::pair<std::pair<int, int>, int>> q;
bool isStart = true;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1 , -1, 0, 0};

std::pair<int,int> ChangeDir(int cur)
{
    std::pair<int,int> ret;
    if(cur == 0 || cur == 1)
    {
        ret.first = 2;
        ret.second = 3;
    }
    else if(cur == 2 || cur == 3)
    {
        ret.first = 0;
        ret.second = 1;
    }

    return ret;
}

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        int xx = x + dx[dir];
        int yy = y + dy[dir];
        std::pair<int,int> dd = ChangeDir(dir);

        if(xx < 0 || xx >= N || yy < 0 || yy >= N || room[xx][yy] == '*') continue;
        if(room[xx][yy] == '!')
        {
            if(visited[xx][yy][dir] > visited[x][y][dir])
            {
                visited[xx][yy][dir] = visited[x][y][dir];
                q.push({{xx, yy}, dir});
            }

            if(visited[xx][yy][dd.first] > visited[x][y][dir] + 1)
            {
                visited[xx][yy][dd.first] = visited[x][y][dir] + 1;
                q.push({{xx, yy}, dd.first});
            }

            if(visited[xx][yy][dd.second] > visited[x][y][dir] + 1)
            {
                visited[xx][yy][dd.second] = visited[x][y][dir] + 1;
                q.push({{xx, yy}, dd.second});
            }
        }
        else if(room[xx][yy] == '.')
        {
            if(visited[xx][yy][dir] > visited[x][y][dir])
            {
                visited[xx][yy][dir] = visited[x][y][dir];
                q.push({{xx, yy}, dir});
            }
        }
        else if(room[xx][yy] == '#')
        {
            if(visited[xx][yy][dir] > visited[x][y][dir])
            {
                visited[xx][yy][dir] = visited[x][y][dir];
            }
        }
    }
    
}

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin>>room[i][j];

            if(room[i][j] == '#' && isStart) 
            {
                start = {i, j};
                isStart = false;
            }

            if(room[i][j] == '#' && !isStart) end = {i, j};

            visited[i][j][0] = visited[i][j][1] = visited[i][j][2] = visited[i][j][3] = inf;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        q.push({{start.first, start.second}, i});
        visited[start.first][start.second][i] = 0;
    }

    bfs();

    int ans = inf;

    for(int i = 0; i < 4; i++)
    {
        ans = std::min(ans, visited[end.first][end.second][i]);
    }

    std::cout<<ans<<'\n';

    return 0;
}