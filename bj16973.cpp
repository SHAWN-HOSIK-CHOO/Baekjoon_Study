/*
    출처 : https://yabmoons.tistory.com/279
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, H, W, Sr, Sc, Fr, Fc;
std::vector<std::vector<int>> board;
std::vector<std::vector<bool>> visited;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool Approved(int r, int c, int op)
{
    if(op == 0)
    {
        for(int i = r; i < r + H; i++)
        {
            if(board[i][c] == 1)
            {
                return false;
            }
        }
    }
    else if(op == 1)
    {
        int y = c + W - 1;
        if(y >= M)
        {
            return false;
        }

        for(int i = r; i < r + H; i++)
        {
            if(board[i][y] == 1)
            {
                return false;
            }
        }
    }
    else if(op == 2)
    {
        for(int i = c; i < c + W; i++)
        {
            if(board[r][i] == 1)
            {
                return false;
            }
        }
    }
    else if(op == 3)
    {
        int x = r + H - 1;
        if(x >= N)
        {
            return false;
        }

        for(int i = c; i < c + W; i++)
        {
            if(board[x][i] == 1)
            {
                return false;
            }
        }
    }

    return true;
}

void bfs()
{
    std::queue<std::pair<std::pair<int,int>, int>> q;
    q.push({{Sr, Sc}, 0});
    visited[Sr][Sc] = true;

    while (!q.empty())
    {
        int cur_pos_x = q.front().first.first;
        int cur_pos_y = q.front().first.second;
        int cur_cnt = q.front().second;
        q.pop();

        if(cur_pos_x == Fr && cur_pos_y == Fc)
        {
            std::cout<<cur_cnt<<'\n';
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int xx = cur_pos_x + dx[i];
            int yy = cur_pos_y + dy[i];

            if(xx >= 0 && xx < N && yy >= 0 && yy < M)
            {
                if(!visited[xx][yy])
                {
                    if(Approved(xx, yy, i))
                    {
                        visited[xx][yy] = true;
                        q.push({{xx, yy}, cur_cnt + 1});
                    }
                }
            }
        }
    }
    std::cout<<-1<<'\n';
}

int main()
{
    std::cin>>N>>M;
    board.assign(N, std::vector<int>(M, 0));
    visited.assign(N, std::vector<bool>(M, false));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin>>board[i][j];
    
        }
    }

    std::cin>>H>>W>>Sr>>Sc>>Fr>>Fc;
    Sr--;
    Sc--;
    Fr--;
    Fc--;
    
    bfs();

    return 0;
}
