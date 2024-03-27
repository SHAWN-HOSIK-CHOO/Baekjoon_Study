/*
    출처 : https://codingnotes.tistory.com/170
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, ans = 0;
std::vector<int> posv;
std::vector<int> negv;

int main()
{
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;

        if(tmp > 0) posv.push_back(tmp);
        else negv.push_back(tmp);
    }

    std::sort(posv.begin(), posv.end(), std::greater<int>());
    std::sort(negv.begin(), negv.end());

    if(posv.size() % 2 == 1) ans += posv[posv.size() - 1];

    if(posv.size() != 0)
        for(int i = 0; i < posv.size() - 1; i += 2)
        {
            if(posv[i + 1] == 1) ans += posv[i] + posv[i + 1];
            else if(posv[i + 1] > 0) ans += posv[i] * posv[i + 1];
        }

    if(negv.size() % 2 == 1) ans += negv[negv.size() - 1];

    if(negv.size() != 0)
        for(int i = 0; i < negv.size() - 1; i += 2)
        {
            ans += negv[i] * negv[i + 1];
        }

    std::cout<<ans;

    return 0;
}