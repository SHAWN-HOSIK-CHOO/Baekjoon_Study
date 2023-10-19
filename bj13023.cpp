/* https://primayy.tistory.com/29 
    코딩하는 드래곤 (primayy)님 코드 보고 작성했습니다.
    primayy님 감사합니다!
*/

#include <iostream>
#include <vector>

bool flag = false;

void DFS(std::vector<std::vector<int>>& g,std::vector<bool>& v, int cnt, int idx)
{
    if(cnt == 4)
    {
        flag = true;
        return;
    }

    for(int i = 0; i < g[idx].size(); i++)
    {
        int next = g[idx][i];
        if(v[next])
        {
            continue;
        }
        v[next] = true;
        DFS(g,v,cnt+1,next);
		// 현재 경로에서 결과를 찾지 못하면 이전 노드로 이동하고
		// 현재 노드를 다시 방문할 수 있도록
        v[next] = false;
    }

}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M, temp1, temp2;
    std::vector<std::vector<int>> graph;

    std::cin>>N>>M;

    for(int i = 0; i < N; i++)
    {
        graph.push_back(std::vector<int>());
    }

    for(int i = 0; i < M; i++)
    {
        std::cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    for(int i = 0; i < N; i++)
    {
        std::vector<bool> visited(N);
        visited[i] = true;
        DFS(graph,visited,0,i);
        if(flag)
        {
            break;
        }
    }

    std::cout<<flag;
    

    return 0;
}