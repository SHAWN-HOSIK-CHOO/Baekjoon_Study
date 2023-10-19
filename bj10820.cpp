#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);

    std::string input;

    while(std::getline(std::cin,input)){
        std::vector<int> v(4,0);
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] >= 'a' && input[i] <= 'z')
            {
            v.at(0)++;
            }
            else if(input[i] >= 'A' && input[i] <= 'Z')
            {
                v.at(1)++;
            }
            else if(input[i] >= '0' && input[i] <= '9')
            {
                v.at(2)++;
            }
            else if(input[i] == ' ')
            {
                v.at(3)++;
            }
        }

        for(auto a : v)
        {
            std::cout<<a<<" ";
        }
        std::cout<<'\n';
    }
    return 0;
}