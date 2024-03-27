/*
    출처 : https://donggoolosori.github.io/2020/09/22/boj-1074-Z/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N, r, c, ans = 0;
std::vector<std::vector<int>> map;

void Divide(int x, int y, int n)
{
   if(x == r && y == c)
   {    
        std::cout<<ans<<'\n';
        return;
   }

   if(r < x + n && r >= x && c < y + n && c >= y)
   {
        Divide(x, y, n / 2);
        Divide(x, y + n / 2, n / 2);
        Divide(x + n / 2, y, n / 2);
        Divide(x + n / 2, y + n / 2, n / 2);
   }
   else
   {
        ans += n * n;
   }
}

int main()
{
    std::cin>>N>>r>>c;
    map.assign(N, std::vector<int>(N, 0));

    Divide(0, 0, (1 << N));

    return 0;
}