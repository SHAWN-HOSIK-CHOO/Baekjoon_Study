#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<bool> visited;
std::queue<std::pair<int,int>> q;
int N,K, gMinTime = 0;

void BFS()
{
    while (!q.empty())
    {
        int location = q.front().first;
        int time = q.front().second;
        q.pop();

        if(location == K)
        {
            gMinTime = time;
            break;
        }

        if(location >= 0 && location < 100000)
        {
            if(!visited[location + 1])
            {
                visited[location + 1] = true;
                q.push({location + 1, time + 1});
            }
        }

        if(location >= 1 && location <= 100000)
        {
            if(!visited[location - 1])
            {
                visited[location - 1] = true;
                q.push({location - 1, time + 1});
            }
        }

        if(location >= 0 && location * 2 <= 100000)
        {   
            if(!visited[location * 2])
            {
                visited[location * 2] = true;
                q.push({location * 2, time + 1});
            }
        }
    }
}

int main()
{
    std::cin>>N>>K;

    visited.assign(100001,false);

    visited[N] = true;
    q.push({N,0});

    BFS();

    std::cout<<gMinTime;

    return 0;
}