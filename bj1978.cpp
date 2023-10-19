#include <iostream>

int main()
{
    int N, num, ans = 0;

    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>num;
        bool isnPrime = false;

        if(num == 1)
        {
            continue;
        }
        else if(num == 2)
        {
            ans++;
        }
        else
        {
            for(int j = 2; j < num; j++)
            {
                if(num % j == 0)
                {
                    isnPrime = true;
                }
            }

            if(!isnPrime)
            {
                ans++;
            }
        }
    }

    std::cout<<ans;

    return 0;
}