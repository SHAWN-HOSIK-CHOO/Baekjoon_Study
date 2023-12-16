/*
    출처 :  https://yabmoons.tistory.com/187
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, M, ans = 0;
std::vector<int> parent;
std::vector<std::pair<int,std::pair<int,int>>> T;

int Find_Parent(int x)
{
    if(parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = Find_Parent(parent[x]);
    }
}

void Union(int x, int y)
{
    x = Find_Parent(x);
    y = Find_Parent(y);

    if(x != y)
    {
        parent[y] = x;
    }
}

bool SameParent(int x, int y)
{
    x = Find_Parent(x);
    y = Find_Parent(y);

    return (x == y);
}

void mst() // kruskal
{
    for(int i = 0; i < M; i++)
    {
        if(!SameParent(T[i].second.first,T[i].second.second))
        {
            Union(T[i].second.first,T[i].second.second);
            ans += T[i].first;
        }
    }
}

int main()
{
    std::cin>>N>>M;

    parent.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        /* code */
        int a,b,c;
        std::cin>>a>>b>>c;

        T.push_back({c,{a,b}});
    }
    
    std::sort(T.begin(),T.end());

    mst();

    std::cout<<ans;

    return 0;
}