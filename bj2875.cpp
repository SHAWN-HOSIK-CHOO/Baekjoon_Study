#include <iostream>
#include <algorithm>

int N, M, K, max = 0;

int main()
{
    std::cin>>N>>M>>K;

    for(int i = 0; i <= K; i++)
    {
        int girls_able = (N - i) / 2;
        int guys_able = M - (K - i);

        if(max < std::min(girls_able, guys_able)) max = std::min(girls_able, guys_able);
    }

    std::cout<<max;

    return 0;
}