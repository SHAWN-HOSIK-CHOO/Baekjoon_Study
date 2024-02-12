#include <iostream>
#include <vector>
#include <algorithm>

#define inf 987654321

int N;
std::vector<int> maze;
std::vector<int> dp;

int main()
{
    std::cin>>N;
    maze.assign(N + 1, 0);
    dp.assign(N + 1, inf);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>maze[i];
    }

    dp[1] = 0;

    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j <= maze[i]; j++)
        {
            if(i + j > N)
            {
                break;
            }

            dp[i + j] = std::min(dp[i + j], dp[i] + 1);
        }
    }

    if(dp[N] == inf)
    {
        std::cout<<-1;
    }
    else
    {
        std::cout<<dp[N];
    }

    return 0;
}