#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, ans = 0;
std::vector<std::pair<int,int>> tree[1001];
bool visited[1001] = {false};

void DFS(int startNode, int destinationNode, int distance)
{
    if(startNode == destinationNode)
    {
        ans = distance;
        return;
    }

    for(int i = 0; i < tree[startNode].size(); i++)
    {
        int next = tree[startNode][i].first;
        int nextCost = tree[startNode][i].second;

        if(visited[next] == false)
        {
            visited[next] = true;
            DFS(next, destinationNode, distance + nextCost);
            visited[next] = false;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>M;
    int tmp1, tmp2, weight;
    for(int i = 0; i < N - 1; i++)
    {
        std::cin>>tmp1>>tmp2>>weight;

        tree[tmp1].push_back({tmp2, weight});
        tree[tmp2].push_back({tmp1, weight});
    }

    for(int i = 0; i < M; i++)
    {
        std::cin>>tmp1>>tmp2;
        memset(visited, false, sizeof(visited));

        visited[tmp1] = true;
        DFS(tmp1, tmp2, 0);

        std::cout<<ans<<'\n';
    }

    return 0;
}