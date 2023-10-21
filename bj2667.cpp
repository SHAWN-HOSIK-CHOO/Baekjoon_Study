/*
    https://tooo1.tistory.com/165
    님의 코드 참고해서 작성했습니다. 감사합니다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

void DFS(std::vector<std::string>& graph, std::vector<std::vector<int>>& visited, int x, int y, int& cnt)
{
    std::vector<int> x_var{-1,1,0,0};
    std::vector<int> y_var{0,0,-1,1};
    std::stack<std::pair<int,int>> stack;
    stack.push({x,y});
    cnt = 1;

    visited[x][y] = 1;

    while (!stack.empty())
    {
        int xx = stack.top().first;
        int yy = stack.top().second;

        stack.pop();

        for(int i = 0; i < 4; i++)
        {
            int x_nxt = xx + x_var[i];
            int y_nxt = yy + y_var[i];

            if(x_nxt >= 0 && y_nxt >= 0 && x_nxt < graph.size() && y_nxt < graph.size() &&  visited[x_nxt][y_nxt] == 0 && graph[x_nxt][y_nxt] == '1')
            {
                stack.push({x_nxt,y_nxt});
                visited[x_nxt][y_nxt] = 1;
                cnt++;
            }
        }
    }
}

int main()
{
    std::vector<std::string> graph;
    std::vector<std::vector<int>> visited;
    std::vector<int> count;
    int N ,temp, cnt = 0;

    std::cin>>N;

    graph.assign(N,"");
    visited.assign(N,std::vector<int>(N,0));

    for(int i = 0; i < N; i++)
    {
        std::cin>>graph[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(graph[i][j] == '1' && (visited[i][j] == 0))
            {
                DFS(graph,visited,i,j, cnt);
                count.push_back(cnt);
            }
        }
    }

    std::sort(count.begin(),count.end());
    std::cout<<count.size()<<"\n";
    for(auto ans : count)
    {
        std::cout<<ans<<'\n';
    }

    return 0;
}