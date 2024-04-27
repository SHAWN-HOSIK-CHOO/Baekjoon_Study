#include <iostream>
#include <vector>
#include <algorithm>

#define ll double

int N;
ll ans = 0;
std::vector<std::pair<ll,ll>> coord;

ll CalTriArea(int i, int j)
{
    ll a = coord[0].first;
    ll b = coord[0].second;
    ll c = coord[i].first;
    ll d = coord[i].second;
    ll e = coord[j].first;
    ll f = coord[j].second;

    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        ll tmp1, tmp2;
        std::cin>>tmp1>>tmp2;

        coord.push_back({tmp1, tmp2});
    }

    for(int i = 1; i < N - 1; i++)
    {
        ans += CalTriArea(i, i + 1);
    }

    printf("%.1lf", std::abs(ans));

    return 0;
}