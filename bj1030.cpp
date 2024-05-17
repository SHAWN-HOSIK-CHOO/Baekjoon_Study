/*
    출처 : https://please-amend.tistory.com/entry/%EB%B0%B1%EC%A4%80-1030%EB%B2%88-%ED%94%84%EB%A0%89%ED%83%88-%ED%8F%89%EB%A9%B4-Ccpp-%ED%92%80%EC%9D%B4
*/
#include <iostream>
#include <vector>
#include <cmath>

int s, N, K, R1, R2, C1, C2;
int ans[51][51];

void CreateFractal(int len, int x, int y)
{
    if(len == 1) return;
    if(x > R2 || x + len - 1 < R1 || y > C2 || y + len - 1 < C1) return;

    int blackAreaStart = len / N * (N - K) / 2;
    int blackAreaEnd = len / N * ((N - K) / 2 + K) - 1;
    int blackX1 = std::max(R1, blackAreaStart + x);
    int blackY1 = std::max(C1, blackAreaStart + y);
    int blackX2 = std::min(R2, blackAreaEnd + x);
    int blackY2 = std::min(C2, blackAreaEnd + y);

    for(int i = blackX1; i <= blackX2; i++)
    {
        for(int j = blackY1; j <= blackY2; j++)
        {
            ans[i - R1][j - C1] = 1;
        }
    }

    for(int i = 0; i < len; i += len / N)
    {
        for(int j = 0; j < len; j += len / N)
        {
            if(i >= blackAreaStart && j >= blackAreaStart && i <= blackAreaEnd && j <= blackAreaEnd)
                continue;

            CreateFractal(len / N, x + i, y + j);
        }
    }
}

int main()
{
    std::cin>>s>>N>>K>>R1>>R2>>C1>>C2;

    CreateFractal(static_cast<int>(std::pow(N, s)), 0, 0);

    for(int i = 0; i <= R2 - R1; i++)
    {
        for(int j = 0; j <= C2 - C1; j++)
        {
            std::cout<<ans[i][j];
        }
        std::cout<<'\n';
    }

    return 0;
}