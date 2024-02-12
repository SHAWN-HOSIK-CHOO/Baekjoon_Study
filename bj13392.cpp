/*
    출처 : https://kimcodingvv.github.io/BOJ-13392/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int N;
int dp[10005][10];
int a[10005];
int b[10005];

int main()
{
    memset(dp, 0x3f, sizeof(dp));

    std::cin>>N;

    for(int i = 1; i <= N; i++)
    {
        scanf("%1d", &a[i]);
    }

    for(int i = 1; i <= N; i++)
    {
        scanf("%1d", &b[i]);
    }

    for(int i = 0; i <= 9; i++)
    {
        dp[0][i] = i;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            int left_cnt = (b[i] - a[i] - j + 20) % 10;
            int right_cnt = 10 - left_cnt;
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + right_cnt);
            dp[i][(j + left_cnt) % 10] = std::min(dp[i][(j + left_cnt) % 10], dp[i - 1][j] + left_cnt);
        }
    }

    int ans = 1e9;

    for(int i = 0; i <= 9; i++)
    {
        ans = std::min(ans, dp[N][i]);
    }

    std::cout<<ans;

    return 0;
}