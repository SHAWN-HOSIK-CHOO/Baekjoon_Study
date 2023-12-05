/*
    출처 : https://velog.io/@matcha_/%EB%B0%B1%EC%A4%80-2133-%ED%83%80%EC%9D%BC-%EC%B1%84%EC%9A%B0%EA%B8%B0-C-DP
*/
#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<int> dp;

    std::cin>>N;

    dp.assign(N + 1, 0);

    dp[2] = 3;
    dp[0] = 1; // 상수 2 곱하기 항 때문

    for(int i = 3; i <= N; i++)
    {
        if(i % 2 != 0)
        {
            dp[i] = 0;
        }
        else
        {
            for(int j = 2; j <= N; j += 2)
            {
                if(j == 2)
                {
                    dp[i] = dp[i - j] * dp[2];
                }
                else if(i - j >= 0)
                {
                    dp[i] += dp[i - j] * 2;
                }
            }
        }
    }

    std::cout<<dp[N];

    return 0;
}