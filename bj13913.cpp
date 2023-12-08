/*
    출처 : https://skd03052.tistory.com/151
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, K;
std::vector<bool> visited(100001,false);
std::queue<std::pair<int,int>> q;
std::vector<int> parent(100001,0);
std::vector<int> path;

void BFS()
{
    while (!q.empty())
    {
        /* code */
        int location = q.front().first;
        int time = q.front().second;
        q.pop();

        if(location == K)
        {
            int index = location;

            std::cout<<time<<'\n';
            
            while (index != N)
            {
                /* code */
                path.push_back(index);
                index = parent[index];
            }
            break;
        }

        if(location >= 0 && location < 100000)
        {
            if(!visited[location + 1])
            {
                visited[location + 1] = true;
                q.push({location + 1, time + 1});
                parent[location + 1] = location;
            }
        }

        if(location > 0 && location <= 100000)
        {
            if(!visited[location - 1])
            {
                visited[location - 1] = true;
                q.push({location - 1, time + 1});
                parent[location - 1] = location;
            }
        }

        if(location >= 0 && location * 2 <= 100000)
        {
            if(!visited[location * 2])
            {
                visited[location * 2] = true;
                q.push({location * 2, time + 1});
                parent[location * 2] = location;
            }
        }
    }
    
}

int main()
{
    std::cin>>N>>K;

    q.push({N,0});
    visited[N] = true;

    BFS();

    std::cout<<N<<" ";

    for(auto rit = path.rbegin(); rit != path.rend(); rit++)
    {
        std::cout<<*rit<<" ";
    }
    

    return 0;
}