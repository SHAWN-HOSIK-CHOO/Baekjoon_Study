#include <iostream>
#include <vector>
#include <algorithm>

int N, acc = 0, ans = 0;
std::vector<int> time;

int main()
{
    std::cin>>N;
    time.assign(N, 0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>time[i];
    }

    std::sort(time.begin(), time.end());

    for(int i = 0; i < N; i++)
    {
        acc += time[i];
        ans += acc;
    }

    std::cout<<ans;

    return 0;
}