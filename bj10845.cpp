#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<int> queue;
    std::string op;
    int N, val;

    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        std::cin>>op;

        if(op == "push")
        {
            std::cin>>val;
            queue.push_back(val);
        }
        else if(op == "pop")
        {
            if(queue.empty())
            {
                std::cout<<-1<<'\n';
            }
            else
            {
                std::cout<<queue.front()<<'\n';
                queue.pop_front();
            }
        }
        else if(op == "size")
        {
            std::cout<<queue.size()<<'\n';
        }
        else if(op == "empty")
        {
            if(queue.empty())
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
            if(queue.empty())
            {
                std::cout<<-1<<'\n';
            }
            else
            {
                std::cout<<queue.front()<<'\n';
            }
        }
        else if(op == "back")
        {
            if(queue.empty())
            {
                std::cout<<-1<<'\n';
            }
            else
            {
                std::cout<<queue.back()<<'\n';
            }
        }
        else
        {
            std::cout<<"error"<<'\n';
        }
    }

    return 0;
}