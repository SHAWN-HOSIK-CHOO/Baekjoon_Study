#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string B,D;
    long long numA,numB,numC,numD;

    std::cin>>numA>>B>>numC>>D;

    for(int i = 0; i < B.size(); i++)
    {
        numA *= 10;
    }

    for(int i = 0; i < D.size(); i++)
    {
        numC *= 10;
    }
    
    numB = std::stoll(B);
    numD = std::stoll(D);

    std::cout<<numA + numB + numC + numD;

    return 0;
}