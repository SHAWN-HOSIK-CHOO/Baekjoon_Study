/*
    출처 : https://ghqls0210.tistory.com/145
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define max_log 20

int m, n, Q, x;
std::vector<int> f;
std::vector<std::vector<int>> sparse;

int solve(int n, int x)
{
    int cur = x;

    for(int i = 0; i < max_log; i++)
    {
        if(n & (1 << i))
        {
            cur = sparse[i][cur];
        }
    }

    return cur;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>m;

    f.assign(m + 1, 0);
    sparse.assign(21, std::vector<int>(m + 1, 0));

    //init  

    for(int i = 1; i <= m; i++)
    {
        std::cin>>f[i];
    }

    for(int i = 1; i <= m; i++)
    {
        sparse[0][i] = f[i];
    }

    for(int i = 1; i < max_log; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
        }
    }

    //solve 
    std::cin>>Q;

    for(int i = 0; i < Q; i++)
    {
        std::cin>>n>>x;

        int res = solve(n,x);
        std::cout<<res<<'\n';
    }

    return 0;
}