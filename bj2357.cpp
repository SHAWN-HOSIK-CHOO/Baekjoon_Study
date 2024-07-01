/*
    출처 : https://yabmoons.tistory.com/433
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h> 

#define MAX 987654321

int N, M;
std::vector<int> MaxTree;
std::vector<int> MinTree;
int Array_[100001];

void MakeTree(int Node, int Start, int End)
{
    if(Start == End)
    {
        MaxTree[Node] = MinTree[Node] = Array_[Start];
    }
    else
    {
        int mid = (Start + End) / 2;
        MakeTree(Node * 2, Start, mid);
        MakeTree(Node * 2 + 1, mid + 1, End);
        MaxTree[Node] = std::max(MaxTree[Node * 2], MaxTree[Node * 2 + 1]);
        MinTree[Node] = std::min(MinTree[Node * 2], MinTree[Node * 2 + 1]);
    }

    return;
}

std::pair<int, int> FindMinMax(int Node, int Start, int End, int Left, int Right)
{
    if (Left > End || Right < Start)
        return std::make_pair(INT_MAX, INT_MIN); // INT_MAX와 INT_MIN 사용
    if (Left <= Start && End <= Right)
        return std::make_pair(MinTree[Node], MaxTree[Node]);

    int mid = (Start + End) / 2;
    std::pair<int, int> LeftRes = FindMinMax(Node * 2, Start, mid, Left, Right);
    std::pair<int, int> RightRes = FindMinMax(Node * 2 + 1, mid + 1, End, Left, Right);
    return std::make_pair(std::min(LeftRes.first, RightRes.first), std::max(LeftRes.second, RightRes.second));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M;

    int Height = static_cast<int>(ceil(log2(N)));
    MaxTree.resize(1 << (Height + 1));
    MinTree.resize(1 << (Height + 1));

    for (int i = 1; i <= N; i++)
    {
        std::cin >> Array_[i];
    }

    MakeTree(1, 1, N);

    int BoundFrom, BoundTo;
    std::pair<int, int> Res;

    while (M--)
    {
        std::cin >> BoundFrom >> BoundTo;
        Res = FindMinMax(1, 1, N, BoundFrom, BoundTo);
        std::cout << Res.first << " " << Res.second << '\n';
    }

    return 0;
}
