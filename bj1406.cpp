#include <iostream>
#include <list>
#include <string>

int main()
{
    std::string input;
    int M;
    char op, c;

    std::cin>>input;
    std::cin>>M;

    std::list<char> myList(input.begin(),input.end());

    std::list<char>::iterator cursor = myList.end();

    for(int i = 0; i < M; i++)
    {
        std::cin>>op;
        
        switch (op)
        {
        case 'L':
        {
            if(cursor != myList.begin())
            {
                cursor--;
            }
            break;
        }
        case 'D':
        {
            if(cursor != myList.end())
            {
                cursor++;
            }
            break;
        }
        case 'B':
        {
            if(cursor != myList.begin())
            {
                cursor--;
                cursor = myList.erase(cursor);
            }
            break;
        }
        case 'P':
        {
            std::cin>>c;
            myList.insert(cursor,c);
            break;
        }
        default:
            break;
        }
    }

    for(auto l : myList)
    {
        std::cout<<l;
    }

    return 0;
}