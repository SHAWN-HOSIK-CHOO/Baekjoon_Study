#include <iostream>
#include <stack>
#include <string>

int main()
{
    int N = 0;
    std::stack<char> stack;
    std::string s;

    std::cin>>N;

    std::cin.ignore();
    for(int i = 0; i < N; i++)
    {
        std::getline(std::cin,s);
        s += " ";

        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == ' ')
            {
                while(!stack.empty())
                {
                    std::cout<<stack.top();
                    stack.pop();
                }
                std::cout<<" ";
            }
            else
            {
                stack.push(s[j]);
            }
        }
    }

    return 0;
}

