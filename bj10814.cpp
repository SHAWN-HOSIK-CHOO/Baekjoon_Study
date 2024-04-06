#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>

int N;
std::unordered_map<int, std::string> dict;
std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

int main()
{
    std::cin>>N;

    int temp1;
    std::string temp2;

    for(int i = 0; i < N; i++)
    {
        std::cin>>temp1>>temp2;
        dict[i] = temp2;

        pq.push({temp1, i});
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        std::cout<<cur.first<<" "<<dict[cur.second]<<'\n';    
    }
    
    return 0;
}
