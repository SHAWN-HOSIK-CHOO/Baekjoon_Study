#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define INF 987654321

int N, ans = 0;
std::vector<std::vector<int>> g_Graph;

void Floyd()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                g_Graph[i][j] = std::min(g_Graph[i][j], g_Graph[i][k] + g_Graph[k][j]);
            }
        }
    }
}

int main()
{
    std::cin>>N;
    g_Graph.assign(N + 1, std::vector<int>(N + 1, INF));

    std::string s_temp;

    for(int i = 1; i <= N; i++)
    {
        std::cin>>s_temp;
        for(int j = 1; j <= s_temp.size(); j++)
        {
            if(s_temp[j - 1] == 'Y')
                g_Graph[i][j] = 1;
        }
    }

    Floyd();

    for(int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= N; j++)
        {
            if(i == j)
                continue;

            if(g_Graph[i][j] >= 1 && g_Graph[i][j] <= 2)
                cnt++;
        }

        ans = std::max(ans, cnt);
    }

    std::cout<<ans<<'\n';

    return 0;
}