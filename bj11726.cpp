/*
    https://velog.io/@matcha_/BOJ-%EB%B0%B1%EC%A4%80-11726-2xn-%ED%83%80%EC%9D%BC%EB%A7%81-C-DP
    블로그 참고했습니다. 감사합니다.
*/
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::vector<int> tile;

    std::cin>>n;

    tile.assign(n+1,0);

    tile[1] = 1;
    tile[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        tile[i] = (tile[i - 1] + tile[i - 2]) % 10007 ;
    }

    std::cout<<tile[n];

    return 0;
}