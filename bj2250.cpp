/*
    https://m42-orion.tistory.com/52
    오리온님 블로그 참고했습니다. 감사합니다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int>> SegTree;
std::vector<std::vector<int>> grid;
std::vector<int> nodeCount;
int curIndex = 1;

void Inodrer(int cur, int level)
{
    if(cur == -1)
    {
        return;
    }

    Inodrer(SegTree[cur].first, level + 1);

    if(grid.size() <= level)
    {
        grid.resize(level + 1);
    }
    grid[level].push_back(curIndex++);

    Inodrer(SegTree[cur].second, level + 1);
}

int main()
{
    int N, temp1, temp2, temp3, root, width = 0, ans_width = 0, ans_level = 0;

    std::cin>>N;

    SegTree.assign(N+1,std::pair<int,int>());
    nodeCount.assign(N+1,0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>temp1>>temp2>>temp3;

        SegTree[temp1] = std::make_pair(temp2,temp3);
        if(temp2 != -1)
        {
            nodeCount[temp2]++;
        }

        if(temp3 != -1)
        {
            nodeCount[temp3]++;
        }
    }

    //Finding Root
    for(int i = 1; i <= N; i++)
    {
        if(nodeCount[i] == 0)
        {
            root = i;
            break;
        }
    }

    Inodrer(root,1);

    for(int i = 1; i < grid.size(); i++)
    {
        std::sort(grid[i].begin(),grid[i].end());

        width = grid[i][grid[i].size() - 1] - grid[i][0] + 1;

        if(width > ans_width)
        {
            ans_width = width;
            ans_level = i;
        }
    }

    std::cout<<ans_level<<" "<<ans_width;

    return 0;
}