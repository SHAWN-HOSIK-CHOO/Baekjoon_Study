#include <iostream>

int Factorial(int n)
{
    if(!n)
    {   
        return 1;
    }
    else
    {
        return n*Factorial(n - 1);
    }
    
}

int main()
{
    int num, ans;
    std::cin>>num;

    ans = Factorial(num);

    std::cout<<ans;
    return 0;
}