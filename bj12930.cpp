/*
    출처 : https://deulee.tistory.com/15
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define inf 987654321

int N, ans = 0;
std::vector<std::pair<int,int>> graph[2][21];
std::vector<std::vector<int>> dist;

struct node
{
    int index;
    int cost;
    int w1;
    int w2;
};

struct cmp
{
    bool operator()(const node& a, const node& b)
    {
        if(a.cost > b.cost)
        {
            return true;
        }
        else if(a.cost == b.cost)
        {
            if(a.index > b.index)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }
};

void Dijkstra()
{
    std::priority_queue<node, std::vector<node>, cmp> pq;
    pq.push({0,0,0,0});
    dist[0][0] = 0;
    dist[1][0] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().index;
        int cur_cost = pq.top().cost;
        int w1 = pq.top().w1;
        int w2 = pq.top().w2;
        pq.pop();

        if(cur == 1)
        {
            ans = cur_cost;
            return;
        }

        if(w1 > dist[0][cur] && w2 > dist[1][cur])
        {
            continue;
        }

        for(int i = 0; i < graph[0][cur].size(); i++)
        {
            int next = graph[0][cur][i].first;
            int next_w1 = w1 + graph[0][cur][i].second;
            int next_w2 = w2 + graph[1][cur][i].second;
            int next_Distance = next_w1 * next_w2;

            if(dist[0][next] > next_w1 || dist[1][next] > next_w2)
            {
                dist[0][next] = std::min(dist[0][next], next_w1);
                dist[1][next] = std::min(dist[1][next], next_w2);
                pq.push({next, next_Distance, next_w1, next_w2});
            }
        }
    }
    
    ans = -1;
    return;
}

int main()
{
    std::cin>>N;
    dist.assign(2, std::vector<int>(N, inf));

    std::string input;

    for(int i = 0; i < N; i++)
    {
        std::cin>>input;

        for(int j = 0; j < input.size(); j++)
        {
            if(input[j] != '.')
            {
                graph[0][i].push_back({j, input[j] - '0'});
                graph[0][j].push_back({i, input[j] - '0'});
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        std::cin>>input;

        for(int j = 0; j < input.size(); j++)
        {
            if(input[j] != '.')
            {
                graph[1][i].push_back({j, input[j] - '0'});
                graph[1][j].push_back({i, input[j] - '0'});
            }
        }
    }

    Dijkstra();

    std::cout<<ans;

    return 0;
}
