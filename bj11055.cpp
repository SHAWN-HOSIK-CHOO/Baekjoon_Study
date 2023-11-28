/*
    출처 : https://yabmoons.tistory.com/87
*/
#include <iostream>
#include <vector>

int main()
{
    int N, max = 0;
    std::vector<int> dp;
    std::vector<int> array;

    std::cin>>N;
    dp.assign(N,0);
    array.assign(N,0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>array[i];
    }

    for(int i = 0; i < N; i++)
    {
        dp[i] = array[i];
        for (int j = 0; j < i; j++)
        {
            /* code */
            if(array[i] > array[j] && dp[i] < dp[j] + array[i])
            {
                dp[i] = dp[j] + array[i];
            }
        }

        if(dp[i] > max)
        {
            max = dp[i];
        }
    }

    std::cout<<max;

    return 0;
}