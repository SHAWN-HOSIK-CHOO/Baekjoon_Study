#include <iostream>
#include <vector>

#define mod 1000000007
#define ll long long

int T, N;
std::vector<ll> v;

int main()
{
    std::cin>>T;

    v.assign(5001, 0); 

    v[0] = 1;

    for(int i = 2; i <= 5000; i += 2)
    {
        for(int j = 2; j <= i; j += 2)
        {
            v[i] += v[j - 2] * v[i - j]; // += 인 이유는 j가 2부터 i 까지 변하는 동안 모든 경우의 수를 계산하기 위함
            v[i] %= mod;
        }
    }

    while (T--)
    {
        std::cin>>N;

        std::cout<<v[N]<<'\n';
    }
    
    return 0;
}