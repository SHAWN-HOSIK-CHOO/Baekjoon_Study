#include <iostream>

int GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a%b);
    }
    
}

int main()
{
    int A,B,gcd,lcm;

    std::cin>>A>>B;

    gcd = GCD(A,B);
    lcm = A*B / gcd;

    std::cout<<gcd<<'\n'<<lcm;

    return 0;
}