/*
    출처 :  https://ongveloper.tistory.com/326
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N, ans = 0;
std::vector<int> v;

int main()
{
    std::cin>>N;
    
    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;

        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        ans = std::max(ans, (N - i) * v[i]);
    }

    std::cout<<ans<<'\n';

    return 0;
}
