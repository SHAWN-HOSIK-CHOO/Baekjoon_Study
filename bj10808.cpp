#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<char,int> cmap;
    std::string input;

    for(int i = 0; i < 26; i++)
    {
        cmap.insert({'a' + i,0});
    }

    std::cin>>input;

    for(int i = 0; i < input.length(); i++)
    {
        cmap[input[i]]++;
    }

    for(int i = 0; i < 26; i++)
    {
        std::cout<<cmap['a' + i]<<" ";
    }

    return 0;
}