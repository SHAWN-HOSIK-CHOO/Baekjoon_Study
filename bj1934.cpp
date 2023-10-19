#include <iostream>
#include <vector>

int GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b,a%b);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, num1,num2;
    std::vector<int> ans;
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>num1>>num2;
        ans.push_back(num1*num2 /GCD(num1,num2));
    }

    for(auto a : ans)
    {
        std::cout<<a<<'\n';
    }

    return 0;
}