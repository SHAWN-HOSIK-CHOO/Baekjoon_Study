#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;

int main()
{
    for(int i = 0; i < 3; i++)
    {
        int tmp;
        std::cin>>tmp;

        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end(), std::greater<int>());

    std::cout<<v[1]<<'\n';

    return 0;
}
