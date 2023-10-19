#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n = 1, a, b;
    bool ohYes = false;
    std::vector<int> chae;

    for(int i = 0; i <= 1000000; i++)
    {
        chae.push_back(1);
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

    while(true)
    {
        std::cin>>n;
        if(!n)
        {
            break;
        }

        for(int i = 2; i <= n/2; i++)
        {
            if(chae.at(i) && (n - i) > 0 &&chae.at(n - i))
            {
                ohYes = true;
                std::cout<<n<<" = "<<i<<" + "<<n - i<<'\n';
                break;
            }
        }

        if(!ohYes)
        {
            std::cout<<"Goldbach's conjecture is wrong."<<'\n';
            ohYes = false;
        }
    }

    return 0;
}