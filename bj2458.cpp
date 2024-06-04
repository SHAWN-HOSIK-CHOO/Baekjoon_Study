#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

int N, M, ans = 0;
std::vector<std::vector<int>> g_Map;

void Floyd()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(g_Map[i][j] > g_Map[i][k] + g_Map[k][j])
                {
                    g_Map[i][j] = g_Map[i][k] + g_Map[k][j];
                }
            }
        }
    }
}

int main()
{
    std::cin>>N>>M;
    g_Map.assign(N + 1, std::vector<int>(N + 1, INF));

    for(int i = 0; i < M; i++)
    {
        int a, b;
        std::cin>>a>>b;

        g_Map[a][b] = 1;
    }

    Floyd();

    for(int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= N; j++)
        {
            if(g_Map[i][j] != INF || g_Map[j][i] != INF)
            {
                cnt++;
            }
        }

        if(cnt == N - 1)
        {
            ans++;
        }
    }

    std::cout<<ans<<'\n';

    return 0;
}