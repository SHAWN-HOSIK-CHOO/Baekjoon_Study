#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int N,K;
std::deque<std::pair<int,int>> q;
std::vector<bool> visited(100001,false);

void BFS()
{
    while (!q.empty())
    {
        /* code */
        int loc = q.front().first;
        int time = q.front().second;
        q.pop_front();

        //TODO: 왜 여기에서 visited check를 해야하는가
        visited[loc] = true;

        if(loc == K)
        {
            std::cout<<time;
            break;
        }

        if(loc - 1 >= 0 && !visited[loc - 1])
        {
            q.push_back({loc - 1, time + 1});
        }

        if(loc + 1 <= 100000 && !visited[loc + 1])
        {
            q.push_back({loc + 1, time + 1});
        }

        if(loc * 2 <= 100000 && !visited[loc * 2])
        {
            q.push_front({loc * 2, time});
        }
    }
    
}

int main()
{
    std::cin>>N>>K;
    
    q.push_back({N,0});

    BFS();

    return 0;
}