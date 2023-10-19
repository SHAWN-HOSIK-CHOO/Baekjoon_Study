//https://mun-coding.tistory.com/39 참고했습니다.

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long long N;
    std::string ans = "";

    std::cin>>N;

    while(true)
    {
        if((N == 1) || (N == 0))
        {
            ans.append(std::to_string(N));
            break;
        }
        else if(N % -2 == 0)
        {
            ans.append(std::to_string(0));
            N /= -2;
        }
        else
        {
            ans.append(std::to_string(1));
            N = N - 1;
            N /= -2;
        }
        
    }

    std::reverse(ans.begin(),ans.end());

    std::cout<<ans;

    return 0;
}