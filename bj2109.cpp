/*
    출처 : https://baebalja.tistory.com/24
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n, sum = 0;
std::vector<std::pair<int,int>> v; // {d, p}
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main()
{
    int p, d;
    std::cin>>n;

    for(int i = 0; i < n; i++)
    {
        std::cin>>p>>d;
        v.push_back({d, p});
    }

    std::sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        pq.push(v[i].second); 

        if(pq.size() > v[i].first) pq.pop();
    }

    while (!pq.empty())
    {
        /* code */
        sum += pq.top();
        pq.pop();
    }
    
    std::cout<<sum;

    return 0;
}