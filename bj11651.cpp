#include <iostream>
#include <queue>
#include <algorithm>

int N;
std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        int x, y;
        std::cin>>x>>y;

        pq.push({y,x});
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        std::cout<<cur.second<<" "<<cur.first<<'\n';
    }
    

    return 0;
}