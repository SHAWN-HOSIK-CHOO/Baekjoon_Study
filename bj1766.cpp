/*
    출처 : https://jungahshin.tistory.com/218
*/
#include <iostream>
#include <queue>
#include <vector>

int N, M;
std::vector<std::vector<int>> graph;
std::vector<int> inDegree;

void Topology_Sort()
{
    std::priority_queue<int,std::vector<int>,std::greater<int>> q;

    for(int i = 1; i <= N; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        /* code */
        int cur = q.top();
        q.pop();

        std::cout<<cur<<" ";

        for(int i = 0; i < graph[cur].size(); i++)
        {
            inDegree[graph[cur][i]]--;

            if(inDegree[graph[cur][i]] == 0)
            {
                q.push(graph[cur][i]);
            }
        }
    }
    
}

int main()
{
    std::cin>>N>>M;

    graph.assign(N + 1, std::vector<int>());
    inDegree.assign(N + 1, 0);

    for(int i = 0; i < M; i++)
    {
        int x,y;
        std::cin>>x>>y;

        graph[x].push_back(y);
        inDegree[y]++;
    }

    Topology_Sort();

    return 0;
}