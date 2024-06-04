/*
    출처 : https://cloer.tistory.com/118
*/
#include <iostream>
#include <stack>
#include <algorithm>

struct Rect 
{
    int index, height;
};

int N, ans = 0;
std::stack<Rect> s;

int main()
{
    std::cin>>N;

    for(int i = 0; i <= N; i++)
    {
        int h = 0;
        int index = i;

        if(i != N)
        {
            std::cin>>h;
        }

        while (!s.empty() && s.top().height > h)
        {
            index = s.top().index;
            ans = std::max(ans, s.top().height * (i - index));
            s.pop();
        }
        
        if(s.empty() || s.top().height != h)
        {
            s.push({index, h});
        }
    }

    std::cout<<ans<<'\n';

    return 0;
}