/*
    출처 : https://velog.io/@minayeah/C-%EB%B0%B1%EC%A4%80-1446-%EC%A7%80%EB%A6%84%EA%B8%B8
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii std::pair<int,int>

int N, D;
std::vector<std::vector<pii>> g_Graph;
std::vector<int> g_Dist;

int main()
{
    std::cin>>N>>D;
    g_Graph.assign(10005, std::vector<pii>());
    g_Dist.assign(10005, 987654321);
    
    for(int i = 0; i < N; i++)
    {
        int tmp_start, tmp_end, tmp_weight;

        std::cin>>tmp_start>>tmp_end>>tmp_weight;

        if(tmp_end > D || tmp_end - tmp_start < tmp_weight)
            continue;

        g_Graph[tmp_end].push_back({tmp_start, tmp_weight});
    }

    g_Dist[0] = 0;

    for(int i = 1; i <= D; i++)
    {
        g_Dist[i] = g_Dist[i - 1] + 1;

        for(int j = 0; j < g_Graph[i].size(); j++)
        {
            int nextIndex = g_Graph[i][j].first;
            int nextCost = g_Graph[i][j].second;

            g_Dist[i] = std::min(g_Dist[i], g_Dist[nextIndex] + nextCost);
        }
    }

    std::cout<<g_Dist[D];

    return 0;
}