/*
    출처 : https://junseok.tistory.com/301
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

#define inf 987654321
#define ll long long

ll ans = inf;
int t, h, w;
char map[103][103];
int dist[3][103][103];
std::vector<std::pair<int,int>> start;
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

void Dijkstra(std::pair<int, int> p, int label)
{
    std::priority_queue<std::pair<int, std::pair<int,int>>> pq;
    pq.push({-0, p});
    dist[label][p.first][p.second] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[label][x][y] < cost) continue;

        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx < 0 || xx > h + 1 || yy < 0 || yy > w + 1 || map[xx][yy] == '*') continue;
            if(map[xx][yy] == '#')
            {
                if(dist[label][xx][yy] > cost + 1)
                {
                    dist[label][xx][yy] = cost + 1;
                    pq.push({-(cost + 1), {xx, yy}});   
                }
            }
            else if(map[xx][yy] == '.' || map[xx][yy] == '$')
            {
                if(dist[label][xx][yy] > cost)
                {
                    dist[label][xx][yy] = cost;
                    pq.push({-cost, {xx, yy}});
                }
            }
        }
    }
    
}

int main()
{
    std::cin>>t;

    while (t--)
    {
        start.clear();

        std::cin>>h>>w;

        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                std::cin>>map[i][j];

                if(map[i][j] == '$')
                {
                    start.push_back({i, j});
                }
            }
        }

        for(int i = 0; i <= h + 1; i++)
        {
            map[i][0] = '.';
            map[i][w + 1] = '.';
        }

        for(int i = 0; i <= w + 1; i++)
        {
            map[0][i] = '.';
            map[h + 1][i] = '.';
        }

        start.push_back({0, 0});

        ll ans = inf;
        for(int k = 0; k < 3; k++)
        {
            for(int i = 0; i <= h + 1; i++)
            {
                for(int j = 0; j <= w + 1; j++)
                {
                    dist[k][i][j] = inf;
                }
            }
        }

        for(int i = 0; i < 3; i++)
        {
            Dijkstra(start[i], i);
        }

        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                if(map[i][j] == '*') continue;

                ll sum = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

                if(map[i][j] == '#') sum -= 2;
                if(sum >= 0) ans = std::min(ans, sum);
            }
        }

        std::cout<<ans<<'\n';
    }

    return 0;
}