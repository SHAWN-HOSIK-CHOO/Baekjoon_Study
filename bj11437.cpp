/*
    출처 : https://cocoon1787.tistory.com/328
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
std::vector<std::vector<int>> SegTree;
std::vector<bool> visited;
std::vector<int> parent;
std::vector<int> depth;
std::queue<int> q;

int LCA(int a, int b)
{
    if(depth[b] > depth[a])
    {
        std::swap(a, b);
    }

    while (depth[a] != depth[b])
    {
        a = parent[a];
    }

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    
    return a;
}

int main()
{
    std::cin>>N;
    SegTree.assign(N + 1, std::vector<int>());
    visited.assign(N + 1, false);
    parent.assign(N + 1, 0);
    depth.assign(N + 1, 0);

    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin>>a>>b;

        SegTree[a].push_back(b);
        SegTree[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        /* code */
        int cur = q.front();
        q.pop();

        for(int i = 0; i < SegTree[cur].size(); i++)
        {
            if(!visited[SegTree[cur][i]])
            {
                depth[SegTree[cur][i]] = depth[cur] + 1;
                visited[SegTree[cur][i]] = true;
                parent[SegTree[cur][i]] = cur;
                q.push(SegTree[cur][i]);
            }
        }
    }

    std::cin>>M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        std::cin>>a>>b;

        std::cout<<LCA(a, b)<<'\n';
    }

    return 0;
}