/*
    출처 : https://tooo1.tistory.com/72
*/

#include <iostream>

int N;
int input[10001] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;

    int tmp;

    for(int i = 0; i < N; i++)
    {
        std::cin>>tmp;
        input[tmp]++;
    }

    for(int i = 1; i <= 10000; i++)
    {
        for(int j = 0; j < input[i]; j++)
        {
            std::cout<<i<<'\n';
        }
    }

    return 0;
}