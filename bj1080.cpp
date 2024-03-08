#include <iostream>
#include <vector>
#include <algorithm>

int N, M, cnt = 0, ans  = -1;
int mat_from[50][50] = {0, };
int mat_to[50][50] = {0, };

void Tilt(int a, int b)
{
    for(int i = a; i < a + 3; i++)
    {
        for(int j = b; j < b + 3; j++)
        {
            if(mat_from[i][j] == 0) mat_from[i][j] = 1;
            else if(mat_from[i][j] == 1) mat_from[i][j] = 0;
        }
    }
}

int main()
{
    std::cin>>N>>M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char tmp;
            std::cin>>tmp;
            mat_from[i][j] = tmp - '0';
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char tmp;
            std::cin>>tmp;
            mat_to[i][j] = tmp - '0';
        }
    }

    for(int i = 0; i < N - 2; i++)
    {
        for(int j = 0; j < M - 2; j++)
        {
            if(mat_from[i][j] != mat_to[i][j])
            {
                Tilt(i, j);
                cnt++;
            }
        }
    }
    
    ans = cnt;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(mat_from[i][j] != mat_to[i][j])
            {
                ans = -1;
            }
        }
    }

    std::cout<<ans;

    return 0;
}

