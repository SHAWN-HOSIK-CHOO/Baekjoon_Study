#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
std::vector<int> A;
std::vector<int> B;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>M;
    int tmp;

    for(int i = 0; i < N; i++)
    {
        std::cin>>tmp;
        pq.push(tmp);
    }

    for(int i = 0; i < M; i++)
    {
        std::cin>>tmp;
        pq.push(tmp);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        std::cout<<cur<<" ";
    }
    
    return 0;
}