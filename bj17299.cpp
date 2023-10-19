#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);

    std::vector<int> ans;
    std::stack<int> s;
    std::vector<int> v;
    std::unordered_map<int,int> table;
    int N, num;

    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>num;
        table[num]++;
        v.push_back(num);
    }

    for(int i = N-1; i >= 0; i--)
    {
        while(!s.empty() && table[v[i]] >= table[s.top()])
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

        s.push(v[i]);
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        std::cout<<*it<<" ";
    }

    return 0;
}