#include <iostream>

// 피사노의 주기 참고
#define ll long long
#define SIZE 1500000
#define MOD 1000000

ll n;
ll g_Arr[SIZE] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>n;

    g_Arr[0] = 0;
    g_Arr[1] = 1;

    for(int i = 2; i < SIZE; i++)
    {
        g_Arr[i] = (g_Arr[i - 1] + g_Arr[i - 2]) % MOD;
    }

    std::cout<<g_Arr[n % SIZE];

    return 0;
}