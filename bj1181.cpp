#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int N;

struct Compare
{
    bool operator() (const std::string& s1, const std::string& s2) const
    {
        if(s1.length() != s2.length())
        {
            return s1.length() < s2.length();
        }
        else
        {
            return s1 < s2;
        }
    }
};

std::set<std::string, Compare> ans;

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::string tmp;
        std::cin>>tmp;

        ans.insert(tmp);
    }

    for(std::string s : ans)
    {
        std::cout<<s<<'\n';
    }

    return 0;
}