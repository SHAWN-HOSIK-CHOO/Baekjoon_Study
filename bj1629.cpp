/*
    출처 : https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-1629%EB%B2%88-%EA%B3%B1%EC%85%88-CC
*/
#include <iostream>
#include <vector>

#define ll long long

int A, B, C;

ll power(int p)
{
    if(p == 1) return A%C;

    ll k = power(p / 2) % C;

    if(p % 2 == 0) return k * k % C;
    else return k * k % C * A % C;
}

int main()
{
    std::cin>>A>>B>>C;

    std::cout<<power(B);

    return 0;
}