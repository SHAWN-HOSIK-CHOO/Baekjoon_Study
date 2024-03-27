/*
    출처 : https://non-stop.tistory.com/128
*/
#include <iostream>
#include <vector>

int N, root;
int Index[100001];
std::vector<int> inOrder;
std::vector<int> postOrder;

void PreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    if(inStart > inEnd || postStart > postEnd) return;

    int root = postOrder[postEnd];
    int rootIndex = Index[root];
    int leftSize = rootIndex - inStart;
    std::cout<<root<<" ";

    PreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    PreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
    std::cin>>N;

    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;
        inOrder.push_back(tmp);
        Index[tmp] = i;
    }

    for(int i = 0; i < N; i++)
    {
        int tmp;
        std::cin>>tmp;
        postOrder.push_back(tmp);
    }

    PreOrder(0, N - 1, 0, N - 1);

    return 0;
}