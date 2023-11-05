/*
    https://danidani-de.tistory.com/4
    코드 참고했습니다. 감사합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::vector<int> v;

    std::cin>>N;

    v.assign(N+1,0);

    for(int i = 2; i <= N; i++)
    {
        v[i] = v[i - 1] + 1;
        
        if(i%2 == 0)
        {
            v[i] = std::min(v[i],v[i/2] + 1);
        }

        if(i%3 == 0)
        {
            v[i] = std::min(v[i],v[i/3] + 1);
        }
    }

    std::cout<<v[N];

    return 0;
}