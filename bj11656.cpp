#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<std::string> array;
    std::string input, temp;

    std::cin>>input;

    for(int i = 0; i < input.length(); i++)
    {
        temp = input.substr(i,input.length());
        array.push_back(temp);
    }

    std::sort(array.begin(),array.end());

    for(auto e : array)
    {
        std::cout<<e<<'\n';
    }

    return 0;
}