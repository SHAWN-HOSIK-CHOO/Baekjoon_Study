#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> v;

int main()
{
    std::cin>>n;

    for(int i = 0; i < n; i++)
    {
        int input;
        std::cin>>input;

        if(v.empty() || v.back() < input) v.push_back(input);
        else *std::lower_bound(v.begin(), v.end(), input) = input;
    }

    std::cout<<v.size();

    return 0;
}