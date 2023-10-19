#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::vector<char> order;
    std::vector<char> ans;

    for(int i = 0; i < 26; i++)
    {
        order.push_back('a' + i);
    }

    std::getline(std::cin,input);

    for(int i = 0; i < input.length(); i++)
    {
        if(input.at(i) == ' ')
        {
            ans.push_back(' ');
        }
        else if(input.at(i) >= '0' && input.at(i) <= '9')
        {
            ans.push_back(input.at(i));
        }
        else
        {
            if(std::isupper(input.at(i)))
            {
                auto it = std::find(order.begin(),order.end(),std::tolower(input.at(i)));
                for(int i = 0; i < 13; i++)
                {   
                    it++;
                    if(it == order.end())
                    {
                        it = order.begin();
                    }
                }
                ans.push_back(std::toupper(*it));
            }
            else
            {
                auto it = std::find(order.begin(),order.end(),input.at(i));
                for(int i = 0; i < 13; i++)
                {   
                    it++;
                    if(it == order.end())
                    {
                        it = order.begin();
                    }
                }
                ans.push_back(*it);
            }
        }
        
    }

    for(auto a : ans)
    {
        std::cout<<a;
    }

    return 0;
}