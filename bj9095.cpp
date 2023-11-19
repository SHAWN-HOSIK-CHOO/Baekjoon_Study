#include <iostream>
#include <vector>


int main()
{
    int T, n;
    std::vector<int> v;

    std::cin>>T;

    for(int j = 0; j < T; j++){

        std::cin>>n;

        v.assign(n+1, 0);
        v[1] = 1;
        v[2] = 2;
        v[3] = 4;

        for(int i = 4; i <= n; i++)
        {
            v[i] = v[i - 1] + v[i - 2] + v[i - 3];
        }

        std::cout<<v[n]<<'\n';
    }

    return 0;
}