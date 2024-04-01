#include <iostream>
#include <vector>
#include <algorithm>

int R, C, ans = 0;
char map[20][20];
bool visited[26] = {false, };

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int cnt)
{
    ans = std::max(ans, cnt);

    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx < 0 || xx >= R || yy < 0 || yy >= C || visited[map[xx][yy] - 'A']) 
            continue;

        visited[map[xx][yy] - 'A'] = true;
        DFS(xx, yy, cnt + 1);
        visited[map[xx][yy] - 'A'] = false;
    }
}

int main()
{
    std::cin>>R>>C;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            std::cin>>map[i][j];
        }
    }

    visited[map[0][0] - 'A'] = true;

    DFS(0, 0, 1);

    std::cout<<ans;

    return 0;
}