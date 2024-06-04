#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

#define pii std::pair<int,int>

int N;
std::vector<std::vector<int>> g_Graph;
std::vector<pii> ans;
std::queue<pii> q;
std::set<int> g_Visited;
std::vector<int> chairmanCandidates;

void BFS(int startNode)
{
    int total = 0;
    g_Visited.insert(startNode);
    q.push({startNode, 0});

    while (!q.empty())
    {
        int curNode = q.front().first;
        int curCost = q.front().second;
        q.pop();

        total = std::max(total, curCost);

        for(int i = 0; i < g_Graph[curNode].size(); i++)
        {
            int nextNode = g_Graph[curNode][i];

            if(g_Visited.find(nextNode) != g_Visited.end())
                continue;

            g_Visited.insert(nextNode);
            q.push({nextNode, curCost + 1});
            //std::cout<<"queue push on :"<<startNode<<" , with cost "<< curCost + 1<<'\n';
        }
    }

    ans.push_back({total, startNode});
}

int main()
{
    std::cin>>N;
    g_Graph.assign(N + 1, std::vector<int>());

    while (true)
    {
        int tmp1, tmp2;
        std::cin>>tmp1>>tmp2;

        if(tmp1 == -1 && tmp2 == -1)
            break;

        g_Graph[tmp1].push_back(tmp2);
        g_Graph[tmp2].push_back(tmp1);
    }

    for(int i = 1; i <= N; i++)
    {
        g_Visited.clear();

        BFS(i);
    }

    std::sort(ans.begin(), ans.end());

    int chairmanCount = 0;
    int chairmanScore = ans.front().first;

    for(pii v : ans)
    {
        if(v.first == chairmanScore)
        {
            chairmanCandidates.push_back(v.second);
            chairmanCount++;
        }
    }

    std::cout<<chairmanScore<<" "<<chairmanCount<<'\n';
    for(int v : chairmanCandidates)
    {
        std::cout<<v<<" ";
    }

    return 0;
}




