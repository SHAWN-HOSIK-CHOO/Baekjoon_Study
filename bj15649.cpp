#include <iostream>
#include <vector>

int N, M;
std::vector<int> vec;
std::vector<bool> visited;

void DFS(int cnt)
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

    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            vec[cnt] = i;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    std::cin>>N>>M;
    vec.assign(N + 1, 0);
    visited.assign(N + 1, false);
    DFS(0);

    return 0;
}