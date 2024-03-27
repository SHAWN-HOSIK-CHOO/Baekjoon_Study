/*
    출처 :  https://chanhuiseok.github.io/posts/baek-13/
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

int N;
std::unordered_map<int, int> res;
std::vector<std::vector<int>> map;

bool Check(int x, int y, int num)
{
    int start = map[x][y];
    for(int i = x; i < x + num; i++)
    {
        for(int j = y; j < y + num; j++)
        {
            if(start != map[i][j]) return false;
        }
    }

    return true;
}

void Divide(int x, int y, int num)
{
    if(Check(x, y, num)) res[map[x][y]]++;
    else
    {
        int size = num / 3;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                Divide(x + size * i, y + size * j, size);
            }
        }
    }
}

int main()
{
    std::cin>>N;
    map.assign(N, std::vector<int>(N ,0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin>>map[i][j];
        }
    }

    Divide(0, 0, N);

    std::cout<<res[-1]<<'\n'<<res[0]<<'\n'<<res[1]<<'\n';

    return 0;
}