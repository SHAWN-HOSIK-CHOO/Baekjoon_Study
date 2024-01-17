#include <iostream>
#include <vector>
#include <algorithm>

int N, M, answer = 0;
std::vector<std::pair<int,std::pair<int,int>>> edges;
std::vector<int> parent;
std::vector<int> ans;

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
    int px = Find_Parent(x);
    int py = Find_Parent(y);

    if(px == py)
    {
        return;
    }

    parent[py] = px;
}

bool Has_Same_Parent(int x, int y)
{
    int px = Find_Parent(x);
    int py = Find_Parent(y);

    return (px == py);
}

void Kruskal()
{
    std::sort(edges.begin(), edges.end());

    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < edges.size(); i++)
    {
        if(!Has_Same_Parent(edges[i].second.first, edges[i].second.second))
        {
            Union(edges[i].second.first, edges[i].second.second);
            ans.push_back(edges[i].first);
        }
    }
}

int main()
{
    std::cin>>N>>M;
    parent.assign(N + 1, 0);

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;

        edges.push_back({c,{a,b}});
    }

    Kruskal();

    for(int i = 0; i < ans.size() - 1; i++)
    {
        answer = answer + ans[i];
    }

    std::cout<<answer;

    return 0;
}
