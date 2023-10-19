#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T, N, cnt = 0;
    std::vector<int> chae;

    for(int i = 0; i <= 1000000; i++)
    {
        chae.emplace_back(1);
    }

    chae.at(0) = 0;
    chae.at(1) = 0;

    for(int i = 2; i <= 1000000; i++)
    {
        if(chae.at(i))
        {
            for(int j = i * 2; j <= 1000000; j += i)
            {
                chae.at(j) = 0;
            }
        }
    }

    std::cin>>T;

    for(int i = 0; i < T; i++)
    {
        std::cin>>N;

        for(int j = 2; j <= N/2; j++)
        {
            if(chae.at(j) && chae.at(N - j))
            {
                cnt++;
            }
        }
        std::cout<<cnt<<'\n';
        cnt = 0;
    }

    return 0;
}