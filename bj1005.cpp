/*
    출처 : https://yabmoons.tistory.com/410
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 1001

int T, N, K, D, W;
int g_Time[MAX] = {0};
int g_Result[MAX] = {0};
int g_Indgree[MAX] = {0};
std::vector<int> g_Graph[MAX];
std::queue<int> g_Q;

void Init()
{
    memset(g_Time, 0 , sizeof(g_Time));
    memset(g_Result, 0, sizeof(g_Result));
    memset(g_Indgree, 0, sizeof(g_Indgree));

    for(int i = 0; i < MAX; i++)
    {
        g_Graph[i].clear();
    }

    while (!g_Q.empty())
    {
        g_Q.pop();
    }
    
}

void Input()
{
    std::cin>>N>>K;

    for(int i = 1; i <= N; i++)
    {
        std::cin>>g_Time[i];
    }

    for(int i = 0; i < K; i++)
    {
        int tmp1, tmp2;
        std::cin>>tmp1>>tmp2;

        g_Graph[tmp1].push_back(tmp2);
        g_Indgree[tmp2]++;
    }

    std::cin>>W;
}

void PS()
{
    for(int i = 1; i <= N; i++)
    {
        if(g_Indgree[i] == 0)
        {
            g_Q.push(i);
            g_Result[i] = g_Time[i];
        }
    }

    while (!g_Q.empty())
    {
        int cur = g_Q.front();
        g_Q.pop();

        for(int i = 0; i < g_Graph[cur].size(); i++)
        {
            int next = g_Graph[cur][i];
            g_Result[next] = std::max(g_Result[next], g_Result[cur] + g_Time[next]);
            g_Indgree[next]--;

            if(g_Indgree[next] == 0)
            {
                g_Q.push(next);
            }
        }
    }
    

    std::cout<<g_Result[W]<<'\n';
}

void Solve()
{
    std::cin>>T;

    for(int i = 0; i < T; i++)
    {
        Init();
        Input();
        PS();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Solve();

    return 0;
}
