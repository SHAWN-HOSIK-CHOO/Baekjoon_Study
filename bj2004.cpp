#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long long n,m,n_m;
    long long cnt_2 = 0, cnt_5 = 0, ans;

    std::cin>>n>>m;
    n_m = n - m;

    //for n
    for(long long i = 2; i <= n; i *= 2)
    {
        cnt_2 += n/i;
    }
    for(long long i = 5; i <= n; i *= 5)
    {
        cnt_5 += n/i;
    }

    //for m
    for(long long i = 2; i <= m; i *= 2)
    {
        cnt_2 -= m/i;
    }
    for(long long i = 5; i <= m; i *= 5)
    {
        cnt_5 -= m/i;
    }

    //for n-m
    for(long long i = 2; i <= n_m; i *= 2)
    {
        cnt_2 -= n_m/i;
    }
    for(long long i = 5; i <= n_m; i *= 5)
    {
        cnt_5 -= n_m/i;
    }

    ans = (cnt_2 >= cnt_5) ? cnt_5 : cnt_2; 

    std::cout<<ans;

    return 0;
}