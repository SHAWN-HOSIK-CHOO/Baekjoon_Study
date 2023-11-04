#include <iostream>
#include <vector>
#include <algorithm>

int gMaxLength = 0;
int gFarNode = 0;

void DFS(std::vector<std::vector<std::pair<int,int>>>& tree, std::vector<int>& visitedNLength, int index)
{
    //가장 처음 들어오는 index 길이 설정
    if(visitedNLength[index] == -1)
    {
        visitedNLength[index] = 0;
    }

    int span = tree[index].size();

    for(int i = 0; i < span; i++)
    {
        if(visitedNLength[tree[index][i].first] == -1)
        {
            visitedNLength[tree[index][i].first] = visitedNLength[index] + tree[index][i].second;

            if(visitedNLength[tree[index][i].first] > gMaxLength)
            {
                gMaxLength = visitedNLength[tree[index][i].first];
                gFarNode = tree[index][i].first;
            }

            DFS(tree, visitedNLength, tree[index][i].first);
        }
    }

    visitedNLength[index] = -1;
}   

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, temp1, temp2, temp3;
    std::vector<std::vector<std::pair<int,int>>> tree;
    std::vector<int> visitedNLength;

    std::cin>>N;

    tree.assign(N+1,std::vector<std::pair<int,int>>());
    visitedNLength.assign(N+1,-1);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>temp3;
        while (true)
        {
            /* code */
            std::cin>>temp1;
            if(temp1 == -1)
            {
                break;
            }
            std::cin>>temp2;

            tree[temp3].push_back({temp1,temp2});
        }
        
    }

    DFS(tree,visitedNLength,1);
    gMaxLength = 0;
    visitedNLength.assign(N+1,-1);
    DFS(tree,visitedNLength,gFarNode);

    std::cout<<gMaxLength;

    return 0;
}