#include <iostream>
#include <string>
#include <vector>

struct Stack
{
    /* data */
    std::vector<int> data;
};

int main()
{
    Stack* s;
    int N= 0;
    int x = 0;
    std::string op;

    s = new Stack;

    std::cin>>N;


    for(int i = 0; i < N; i++)
    {
        std::cin>>op;

        if(op == "push")
        {
            std::cin>>x;
            s->data.push_back(x);
        }
        else if(op == "pop")
        {
            if(!s->data.empty())
            {
                std::cout<<s->data.back()<<std::endl;
                s->data.pop_back();
            }
            else
            {
                std::cout<<-1<<std::endl;
            }
            
        }
        else if(op == "size")
        {
            std::cout<<s->data.size()<<std::endl;
        }
        else if(op == "empty")
        {
            if(s->data.empty())
            {
                std::cout<<1<<std::endl;
            }
            else{
                std::cout<<0<<std::endl;
            }
        }
        else if(op == "top")
        {
             if(!s->data.empty())
            {
                std::cout<<s->data.back()<<std::endl;
            }
            else
            {
                std::cout<<-1<<std::endl;
            }
            
        }else{
            break;
        }
    }

    return 0;
}

