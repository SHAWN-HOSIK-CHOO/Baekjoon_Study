#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<char,char>> SegTree;

void Preorder(char val)
{
    if(val == '.')
    {
        return;
    }

    std::cout<<val;
    Preorder(SegTree[val - 'A'].first);
    Preorder(SegTree[val - 'A'].second);
}

void Inorder(char val)
{
    if(val == '.')
    {
        return;
    }

    Inorder(SegTree[val - 'A'].first);
    std::cout<<val;
    Inorder(SegTree[val - 'A'].second);
}

void Postorder(char val)
{
    if(val == '.')
    {
        return;
    }

    Postorder(SegTree[val - 'A'].first);
    Postorder(SegTree[val - 'A'].second);
    std::cout<<val;
}

int main()
{
    int N;
    char temp1, temp2, temp3;

    std::cin>>N;

    SegTree.assign(N,std::pair<char,char>());

    for(int i = 0; i < N; i++)
    {
        std::cin>>temp1>>temp2>>temp3;
        SegTree[temp1 - 'A'].first = temp2;
        SegTree[temp1 - 'A'].second = temp3;
    }

    Preorder('A');
    std::cout<<'\n';
    Inorder('A');
    std::cout<<'\n';
    Postorder('A');

    return 0;
}