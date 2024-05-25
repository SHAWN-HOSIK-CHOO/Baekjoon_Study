#include <iostream>
#include <vector>
#include <queue>

int N, x;
std::vector<int> ans;
std::priority_queue<int> pq;

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>x;

        if(x != 0)
            pq.push(x);
        else
        {
            if(pq.empty())
                ans.push_back(0);
            else
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
    }

    for(int a : ans)
    {
        std::cout<<a<<'\n';
    }

    return 0;
}