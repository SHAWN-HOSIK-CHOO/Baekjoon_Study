#include <iostream>
#include <vector>
#include <cstring>

#define max_log 20

int N, M;

/*
std::vector<std::vector<int>> tree; 
std::vector<std::vector<int>> sparse;
std::vector<int> depth;
*/


std::vector<int> tree[100001];
int sparse[100001][max_log];
int depth[100001];

void dfs(int cur, int dep)
{
    depth[cur] = dep;

    for(int i = 0; i < tree[cur].size(); i++)
    {
        if(depth[tree[cur][i]] != -1)
        {
            continue;
        }
        sparse[tree[cur][i]][0] = cur;
        dfs(tree[cur][i], dep + 1);
    }
}

void Memoization()
{
    for(int j = 1; j < max_log; j++)
    {
        for(int i = 1; i <= N; i++)
        {
            sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    if(depth[a] < depth[b])
    {
        std::swap(a, b);
    }

    int diff = depth[a] - depth[b];
    for(int i = 0; diff > 0; i++)
    {
        if(diff % 2 == 1)
        {
            a = sparse[a][i];
        }

        diff = diff >> 1;
    }

    if(a != b)
    {
        for(int j = max_log - 1; j >= 0; j--)
        {
            if(sparse[a][j] != sparse[b][j])
            {
                a = sparse[a][j];
                b = sparse[b][j];
            }
        }

        a = sparse[a][0];
    }

    return a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;
    
    /* // 메모리 소비량이 너무 커서 이렇게 할당 하지 말것
    tree.assign(100000, std::vector<int>(100000, 0));
    sparse.assign(100000, std::vector<int>(20, 0));
    depth.assign(100000, -1);
    */

    
    memset(depth, -1, sizeof(depth));
    

    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        std::cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1,0);
    Memoization();

    std::cin>>M;

    for(int i = 0; i < M; i++)
    {
        int r, u, v, ans, res;
        std::cin>>r>>u>>v;

        ans = res = LCA(u, v);

        if(depth[(res = LCA(u, r))] > depth[ans])
        {
            ans = res;
        }

        if(depth[(res = LCA(v, r))] > depth[ans])
        {
            ans = res;
        }

        std::cout<<ans<<'\n';
    }

    return 0;
}