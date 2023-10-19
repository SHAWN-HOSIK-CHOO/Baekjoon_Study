#include <iostream>
#include <string>
#include <algorithm>

std::string hex2bin(int hex)
{
    if(hex == 0)
    {
        return "000";
    }
    else
    {
        std::string rt_val = "";
        while(hex != 0)
        {
            rt_val.append(std::to_string(hex % 2));

            hex /= 2;
        }
        std::reverse(rt_val.begin(),rt_val.end());

        while(rt_val.length() % 3 != 0)
        {
            rt_val.insert(0,"0");
        }

        return rt_val;
    }
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string hex, ans = "";

    std::cin>>hex;

    for(int i = 0; i < hex.size(); i++)
    {
        ans += hex2bin(hex[i] - '0');
    }

    while(ans.front() == '0')
    {
        ans.erase(0,1);
    }

    if(ans.empty())
    {
        ans = "0";
    }

    std::cout<<ans;

    return 0;
}