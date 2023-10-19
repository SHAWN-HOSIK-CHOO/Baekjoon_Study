#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int N, num, cur = 1;

    std::stack<int> stack;
    std::vector<char> ans;

    std::cin>>N;

    for(int i = 1; i <= N; i++)
    {
        std::cin>>num;
        while(cur <= num)
        {
                stack.push(cur);
                ans.push_back('+');
                cur++;
        }
        
        if(stack.top() == num)
        {
            stack.pop();
            ans.push_back('-');
        }
        else
        {
            std::cout<<"NO";
            return 0;
        }
    
    }

    for(auto a : ans)
    {
        std::cout<<a<<'\n';
    }

    return 0;
}