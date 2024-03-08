#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int F, S, G, U, D;
std::vector<bool> g_Visited;

int bfs(int start)
{
    std::queue<std::pair<int,int>> q;
    g_Visited[start] = true;

    if(start == G) return 0;

    if(start - D >= 1) q.push({start - D, 1});
    if(start + U <= F) q.push({start + U, 1});

    while (!q.empty())
    {
        std::pair<int,int> cur = q.front();
        q.pop();

        if(cur.first == G) return cur.second;

        if(cur.first - D >= 1 && !g_Visited[cur.first - D])
        {
            g_Visited[cur.first - D] = true;
            q.push({cur.first - D, cur.second + 1});
        }

        if(cur.first + U <= F && !g_Visited[cur.first + U])
        {
            g_Visited[cur.first + U] = true;
            q.push({cur.first + U, cur.second + 1});
        }
    }
    
    return -1;
}

int main()
{
    std::cin>>F>>S>>G>>U>>D;
    g_Visited.assign(F + 1, false);

    int ans = bfs(S);

    if(ans == -1)
    {
        std::cout<<"use the stairs";
    }
    else
    {
        std::cout<<ans;
    }
    
    return 0;
}