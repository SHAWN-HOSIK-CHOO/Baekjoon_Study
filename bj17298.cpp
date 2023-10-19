#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int N, num;
    std::vector<int> v;
    std::vector<int> ans;
    std::stack<int> s;
    bool found = false;

    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>num;
        v.push_back(num);
    }

    for(int i = N-1; i >= 0; i--)
    {
        while(!s.empty() && s.top() <= v.at(i))
        {
            s.pop();
        }

        if(s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }

        s.push(v.at(i));
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        std::cout<<*it<<" ";
    }
    return 0;
}