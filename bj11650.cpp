#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int N;
std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
std::vector<std::pair<int,int>> v;

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        int x, y;
        std::cin>>x>>y;

        pq.push({x, y});
    }

    while (!pq.empty())
    {
        std::pair<int,int> cur = pq.top();
        pq.pop();

        std::cout<<cur.first<<" "<<cur.second<<'\n';
    }
    

    return 0;
}