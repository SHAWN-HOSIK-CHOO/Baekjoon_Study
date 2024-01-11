/*
    출처 : https://codecollector.tistory.com/274
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, ans;
std::vector<std::vector<std::pair<int,int>>> tree;
std::vector<bool> visited;
std::vector<int> depth;
std::vector<int> parent;
std::vector<int> dist;

int LCA(int a, int b)
{
    if(depth[a] < depth[b])
    {
        std::swap(a, b);
    }

    while (depth[a] != depth[b])
    {
        ans += dist[a];
        a = parent[a];
    }

    while (a != b)
    {
        ans += dist[a];
        ans += dist[b];
        a = parent[a];
        b = parent[b];
    }

    return ans;
}

int main()
{
    std::queue<int> q;
    std::cin>>N;

    tree.assign(N + 1, std::vector<std::pair<int,int>>());
    visited.assign(N + 1, false);
    depth.assign(N + 1, 0);
    parent.assign(N + 1, 0);
    dist.assign(N + 1, 0);

    for(int i = 1; i < N; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    visited[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i].first;

            if(!visited[next])
            {
                depth[next] = depth[cur] + 1;
                dist[next] = tree[cur][i].second;
                parent[next] = cur;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    

    std::cin>>M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        std::cin>>a>>b;
        ans = 0;
        std::cout<<LCA(a,b)<<'\n';
    }

    return 0;
}