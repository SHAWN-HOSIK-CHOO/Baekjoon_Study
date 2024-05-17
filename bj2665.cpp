#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>

#define pii std::pair<int,int>
#define INF 987654321

int n;
std::set<std::pair<int,pii>> visited;
std::vector<std::vector<int>> graph;
std::priority_queue<std::pair<int,pii>,std::vector<std::pair<int,pii>>, std::greater<std::pair<int,pii>>> pq;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int g_CurMinCount = INF;

void Dijkstra()
{
    pq.push({0,{0, 0}});

    while (!pq.empty())
    {
        int cur_count = pq.top().first;
        int cur_X = pq.top().second.first;
        int cur_Y = pq.top().second.second;
        pq.pop();

        if(visited.find({cur_count, {cur_X, cur_Y}}) != visited.end())
            continue;

        visited.insert({cur_count, {cur_X, cur_Y}});

        if(cur_X == (n - 1) && cur_Y == (n - 1))
        {
            if(cur_count < g_CurMinCount)
                g_CurMinCount = cur_count;
        }

        for(int i = 0; i < 4; i++)
        {
            int next_X = cur_X + dx[i];
            int next_Y = cur_Y + dy[i];

            if(next_X < 0 || next_X >= n || next_Y < 0 || next_Y >= n)
                continue;

            if(cur_count + 1 >= g_CurMinCount)
                continue;

            if(graph[next_X][next_Y] == 0)
            {
                pq.push({cur_count + 1,{next_X, next_Y}});
            }
            else
            {
                pq.push({cur_count,{next_X, next_Y}});
            }
        }
    }
}

int main()
{
    std::cin>>n;
    graph.assign(n + 1, std::vector<int>(n + 1, 0));

    std::string tmp;
    for(int i = 0; i < n; i++)
    {
        std::cin>>tmp;
        for(int j = 0; j < tmp.size(); j++)
        {
            graph[i][j] = tmp[j] - '0';
        }
    }

    Dijkstra();

    std::cout<<g_CurMinCount<<'\n';

    return 0;
}