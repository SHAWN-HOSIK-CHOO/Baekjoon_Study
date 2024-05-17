#include <iostream>
#include <vector>

int N, M;
std::vector<int> vec;
std::vector<bool> visited;

void DFS(int num,int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
        {
            std::cout<<vec[i]<<" ";
        }
        std::cout<<'\n';

        return;
    }

    for(int i = num; i <= N; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            vec[cnt] = i;
            DFS(i + 1,cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    std::cin>>N>>M;
    vec.assign(N + 1, 0);
    visited.assign(N + 1, false);
    DFS(1, 0);

    return 0;
}