/*
    출처 : https://junbastick.tistory.com/8
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, max = 0;
    std::vector<int> array;
    std::vector<std::vector<int>> dp; // 1은 제거했다는 것 0은 안했다는 것 표시

    std::cin>>n;

    array.assign(n,0);
    dp.assign(n, std::vector<int>(2,0));

    for(int i = 0; i < n; i++)
    {
        std::cin>>array[i];
    }

    dp[0][1] = array[0];
    dp[0][0] = array[0];
    max = array[0];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = std::max(array[i], dp[i - 1][0] + array[i]);
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1] + array[i]);

        max = std::max(max, std::max(dp[i][0], dp[i][1]));
    }

    std::cout<<max;

    return 0;
}