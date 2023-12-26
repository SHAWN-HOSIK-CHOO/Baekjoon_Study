/*
    출처 : https://hackids.tistory.com/86
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define inf 987654321

int N, M, min = inf, res;
std::vector<std::vector<int>> g;
std::vector<bool> visited;
std::vector<int> cnt;

void BFS(int start)
{
    std::queue<int> q;
    q.push(start);

    visited[start] = true;

    while (!q.empty())
    {
        /* code */
        int cur = q.front();
        q.pop();

        for(int i = 1; i <= N; i++)
        {
            if(!visited[i] && g[cur][i])
            {
                cnt[i] = cnt[cur] + 1;
                visited[i] = true;
                q.push(i);
            }
        }
    }

    int sum = 0; 

    for(int i = 1; i <= N; i++)
    {
        sum += cnt[i];
    }

    if(sum < min)
    {
        min = sum;
        res = start;
    }
    
}

int main()
{
    std::cin>>N>>M;

    g.assign(N + 1, std::vector<int>(N + 1, 0));
    visited.assign(N + 1, false);
    cnt.assign(N + 1, 0);

    for(int i = 0 ; i < M; i++)
    {
        int a, b;
        std::cin>>a>>b;

        g[a][b] = 1;
        g[b][a] = 1;
    }

    for(int i = 1; i <= N; i++)
    {
        BFS(i);
        visited.assign(N + 1, false);
        cnt.assign(N + 1, 0);
    }

    std::cout<<res;

    return 0;
}