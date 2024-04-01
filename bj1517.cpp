/*
    출처 : https://j3sung.tistory.com/518
*/

#include <iostream>
#include <vector>

#define ll long long

int N;
ll swap_cnt = 0;
std::vector<int> v;

void Merge_Sort(int start, int end)
{
    if(start == end) return;

    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    std::vector<int> tmp;

    Merge_Sort(left, mid);
    Merge_Sort(right, end);

    while (left <= mid && right <= end)
    {
        if(v[left] <= v[right]) tmp.push_back(v[left++]);
        else
        {
            tmp.push_back(v[right++]);
            swap_cnt += (mid + 1 - left); //TODO: 왜 right라 하면 안되는지?
                                          // 당연히 안된다 바로 윗 라인에서 right++ 이런식으로
                                          // 값을 변경했다.
        }
    }

    while (left <= mid)
    {
        tmp.push_back(v[left++]);
    }
    
    while (right <= end)
    {
        tmp.push_back(v[right++]);
    }

    for(int i = start, j = 0; i <= end; i++, j++)
    {
        v[i] = tmp[j];
    }    
    
}

int main()
{
    std::cin>>N;
    v.assign(N ,0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>v[i];
    }

    Merge_Sort(0, N - 1);

    std::cout<<swap_cnt;

    return 0;
}