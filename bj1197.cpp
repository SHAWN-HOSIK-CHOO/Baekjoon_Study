#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

long long ans = 0;
int V, E;
std::vector<int> Parent;
std::vector<std::pair<int,std::pair<int,int>>> T;

int Find_Parent(int x)
{
    if(Parent[x] == x)
    {
        return x;
    }
    else
    {
        return Find_Parent(Parent[x]);
    }

}

void Union(int x, int y)
{
    x = Find_Parent(x);
    y = Find_Parent(y);

    if(x != y)
    {
        Parent[y] = x;
    }
}

bool SameParent(int x, int y)
{
    x = Find_Parent(x);
    y = Find_Parent(y);

    return (x == y);
}

void Kruskal()
{
    for(int i = 0; i < E; i++)
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
    std::cin>>V>>E;

    Parent.assign(V + 1, 0);
    for(int i = 0; i <= V; i++)
    {
        Parent[i] = i;
    }

    for(int i = 0; i < E; i++)
    {
        int a,b,c;
        std::cin>>a>>b>>c;

        T.push_back({c,{a,b}});
    }

    std::sort(T.begin(),T.end());

    Kruskal();

    std::cout<<ans;

    return 0;
}