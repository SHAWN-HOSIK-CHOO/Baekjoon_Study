/*
    출처 : https://cocoon1787.tistory.com/147
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, start, end, cnt = 1;
std::vector<std::pair<int,int>> t;

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>start>>end;
        t.push_back({end, start});
    }

    std::sort(t.begin(), t.end());

    int cur_time = t.front().first;

    for(int i = 1; i < N; i++)
    {
        if(cur_time <=  t[i].second)
        {
            cur_time = t[i].first;
            cnt++;
        }
    }

    std::cout<<cnt;

    return 0;
}