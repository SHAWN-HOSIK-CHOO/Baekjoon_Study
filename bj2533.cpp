#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int N;
std::vector<std::vector<int>> SegTree;
int dp[1000001][2];
std::set<int> visited;

void Solve(int n)
{   
    visited.insert(n);
    dp[n][0] = 1;

    for(int i = 0; i < SegTree[n].size(); i++)
    {
        int child = SegTree[n][i];

        if(visited.find(child) != visited.end())
            continue;

        Solve(child);
        
        dp[n][1] += dp[child][0];
        dp[n][0] += std::min(dp[child][1], dp[child][0]);
    }
}

int main()
{
    std::cin>>N;
    SegTree.assign(N + 1, std::vector<int>());

    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2;
        std::cin>>tmp1>>tmp2;

        SegTree[tmp1].push_back(tmp2);
        SegTree[tmp2].push_back(tmp1);
    }

    Solve(1);

    std::cout<<std::min(dp[1][0], dp[1][1]);

    return 0;
}