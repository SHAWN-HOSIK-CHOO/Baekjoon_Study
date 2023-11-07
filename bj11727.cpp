#include <iostream>
#include <vector>

int main()
{
    int n;
    std::vector<int> v;

    std::cin>>n;

    v.assign(n+1,0);

    v[1] = 1;
    v[2] = 3;

    for(int i = 3; i <= n; i++)
    {
        v[i] = (v[i - 1] + 2 * v[i - 2])  % 10007;
    }

    std::cout<<v[n];

    return 0;
}