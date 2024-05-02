#include <iostream>
#include <vector>
#include <string>

int N;
std::vector<std::vector<int>> tree;

void TreePartition(int x, int y, int size)
{
    for(int i = x; i < x + size; i++)
    {
        for(int j = y; j < y + size; j++)
        {
            if(tree[i][j] != tree[x][y])
            {
                std::cout<<"(";
                TreePartition(x, y, size / 2);
                TreePartition(x, y + size / 2, size / 2);
                TreePartition(x + size / 2, y, size / 2);
                TreePartition(x + size / 2, y + size / 2, size / 2);
                std::cout<<")";
                return;
            }
        }
    }
    std::cout<<tree[x][y];
}

int main()
{
    std::cin>>N;
    tree.assign(N + 1, std::vector<int>(N + 1, 0));

    std::string tmp;
    for(int i = 0; i < N; i++)
    {
        std::cin>>tmp;
        for(int j = 0; j < tmp.size(); j++)
        {
            tree[i][j] = tmp[j] - '0';
        }
    }

    TreePartition(0, 0, N);

    return 0;
}