/*
    출처 : https://gamedoridori.tistory.com/13
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

int N, root, erase, ans = 0;
std::vector<int> tree[51];
bool visited[51] = {false};

void DFS(int node)
{
    if(visited[node])
        return;

    visited[node] = true;

    if(tree[node].size() == 0 || (tree[node].size() == 1 && tree[node][0] == erase))
        ans++;
    
    for(int i = 0; i < tree[node].size(); i++)
    {
        if(tree[node][i] != erase)
            DFS(tree[node][i]);
    }
}

int main()
{
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;

        if(tmp == -1)
        {
            root = i;
        }
        else
        {
            tree[tmp].push_back(i);
        }
    }

    std::cin>>erase;
    if(erase == root)
    {
        std::cout<<0;
        return 0;
    }

    DFS(root);

    std::cout<<ans;

    return 0;
}
