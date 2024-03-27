/*
    출처 : https://ongveloper.tistory.com/114
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::string s;
    std::cin>>s;

    std::sort(s.begin(), s.end(), std::greater<char>());

    if(s[s.length() - 1] != '0')
    {
        std::cout<<-1;
    }
    else
    {
        long long sum = 0;

        for(char c : s)
        {
            sum += c - '0';
        }

        if(sum % 3 == 0) std::cout<<s;
        else std::cout<<-1;
    }

    return 0;
}
