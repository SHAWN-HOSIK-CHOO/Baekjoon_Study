#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string input;
    std::stack<char> s;
    int barCount = 0, razorCount = 0;

    std::cin>>input;

    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '(' && (i+1 < input.size()) && input[i+1] == ')')
        {
            if(!s.empty())
            {
                barCount += s.size();
            }
        }
        else if(input[i] == '(')
        {
            s.push(input[i]);
        }
        else if(input[i] == ')' && (i-1 >= 0) && input[i - 1] != '(')
        {
            s.pop();
            barCount++;
        }
    }

    std::cout<<barCount;

    return 0;
}