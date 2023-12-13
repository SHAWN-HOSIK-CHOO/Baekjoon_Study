#include <iostream>
#include <vector>
#include <queue>
#include <string>

std::vector<int> ans;

void Find_Circle_DFS(std::vector<std::vector<int>>& graph, std::vector<int>& visited, std::vector<int>& inCircle, int index,int startIndex,int cnt)
{
    if(index == startIndex && cnt >= 3)
    {
        inCircle[index] = 1;
        return;
    }

    visited[index] = 1;

    for(int i = 0; i < graph[index].size(); i++)
    {
        if(visited[graph[index][i]] == false || (graph[index][i] == startIndex && cnt >= 2))
        {
            Find_Circle_DFS(graph,visited,inCircle,graph[index][i],startIndex,cnt + 1);
        }
    }

    visited[index] = 0;
}

void To_Circle_BFS(std::vector<std::vector<int>>& graph, std::vector<int>& visited, std::vector<int>& inCircle)
{
    std::queue<int> queue;

    for(int i = 1; i <= graph.size(); i++)
    {
        if(inCircle[i] == 1 && graph[i].size() > 2)
        {
            queue.push(i);
            visited[i] = 1;
        }
    }

    while (!queue.empty())
    {
        /* code */
        int a = queue.front();
        queue.pop();

        for(int i = 0; i < graph[a].size(); i++)
        {
            if(visited[graph[a][i]] == 0)
            {
                queue.push(graph[a][i]);
                visited[graph[a][i]] = 1;
                ans[graph[a][i]] = ans[a] + 1;
            }
        }
    }
    
}

int main()
{
    int N;
    int temp1, temp2, startIndex;
    std::vector<std::vector<int>> graph;
    std::vector<int> visited;
    std::vector<int> inCircle;

    std::cin>>N;

    // 0번역은 존재하지 않음
    graph.assign(N+1,std::vector<int>());
    visited.assign(N+1,0);
    inCircle.assign(N+1,0);
    ans.assign(N+1,0);
    visited[0] = 1;

    for(int i = 0; i < N; i++)
    {
        std::cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    for(int i = 1; i <= N; i++)
    {
        //TODO: 중요!!!! Find_Circle_DFS를 한번 하고 오면 visited[i]는 0이 아닌 상태이다. 따라서 해당 if문은 실행되지 않는다.
        if(visited[i] == 0)
        {
            visited.clear();
            visited.assign(N+1,0);
            visited[0] = 1;
            startIndex = i;
            Find_Circle_DFS(graph,visited,inCircle,i,startIndex,0);
        }
    }

    visited.clear();
    visited.assign(N+1,0);
    To_Circle_BFS(graph,visited,inCircle);

    for(int i = 1; i <= N; i++)
    {
        if(inCircle[i] == 1)
        {
            std::cout<<"0 ";
        }
        else
        {
            std::cout<<ans[i]<<' ';
        }
    }

    return 0;
}