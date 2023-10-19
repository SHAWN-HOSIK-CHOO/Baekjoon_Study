#include <iostream>
#include <stack>
#include <cstdlib>

long long GCD(long long a, long long b)
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

    long long N, S, pos, temp1, temp2, temp3;
    std::stack<long long> position_dist;

    std::cin>>N>>S;

    for(int i = 0; i < N; i++)
    {
        std::cin>>pos;
        position_dist.push(std::abs(pos - S));
    }

    while(position_dist.size() > 1)
    {
        temp1 = position_dist.top();
        position_dist.pop();
        temp2 = position_dist.top();
        position_dist.pop();

        temp3 = GCD(temp1,temp2);
        position_dist.push(temp3);
    }

    std::cout<<position_dist.top();

    return 0;
}