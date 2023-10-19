#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int A,B,C, AmodC, BmodC;
    std::vector<int> ans;

    std::cin>>A>>B>>C;

    AmodC = (A%C);
    BmodC = (B%C);

    ans.push_back((A + B)%C);
    ans.push_back((AmodC + BmodC)%C);
    ans.push_back((A * B)%C);
    ans.push_back((AmodC * BmodC)%C);

    for(auto it : ans)
    {
        std::cout<<it<<'\n';
    }
    return 0;
}