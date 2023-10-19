#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main()
{
    int cnt = 0;
    std::string input;
    std::stack<char> s;
    std::vector<char> ans;

    std::getline(std::cin,input);

    input += " ";

    while(cnt < input.size())
    {
        if(input[cnt] == '<')
        {
            if(!s.empty())
            {
                while(!s.empty())
                {
                    ans.push_back(s.top());
                    s.pop();
                }
            }

            while(input[cnt] != '>')
            {
                ans.push_back(input[cnt++]);
            }
            ans.push_back(input[cnt++]);

            if(input[cnt] == '<')
            {
                continue;
            }
        }


        if(input[cnt] == ' ')
        {
            if(s.empty())
            {
                break;
            }

            while(!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
            ans.push_back(' ');
            cnt++;
        }
        else
        {
            s.push(input[cnt++]);
        }
    }

    for(auto a : ans)
    {
        std::cout<<a;
    }

    return 0;
}