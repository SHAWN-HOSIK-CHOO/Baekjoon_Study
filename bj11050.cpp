#include <iostream>
#include <algorithm>

int N, K;

int Factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * Factorial(n - 1);
}

int main()
{
    std::cin>>N>>K;

    std::cout<<(Factorial(N) / (Factorial(K) * Factorial(N - K)));

    return 0;
}