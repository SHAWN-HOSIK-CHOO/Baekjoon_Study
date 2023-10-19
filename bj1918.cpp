#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    std::string input;
    std::vector<char> ans;
    std::stack<char> s;
    std::unordered_map<char,int> priorityMap;

    priorityMap.insert({'(',0});
    priorityMap.insert({'*',2});
    priorityMap.insert({'/',2});
    priorityMap.insert({'+',1});
    priorityMap.insert({'-',1});

    std::cin>>input;

    for(int i = 0; i < input.length(); i++)
    {
        if(input.at(i) >= 'A' && input.at(i) <= 'Z')
        {
            ans.push_back(input.at(i));
        }
        else if(input.at(i) == '(')
        {
            s.push('(');
        }
        else if(input.at(i) == ')')
        {
            while(s.top() != '(')
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && priorityMap[s.top()] >= priorityMap[input.at(i)])
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.push(input.at(i));
        }
    }

    for(auto a : ans)
    {
        std::cout<<a;
    }
    while(!s.empty())
    {
        std::cout<<s.top();
        s.pop();
    }

    return 0;
}