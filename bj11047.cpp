#include <iostream>
#include <vector>
#include <stack>

int N, K, cur_cnt = 0;
std::stack<int> s;

int main()
{   
    std::cin>>N>>K;

    for(int i = 0; i < N; i++)
    {
        int tmp;

        std::cin>>tmp;
        s.push(tmp);
    }

    while (!s.empty() && K != 0)
    {
        int cur = s.top();
        s.pop();

        if(K == 0) break;

        if(K < cur) continue;

        cur_cnt += (K / cur);
        K %= cur;
    }

    std::cout<<cur_cnt;
    
    return 0;
}