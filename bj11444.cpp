/*
    출처 : https://blogshine.tistory.com/274
*/
#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define MOD 1000000007

ll n;
typedef std::vector<std::vector<ll>> mat;

mat operator* (mat& a, mat& b)
{
    mat temp(2, std::vector<ll>(2));

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }

    return temp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>n;

    mat ans = {{1,0},{0,1}};
    mat a = {{1,1},{1,0}};

    while (n > 0)
    {
        if(n % 2 == 1)
        {
            ans = ans * a;
        }

        a = a * a;
        n /= 2;
    }
    
    std::cout<<ans[0][1]<<'\n';

    return 0;
}
