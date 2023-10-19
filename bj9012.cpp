#include <iostream>
#include <stack>
#include <string>

int main()
{
    int N;
    std::stack<char> stack;
    std::string s;
    bool b = true;

    std::cin>>N;

    std::cin.ignore();
    for(int i = 0; i < N; i++)
    {
        std::getline(std::cin,s);
        b = true;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == '(')
            {
                stack.push(s[j]);
            }
            else
            {
                if(stack.empty())
                {
                    b = false;
                    std::cout<<"NO"<<std::endl;
                    break;
                }
                stack.pop();
            }
        }

        if(b)
        {
            if(stack.empty())
            {
                std::cout<<"YES"<<std::endl;
            }
            else
            {
                
                std::cout<<"NO"<<std::endl;
            }
        }

        while(!stack.empty())
        {
            stack.pop();
        }
    }


    return 0;
}