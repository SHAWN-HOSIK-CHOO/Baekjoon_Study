/*
    출처 : https://velog.io/@al_potato/c-%EB%B0%B1%EC%A4%80-11652-%EC%B9%B4%EB%93%9C
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int N, max = 0, cnt = 0;
ll res = 0;
std::vector<ll> v;

int main()
{
    std::cin>>N;

    ll tmp;
    for(int i = 0; i < N; i++)
    {
        std::cin>>tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    res = v.at(0);

    for(int i = 1; i < N; i++)
    {
        if(v[i] == v[i - 1])
        {
            cnt++;
            if(cnt > max)
            {
                max = cnt;
                res = v[i];
            }
        }
        else
        {
            cnt = 0;
        }
    }

    std::cout<<res;

    return 0;
}