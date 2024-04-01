/*
   출처 :  https://cryptosalamander.tistory.com/38
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N;

void Draw(int n, int x, int y)
{
    // n으로 나누는 이유 -> 일종의 정규화 과정
    if((x / n) % 3 == 1 && (y / n) % 3 == 1)
    {
        std::cout<<" ";
    }
    else
    {
        if(n / 3 == 0) std::cout<<"*";
        else Draw(n / 3, x, y);
    }
}

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Draw(N, i, j);
        }
        std::cout<<'\n';
    }

    return 0;
}