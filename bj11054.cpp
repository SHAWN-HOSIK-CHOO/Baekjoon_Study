/*
    출처 : https://snnchallenge.tistory.com/51
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, max = 0;
    std::vector<int> array;
    std::vector<int> left_dp;
    std::vector<int> right_dp;

    std::cin>>N;

    array.assign(N,0);
    left_dp.assign(N,1);
    right_dp.assign(N,1);

    for(int i = 0; i < N; i++)
    {
        std::cin>>array[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(array[i] > array[j] && left_dp[i] < (left_dp[j] + 1))
            {
               left_dp[i] = left_dp[j] + 1;
            }
        }
    }

    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(array[i] > array[j] && right_dp[i] < (right_dp[j] + 1))
            {
                right_dp[i] = right_dp[j] + 1;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        max = std::max(max, left_dp[i] + right_dp[i]);
    }

    std::cout<<max - 1;

    return 0;
}