/*
    출처 : 
    https://h202.tistory.com/604
*/
#include <iostream>
#include <vector>
#include <cstring>

int N, R, Q;
std::vector<int> dp;
std::vector<bool> visited;
std::vector<int> v[100001];

void DFS(int node)
{
    for(int n : v[node])
    {
        if(visited[n] == false)
        {
            visited[n] = true;
            DFS(n);
            dp[node] += dp[n];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>R>>Q;

    dp.assign(N + 1, 1);
    visited.assign(N + 1, false);

    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2;
        std::cin>>tmp1>>tmp2;

        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    visited[R] = true;
    DFS(R);

    for(int i = 0; i < Q; i++)
    {
        int q;
        std::cin>>q;
        std::cout<<dp[q]<<'\n';
    }

    return 0;
}