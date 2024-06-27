/*
    출처 : https://gusdnr69.tistory.com/189
*/
#include <iostream>
#include <vector>
#include <algorithm>

int n, m, root = 0;
std::vector<std::vector<int>> tree;
std::vector<int> good_boy;

void Search_Dogs(int node)
{
    for(int _this : tree[node])
    {
        good_boy[_this] += good_boy[node];
        Search_Dogs(_this);
    }
}

int main()
{
    std::cin>>n>>m;
    tree.assign(n + 1, std::vector<int>());
    good_boy.assign(n + 1, 0);

    for(int i = 1; i <= n; i++) // 1은 항상 사장
    {
        int tmp;
        std::cin>>tmp;

        if(tmp == -1)
            continue;

        tree[tmp].push_back(i);
    }

    int who, how_much;

    for(int i = 1; i <= m; i++)
    {
        std::cin>>who>>how_much;

        good_boy[who] += how_much;
    }

    Search_Dogs(1);

    for(int i = 1; i <= n; i++)
    {
        std::cout<<good_boy[i]<<" ";
    }

    return 0;
}