#include <iostream>
#include <deque>
#include <string>

int N;
std::deque<int> dq;

int main()
{
    std::cin>>N;
    std::string op;
    int tmp;

    for(int i = 0; i < N; i++)
    {
        std::cin>>op;

        if(op == "push_front")
        {
            std::cin>>tmp;
            dq.push_front(tmp);
        }
        else if(op == "push_back")
        {
            std::cin>>tmp;
            dq.push_back(tmp);
        }
        else if(op == "pop_front")
        {
            if(dq.empty())
            {
                std::cout<<-1<<'\n';
                continue;
            }

            std::cout<<dq.front()<<'\n';
            dq.pop_front();
        }
        else if(op == "pop_back")
        {
            if(dq.empty())
            {
                std::cout<<-1<<'\n';
                continue;
            }

            std::cout<<dq.back()<<'\n';
            dq.pop_back();
        }
        else if(op == "size")
        {
            std::cout<<dq.size()<<'\n';
        }
        else if(op == "empty")
        {
            if(dq.empty())
            {
                std::cout<<1<<'\n';
            }
            else
            {
                std::cout<<0<<'\n';
            }
        }
        else if(op == "front")
        {
            if(dq.empty())
            {
                std::cout<<-1<<'\n';
                continue;
            }
            std::cout<<dq.front()<<'\n';
        }
        else if(op == "back")
        {
            if(dq.empty())
            {
                std::cout<<-1<<'\n';
                continue;
            }
            std::cout<<dq.back()<<'\n';
        }
        else
        {
            std::cout<<"Wrong OP"<<'\n';
        }
    }

    return 0;
}