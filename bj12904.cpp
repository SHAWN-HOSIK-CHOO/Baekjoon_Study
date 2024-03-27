/*
    출처 : https://m.blog.naver.com/fbfbf1/222658732446
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string S, T;

int main()
{
    std::cin>>S>>T;

    while (true)
    {
        if(T[T.size() - 1] == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }

        if(S.size() == T.size())
        {
            if(S == T)
            {
                std::cout<<1;
            }
            else
            {
                std::cout<<0;
            }

            break;
        }
    }
    
    return 0;
}