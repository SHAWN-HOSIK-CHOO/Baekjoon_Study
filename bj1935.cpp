#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout<<std::fixed;
    std::cout.precision(2);

    int N, ans = 0; 
    double num, arg1, arg2;
    std::stack<double> s;
    std::string input;
    std::unordered_map<char,double> map;

    std::cin>>N;
    std::cin>>input;

    for(int i = 0; i < input.length(); i++)
    {
        if(input.at(i) >= 'A' && input.at(i) <= 'Z')
        {
            if(!map[input.at(i)])
            {
                std::cin>>num;
                map[input.at(i)] = num;
                s.push(num);
            }
            else
            {
                s.push(map[input.at(i)]);
            }
        }
        else
        {
            switch (input.at(i))
            {
            case '+': {
                arg1 = s.top(); 
                s.pop();
                arg2 = s.top();
                s.pop();
                s.push(arg1 + arg2);
                break;
            }
            case '-':{
                arg2 = s.top();
                s.pop();
                arg1 = s.top();
                s.pop();
                s.push(arg1 - arg2);
                break;  
            }
            case '/':{
                arg2 = s.top();
                s.pop();
                arg1 = s.top();
                s.pop();
                s.push(arg1 / arg2);
                break;
            }
            case '*':{
                arg2 = s.top();
                s.pop();
                arg1 = s.top();
                s.pop();
                s.push(arg1 * arg2);
            }
            default:
                break;
            }
        }
    }

    std::cout<<s.top();

    return 0;
}