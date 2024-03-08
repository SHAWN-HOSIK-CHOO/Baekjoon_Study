#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

int w, h, k = 0;
int map[201][201] = {0, };
bool visited[201][201][31] = {false, };

int monkeyDX[4] = {-1, 1, 0, 0};
int monkeyDY[4] = {0, 0, -1, 1};

int knightDX[8] = {1, 2,  1,  2, -1, -2, -1, -2};
int knightDY[8] = {2, 1, -2, -1,  2,  1, -2, -1};

int bfs()
{
    std::queue<std::pair<std::pair<int,int>,std::pair<int,int>>> q;
    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        int cur_h = q.front().first.first;
        int cur_w = q.front().first.second;
        int cur_cnt = q.front().second.second;
        int cur_knight_cnt = q.front().second.first;
        q.pop();

        if(cur_h == h - 1 && cur_w == w - 1) return cur_cnt;

        if(cur_knight_cnt < k)
        {
            for(int i = 0; i < 8; i++)
            {
                int hh = cur_h + knightDX[i];
                int ww = cur_w + knightDY[i];

                if(hh < 0 || hh >= h || ww < 0 || ww >= w || map[hh][ww] == 1
                    || visited[hh][ww][cur_knight_cnt + 1] == true) continue;

                visited[hh][ww][cur_knight_cnt + 1] = true;
                q.push({{hh, ww}, {cur_knight_cnt + 1, cur_cnt + 1}});
            }
        }

        for(int i = 0; i < 4; i++)
        {
            int hh = cur_h + monkeyDX[i];
            int ww = cur_w + monkeyDY[i];

            if(hh < 0 || hh >= h || ww < 0 || ww >= w || map[hh][ww] == 1
                || visited[hh][ww][cur_knight_cnt] == true) continue;

            visited[hh][ww][cur_knight_cnt] = true;
            q.push({{hh, ww}, {cur_knight_cnt, cur_cnt + 1}});
        }
    }
    
    return -1;
}

int main()
{
    std::cin>>k;
    std::cin>>w>>h;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            std::cin>>map[i][j];
        }
    }

    std::cout<<bfs();

    return 0;
}