#include <iostream>
#include <list>
#include <vector>

int main()
{
    int N, K;
    std::list<int> seq;
    std::vector<int> ans;

    std::cin>>N>>K;

    for(int i = 1; i <= N; i++)
    {
        seq.push_back(i);
    }

    std::list<int>::iterator kill = seq.begin();

    while(!seq.empty())
    {

        for(int i = 0; i < K - 1; i++)
        {
            kill++;
            if(kill == seq.end())
            {
                kill = seq.begin();
            }
        }
        ans.push_back(*kill);
        kill = seq.erase(kill);

        // 중요 ******* kill 반복자가 마지막 원소를 지우면 seq의 end로 이동하게 된다. 따라서 처음으로 되돌리는 코드를 다시 한번 적용해야한다.
        if(kill == seq.end())
        {
            kill = seq.begin();
        }
    }

    std::cout<<"<";
    for(int i = 0; i < N-1;i++)
    {
        std::cout<<ans[i]<<", ";
    }
    std::cout<<ans[N-1]<<">";

    return 0;
}