/*
    출처 : https://justicehui.github.io/ps/2019/07/03/BOJ2099/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int N, K, M;

struct Matrix
{
    int size;
    std::vector<std::vector<ll>> arr;

    Matrix() 
    {
        size = 0;
    }

    Matrix(int n)
    {
        size = n;
        arr.assign(n, std::vector<ll>(n, 0));
    }

    Matrix operator *(const Matrix& m)
    {
        Matrix ret(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                for(int k = 0; k < size; k++)
                {
                    ret.arr[i][j] += arr[i][k] * m.arr[k][j];
                    ret.arr[i][j] %= 987654321;
                }
            }
        }
        return ret;
    }
};

Matrix power(Matrix& m, ll x)
{
    if(x == 1)
    {   
        return m;
    }
    
    Matrix ret = power(m, x/2);
    ret = ret * ret;

    if(x & 1)
    {
        ret = ret * m;
    }

    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>K>>M;

    Matrix g(N);
    for(int i = 0; i < N; i++)
    {
        int a, b; 
        std::cin>>a>>b;
        a--;
        b--;
        g.arr[i][a] = g.arr[i][b] = 1;
    }

    Matrix cur = power(g, K);

    for(int i = 0; i < M; i++)
    {
        int a, b;
        std::cin>>a>>b;

        a--;
        b--;

        if(cur.arr[a][b] >= 1)
        {
            std::cout<<"death\n";
        }
        else
        {
            std::cout<<"life\n";
        }
    }

    return 0;
}