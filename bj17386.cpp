#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

ll CCW(std::pair<ll, ll>& A, std::pair<ll,ll>& B, std::pair<ll,ll>& C)
{
    ll tmp = (A.first * B.second) + (B.first * C.second) + (C.first * A.second);
    tmp -= (A.first * C.second) + (B.first * A.second) + (C.first * B.second);

    if(tmp > 0) return 1;
    else if(tmp < 0) return -1;
    else return 0;
}

bool isCrossing(std::pair<ll, ll>& A, std::pair<ll,ll>& B, std::pair<ll,ll>& C, std::pair<ll,ll>& D)
{
    int tmp1 = CCW(A, B, C) * CCW(A, B, D);
    int tmp2 = CCW(C, D, A) * CCW(C, D, B);

    return (tmp1 < 0) && (tmp2 < 0);
}

int main()
{
    std::pair<ll,ll> arr[4];

    for(int i = 0; i < 4; i++)
    {
        ll tmp1, tmp2;
        std::cin>>tmp1>>tmp2;
        arr[i].first = tmp1;
        arr[i].second = tmp2;
    }

    if(isCrossing(arr[0], arr[1], arr[2], arr[3]))
    {
        std::cout<<1<<'\n';
    }
    else
    {
        std::cout<<0<<'\n';
    }

    return 0;
}