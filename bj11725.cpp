#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<int>>& tree, std::vector<bool>& visited, std::vector<int>& ans, int index)
{
    visited[index] = true;

    for(int i = 0; i < tree[index].size(); i++)
    {
        if(visited[tree[index][i]] == false)
        {
            ans[tree[index][i]] = index;
            DFS(tree,visited,ans,tree[index][i]);
        }
    }
}

int main()
{
    int N, temp1, temp2;
    std::vector<std::vector<int>> tree;
    std::vector<bool> visited;
    std::vector<int> ans;

    std::cin>>N;
    tree.assign(N+1,std::vector<int>());
    visited.assign(N+1,false);
    ans.assign(N+1,0);

    for(int i = 0; i < N - 1; i++)
    {
        std::cin>>temp1>>temp2;
        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }

    DFS(tree,visited,ans,1);

    for(int i = 2; i <= N; i++)
    {
        std::cout<<ans[i]<<'\n';
    }

    return 0;
}