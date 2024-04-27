/*
    출처 : https://heespace.tistory.com/15
*/
#include <iostream>
#include <vector>

#define ll long long

ll N, B;
ll mat[5][5] = {0};
ll ans[5][5] = {0};

void MatMul(ll mat1[5][5], ll mat2[5][5])
{
    ll tmp[5][5] = {0};

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            tmp[i][j] = 0;

            for(int k = 0; k < N; k++)
            {
                tmp[i][j] += mat1[i][k] * mat2[k][j];
            }

            tmp[i][j] %= 1000;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            mat1[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    std::cin>>N>>B;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin>>mat[i][j];
        }
        ans[i][i] = 1;
    }

    while (B > 0)
    {
        /* code */
        if(B % 2 == 1)
        {
            MatMul(ans, mat);
        }
        MatMul(mat, mat);

        B /= 2;
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<'\n';
    }

    return 0;
}