#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

int main()
{
    int temp, tempsum = 0;
    std::string bin_input;
    std::queue<int> q;
    std::stack<int> ans;

    std::cin>>bin_input;

    for(int i = bin_input.size() - 1; i >= 0; i--)
    {
        q.push(bin_input[i] - '0');
    }

    while(q.size() % 3 != 0)
    {
        q.push(0);
    }

    while(!q.empty()){
        for(int i = 0; i < 3; i++)
        {
            temp = q.front();
            q.pop();
            tempsum += std::pow(2,i) * temp;
        }
        ans.push(tempsum);
        tempsum = 0;
    }

    while (!ans.empty() && ans.top() == 0)
    {
        ans.pop();
    }

    if(ans.empty())
    {
        ans.push(0);
    }
    
    while(!ans.empty())
    {
        std::cout<<ans.top();
        ans.pop();
    }

    return 0;
}