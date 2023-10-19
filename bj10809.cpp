#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<char,int> cmap;
    std::string input;

    std::cin>>input;

    for(int i = 0; i < 26; i ++)
    {
        cmap.insert({'a' + i,-1});
    }

    for(int i = 0; i < input.length(); i++)
    {
        if(cmap[input.at(i)] == -1)
        {
            cmap[input.at(i)] = i;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        std::cout<<cmap['a' + i]<<" ";
    }

    return 0;
}