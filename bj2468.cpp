#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

int N, ans = -1;
int map[101][101] = {0};
bool visited[101][101] = {false};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y)
{
    visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
            continue;
        
        if(visited[nextX][nextY])
            continue;

        DFS(nextX, nextY);
    }
}

int CountSafeArea(int rainHeight)
{
    int retCount = 0;
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //물에 잠긴 지역을 방문한 지역으로 간주한다.
            if(map[i][j] - rainHeight < 0)
            {
                visited[i][j] = true;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(visited[i][j] == false)
            {
                DFS(i, j);
                retCount++;
            }
        }
    }

    return retCount;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int tmp;
            std::cin>>tmp;

            map[i][j] = tmp;
        }
    }

    for(int i = 1; i <= 100; i++)
    {
        ans = std::max(ans, CountSafeArea(i));
    }

    std::cout<<ans<<'\n';

    return 0;
}

