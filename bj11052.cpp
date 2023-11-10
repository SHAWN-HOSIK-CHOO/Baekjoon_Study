#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::vector<int> p;
    std::vector<int> ans;

    std::cin>>N;
    p.assign(N+1,0);
    ans.assign(N+1,0);

    for(int i = 1; i <= N; i++)
    {
        std::cin>>p[i];
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            ans[i] = std::max(ans[i],ans[i - j] + p[j]);
        }
    }

    std::cout<<ans[N];

    return 0;
}