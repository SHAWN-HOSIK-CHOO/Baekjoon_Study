/*
    출처 :  https://softworking.tistory.com/399
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int N, K;

int main()
{
    std::cin>>N>>K;

    for(int a = 1; a < N; a++)
    {
        int b = N - a;

        if(a * b < K) continue;

        std::vector<int> A_s(b + 1);
        for(int i = 0; i < a; i++)
        {
            int after = std::min(b, K);

            A_s[b - after]++;
            K -= after;
        }

        for(int i = 0; i <= b; i++)
        {
            for(int j = 0; j < A_s[i]; j++)
            {
                std::cout<<'A';
            }
            if(i < b) std::cout<<'B';
        }

        return 0;
    }

    std::cout<<-1;

    return 0;
}