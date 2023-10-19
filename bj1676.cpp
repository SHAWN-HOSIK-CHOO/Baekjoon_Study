/*https://velog.io/@youhyeoneee/%EB%B0%B1%EC%A4%80-1676%EB%B2%88-%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC-0%EC%9D%98-%EA%B0%9C%EC%88%98
    youhyeoneee.log님 코드 참고
*/

#include <iostream>

int main()
{
    int num, cnt = 0;

    std::cin>>num;

    for(int i = 2; i <= num; i++)
    {
        if(i % 5 == 0)
        {
            cnt++;
        }

        if(i % 25 == 0)
        {
            cnt++;
        }

        if(i % 125 == 0)
        {
            cnt++;
        }
    }

    std::cout<<cnt;

    return 0;
}