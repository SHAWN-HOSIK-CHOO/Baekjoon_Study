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

    long long number, ans = 0; int N, loop;
    std::vector<long long> nums;

    std::cin>>loop;

    for(int i = 0; i < loop; i ++)
    {
        std::cin>>N;

        for(int i = 0; i < N; i++)
        {
            std::cin>>number;
            nums.push_back(number);
        }

        for(int i = 0; i < N-1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                ans += GCD(nums.at(i),nums.at(j));
            }
        }

        std::cout<<ans<<'\n';
        ans = 0;
        nums.clear();
    }

    return 0;
}