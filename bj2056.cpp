/*
    출처 : https://scarlettb.tistory.com/122
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::vector<std::vector<int>> graph;
std::vector<int> inDegree;
std::vector<int> time;
std::vector<int> result;
std::queue<int> q;


void Topology_Sort()
{
    for(int i = 1; i <= N; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
        result[i] = time[i];
    }

    while (!q.empty())
    {
        /* code */
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++)
        {
            inDegree[graph[cur][i]]--;

            //TODO: 왜 max? min이 아니라?
            result[graph[cur][i]] = std::max(result[graph[cur][i]], result[cur] + time[graph[cur][i]]);

            if(inDegree[graph[cur][i]] == 0)
            {
                q.push(graph[cur][i]);
            }
        }
    }
    
}

int main()
{
    std::cin>>N;

    graph.assign(N + 1, std::vector<int>());
    inDegree.assign(N + 1, 0);
    time.assign(N + 1, 0);
    result.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>time[i];

        int num;
        std::cin>>num;
        for(int j = 0; j < num; j++)
        {
            int work;
            std::cin>>work;
            graph[work].push_back(i);
            inDegree[i]++;
        }
    }

    Topology_Sort();

    int ans = -1;

    for(int i = 1; i <= N; i++)
    {
        ans = std::max(ans,result[i]);
    }
    std::cout<<ans;

    return 0;
}