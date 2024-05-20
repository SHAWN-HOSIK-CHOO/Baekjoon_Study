#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int N, M;
std::map<std::string, int> g_Map;
std::vector<std::string> ans;

int main()
{
    std::cin>>N>>M;
    std::string tmp;

    for(int i = 0; i < N + M; i++)
    {
        std::cin>>tmp;
        g_Map[tmp]++;

        if(g_Map[tmp] > 1)
        {
            ans.push_back(tmp);
        }
    }

    std::cout<<ans.size()<<'\n';

    std::sort(ans.begin(), ans.end());

    for(auto a : ans)
    {
        std::cout<<a<<'\n';
    }

    return 0;
}