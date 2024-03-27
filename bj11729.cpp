#include <iostream>
#include <vector>

int N;

void Hanoi(int n, int from, int to, int bypass)
{
    if(n == 1) std::cout<<from<<" "<<to<<'\n';
    else
    {
        Hanoi(n - 1, from, bypass, to);
        std::cout<<from<<" "<<to<<'\n';
        Hanoi(n - 1, bypass, to, from);
    }
}

int main()
{
    std::cin>>N;

    std::cout<<(1 << N) - 1 <<'\n';

    Hanoi(N, 1, 3, 2);

    return 0;
}