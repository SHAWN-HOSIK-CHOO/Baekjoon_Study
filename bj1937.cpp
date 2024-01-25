/*
    출처 : https://velog.io/@rhkswls98/%EB%B0%B1%EC%A4%80-1937-C-%EC%9A%95%EC%8B%AC%EC%9F%81%EC%9D%B4-%ED%8C%90%EB%8B%A4
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, ans = 0;
std::vector<std::vector<int>> bamboo;
std::vector<std::vector<int>> dp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y)
{
    if(dp[x][y] != 0)
    {
        return dp[x][y];
    }

    dp[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 && xx < N && yy >= 0 && yy < N)
        {
            if(bamboo[xx][yy] > bamboo[x][y])
            {
                dp[x][y] = std::max(dp[x][y], dfs(xx, yy)+ 1);
            }
        }
    }

    return dp[x][y];
}

int main()
{
    std::cin>>N;
    bamboo.assign(N, std::vector<int>(N, 0));
    dp.assign(N, std::vector<int>(N, 0));

    for(int i = 0; i < N; i++)
    {   
        for(int j = 0; j < N; j++)
        {
            std::cin>>bamboo[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            ans = std::max(ans, dfs(i, j));
        }
    }

    std::cout<<ans;

    return 0;
}
