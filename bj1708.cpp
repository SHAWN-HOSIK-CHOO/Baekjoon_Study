/*
    유튜브 참고 : https://youtu.be/Ps1idzOx6LA?si=e8TPYw7OCw6_4HBg
    출처 : https://velog.io/@min_gi1123/c-%EB%B0%B1%EC%A4%80-1708-%EB%B8%94%EB%A1%9D-%EA%BB%8D%EC%A7%88-%EB%B8%94%EB%A1%9D-%EA%BB%8D%EC%A7%88%EC%9D%84-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%B5%9C%EC%A0%81%ED%99%94-Convex-Hull-Trick
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long

struct pos
{
    ll x, y;
};

int n;
std::vector<pos> v;
std::stack<pos> s;

ll CCW(pos a, pos b, pos c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool Compare(pos a, pos b)
{
    ll cc = CCW(v[0], a, b);

    if(cc)
        return cc > 0;
    else if(a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>n;

    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        std::cin>>v[i].x>>v[i].y;
    }

    for(int i = 1; i < n; i++)
    {
        if(v[i].y < v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x))
        {
            std::swap(v[0].x, v[i].x);
            std::swap(v[0].y, v[i].y);
        }
    }

    std::sort(v.begin() + 1, v.end(), Compare);
    s.push(v[0]);
    s.push(v[1]);

    for(int i = 2; i < n; i++)
    {
        while (s.size() >= 2)
        {
            pos top_2 = s.top();
            s.pop();

            pos top_1 = s.top();
            if(CCW(top_1, top_2, v[i]) > 0)
            {
                s.push(top_2);
                break;
            }
        }
        s.push(v[i]);
    }

    std::cout<<s.size();

    return 0;
}
