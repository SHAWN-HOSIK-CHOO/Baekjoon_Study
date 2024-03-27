/*
    출처 : https://codejin.tistory.com/169
*/
#include <iostream>
#include <algorithm>

int N, M, ans = 0;

int main()
{
    std::cin>>N>>M;

    if(N == 1)
    {
        std::cout<<1;
    }
    else if(N == 2)
    {
        std::cout<<std::min(4, (M + 1) / 2);
    }
    else if(M < 7)
    {
        std::cout<<std::min(4, M);
    }
    else
    {
        std::cout<<M - 2;
    }

    return 0;
}

