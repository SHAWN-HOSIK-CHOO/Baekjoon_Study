#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

int N, M, ans = -987654321;
int map[51][51];
bool visited[51][51] = {false, };
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
std::vector<std::pair<int,int>> v;

int bfs(int a, int b)
{
    std::queue<std::pair<std::pair<int,int>, int>> q;
    q.push({{a, b}, 0});
    visited[a][b] = true;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(map[x][y] == 1) return cnt;

        for(int i = 0; i < 8; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx < 0 || xx >= N || yy < 0 || yy >= M || visited[xx][yy]) continue;

            visited[xx][yy] = true;
            q.push({{xx, yy}, cnt + 1});
        }
    }

    return -1;
}

int main()
{
    std::cin>>N>>M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin>>map[i][j];

            if(map[i][j] == 0) v.push_back({i, j});
        }
    }

    for(auto it : v)
    {
        memset(visited, false, sizeof(visited));
        ans = std::max(ans, bfs(it.first, it.second));
    }

    std::cout<<ans;

    return 0;
}