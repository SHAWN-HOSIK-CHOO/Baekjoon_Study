#include <iostream>
#include <algorithm>

int main()
{
    std::pair<int, int> p1;
    std::pair<int, int> p2;
    std::pair<int, int> p3;

    std::cin>>p1.first>>p1.second;
    std::cin>>p2.first>>p2.second;
    std::cin>>p3.first>>p3.second;

    int ans = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);

    if(ans > 0) std::cout<<1;
    else if(ans < 0) std::cout<<-1;
    else std::cout<<0;

    return 0;
}