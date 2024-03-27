/*
    출처 : https://geniusjo-story.tistory.com/489
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define inf 987654321

int N, ans = inf;
std::vector<std::string> arr;

int Solve(int r)
{
    int ret = 0;
    for(int i = 0; i < N; i++)
    {
        int tail_cnt = 0;
        int head_cnt = 0;

        for(int j = 0; j < N; j++)
        {
            if(((r >> j) & 1) == 1)
            {
                if(arr[i][j] == 'H') tail_cnt++;
                else head_cnt++;
            }
            else
            {
                if(arr[i][j] == 'H') head_cnt++;
                else tail_cnt++;
            }
        }

        ret += std::min(head_cnt, tail_cnt);
    }

    return ret;
}

int main()
{
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        std::string tmp;
        std::cin>>tmp;
        arr.push_back(tmp);
    }

    for(int r = 0; r < (1 << N); r++)
    {
        ans = std::min(ans, Solve(r));
    }

    std::cout<<ans;

    return 0;
}