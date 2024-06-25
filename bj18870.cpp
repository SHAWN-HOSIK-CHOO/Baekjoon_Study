#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

int N;
std::set<int> g_Sorts;
std::vector<int> g_Inputs;
std::vector<int> ans;
std::unordered_map<int,int> g_Map;

int main()
{
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;
        g_Inputs.push_back(tmp);
        g_Sorts.insert(tmp);
    }

    int cnt = 0;
    for(int it : g_Sorts)
    {
        g_Map[it] = cnt++;
    }

    for(int it : g_Inputs)
    {
        std::cout<<g_Map[it]<<" ";
    }

    return 0;
}