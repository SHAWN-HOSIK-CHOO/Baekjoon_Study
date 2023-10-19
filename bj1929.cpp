#include <iostream>
#include <vector>

int main()
{
    int N,M;
    std::vector<int> plate;

    std::cin>>N>>M;

    for(int i = 0; i <= M; i++)
    {
        plate.push_back(1);
    }

    plate.at(1) = 0;

    for(int i = 2; i <= M; i++)
    {
        if(plate.at(i))
        {
            for(int j = i * 2; j <= M; j += i)
            {
                plate.at(j) = 0;
            }
        }
    }

    for(int i = N; i <= M; i++)
    {
        if(plate.at(i))
        {
            std::cout<<i<<'\n';
        }
    }

    return 0;
}