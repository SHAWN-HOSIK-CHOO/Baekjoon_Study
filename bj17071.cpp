/*
    출처 : https://transferhwang.tistory.com/291
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define end_region 500000

int N, K;
std::vector<std::vector<bool>> visited;

int bfs()
{
    std::queue<std::pair<int, int>> q;
    q.push({N, 0});
    visited[N][0] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if(K + cur.second * (cur.second + 1) / 2 > end_region)
        {
            return -1;
        }

        if(visited[K + cur.second * (cur.second + 1) / 2][cur.second % 2])
        {
            return cur.second;
        }

        if(cur.first * 2 <= end_region && !visited[cur.first * 2][(cur.second + 1) % 2])
        {
            visited[cur.first * 2][(cur.second + 1) % 2] = true;
            q.push({cur.first * 2, cur.second + 1});
        }

        if(cur.first + 1 <= end_region && !visited[cur.first + 1][(cur.second + 1) % 2])
        {
            visited[cur.first + 1][(cur.second + 1) % 2] = true;
            q.push({cur.first + 1, cur.second + 1});
        }

        if(cur.first - 1 >= 0 && !visited[cur.first - 1][(cur.second + 1) % 2])
        {
            visited[cur.first - 1][(cur.second + 1) % 2] = true;
            q.push({cur.first - 1, cur.second + 1});
        }
    }
    
}

int main()
{
    std::cin>>N>>K;

    visited.assign(end_region + 1, std::vector<bool>(2, false));

    std::cout<<bfs();

    return 0;
}