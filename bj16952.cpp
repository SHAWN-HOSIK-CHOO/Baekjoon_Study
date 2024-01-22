#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max 11

struct Actor
{
    int x;
    int y;
    int type;
    int departure;
    int time_count = 0;
    int change_count = 0;
};

int N;
std::vector<std::vector<int>> gChess;
std::pair<int,int> gStart;
std::pair<int,int> gVisited[max][max][max * max][3];
int dX_knight[8] = {-2,-1,1,2,2,1,-1,-2};
int dY_knight[8] = {1,2,2,1,-1,-2,-2,-1};
int dX_bishop[4] = {-1,1,1,-1};
int dY_bishop[4] = {1,1,-1,-1};
int dX_look[4] = {0,0,1,-1};
int dY_look[4] = {1,-1,0,0};

bool isInRange(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >= N)
    {
        return false;
    }

    return true;
}

std::pair<int,int> bfs()
{
    std::pair<int,int> ret{-1, -1};
    std::queue<Actor> q;
    q.push({gStart.first, gStart.second, 0, 1, 0, 0});
    q.push({gStart.first, gStart.second, 1, 1, 0, 0});
    q.push({gStart.first, gStart.second, 2, 1, 0, 0});
    gVisited[gStart.first][gStart.second][1][0] = std::make_pair(0, 0);
    gVisited[gStart.first][gStart.second][1][1] = std::make_pair(0, 0);
    gVisited[gStart.first][gStart.second][1][2] = std::make_pair(0, 0);

    while (!q.empty())
    {
        Actor cur = q.front();
        q.pop();
        std::pair<int,int> tmp = gVisited[cur.x][cur.y][cur.departure][cur.type];

        if(cur.departure == N * N)
        {
            if(ret.first == -1 || ret > tmp)
            {
                ret = tmp;
            }
        }

        if(cur.type == 0)
        {
            for(int i = 0; i < 8; i++)
            {
                int nextX = cur.x + dX_knight[i];
                int nextY = cur.y + dY_knight[i];
                int departure = cur.departure;

                if(!isInRange(nextX, nextY))
                {
                    continue;
                }

                if(cur.departure + 1 == gChess[nextX][nextY])
                {
                    departure++;
                }

                std::pair<int,int> p = std::make_pair(tmp.first + 1, tmp.second);

                if((gVisited[nextX][nextY][departure][cur.type]).first == -1 ||
                    ((gVisited[nextX][nextY][departure][cur.type]) > p))
                {
                    gVisited[nextX][nextY][departure][cur.type] = p;
                    q.push({nextX, nextY, cur.type, departure, cur.time_count + 1, cur.change_count});
                }
            }
        } 
        else if(cur.type == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 1; j < N; j++)
                {
                    int nextX = cur.x + dX_bishop[i] * j;
                    int nextY = cur.y + dY_bishop[i] * j;
                    int departure = cur.departure;

                    if(!isInRange(nextX, nextY))
                    {
                        break;
                    }

                    if(cur.departure + 1 == gChess[nextX][nextY])
                    {
                        departure++;
                    }

                   std::pair<int,int> p = std::make_pair(tmp.first + 1, tmp.second);

                    if((gVisited[nextX][nextY][departure][cur.type]).first == -1 ||
                        ((gVisited[nextX][nextY][departure][cur.type]) > p))
                    {
                        gVisited[nextX][nextY][departure][cur.type] = p;
                        q.push({nextX, nextY, cur.type, departure, cur.time_count + 1, cur.change_count});
                    }
                }
            }
        }
        else if(cur.type == 2)
        {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 1; j < N; j++)
                {
                    int nextX = cur.x + dX_look[i] * j;
                    int nextY = cur.y + dY_look[i] * j;
                    int departure = cur.departure;

                    if(!isInRange(nextX, nextY))
                    {
                        break;
                    }

                    if(cur.departure + 1 == gChess[nextX][nextY])
                    {
                        departure++;
                    }

                    std::pair<int,int> p = std::make_pair(tmp.first + 1, tmp.second);

                    if((gVisited[nextX][nextY][departure][cur.type]).first == -1 ||
                        ((gVisited[nextX][nextY][departure][cur.type]) > p))
                    {
                        gVisited[nextX][nextY][departure][cur.type] = p;
                        q.push({nextX, nextY, cur.type, departure, cur.time_count + 1, cur.change_count});
                    }
                }
            }
        }

        for(int i = 0; i < 3; i++)
        {
            if(i == cur.type)
            {
                continue;
            }

            std::pair<int,int> p = std::make_pair(tmp.first + 1, tmp.second + 1);
            if((gVisited[cur.x][cur.y][cur.departure][i]).first == -1 ||
                ((gVisited[cur.x][cur.y][cur.departure][i]) > p))
            {
                gVisited[cur.x][cur.y][cur.departure][i] = p;
                q.push({cur.x, cur.y, i, cur.departure, cur.time_count + 1, cur.change_count + 1});
            }
        }
    }
    
    return ret;
}

int main()
{
    std::cin>>N;
    gChess.assign(N, std::vector<int>(N, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin>>gChess[i][j];

            if(gChess[i][j] == 1)
            {
                gStart.first = i;
                gStart.second = j;
            }
        }
    }

    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < max; j++)
        {
            for(int k = 0; k < max * max; k++)
            {
                for(int m = 0; m < 3; m++)
                {
                    gVisited[i][j][k][m] = std::make_pair(-1, -1);
                }
            }
        }
    }

    std::pair<int,int> ans = bfs();

    std::cout<<ans.first<<" "<<ans.second<<'\n';

    return 0;
}