#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<char,char>> tree;

void Preorder(char val)
{
    if(val == '.')
    {
        return;
    }

    std::cout<<val;
    Preorder(tree[val - 'A'].first);
    Preorder(tree[val - 'A'].second);
}

void Inorder(char val)
{
    if(val == '.')
    {
        return;
    }

    Inorder(tree[val - 'A'].first);
    std::cout<<val;
    Inorder(tree[val - 'A'].second);
}

void Postorder(char val)
{
    if(val == '.')
    {
        return;
    }

    Postorder(tree[val - 'A'].first);
    Postorder(tree[val - 'A'].second);
    std::cout<<val;
}

int main()
{
    int N;
    char temp1, temp2, temp3;

    std::cin>>N;

    tree.assign(N,std::pair<char,char>());

    for(int i = 0; i < N; i++)
    {
        std::cin>>temp1>>temp2>>temp3;
        tree[temp1 - 'A'].first = temp2;
        tree[temp1 - 'A'].second = temp3;
    }

    Preorder('A');
    std::cout<<'\n';
    Inorder('A');
    std::cout<<'\n';
    Postorder('A');

    return 0;
}