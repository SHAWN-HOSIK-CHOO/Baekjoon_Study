#include <iostream>
#include <vector>

int main()
{
    int fib[46] = {0};
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= 45; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    std::cin>>n;

    std::cout<<fib[n];

    return 0;
}