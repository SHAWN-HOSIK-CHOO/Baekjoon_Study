/*
    출처 : https://bighorn.tistory.com/43
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
std::vector<std::vector<int>> SegTree;
std::vector<int> depth;
std::vector<std::vector<int>> parent;

void Depth(int a)
{
    for(auto i : SegTree[a])
    {
        if(depth[i] == 0)
        {
            depth[i] = depth[a] + 1;
            parent[i][0] = a;

            for(int j = 0; j < 16; j++)
            {
                parent[i][j + 1] = parent[parent[i][j]][j];

                if(parent[i][j + 1] == 0)
                {
                    break;
                }   
            }

            Depth(i);
        }
    }
}

int LCA(int a, int b)
{
    if(depth[a] < depth[b])
    {
        std::swap(a, b);
    }

    int diff = depth[a] - depth[b];
    int j = 0;

    while (diff)
    {
        if(diff % 2 == 1)
        {
            a = parent[a][j];
        }
        j++;

        diff /= 2;
    }

    if(a != b)
    {
        for(int j = 16; j >= 0; j--)
        {
            if(parent[a][j] != parent[b][j])
            {
                a = parent[a][j];
                b = parent[b][j];
            }
        }

        a = parent[a][0];
    } 
    
    return a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;
    SegTree.assign(N + 1, std::vector<int>());
    depth.assign(N + 1, 0);
    parent.assign(N + 1, std::vector<int>(17,0));

    parent[1][0] = 1;
    depth[0] = 0;
    depth[1] = 1;

    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin>>a>>b;

        SegTree[a].push_back(b);
        SegTree[b].push_back(a);
    }

    Depth(1);

    std::cin>>M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        std::cin>>a>>b;

        std::cout<<LCA(a, b)<<'\n';
    }

    return 0;
}
